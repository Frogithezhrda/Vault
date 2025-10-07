from twilio.rest import Client
import Auth
import sys

client = Client(Auth.ACCOUNT_SID, Auth.AUTH_TOKEN)


def send_message(message):
    client.messages.create(
        from_=Auth.SEND_FROM,
        body=message,
        to=Auth.SEND_TO
    )


if __name__ == "__main__":
    if len(sys.argv) > 1:
        for arg in sys.argv[1:]:
            send_message(arg)
