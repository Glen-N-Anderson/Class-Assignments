def kwic(document, ignoreWords, listPairs, setPeriodBreaks): #sorts the list alphabetically regardless of case
	templist = []
	biglist = []
	count = 0
	count2 = document.count('\n')

	if count2 == 0:
		document = document.split()
		for i in document:
			biglist.append((document[:], count,))
                	document.insert(0,document[-1])
                	document.pop(-1)
	else:
		document = document.split('\n')
		for string1 in document:
			string1 = string1.split()	
			count = 1
			count+=1
			for i in string1:
				biglist.append((string1[:], count,))
				string1.insert(0,string1[-1])
				string1.pop(-1)	
				print string1
	
	biglist = sorted(biglist, key=lambda (a,b):(a[0].lower(), b)) #the sorted function lets us use a dummy variable lambda to call the lower function on the appropriate elements of biglist to get a sort
	print count2
	print biglist
	return biglist


def get_init_list(document):
        return document.split()
def get_original_list(document):
        document = [document]
	return document

