def kwic(document, ignoreWords, listpairs, setPeriodBreaks): #if set period breaks is true, a new line is made where 'lowercase. ' occurs
	templist = []
	biglist = []
	count = 0
	count2 = document.count('\n')
	count3 = 0
	


	if count2 == 0 and setPeriodBreaks == False:
		document = document.split()
		for i in document:
			biglist.append((document[:], 0,))
                	document.insert(0,document[-1])
                	document.pop(-1)
		if(ignoreWords):
                        templist = []
                        for word in ignoreWords:
                                templist.append(word)
                        for tup in biglist:
                                for i in range(len(templist)):
                                        if tup[0][0] ==  templist[i]:
                                                biglist.pop(count3)
                                count3 += 1


	if setPeriodBreaks == True:
		breakstring = ""
                remainstring = ""
                tempstring = ""
                breaklist = []
                for i in range(len(document)):
                        if document[i] == ' ' and document[i-1] == '.' and document[i-2].islower(): #check that i is a space preceded by a lowercase letter and a period

                                for chars in range(len(document[:i])): #for everything before we hit that space 
                                        breakstring = breakstring + document[chars] #add to a fresh list
                                for chars2 in range(i, len(document)): #for everything we didn't get to (no more periods)
                                        remainstring = remainstring + document[chars2] #add the extras
                                tempstring = remainstring #allows us to reset remainstring without losing the remainder of the list
                                remainstring = ""
                                breaklist.append(breakstring) #append the fresh list each time we run through the if statement
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
                                templist.append(word)
                        for tup in biglist:
                                for i in range(len(templist)):
                                        if tup[0][0] ==  templist[i]:
                                                biglist.pop(count3)
                                count3 += 1

	
	
	if count2 > 0 and setPeriodBreaks == False:
		document = document.split('\n')
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
                                templist.append(word)
                        for tup in biglist:
                                for i in range(len(templist)):
                                        if tup[0][0] ==  templist[i]:
                                                biglist.pop(count3)
                                count3 += 1




	biglist = sorted(biglist, key=lambda (a,b):(a[0].lower(), b))	

	print biglist
	return biglist


def get_init_list(document):
        return document.split()
def get_original_list(document):
	document = [document]
	return document



