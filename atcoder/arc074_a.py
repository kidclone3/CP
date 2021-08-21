import math
H, W = map(int, input().split())
def solve():
    ans = int(1e18)
    if (H % 3 == 0 or W % 3 == 0):
        return 0
    else:
        for h in range(1, H):
            h_B = math.floor((H-h)/2)
            h_C = math.ceil((H-h)/2)
            w_B = math.floor(W/2)
            w_C = math.ceil(W/2)
            s1 = h*W
            s2 = h_B*W
            s3 = h_C*W
            mx = max([s1, s2, s3])
            mn = min([s1, s2, s3])
            ans = min(mx - mn, ans)
            # print(f"{s1}, {s2}, {s3}\t {ans}")
            s2 = (H-h)*w_B
            s3 = (H-h)*w_C
            mx = max([s1, s2, s3])
            mn = min([s1, s2, s3])
            ans = min(mx - mn, ans)
            # print(f"{s1}, {s2}, {s3}\t {ans}")
        for w in range(1, W):
            h_B = math.floor(H/2)
            h_C = math.ceil(H/2)
            w_B = math.floor((W-w)/2)
            w_C = math.ceil((W-w)/2)
            s1 = H*w
            s2 = H*w_B
            s3 = H*w_C
            mx = max([s1, s2, s3])
            mn = min([s1, s2, s3])
            ans = min(mx - mn, ans)
            # print(f"{s1}, {s2}, {s3}\t {ans}")
            s2 = h_B*(W-w)
            s3 = h_C*(W-w)
            mx = max([s1, s2, s3])
            mn = min([s1, s2, s3])
            ans = min(mx - mn, ans)
            # print(f"{s1}, {s2}, {s3}\t {ans}")
        return ans
print(solve())
