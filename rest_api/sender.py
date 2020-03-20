import requests

class Sender:
    def __init__(self):
        self.url = "http://"

    def on(self):
        request_url = self.url + "/on"
        request = requests.get(request_url)
        return request.text

    def off(self):
        request_url = self.url + "/off"
        request = requests.get(request_url)
        return request.text
