import kwic
document = "Hello world Im Glen from"
listPairs = False
ignoreWords = ['Hello']
setPeriodBreaks = False
assert kwic.kwic(document, ignoreWords, listPairs, setPeriodBreaks) == [(['from', 'Hello', 'world', 'Im', 'Glen'], 0), (['Glen', 'from', 'Hello', 'world', 'Im'], 0), (['Im', 'Glen', 'from', 'Hello', 'world'], 0), (['world', 'Im', 'Glen', 'from', 'Hello'], 0)] #make sure list beginning with 'Hello' is not present (in accordance with the specifications of ignoreWords
