import kwic
document = "Hello world, lots of words!"
listPairs = False
ignoreWords = False
setPeriodBreaks = False
assert kwic.get_original_list(document) == ['Hello world, lots of words!'] #tests to make sure the string passed is broken up by word and put in a list
