n = 0
n = input("Number:")
c = n
while(True):
    if (len(n) == 13 or len(n) == 15 or len(n) == 16):
        try:
            c = int(n)
            break
        except:
            print("INVALID")
            break
    else:
        print("INVALID")
        break
flag = 0
sumx = 0
sum1 = 0
rem1 = 0
while(c > 0):
    rem = c % 10
    c = c // 10
    if flag == 1:
        if rem >= 5 and rem <= 9:
            rem = rem * 2
            while(rem > 0):
                rem1 = rem % 10
                sum1 = sum1 + rem1
                rem = rem // 10
            sumx = sumx + sum1
            sum1 = 0
            flag = 0
        else:
            sumx = sumx + 2 * rem
            flag = 0
    else:
        sumx = sumx + rem
        flag = 1
if sumx % 10 == 0:
    if len(n) == 15:
        if n.startswith('34') or n.startswith('37'):
            print("AMEX")
        else:
            print("INVALID")
    if len(n) == 16:
        if n.startswith('4') or n.startswith('4'):
            print("VISA")
        elif n.startswith('51') or n.startswith('52') or n.startswith('53') or n.startswith('54') or n.startswith('55'):
            print("MASTERCARD")
        else:
            print("INVALID")
    if len(n) == 13:
        if n.startswith('4'):
            print("VISA")
        else:
            print("INVALID")
else:
    print("INVALID")