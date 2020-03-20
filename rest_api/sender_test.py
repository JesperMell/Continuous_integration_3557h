import unittest
from unittest import mock
from sender import Sender

def mocked_esp_request(*args, **kwargs):
    class ESPResponse:
        def __init__(self, text):
            self.text = text

        def text(self):
            return self.text

    if args[0] == "http://test.invalid/on":
        return ESPResponse("Turned On")
    elif args[0] == "http://test.invalid/off":
        return ESPResponse("Turned Off")


class TestSenderRequests(unittest.TestCase):

    @mock.patch("requests.get", side_effect=mocked_esp_request)
    def test_on_1(self, mock_get):
        sender = Sender()
        sender.url = "http://test.invalid"

        self.assertEqual(sender.on(), "Turned On")

    @mock.patch("requests.get", side_effect=mocked_esp_request)
    def test_off_1(self, mock_get):
        sender = Sender()
        sender.url = "http://test.invalid"

        self.assertEqual(sender.off(), "Turned Off")

if __name__=='__main__':
    unittest.main()
