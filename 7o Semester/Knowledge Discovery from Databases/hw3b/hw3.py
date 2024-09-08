import numpy as np
import pandas as pd
import math
from sklearn.preprocessing import MinMaxScaler
import warnings
from operator import itemgetter


sk=MinMaxScaler()

df_i=pd.read_csv('iris.csv')
df_ii=pd.read_csv('letter-recognition.csv')

class_i=df_i['class']
class_ii=df_ii['class']

df_i_normalization=pd.DataFrame(sk.fit_transform(df_i.drop('class', axis='columns')))
df_i_normalization=np.around(df_i_normalization,decimals=6)

df_ii_normalization=pd.DataFrame(sk.fit_transform(df_ii.drop('class', axis='columns')))
df_ii_normalization=np.around(df_ii_normalization,decimals=6)

warnings.simplefilter(action='ignore', category=FutureWarning)


def IB2(df,class_attribute):
    columns=[str(i) for i in range(0,len(df.values[0]))]
    cs={'point':pd.DataFrame([df.values[0]],columns=[str(i) for i in range(0,len(df.values[0]))]),'class':[class_attribute.values[0]]}
    ts={'point':df.drop(0),'class':class_attribute.drop(0)}
    
    for index,point in enumerate(ts['point'].values):
        if k_nearest(cs,point,1)[-1]['class']!=ts['class'].values[index]:
            newPoint={}
            for col in columns:
                newPoint[col]=ts['point'].values[index][int(col)]

            cs['point']=cs['point'].append(newPoint,ignore_index=True)
            cs['class'].append(ts['class'].values[index])
    
    cs['class']=pd.DataFrame(cs['class'],columns=['class'])
    return cs['point'].join(cs['class'])


def ENN(df,class_attribute):
    es={'point':df,'class':class_attribute}
    ts={'point':df,'class':class_attribute}
   
    for index,point in enumerate(ts['point'].values):
        nearest=k_nearest(ts,point,3)
        if  len([1 for k in nearest if k['class']==ts['class'][index]])/3 < 0.5:
            es['point']=es['point'].drop(index)
            es['class']=es['class'].drop(index)
        
    return es['point'].join(es['class'])

           
def k_nearest(available,current_point,k):
    nearest=[]
    for index,point in enumerate(available['point'].values):
        
        if (len(nearest)<k and np.around(math.dist(point,current_point),decimals=6)!=0.0):
            distance=np.around(math.dist(point,current_point),decimals=6)
            nearest.append({'distance':distance,'class':available['class'][index]})
            continue
        else:
            score=np.around(math.dist(point,current_point),decimals=6)
            if len(nearest)==k and score<nearest[k-1]['distance'] and score!=0.0:
                nearest[k-1]['distance']=score
                nearest[k-1]['class']=available['class'][index]
                nearest=sorted(nearest,key=itemgetter('distance'))
        
    return nearest


#Run IB2:

irisIB2=IB2(df_i_normalization,class_i)
irisIB2.to_csv('irisIB2.csv')

letter_recognitionIB2=IB2(df_ii_normalization,class_ii)
letter_recognitionIB2.to_csv('letter-recognitionIB2.csv')

#Run ENN:
irisENN=ENN(df_i_normalization,class_i)
irisENN.to_csv('irisENN.csv')

letter_recognitionENN=ENN(df_ii_normalization,class_ii)
letter_recognitionENN.to_csv('letter-recognitionENN.csv')



