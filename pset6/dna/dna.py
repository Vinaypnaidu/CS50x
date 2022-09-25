from sys import argv
if len(argv) != 3:
    print("usage error, dna.py sequence.txt database.csv")
    exit()
from sys import argv
data = open(argv[1])
seqf = open(argv[2])
strname = []
strperson = []
for line in seqf:
    finalstr = line
for line in data:
    line = line.rstrip("\n")
    strname = line.split(",")
    break
i = 1
count = 0
for line in data:
    line = line.rstrip("\n")
    strperson = line.split(",")
    count = 0
    while(i < len(strperson)):
        if int(strperson[i]) * strname[i] in finalstr and (int(strperson[i])+1) * strname[i] not in finalstr:
            count = count + 1
        i = i + 1
    i = 1
    if(count == (len(strname)-1)):
        print(strperson[0])
        exit()
print("No match")
