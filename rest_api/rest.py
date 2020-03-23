from flask import Flask, escape, request
from sender import Sender

# sending get request and saving the response as response object 

app=Flask(__name__)

@app.route("/on")
def on():
    sender = Sender()
    return sender.on()

@app.route("/off")
def off():
    sender = Sender()
    return sender.off()
    
