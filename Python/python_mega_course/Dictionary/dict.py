# Created by Abhijith P Kumar

import json
from difflib import get_close_matches
data = json.load(open("data.json"))
def meaning(w):
    w = w.lower()
    for i in data.keys():
        i=i.lower()
    if w in data:
        return  data[w]
    elif w.title() in data:
        return data[w.title()]
    elif w.upper() in data:
        return data[w.upper()]
    elif len(get_close_matches(w,data.keys()))>0:
        for i in range(0,3):
            a = input("Did you mean %s instead? Y / N: " % get_close_matches(w,data.keys())[i])
            a = a.upper()
            if a == 'Y':
                b = get_close_matches(w,data.keys())[i]
                return meaning(b)
            elif a == 'N' and i >= 3:
                return "The word doesn't exist"
            elif a != 'Y' and a != 'N':
                return "Can't understand"
    else:
        return "The word doesn't exist"
word = input("Enter a word: ")
output = meaning(word)
print("\n")
if type(output) == list:
    for i in output:
        print(i)
else:
    if output is None:
        print("Sorry, the word doesn't exist...")
    else:
        print(output)