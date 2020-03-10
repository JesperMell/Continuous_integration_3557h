from flask import Flask, escape, request
import requests
URL = "Http://maps.googleapis.com/maps/api/geocode/json"
# location given here 
location = "delhi technological university"
  
# defining a params dict for the parameters to be sent to the API 
PARAMS = {'address':location} 
  
# sending get request and saving the response as response object 
r = requests.get(url = URL, params = PARAMS) 
  
# extracting data in json format 
data = r.json() 

app=Flask(__name__)

@app.route("/on")
def on():
    send on to esp32
    return 'Hello Linus'

@app.route("/off")
def off():
    return 'Goodbye Linus'