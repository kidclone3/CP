from typing import List
def findOriginalArray(changed: List[int]) -> List[int]:
        changed.sort()
        ans = []
        n = len(changed)
        i = 0
        j = 0
        check = [0]*(n)
        while(len(ans) < n//2):
            if (check[i] == 1):
                i+=1
                continue
            check[i] = 1
            while(j < n-1 and (changed[j] < 2*changed[i] or check[j]==1)):
                j+=1
            if (changed[j] == 2*changed[i] and check[j] == 0):
                ans.append(changed[i])
                check[j] = 1
            else:
                return []
            i+=1
            
        return ans
inp = [0,3,2,4,6,0]
print(findOriginalArray(inp))