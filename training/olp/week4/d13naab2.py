a = int(input())
b = int(input())
    # ll a, b; cin >> a >> b;
    # ll ans = 0LL;
ans = 0
while(a % 9 != 0 and a <= b):
    ans += a%9 
    a += 1
if (a % 9 ==0):
    ans += 9 
    a += 1
while(b % 9 != 0 and b >= a):
    ans += b % 9 
    b -= 1
if (b > a):
    ans += (b-a+1)//9 * 45;

# print(a, b)
print(ans)
