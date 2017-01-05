import kwic
document = "apple, cab, buddy"
ignoreWords = False
listPairs = False
setPeriodBreaks = False
assert kwic.kwic(document, ignoreWords, listPairs, setPeriodBreaks) == [(['apple,', 'cab,', 'buddy'], 0), (['buddy', 'apple,', 'cab,'], 0), (['cab,', 'buddy', 'apple,'], 0)]#make sure that kwic is moving words properly, putting them in lists in tuples w/ a line number and putting all that in a big list

