import kwic
document = "apple, cab, buddy"
ignoreWords = False
setPeriodBreaks = False
listPairs = True
assert kwic.kwic(document, ignoreWords, listPairs, setPeriodBreaks) == ([(['apple,', 'cab,', 'buddy'], 0), (['buddy', 'apple,', 'cab,'], 0), (['cab,', 'buddy', 'apple,'], 0)], [(('apple', 'buddy'), 2), ('buddy', 'cab'), 2)]) #checks to make sure listPairs is working as intended NOTE: did not complete this test/part of program, it will fail due to an assertion error.  
