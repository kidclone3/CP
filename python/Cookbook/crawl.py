import re 
import requests
import os
import shutil
from settings import *
if os.path.isdir("data"):
    shutil.rmtree("data")
os.mkdir("data")
# pages = [1]
for i in pages:
    url = MAIN_URL.format(i)
    print(url)
    r = requests.get(url) 
    with open('data/out{}.html'.format(i), 'w+') as f:
        print(r.text, file=f)
