import kwic
ignoreWords = False
listPairs = False
setPeriodBreaks = False

document = "Hello \nworld"
assert kwic.kwic(document, ignoreWords, listPairs, setPeriodBreaks) == [(['Hello'], 0), (['world'], 1)] #make sure line numbers print correctly
