import logging

def shift(line):
    return [line[i:] + line[:i] for i in range(0,len(line))]

def cleanWord(word):
    return filter (lambda c: c not in [".",",","?","!",":"], word.lower())

def ignorable(word,ignoreWords):
    return cleanWord(word) in map(lambda w: w.lower(), ignoreWords)

def splitBreaks(string, periodsToBreaks): #changing functionality of this lets us use it to check output when we know periods to breaks is false
    if not periodsToBreaks:
        return string.split("\n")
    else:
    	return break_periods(string);    
	
def break_periods(string): #functionalizing this alows us to pass in string to be broken up and check the functions output knowing periods to breaks is true
	line = ""
        lines = []
        lastChar1 = None
        lastChar2 = None
        for c in string:
            if (c == " ") and (lastChar1 == ".") and (lastChar2 in map(chr, range(ord('a'),ord('z')+1))):
                lines.append(line)
                line = ""
            line += c
            lastChar2 = lastChar1
            lastChar1 = c
        lines.append(line)
        return lines

def kwic(string,ignoreWords=[], listPairs=False, periodsToBreaks=False):
    #I used the following source to aid in understanding and writing logger function: https://fangpenlin.com/posts/2012/08/26/good-logging-practice-in-python/
    logger = logging.getLogger(__name__)
    logger.setLevel(logging.INFO)
    logfile = logging.FileHandler("logs.log")
    logfile.setLevel(logging.INFO)
    logform = logging.Formatter("%(asctime)s - %(name)s - %(message)s")
    logfile.setFormatter(logform)
    logger.addHandler(logfile)

    logger.info("Beginning kwic process, reading in data...")

    lines = splitBreaks(string, periodsToBreaks)
    logger.info("Breaks in lines created successfully")    

    splitLines = map(lambda l: l.split(), lines)
    logger.info("Lines split successfully")
    if listPairs:
        pairs = list_pairs(splitLines, listPairs)
        logger.info("Pairs listed successfully")
    filteredLines = shift_words(splitLines, ignoreWords)
    logger.info("Lines shifted successfully")
    if not listPairs:
        logger.info("listPairs not used, argument was false")
        return sorted(filteredLines, key = lambda l: (map(lambda w:w.lower(), l[0]),l[1]))
    else:
        return (sorted(filteredLines, key = lambda l: (map(lambda w:w.lower(), l[0]),l[1])),
                map(lambda wp: (wp, pairs[wp]), sorted(filter(lambda wp: pairs[wp] > 1, pairs.keys()))))

def shift_words(splitLines, ignoreWords):
    shiftedLines = [map(lambda x:(x,i), shift(splitLines[i])) for i in range(0,len(splitLines))]
    flattenedLines = [l for subList in shiftedLines for l in subList]
    filteredLines = filter(lambda l: not ignorable(l[0][0], ignoreWords), flattenedLines)
    return filteredLines

def list_pairs(splitLines, listPairs):
    if listPairs:
        pairs = {}
        for l in splitLines:
            seen = set([])
            for wu1 in l:
                wc1 = cleanWord(wu1)
                if len(wc1) == 0:
                    continue
                for wu2 in l:
                    wc2 = cleanWord(wu2)
                    if wc1 < wc2:
                        if (wc1,wc2) in seen:
                            continue
                        seen.add((wc1,wc2))
                        if (wc1, wc2) in pairs:
                            pairs[(wc1,wc2)] += 1
                        else:
                            pairs[(wc1,wc2)] = 1
    return pairs 
