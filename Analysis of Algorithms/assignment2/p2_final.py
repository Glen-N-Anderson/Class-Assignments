#!/usr/bin/python

import sys
import math
import time
import csv


size = 6
table = [[0 for x in range(size)] for y in range(size)]

def write_file(str1, str2, cost):
	f = open("imp2output.txt", 'a')
	f.write(str1 + ',' + str2 + ':' + str(cost) + '\n')
	
def openCost(costFile):
	
	with open(costFile) as csvfile:
		readCSV = csv.reader(csvfile, delimiter=',')

		i = 0	
		for row in readCSV:
			table[i] = row
			i = i + 1	

def openStrings(stringsFile):


	with open(stringsFile) as csvfile:
		readCSV = csv.reader(csvfile, delimiter=',')

		for line in readCSV:
			string1 = line[0]
			string2 = line[1]

			editDistance(string1, string2)

def getCost(char1, char2):
	if(char1 == "-"): a = 1
	elif(char1 == "A"): a = 2
	elif(char1 == "T"): a = 3
	elif(char1 == "G"): a = 4
	else: a = 5


	if(char2 == "-"): b = 1
	elif(char2 == "A"): b = 2
	elif(char2 == "T"): b = 3
	elif(char2 == "G"): b = 4
	else: b = 5

	return int(table[a][b])


def editDistance(str1, str2):
	matrix = {}
	matrix2 = {}
	for i in range(0, len(str1)+1):
		if i == 0:
			matrix[i,0] = getCost("-", "-")
		else:	
			matrix[i, 0] = getCost("-", str1[i-1]) + matrix[i-1,0]
		matrix2[i, 0] = (matrix[i,0], "L")
	for j in range(0, len(str2)+1): 
		if j == 0:
			matrix[0, j] = getCost("-", "-")	
		else:	
			matrix[0, j] = getCost("-", str2[j-1]) + matrix[0, j-1]
		matrix2[0, j] = (matrix[0,j], "U")
	for i in range(1, (len(str1)+1)):
		for j in range(1, (len(str2)+1)):
			if str1[i-1] == str2[j-1]: cost = 0
			else: cost = getCost(str1[i-1], str2[j-1])
			
			#min -> insert, delete, sub/copy
			matrix[i, j] = min(matrix[i-1,j]+getCost(str1[i-1], "-"), matrix[i, j-1]+getCost("-", str2[j-1]), matrix[i-1, j-1]+cost)
			if matrix[i, j] == matrix[i-1, j-1]+cost:
				direction = "D"
			elif matrix[i,j] == matrix[i, j-1]+getCost("-", str2[j-1]):
				direction = "U"
			elif matrix[i,j] == matrix[i-1,j]+getCost(str1[i-1], "-"):
				direction = "L"

			matrix2[i, j] = (matrix[i,j], direction,)
			
	cost = matrix[i,j]
	tracei = ""
	tracej = ""	
	
	while i != 0 or j != 0:
		if matrix2[i, j][1] == "D":
			j = j - 1
			i = i - 1
			tracei = tracei + str1[i]
			tracej = tracej + str2[j]	
		elif matrix2[i, j][1] == "U":
			j = j - 1
			tracei = tracei + '-'
			tracej = tracej + str2[j]
		elif matrix2[i,j][1] == "L":
			i = i - 1
			tracei = tracei + str1[i]
			tracej = tracej + '-'

	#Reverse the string since both strings were read backwards
	tracei = tracei[::-1]
	tracej = tracej[::-1]

	write_file(tracei, tracej, cost)

def main():
	openCost("imp2cost.txt")
	openStrings("imp2input.txt")


if __name__ == "__main__":
	main()
	
