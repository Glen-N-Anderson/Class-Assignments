
def get_initial_input():
	nums = []
	nums.append(int(input("Enter number of tests: ")))
	nums.append(int(input("Enter number of assignments: ")))
	nums.append(int(input("Enter number of quizzes: ")))
	nums.append(int(input("Enter number of labs: ")))
	return nums
def get_scores(nums):
	test_scores = []
	for x in range(nums[0]):	
		test_scores.append(float(input("Enter test score: ")))
	assignment_scores = []
	for x in range(nums[1]):	
		assignment_scores.append(float(input("Enter assignment score: ")))
	quiz_scores = []
	for x in range(nums[2]):	
		quiz_scores.append(float(input("Enter quiz score: ")))
	lab_scores = []
	for x in range(nums[3]):	
		lab_scores.append(float(input("Enter lab score: ")))
	scoresavg = []
	scoresavg.append(sum(test_scores) / len(test_scores))
	scoresavg.append(sum(assignment_scores) / len(assignment_scores))
	scoresavg.append(sum(quiz_scores) / len(quiz_scores))
	scoresavg.append(sum(lab_scores))	
	is_final = input("Is there a final with seperate weight?(1 = yes, 0 = no)")
	y = True	
	if is_final == "1":
		final_score = float(input("Enter final score: "))	
		scoresavg.append(final_score)
	if is_final == "0":
		y = False
	return scoresavg
def calculate_weighted_avg(scoresavg):
	
	test = float(input("Enter test weight: "))
	scoresavg[0] = scoresavg[0] * test
	
	assignment = float(input("Enter assignment weight: "))
	scoresavg[1] = scoresavg[1] * assignment
	
	quiz = float(input("Enter quiz weight: "))
	scoresavg[2] = scoresavg[2] * quiz
	
	labs = float(input("Enter lab weight: "))
	scoresavg[3] = scoresavg[3] * labs
		
	if len(scoresavg) == 5:
		final = float(input("Enter final weight: "))
		scoresavg[4] = scoresavg[4] * final
	else:
		calculate_class_grade(scoresavg)
	return scoresavg
def calculate_class_grade(scoresavg):
	grade = sum(scoresavg) / 1
	if grade < .6:
		print("You got an F...APPLY YOURSELF")
		print(grade)
	elif grade < .7:
		print("You got a D")
		print(grade)
	elif grade < .8:
		print("You got a C")
		print(grade)
	elif grade < .9:
		print("You got a B")
		print(grade)
	elif grade < 1:
		print("You got an A!")
		print(grade)
	else:
		print("You got over 100%!")
	return grade
def main():	
	nums = get_initial_input()
	scoresavg = get_scores(nums)
	scoresavg = calculate_weighted_avg(scoresavg)
	grade = calculate_class_grade(scoresavg)
	x = True
	while x is True:
		repeat = input("Would you like to calculate another grade?(1 = yes, 0 = no)")
		if repeat == "1":
			main()
		elif repeat == "0":
			y = False
			break
main()
