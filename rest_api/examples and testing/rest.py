from flask import Flask, escape, request
import requests

# sending get request and saving the response as response object 


app=Flask(__name__)

@app.route("/on")
def on():
    r = requests.get(url = "http://167.172.62.61:3000/turn_on.php")
    return r.text

@app.route("/off")
def off():
    r = requests.get(url = "http://167.172.62.61:3000/turn_off.php")
    return r.text
    