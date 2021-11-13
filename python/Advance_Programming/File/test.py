import json
import pickle

data = {
    'a' : [1, 2.0, 3, 4+6j],
    'b' : ("char", b"byte string"),
    'c' : {None, True, False}
}

with open('data.pickle', 'wb') as f:
    pickle.dump(data, f, pickle.HIGHEST_PROTOCOL)

with open('data.pickle', 'rb') as f:
    data = pickle.load(f)
    print(data)