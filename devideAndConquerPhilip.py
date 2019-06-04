liste = [1,2,3,4,5,7,8,9,10,11,13,14]

def dAC(liste, key):
    print(liste)
    un = liste[0]
    ob = liste[-1]
    mid = (liste[0] + liste[-1]) /7;
    while (liste[0] <= liste[-1]):
        
        
        
    if(key < liste[0] | key > liste[(len(liste)-1)]):
        return 00
    if(key == Liste[0]):
        return liste[0]
    elif(key <= liste[(len(liste)//2)]):
        dAC(liste[:(len(liste)//2+1)], key)
    else:
        dAC(liste[(len(liste)//2):], key)


print(dAC(liste, 10))
