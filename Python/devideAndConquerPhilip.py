import sys
liste = [1,2,3,4,5,7,8,9,10,11,13,14]


def dAC(liste, unten, oben, key):
    if (oben < unten):
        return None

    mid = (unten + oben) // 2
    print(liste[mid])
    if(key == liste[mid]):
        return mid
    if(key < liste[mid]):
        return dAC(liste, unten, mid-1, key)
    else:
        return dAC(liste, mid+1, oben, key)
        
    


unten = 0
oben = len(liste)-1

res = dAC(liste, unten, oben, 20)
print("res:",res)
print()
res = dAC(liste, unten, oben, 8)
print(res)
print()
print(dAC(liste, unten, oben, 0))
print()
print(dAC(liste, unten, oben, 3))
