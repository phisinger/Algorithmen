liste = [1,2,3,4,5,7,8,9,10,11,13,14]

def dAC(liste, key):
    print(liste)
    un = liste[0]
    ob = liste[-1]
    mid = liste[len(liste)/2]

    while (liste[0] <= liste[-1]):
        if(key == Liste[0]):
            return liste[0]
        elif(key < mid):
            dAC(liste[:mid], key)
        else:
            dAC(liste[mid:], key)
        


print(dAC(liste, 10))
