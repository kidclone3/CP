def addNum(a, b):
    '''
    Cho 2 số nguyên a, b được biểu diễn bởi 2 danh sách
    thực hiện phép cộng 2 số a, b trên 2 danh sách theo quy tắc cộng thông thường. kết quả trả về là 1 danh sách biểu diễn tổng a+b
    ví dụ 
    a = [1,2,4,5]
    b =   [7,8,9]
   
    c = [2,0,3,4]
    '''
    aa = a.copy()
    bb = b.copy()
    while(len(aa) < len(bb)):
        aa.insert(0, 0)
    while(len(bb) < len(aa)):
        bb.insert(0, 0)
    k = 0
    c = [0]*len(aa)
    for i in range(len(aa)-1, -1, -1):
        tmp = aa[i] + bb[i] + k
        if (tmp >= 10):
            k = 1
            tmp = tmp % 10
        else:
            k = 0
        c[i] = tmp
    if k:
        c.insert(0, 1)
    return c
# # a = [int(i) for i in input().split()]
# # b = [int(i) for i in input().split()]
# c = addNum(a, b)
# print(c)