import kwic #checks that document is put into correct structure
document = "Hello"
ignoreWords = False
listPairs = False
setPeriodBreaks = False
assert kwic.kwic(document, ignoreWords, listPairs, setPeriodBreaks) == [(['Hello'], 0)]

