# Question Link - https://codeforces.com/contest/1607/problem/B

# Solution - 

def fun():
    t = int(input())
    for _ in range(t):
        start, jumps = map(int, input().split())
        if jumps % 4 == 0:
            print(start)
        if abs(start) % 2 == 0:
            if jumps % 4 == 2:
                print(start+1)
            elif jumps % 4 == 1:
                print(start+1 - 4*(jumps//4+1)+2)
            elif jumps % 4 == 3:
                print(start+4*(jumps//4+1))
        else:
            if jumps % 4 == 2:
                print(start-1)
            elif jumps % 4 == 1:
                print(start-1 + 4*(jumps//4+1)-2)
            elif jumps % 4 == 3:
                print(start-4*(jumps//4+1))
 
    
fun()
