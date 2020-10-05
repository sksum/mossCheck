from flask import Flask, send_from_directory
import random
import mosspy
import os



app = Flask(__name__)

# Path for our main Svelte page
@app.route("/")
def base():
    return send_from_directory('./public', 'index.html')

# Path for all the static files (compiled JS/CSS, etc.)
@app.route("/<path:path>")
def home(path):
    return send_from_directory('./public', path)

@app.route("/moss/<int:userid>")
def hello(userid):
    moss = mosspy.Moss(userid, "python")
    moss.addFile("submission/a01.py")
    moss.addFile("submission/a02.py")
    url = moss.send()
    return url

if __name__ == "__main__":
    app.run(debug=True)