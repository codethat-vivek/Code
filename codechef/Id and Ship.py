# Question Link - https://www.codechef.com/problems/FLOW010

# Solution Link - https://www.codechef.com/viewsolution/36498550

# SOLUTION - 

# cook your dish here
t = int(input())
for i in range(t):
    ele = input()
    if ele == 'b' or ele == 'B':
        print("BattleShip")
    elif ele == 'c' or ele == 'C':
        print("Cruiser")
    elif ele == 'd' or ele == 'D':
        print("Destroyer")
    elif ele == 'f' or ele == "F":
        print("Frigate")
