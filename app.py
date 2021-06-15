from flask import Flask, send_from_directory, request,make_response, jsonify
import mosspy
import json

app = Flask(__name__)

# Path for our main Svelte page
@app.route("/")
def base():
    return send_from_directory('./public', 'index.html')

# Path for all the static files (compiled JS/CSS, etc.)
@app.route("/<path:path>")
def home(path):
    return send_from_directory('./public', path)

@app.route("/hello", methods =["POST","GET"])
def hello1():
    data = json.loads(request.data)
    lang = data["lang"]
    print(lang)
    moss = mosspy.Moss(data["userId"], lang)
    fA = open(f'submission/a.{lang}', "w")
    fA.write(data["fileA"])
    #print(data["fileA"])
    fA.close()
    fB = open(f'submission/b.{lang}', "w")
    fB.write(data["fileB"])
    fB.close()
    moss.addFile(f'submission/a.{lang}')
    moss.addFile(f'submission/b.{lang}')

    url = moss.send()
    print(url)
    #userid that work :12 ,123, 315118721
    res = make_response(jsonify({"url": url}), 200)
    return res

if __name__ == "__main__":
    app.run(debug=True)