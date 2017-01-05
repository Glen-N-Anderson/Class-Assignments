from multiprocessing import Process, Queue
import gc
def shift(line):
    return [line[i:] + line[:i] for i in xrange(0,len(line))]

def ignorable(word,ignoreWords):
    return filter(lambda c: c not in [".", ",", "?", "!", ":"], word.lower()) in map(lambda w: w.lower(), ignoreWords)

def kwic(string,ignoreWords=[], listPairs=False, periodsToBreaks=False):
    gc.disable() 
    if not periodsToBreaks:
        return string.split("\n")
    else:
        line = ""
        lines = []
        lastChar1 = None
        lastChar2 = None
        breakChars = map(chr, xrange(ord('a'),ord('z')+1))
        for c in string:
            if (c == " ") and (lastChar1 == ".") and (lastChar2 in breakChars):
                lines.append(line)
                line = ""
            line += c
            lastChar2 = lastChar1
            lastChar1 = c
        lines.append(line)

    
    splitLines = map(lambda l: l.split(), lines)
    #put list pairs and the line shifting into different functions
    #start processes for each function, running them both at once
    #join the processes after the function calls and use queue to get the returns 
    if listPairs:
        q1 = Queue()
        p1 = Process(target = list_pairs, args = (q1, splitLines)) 
    

        p1.start()

        pairs = q1.get()
	filteredLines = shift_lines(splitLines, ignoreWords)
        p1.join()

    if not listPairs:
        filteredLines = shift_lines(splitLines, ignoreWords)
        return sorted(filteredLines, key = lambda l: (map(lambda w:w.lower(), l[0]),l[1]))
    else:
        return (sorted(filteredLines, key = lambda l: (map(lambda w:w.lower(), l[0]),l[1])),
                map(lambda wp: (wp, pairs[wp]), sorted(filter(lambda wp: pairs[wp] > 1, pairs.keys()))))


def list_pairs(q, splitLines):
	pairs = {}
        for l in splitLines:
            seen = set([])
            for wu1 in l:
                wc1 = filter(lambda c: c not in [".", ",", "?", "!", ":"], wu1.lower())
                if len(wc1) == 0:
                    continue
                for wu2 in l:
                    wc2 = filter(lambda z: z not in [".", ",", "?", "!", ":"],wu2.lower())
                    if wc1 < wc2:
                        if (wc1,wc2) in seen:
                            continue
                        seen.add((wc1,wc2))
                        if (wc1, wc2) in pairs:
                            pairs[(wc1,wc2)] += 1
                        else:
                            pairs[(wc1,wc2)] = 1
	q.put(pairs)   
      
def shift_lines(splitLines, ignoreWords):
    shiftedLines = [map(lambda x:(x,i), shift(splitLines[i])) for i in xrange(0,len(splitLines))]
    flattenedLines = [l for subList in shiftedLines for l in subList]
    filteredLines = filter(lambda l: not ignorable(l[0][0], ignoreWords), flattenedLines)
    return filteredLines
