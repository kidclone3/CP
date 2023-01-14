from collections import defaultdict
from bs4 import BeautifulSoup
import re
with open('test.html', 'r') as f:
    contents = f.read()

    soup = BeautifulSoup(contents, 'html.parser')
    organization = soup.find_all('span', 'organization')
    dt = defaultdict(int)
    for i in organization:
        dt[[_ for _ in i.descendants][1]] += 1
    for i in dt.keys():
        if i.split()[0] != 'HSGS':
            print(i)
    # print(st[:10])
    # fi2 = soup.find('span', 'organization', 'a')
    # print(fi2.decomposed)
    # print(filename)
    # print([_ for _ in fi2.descendants][1])
        # print(i)
    