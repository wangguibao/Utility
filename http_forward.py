"""Demonstrates how to forward http requests
In this demo, if you request http://localhost:8000/search, you will get response {'a': 1, 'b': 2}

@file: http_forward.py
@author: wangguibao (wang_guibao@163.com)
@date: 2023/12/09
"""
from flask import Flask, request
from flask_cors import CORS
import requests

app = Flask(__name__)
CORS(app)

SEARCH_URL = 'http://localhost:8000/new_search'

@app.route('/search', methods=['POST', 'GET'])
def search():
    input_data = request.get_data()

    res = requests.post(SEARCH_URL, data=request.get_data())
    return res.json()

@app.route('/new_search', methods=['POST', 'GET'])
def new_search():
    print("new_search")
    return {'a': 1, 'b': 2}

if __name__ == "__main__":
    app.run(host = "0.0.0.0", port = 8000)
