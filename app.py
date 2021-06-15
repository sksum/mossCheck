from flask import Flask, send_from_directory, request,make_response, jsonify
import random
import mosspy
import os
import json

app = Flask(__name__)

# Path for our main Svelte page
@app.route("/")
def base():
    return send_from_directory('./client/public', 'index.html')

# Path for all the static files (compiled JS/CSS, etc.)
@app.route("/<path:path>")
def home(path):
    return send_from_directory('./client/public', path)

@app.route("/hello", methods =["POST","GET"])
def hello1():
    data = json.loads(request.data)
    lang = data["lang"]
    print(lang)
    extensions = {
        "py": "py",
        "cc": "cpp",
        "c": "c",
        "js": "js",
        "java": "java",
        "haskell":"haskell",
        "fortran": "fortran",
        "csharp": "c#",
        "vb" : "vb"
    }
    moss = mosspy.Moss(data["userId"], lang)
    fA_name = "client/submission/a." + extensions[lang]
    fA = open(fA_name, "w")
    fA.write(data["fileA"])
    fA.close()
    fB_name = "client/submission/b." + extensions[lang]
    fB = open(fB_name, "w")
    fB.write(data["fileB"])
    fB.close()
    moss.addFile(fA_name)
    moss.addFile(fB_name)

    url = moss.send()
    print(url)
    #userid that work :12 ,123, 315118721 ,2, 3
    res = make_response(jsonify({"url": url}), 200)
    return res

if __name__ == "__main__":
    app.run(debug =True);
    port = int(os.environ.get("PORT", 33507))
    app.run(host='0.0.0.0', port=port)