def kwic(document, ignoreWords, listPairs, setPeriodBreaks): #in this file newlines are handled, document will split on newlines if there are more than 0 of them
	templist = []
	biglist = []
	
	count = -1
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
			count+=1
			for i in string1:
				biglist.append((string1[:], count,))
				string1.insert(0,string1[-1])
				string1.pop(-1)	
				print string1
	print count2
	print biglist
	return biglist


def get_init_list(document):
        return document.split()
def get_original_list(document):
        document = [document]
	return document

