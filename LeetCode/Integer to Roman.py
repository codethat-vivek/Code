# Question Link - https://leetcode.com/problems/integer-to-roman/

# Solution - 

class Solution:
    def intToRoman(self, num: int) -> str:
        if num == 0 : return ""
        if num == 4 : return "IV"
        if num == 9 : return "IX"
        if num >= 40 and num <= 49 : return "XL" + self.intToRoman(num-40)
        if num >= 90 and num <= 99 : return "XC" + self.intToRoman(num-90)
        if num >= 400 and num <= 499 : return "CD" + self.intToRoman(num-400)
        if num >= 900 and num <= 999 : return "CM" + self.intToRoman(num-900)
        
        dt = dict()
        dt['I'] = 1
        dt['V'] = 5
        dt['X'] = 10
        dt['L'] = 50
        dt['C'] = 100
        dt['D'] = 500
        dt['M'] = 1000
        
        
        symb, number = 'I', 1
        for key in dt:
            if dt[key] > num:
                break
            symb = key
            number = dt[key]

        times = int(num)//number
        return symb*times + self.intToRoman(num-number*times)
