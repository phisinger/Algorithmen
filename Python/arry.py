
# Pseudo Code!!!
global n 
n = 500
zahlen = []
global k 
k = 100

for i in range(0,k):
    zahlen.append(i)

def loeschen(array, stelle):
    for a in range(stelle, k):
        array[a] = array[a+1]
    k = k - 1

def insertMid(array, stelle, ele):
    b = k
    while(b >= stelle):
        array[b+1] = array[b]
        b = b-1
    array[stelle] = ele
    k = k + 1

def insertEnd(array, ele):
    array[k+1] = ele
    k = k + 1


print("Array:", zahlen)
loeschen(zahlen, 0)
print("Array nach Loeschen 1:", zahlen)
loeschen(zahlen, k)
print("Array nach Loeschen 2:", zahlen)
loeschen(zahlen, 4)
print("Array nach Loeschen 3:", zahlen)



