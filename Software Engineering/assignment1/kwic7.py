def kwic(document, ignoreWords, listPairs, setPeriodBreaks): #removes word that ignorewords specifies. This obviously could have been much better implemented with a function...I did not plan ahead with testing and it led to some interesting results
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

	
	
	if count2 > 0:
		document = document.split('\n')
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
                                        if tup[0][0]  ==  templist[i]:
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



