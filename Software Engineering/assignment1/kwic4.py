def kwic(document): #this file performs the kwic shift to remove the last element of the list and put it in the front. it places each copy of this occurance into a larger list called biglist
	count = 0 #at this point this is only a placeholder, will implement line counts in next test
	templist = []
	if document == "":
		biglist = []
	else:
		

		document = document.split()
		tempdoc = document
		biglist = []
		for i in document:
			biglist.append((document[:], count,))
			document.insert(0,document[-1])
                	document.pop(-1)

	print biglist
	return biglist
def get_init_list(document):
        return document.split()
def get_original_list(document):
	document = [document]
	return document

