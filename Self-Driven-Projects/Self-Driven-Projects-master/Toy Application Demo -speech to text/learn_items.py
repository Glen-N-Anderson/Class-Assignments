# By: Glen N. Anderson
#
# Date: 12/26/16
#
# Description: Program takes user voice input and responds accordingly with
# Chatterbot, for certain keywords program will perform a specific task such
# as allow the user to teach the program what objects are named and what they
# do or help the user practice basic arithmatic.
#
# Purpose: Made as a demo of a (simplified) software set up for a smart toy with
# some possible applications.
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


import speech_recognition as sr
import pyttsx
import os
from chatterbot import ChatBot 
from read_items import read_database
from practice_math import start_math


FILE_DATABASE = "database.txt" #write items and their descriptions here

chatbot = ChatBot('Fred', trainer='chatterbot.trainers.ChatterBotCorpusTrainer')
chatbot.train("chatterbot.corpus.english")  

def check_item(item):
    #Helper function to check if item exists in the database
    with open(FILE_DATABASE, "r") as fin:
            buff = fin.readlines()
            for line in buff:
                if item in line:
                    fin.close()
                    return True
    fin.close()
    return False

def init_datafile():
    #Set up the database with headers if it is empty
    if os.stat(FILE_DATABASE).st_size == 0:
        f = open(FILE_DATABASE, "w")    
    
        f.write("Item:" + '\n')
        f.write("Description:" + '\n')

        f.close()
    
def write_desc(item_desc):
    #Write the item description into the file after the Description header
    with open(FILE_DATABASE, "r") as fin:
        buff = fin.readlines()
        
    with open(FILE_DATABASE, "w") as fout:
        for line in buff:
            if line == "Description:\n":
                line = line + item_desc + '\n'
            fout.write(line)
    fin.close()
    fout.close()
      
def write_item(item_name):
    #Write the item name into the file after the Item header
    with open(FILE_DATABASE, "r") as fin:
        buff = fin.readlines()
    with open(FILE_DATABASE, "w") as fout:
        for line in buff:
            if line == "Item:\n":
                line = line + item_name + '\n'
            fout.write(line)
    fin.close()
    fout.close()
              
    
def get_audio():
    # Record Audio
    while True:
        r = sr.Recognizer()
        engine = pyttsx.init()
        with sr.Microphone() as source:
            #audio listens for keywords and will change state of program according to user's input

            audio = r.listen(source)
            voice_input = translate_audio(audio, r) 

            if "look" in voice_input: #User says something like "Look at this", then bot asks what it is

                engine.say('What is that?') 
                engine.runAndWait()
                audio3 = r.listen(source)
                item = translate_audio(audio3, r)
                
                if check_item(item) == True: #If item already exists in file, don't add it again
                    read_database(item)
                else: #Get description of the item and write item and desc to file
                    engine.say('What does it do?')
                    engine.runAndWait()
                    audio2 = r.listen(source)
                    desc = translate_audio(audio2, r)
        
                    write_item(item)
                    write_desc(desc)
            else: #There is not a keyword match, so we just respond with chatterbot                
                response = chatbot.get_response(voice_input)
                engine.say(response)
                engine.runAndWait()

def translate_audio(audio, r):
    # Turn raw audio into Python string with Google's API
    
    try:
       
        print("You said: " + r.recognize_google(audio))
        item = r.recognize_google(audio) #gives us a python string from the google audio
        if item == "exit": #quit program if the user says exit
            exit()
        if item == "math":
            start_math()
            get_audio()
        else: #else return the Python string so that it can be written to the appropriate part of the file
            return item
                
    except sr.UnknownValueError:
        engine = pyttsx.init()
        engine.say("I did not understand, please repeat?")
        engine.runAndWait()
        get_audio()
    except sr.RequestError as e:
        print("Speech recognition service not available; {0}".format(e))

#Initialize the datafile, then call get_audio to start the program
init_datafile()
get_audio()

