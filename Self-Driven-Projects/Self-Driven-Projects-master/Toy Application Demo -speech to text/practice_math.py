import speech_recognition as sr
import pyttsx
import random
def start_math():
    print "in math"
    while True:
        r = sr.Recognizer()

        engine = pyttsx.init()
        rate = engine.getProperty('rate')
        engine.setProperty('rate', rate - 10)

        num1 = random.randrange(0, 10, 1)
        num2 = random.randrange(0, 10, 1)
        oper = random.randrange(0, 3, 1)
        ans = 0
        operstr = ""
        if oper == 0:
            ans = num1 + num2
            operstr = "plus"
        elif oper == 1:
            ans = num1 - num2
            operstr = "minus"
        elif oper == 2:
            ans = num1 * num2
            operstr = "times"
        with sr.Microphone() as source:
            speech = 'What is ' + str(num1)+ " " + operstr + " " + str(num2)
            engine.say(speech) 
            engine.runAndWait()
        
            audio = r.listen(source)
            userans = r.recognize_google(audio)

            if userans == "exit":
                break
            elif userans == str(ans):
                engine.say("Correct!")
                engine.runAndWait()
            else:
                engine.say("Incorrect")
                engine.runAndWait()
