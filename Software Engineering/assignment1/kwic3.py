def kwic(document, ignoreWords, listPairs, setPeriodBreaks): #this file places the now split document into a tuple with a dummy variable count, this tuple is put into a bigger list
	count = 0 #at this point this is only a placeholder, will implement line counts in next test
	templist = []
	if document == "":
		biglist = []
	else:
		

		document = document.split()
		tempdoc = document
		biglist = [(document, count)]

	print biglist
	return biglist
def get_init_list(document):
        return document.split()
def get_original_list(document):
	document = [document]
	return document

