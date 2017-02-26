#This is the program for a brute force approach to solving the closest points problem, and will run in O(n^2) time.
import sys
import math
def writefile(points, distance):
	f1 = "output_bruteforce.txt"	
	with open(f1, "a+") as f:
		f.write(str(distance) + '\n')
		for i in points:
			f.write(i[0] + " " + i[1] + '\n')
	
def brute_sort(coords):
	#we will append all closest points to some array 
	distances = []
	points = []
	closest_points = []
	current = math.sqrt(pow((float(coords[1][0])-float(coords[0][0])), 2) + pow((float(coords[1][1])-float(coords[0][1])), 2))
	for i in range(len(coords)):
		for j in range(i):
			points.append((coords[i][0] + " " + coords[i][1], coords[j][0] + " " + coords[j][1]))
			distance = math.sqrt(pow((float(coords[j][0])-float(coords[i][0])), 2) + pow((float(coords[j][1])-float(coords[i][1])), 2))
			distances.append(distance) 		
			if current > distance:
				current = distance
				point = coords[j][0] + " "  + coords[i][0] + " " +  coords[j][1] + " " + coords[i][1]			
	for i in range(len(distances)):
		if distances[i] == current:
			closest_points.append(sorted(points[i])) #handles other points of same distance		

	
	closest_points = sorted(closest_points)
	writefile(closest_points, current)

def readfile(fn):
	coords = []
	pairs = []
	with open(fn) as f:
		coords = f.read().splitlines()
	for i in range(len(coords)):
		pairs.append(coords[i].split())
	
	brute_sort(pairs)
def main(filename):
	if len(filename) == 1:
		fn = filename[0]	
		readfile(fn)
	else:
		print "Error reading command line. Format: program <filename>"

	



if __name__ == "__main__":
    main(sys.argv[1:])
