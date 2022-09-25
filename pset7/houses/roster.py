# TODO
import sys
import cs50
if len(sys.argv) != 2:
    print("Error")
    exit()
db = cs50.SQL("sqlite:///students.db")
line = db.execute("SELECT * FROM students WHERE house=(?) ORDER BY last",sys.argv[1])

for student in line:
    if student['middle'] != None:
        print(student['first']," ",student['middle'], " ",student['last'],", ","born ",student['birth'], sep="")
    else:
        print(student['first']," ",student['last'], ", ","born ",student['birth'], sep="")

