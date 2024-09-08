import sys,csv,operator,numpy as np ,pandas as pd,warnings
from sklearn.metrics import mean_absolute_error
from tqdm.auto import tqdm


warnings.simplefilter(action='ignore', category=FutureWarning)

def readFile(file):
    columns = ['userId', 'movieId', 'rating','timestamp']
    ratings = pd.read_csv(file, sep=',', names=columns, encoding='utf-8', quoting=csv.QUOTE_ALL,skipinitialspace=True)
    ratings = ratings.dropna()
    ratings = ratings.drop(ratings.index[0])
    ratings['rating'] = ratings['rating'].astype(float)
    ratings = ratings.drop(columns=['timestamp'])

    return ratings


def adjusted_cosine_similarity(set1, set2):
    numerator = np.dot(set1, set2)
    denominator = np.sqrt(np.sum(np.square(set1))) * np.sqrt(np.sum(np.square(set2)))
    if denominator == 0:
        return 0
    adjusted_cosine = numerator / denominator

    return adjusted_cosine


inputData=readFile("ratings.csv")
#Filter by movies.
movie_counts=inputData.groupby('movieId').size()
movie_counts=movie_counts.sort_values(ascending=False)
movie_counts=movie_counts[movie_counts >= 200]
#Filter by users.
user_counts=inputData.groupby('userId').size()
user_counts=user_counts.sort_values(ascending=False)
user_counts=user_counts[user_counts>= 200]
#update training set.
inputData=inputData[inputData['movieId'].isin(movie_counts.index)]
inputData=inputData[inputData['userId'].isin(user_counts.index)]


while(K := int(input('Enter the K value: '))) < 1:
        print('K value must be greater than 0')

while (training_set_percentage := float(
            input('Please specify the percentage of the data to be used for training. It must be below 90%(p.e. 0.8 = 80%): '))) > 0.9:
        print('The percentage must be below 90%(0.1 - 0.9). Please try again.')


test_set=inputData.sample(frac=0.1)

training_set_count=int(training_set_percentage * len(inputData))    
training_set=inputData.drop(test_set.index)
training_set=inputData.sample(training_set_count)

training_set_pivot=training_set.pivot(index='userId', columns='movieId', values='rating')
training_set_pivot=training_set_pivot.apply(lambda x: (x - np.nanmean(x)))
training_set_pivot=training_set_pivot.fillna(0)


user_similarity={}  
user_rating_dict={}

for user_id, values in training_set_pivot.iterrows():
    user_rating_dict[user_id]=np.array(values)

    for user_id in tqdm(user_rating_dict, desc='Calculating user similarities', unit=' users'):
        user_similarity[user_id] = {}
        for other_user_id in user_rating_dict:
            if user_id != other_user_id:
                user_ratings=user_rating_dict[user_id]
                other_user_ratings=user_rating_dict[other_user_id]

                
                user_similarity[user_id][other_user_id] = adjusted_cosine_similarity(user_ratings, other_user_ratings)

    for user_id in user_similarity:
        user_similarity[user_id]=dict(
            sorted(user_similarity[user_id].items(), key=operator.itemgetter(1), reverse=True))




predicted_ratings = pd.DataFrame(columns=['userId', 'movieId', 'rating'])

for index, row in tqdm(test_set.iterrows(), unit=' entries', total=len(training_set)):        
    user_id=row['userId']
    movie_id=row['movieId']
    rating=row['rating']

    similar_users=user_similarity[user_id]

        
    similar_users_ratings=training_set[
            (training_set['userId'].isin(similar_users)) & (training_set['movieId'] == movie_id)]

        
    similar_users_ratings=similar_users_ratings.assign(
            similarity=similar_users_ratings['userId'].map(lambda x: user_similarity[user_id][x]))

        
    similar_users_ratings=similar_users_ratings[similar_users_ratings['similarity'] > 0]

        
    similar_users_ratings=similar_users_ratings.sort_values(by='similarity', ascending=False).head(K)

        
    if len(similar_users_ratings) != 0:

            
        similar_users_ratings['rating']=similar_users_ratings['rating'] * similar_users_ratings['similarity']

            
        sum_similar_users_ratings=similar_users_ratings['rating'].sum()

            
        sum_similar_users_ratings_similarity=similar_users_ratings['similarity'].sum()

            
        predicted_rating=sum_similar_users_ratings / sum_similar_users_ratings_similarity

            
        predicted_ratings=predicted_ratings.append(
                {'userId': user_id, 'movieId': movie_id, 'rating': predicted_rating}, ignore_index=True)

    else:
        predicted_ratings=predicted_ratings.append({'userId': user_id, 'movieId': movie_id, 'rating': np.nan},
                                                         ignore_index=True)



   
predicted_ratings=predicted_ratings.dropna()

    
test_set=test_set.reset_index(drop=True)

   
test_set=test_set.drop(test_set[test_set.index.isin(predicted_ratings.index) == False].index)

mae=mean_absolute_error(test_set['rating'], predicted_ratings['rating'])

predicted_ratings['positivity']=predicted_ratings['rating'].apply(lambda x: 1 if x >= 3 else 0)

test_set['positivity']=test_set['rating'].apply(lambda x: 1 if x >= 3 else 0)

positivity=pd.DataFrame(columns=['predicted', 'actual'])
positivity['predicted']=predicted_ratings['positivity']
positivity['actual']=test_set['positivity']

 
true_positives=positivity[(positivity['actual'] == 1) & (positivity['predicted'] == 1)].shape[0]
false_positives=positivity[(positivity['actual'] == 0) & (positivity['predicted'] == 1)].shape[0]
false_negatives=positivity[(positivity['actual'] == 1) & (positivity['predicted'] == 0)].shape[0]

    

recall=true_positives/(true_positives + false_negatives)
precision=true_positives/(true_positives + false_positives)


print("---Output:---")
print('test set with 10%')
print('traing set with ',100 * training_set_percentage,'%')
print('k:',K)
print('MAE: ', round(mae,3))
print('Recall: ', round(recall,3))
print('Precision: ', round(precision,3))
print()
   


