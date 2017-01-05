import string
import random

files = [None] * 3 #creates an array to hold all of the files 

	
files[0] = "file1" #assign each element of the array a file name 
files[1] = "file2"
files[2] = "file3"

print "\nFile contents: "
for i in range(3): #loop through the array of files 
	#generate random characters, put them in files
	fp = open(files[i], "a+") #open the next file for writing 
	rand_string = "" #create a string to hold the random string, reset it to nothing each time through 	
	for i in range(10): #we need 10 letters, so loop through 10 times 
		rand_num = random.randint(0, 25) #get us random number to access alphabet by index, randomly 
		rand_string += string.lowercase[rand_num]	#get the random letter and append it to the string 
	rand_string = rand_string + '\n' #this will put newline at end up string. While this won't show up as an empty line in the file, it is clear that there is a newline there when we print. This will make the file line be terminated with a new line. 
	fp.write(rand_string)	#write the string  to the file 
	print rand_string #print each string 
	fp.close() #close current file 

#Number generation:

rand1 = random.randint(1, 42)	#generate two numbers between 1 and 42 inclusively 	
rand2 = random.randint(1, 42)

print "\nNumbers: "

print rand1 #print numbers, then print their products 
print rand2
print rand1 * rand2	
