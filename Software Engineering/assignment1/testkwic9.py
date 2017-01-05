import kwic 
document = "Hello world. Im Glen from"
ignoreWords = ['!Hello']
setPeriodBreaks = False
listPairs = False
assert kwic.kwic(document, ignoreWords, listPairs, setPeriodBreaks) == [(['from', 'Hello', 'world.', 'Im', 'Glen'], 0), (['Glen', 'from', 'Hello', 'world.', 'Im'], 0), (['Im', 'Glen', 'from', 'Hello', 'world.'], 0), (['world.', 'Im', 'Glen', 'from', 'Hello'], 0)] #checks to make sure capitals and punctuation is ignored for ignoreWords 
