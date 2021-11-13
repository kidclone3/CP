import os
def searchInFiles(x, path):
    result = []
    ls = os.listdir(path)
    for file in ls:
        textfile = open(path + "/" + file, encoding="utf-8")
        for line in textfile:
            if x in line:
                result.append((path +'/' + file, line))
                break
        textfile.close()
    result.sort()
    return result

    pass
# searchInFiles("abc", '/home/delus')