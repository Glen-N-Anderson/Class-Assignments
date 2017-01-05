import kwic
document = "Hello world Im Glen from"
listPairs = False
ignoreWords = False
setPeriodBreaks = False
assert kwic.kwic(document, ignoreWords, listPairs, setPeriodBreaks) == [(['from', 'Hello', 'world', 'Im', 'Glen'], 0), (['Glen', 'from', 'Hello', 'world', 'Im'], 0), (['Hello', 'world', 'Im', 'Glen', 'from'], 0), (['Im', 'Glen', 'from', 'Hello', 'world'], 0), (['world', 'Im', 'Glen', 'from', 'Hello'], 0)] #make sure that an alphabetized list is returned
