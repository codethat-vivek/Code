# Question Link - https://leetcode.com/problems/apply-discount-every-n-orders/

# Solution - 

class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.n = n
        self.t = n
        self.discount = discount
        self.dt = {}
        for i in range(len(products)):
            self.dt[products[i]] = prices[i]
        

    def getBill(self, product: List[int], amount: List[int]) -> float:
        self.t -= 1
        bill = 0
        for i in range(len(product)):
            bill += (self.dt[product[i]]*amount[i])
        if self.t == 0:
            bill *= ((100-self.discount)/100)
            self.t = self.n
        return bill


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
