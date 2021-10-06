import pandas as pd
from pandas.core.indexing import _iLocIndexer
df = pd.read_excel('dean.xlsx')

# This tool just print queries to the output, so it should be piped to some file first.

print('INSERT INTO DEAN(TENDA,MADA,DDIEM_DA,PHONG) VALUES ', end = ' ')
for i in range(len(df)):
    print('(', end='')    
    for j in range(len(df.iloc[i])):
        if (j != len(df.iloc[i])-1):
            ed = ', '
        else:
            ed = ' '
        print(f'\'{df.iloc[i, j]}\'', end = ed)
    print(end = '),')
# print(df.iloc[0, 0])