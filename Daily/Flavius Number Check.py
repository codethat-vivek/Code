'''
Question - Given a series of integers from 1 to infinity and a number N.
The task is to remove every (i + 1)-th element from the remaining series at every i-th iterations and find that the given number N exists in the series or not.
Flavius Number: 
 

Numbers in the Flavius Sieve are called Flavius Numbers.
Flavius sieve starts with the natural numbers and keep repeating the below step: 
At the k-th sieving step, remove every (k+1)-st term of the sequence remaining of N natural numbers after the (k-1)-st sieving step. 
For Example: 1, 3, 7, 13, 19, 27, 39, 49....
'''

# Solution - 

def Survives(n) :
	i = 2
	while(True) :
		if (i > n) :
			return True;
		if (n % i == 0) :
			return False;
		n -= n // i;
		i += 1

if __name__ == "__main__" :

	n = 17;
	
	if (Survives(n)) :
		print("Yes");
		
	else :
		print("No");

