#!/usr/bin python

import pickle

with open('data/imdb.pkl', 'rb') as f:
    data = pickle.load(f)
    print data