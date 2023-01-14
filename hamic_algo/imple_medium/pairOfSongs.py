def pairsOfSongs(arr,time):
    n = len(arr)
    mod = [0]*n
    for i in range(n):
        mod[i] = arr[i] % time
    