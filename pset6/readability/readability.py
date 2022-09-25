import string
text = input("Text: ")
i = 0
letters = 0
words = 1
sentences = 0
for i in range(len(text)):
    if text[i].isalpha():
        letters = letters + 1
    elif text[i].isspace():
        words = words + 1
    elif text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences = sentences + 1
grade = 0
grade = 0.0588 * (100 * letters / words) - 0.296 * (100 * sentences / words) - 15.8
if grade < 16 and grade >= 0:
    print("Grade", int(round(grade)))
elif grade >= 16:
    print("Grade 16+")
else:
    print("Before Grade 1")