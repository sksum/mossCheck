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
    moss = mosspy.Moss(data["userId"], lang)
    if lang == "py":
        fA = open("client/submission/a.py", "w")
        fA.write(data["fileA"])
        #print(data["fileA"])
        fA.close()
        fB = open("client/submission/b.py", "w")
        fB.write(data["fileB"])
        fB.close()
        moss.addFile("client/submission/a.py")
        moss.addFile("client/submission/b.py")
    elif lang == "cc":
        fA = open("client/submission/a.cpp", "w")
        fA.write(data["fileA"])
        # print(data["fileA"])
        fA.close()
        fB = open("client/submission/b.cpp", "w")
        fB.write(data["fileB"])
        fB.close()
        moss.addFile("client/submission/a.cpp")
        moss.addFile("client/submission/b.cpp")
    elif lang == "c":
        fA = open("client/submission/a.c", "w")
        fA.write(data["fileA"])
        # print(data["fileA"])
        fA.close()
        fB = open("client/submission/b.c", "w")
        fB.write(data["fileB"])
        fB.close()
        moss.addFile("client/submission/a.c")
        moss.addFile("client/submission/b.c")
    elif lang == "js":
        fA = open("client/submission/a.js", "w")
        fA.write(data["fileA"])
        # print(data["fileA"])
        fA.close()
        fB = open("client/submission/b.js", "w")
        fB.write(data["fileB"])
        fB.close()
        moss.addFile("client/submission/a.js")
        moss.addFile("client/submission/b.js")
    elif lang == "java":
        fA = open("client/submission/a.java", "w")
        fA.write(data["fileA"])
        # print(data["fileA"])
        fA.close()
        fB = open("client/submission/b.java", "w")
        fB.write(data["fileB"])
        fB.close()
        moss.addFile("client/submission/a.java")
        moss.addFile("client/submission/b.java")
    # elif lang == "haskell":
    #     fA = open("client/submission/a.haskell", "w")
    #     fA.write(data["fileA"])
    #     # print(data["fileA"])
    #     fA.close()
    #     fB = open("client/submission/b.haskell", "w")
    #     fB.write(data["fileB"])
    #     fB.close()
    #     moss.addFile("client/submission/a.haskell")
    #     moss.addFile("client/submission/b.haskell")
    # elif lang == "fortran":
    #     fA = open("client/submission/a.fortran", "w")
    #     fA.write(data["fileA"])
    #     # print(data["fileA"])
    #     fA.close()
    #     fB = open("client/submission/b.fortran", "w")
    #     fB.write(data["fileB"])
    #     fB.close()
    #     moss.addFile("client/submission/a.fortran")
    #     moss.addFile("client/submission/b.fortran")
    # elif lang == "c#":
    #     moss = mosspy.Moss(data["userId"], "csharp")
    #     fA = open("client/submission/a.c#", "w")
    #     fA.write(data["fileA"])
    #     # print(data["fileA"])
    #     fA.close()
    #     fB = open("client/submission/b.c#", "w")
    #     fB.write(data["fileB"])
    #     fB.close()
    #     moss.addFile("client/submission/a.c#")
    #     moss.addFile("client/submission/b.c#")
    # elif lang == "vb":
    #     fA = open("client/submission/a.vb", "w")
    #     fA.write(data["fileA"])
    #     # print(data["fileA"])
    #     fA.close()
    #     fB = open("client/submission/b.vb", "w")
    #     fB.write(data["fileB"])
    #     fB.close()
    #     moss.addFile("client/submission/a.vb")
    #     moss.addFile("client/submission/b.vb")


    url = moss.send()
    print(url)
    #userid that work :12 ,123, 315118721 ,2, 3
    res = make_response(jsonify({"url": url}), 200)
    return res

if __name__ == "__main__":
    app.run(debug =True);
    # port = int(os.environ.get("PORT", 33507))
    # app.run(host='0.0.0.0', port=port)