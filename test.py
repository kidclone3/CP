a = [10, 11, 12, 13, 16, 8, 12, 15, 6] # 7
""" Cho giá trị của một cổ phiếu A theo mỗi ngày như mảng bên trên.
    Tìm một ngày mua và một ngày bán sao cho lợi nhuận thu được là cao nhất.
"""

def find_max_profit(a):
    mn = 10
    mxVal = 0
    dayBuy = -1
    daySell = -1
    dayMin = -1
    for i, val in enumerate(a):
        # print(i, val)
        if i == 0:
            continue
        if val <= mn:
            mn = val
            dayMin = i
        if val - mn > mxVal:
            mxVal = val - mn
            daySell = i
            dayBuy = dayMin
    return mxVal, dayBuy, daySell

print(find_max_profit(a))