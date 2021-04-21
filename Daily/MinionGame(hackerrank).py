'''
Question - The Minion Game
Kevin and Stuart want to play the 'The Minion Game'.

Game Rules

Both players are given the same string, S.
Both players have to make substrings using the letters of the string S.
Stuart has to make words starting with consonants.
Kevin has to make words starting with vowels.
The game ends when both players have made all possible substrings.

Scoring
A player gets +1 point for each occurrence of the substring in the string S.

For Example:
String  S= BANANA
Kevin's vowel beginning word = ANA
Here, ANA occurs twice in BANANA. Hence, Kevin will get 2 Points.
Your task is to determine the winner of the game and their score.

Sample Input: BANANA
Sample Output: Stuart 12
'''

# SOLUTION - 

def minion_game(s):
    vowels = "AEIOU"
    stuart = 0
    kevin = 0
    for i in range(len(s)):
        if s[i] in vowels:
            kevin += (len(s) - i)
        else:
            stuart += (len(s) - i)
    if kevin > stuart:
        print("Kevin " + str(kevin))
    elif kevin < stuart:
        print("Stuart " + str(stuart))
    else:
        print("Draw")
    
