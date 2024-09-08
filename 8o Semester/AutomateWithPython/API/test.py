#A Python module for network request
import requests
import json

#API URL
url="https://dummyjson.com/products"


# Get data from API
response=requests.get(url)


# load json data
data=json.loads(response.text)

#for item in data['products']:
#	print(item)

#for item in data['products']:
#	print(item['title'])



url="https://example.com/post"
data={"data":"value"}
r=requests.post(url,data=data)


#print(r.text)

#Define the API endpoint

url="http://api.openweathermap.org/data/2.5/weather?q=London,uk&appid=YOUR_API_KEY"

#Make the request to the API
response=requests.get(url)

#Parse the response

data=response.json()

print(data)



