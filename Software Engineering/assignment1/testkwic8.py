import kwic
document = "Hello. world. Im Glen from"
ignoreWords = False
setPeriodBreaks = True
listPairs = False
assert kwic.kwic(document, ignoreWords, listPairs, setPeriodBreaks) == [(['from', 'Im', 'Glen'], 2), (['Glen', 'from', 'Im'], 2), (['Hello.'], 0), (['Hello.', 'world.'], 1), (['Im', 'Glen', 'from'], 2), (['world.', 'Hello.'], 1)]
 #checks to make sure a newline is created for periods when setPeriodBreaks = True 
