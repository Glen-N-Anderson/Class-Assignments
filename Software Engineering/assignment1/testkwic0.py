import kwic
document = ""
ignoreWords = False
listPairs = False
setPeriodBreaks = False 
assert(kwic.kwic(document, ignoreWords, listPairs, setPeriodBreaks) == []) #makes sure an empty string will be put into an empty list and return an empty list
