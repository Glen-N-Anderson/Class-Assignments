def kwic(document, ignoreWords, listPairs, setPeriodBreaks):
	templist = []
	biglist = []
	count = 0
	count2 = document.count('\n')
	count3 = 0
	ignoreable_set = [".",":",",","?","!"]


	if count2 == 0 and setPeriodBreaks == False: #standard kwic without new lines or special arguments for the shifts
		document = document.split()
		for i in document:
			biglist.append((document[:], 0,))
                	document.insert(0,document[-1])
                	document.pop(-1)
		if(ignoreWords):
			templist = []
			for word in ignoreWords:
				word = filter(lambda chars: chars not in ignoreable_set, word.lower())
				templist.append(word)
			for tup in biglist:
				for i in range(len(templist)):
					if tup[0][0].lower() ==  templist[i]:
						biglist.pop(count3)
				count3 += 1


	if setPeriodBreaks == True: #should check for spaces and then check that two spaces preceeding space are a lowercase letter followed by a period
		breakstring = ""
		remainstring = ""
		tempstring = ""	
		breaklist = []	
		for i in range(len(document)):
			if document[i] == ' ' and document[i-1] == '.' and document[i-2].islower():
					
				for chars in range(len(document[:i])):
					breakstring = breakstring + document[chars]
				for chars2 in range(i, len(document)):
					remainstring = remainstring + document[chars2]
				tempstring = remainstring
				remainstring = ""
				breaklist.append(breakstring)
				breakstring = ""
			

	
		breaklist.append(tempstring)
		document = breaklist
	
		count = -1
                for string1 in document:
                        string1 = string1.split()
                        count += 1
                        for i in string1:
                                biglist.append((string1[:], count,))
                                string1.insert(0,string1[-1])
                                string1.pop(-1)

	

		if(ignoreWords):
			 templist = []
                         for word in ignoreWords:
                                 word = filter(lambda chars: chars not in ignoreable_set, word.lower())
                                 templist.append(word)
                         for tup in biglist:
                                 for i in range(len(templist)):
                                         if tup[0][0].lower() ==  templist[i]:
                                                 biglist.pop(count3)
                                 count3 += 1

	
	if count2 > 0 and setPeriodBreaks == False: #there are newlines but no specification for period breaks
		document = document.split('\n') #splits document everywhere there is a newline, creates list of these which is then split further below
		count = -1
		for string1 in document:
			string1 = string1.split()	
			count += 1
			for i in string1:
				biglist.append((string1[:], count,))
				string1.insert(0,string1[-1])
				string1.pop(-1)	
		if(ignoreWords):
			 templist = []
                         for word in ignoreWords:
                                 word = filter(lambda chars: chars not in ignoreable_set, word.lower())
                                 templist.append(word)
                         for tup in biglist:
                                 for i in range(len(templist)):
                                         if tup[0][0].lower() ==  templist[i]:
                                                 biglist.pop(count3)
                                 count3 += 1



	if listPairs == True:
		biglist = list_pairs(biglist, ignoreable_set)
		

		return biglist

	biglist = sorted(biglist, key=lambda (a,b):(a[0].lower(), b))	

	print biglist
	return biglist


def list_pairs(biglist, ignoreable_set): #attempt at listpairs. only can sort alphabetically and retrieve pairs including duplicates as-is 
	templist = biglist
	
	pairlist = []
	smalltuple = ()
	pair_count = 0
	for tup in range(len(templist)):
		templist[tup][0].sort()
		for i in range(len(templist[tup][0])):
			templist[tup][0][i] = filter(lambda chars: chars not in ignoreable_set, templist[tup][0][i].lower())
			for j in range(i+1, len(templist[tup][0])):
				if templist[tup][0][i] == templist[tup][0][j]:
					pair_count += 1
				pairlist.append(((templist[tup][0][i], templist[tup][0][j]), pair_count))	
	
	
	pairlist = sorted(pairlist, key=lambda (a,b):(a[0].lower(), b))
		
	
	
def get_init_list(document):
        return document.split()
def get_original_list(document):
	document = [document]
	return document



