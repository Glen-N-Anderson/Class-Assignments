def main():
	def get_initial_input():
		num_tests =int(input("Enter the number of unweighted tests: "))
		num_assignments = int(input("Enter the number of assignments: "))
		num_quizzes = int(input("Enter the number of quizzes: "))
		num_labs = int(input("Enter the number of labs: "))
	get_initial_input()
	def get_scores():
		num_tests = int(input("Enter the number of unweighted tests:"))
		test_scores = []
		for x in range(0,num_tests):
			test_scores.append(float(input("Enter test scores(decimal value of points/points possible): ")))
			
		
		
			
			
	get_scores()	
	def tests_weighted():
		num_tests_weighted = int(input("How many weighted tests are there?"))
		weights = []
		for x in range(num_tests_weighted):
			x += 1
			weights.append(input("What is the weight of test?"))
		scores = []
		for x in range(num_tests_weighted):
			x += 1
			scores.append(input("What are the scores of weighted tests?"))	 	
	tests_weighted() 
	
				

main()	
		
