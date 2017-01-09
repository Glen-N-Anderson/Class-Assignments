import pyttsx
FILE_DATABASE =  "database.txt" #read items and their descriptions

def search_items(items, descs, item):
    print items
    print "in search" + item
    #If item exists, look up its description and tell the user
    desc_index = 0
    for i in range(len(items)):
        if items[i] == item + '\n':
            print "in if"
            desc_index = i
            
            engine = pyttsx.init()
            engine.say('I know that item, it ' + descs[desc_index])
            engine.runAndWait()
        
            
def read_database(item):
    #Reads in the entire database so that it can be searched
    i = 0
    items = []
    descs = []
    with open(FILE_DATABASE, "r") as f:
        buff = f.readlines()
        for i in range(0, len(buff) / 2):
            items.append(buff[i])
            i = i + 1
        for n in range(i, len(buff)):
            descs.append(buff[n])
    f.close()
    search_items(items, descs, item)
    
