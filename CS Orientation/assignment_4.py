import math
n = input("Enter a positive whole number to get sqaure root: ")
guess = input("Guess at the square root of your number: ")
for i in range(0,30): 
	r = int(n)/int(guess)
	guess = (int(guess) + r)/2
print(guess)	
print(math.sqrt(int(n)))
	
