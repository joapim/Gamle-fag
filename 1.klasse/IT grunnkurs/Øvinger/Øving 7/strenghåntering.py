#a
def check_equal(str1,str2):
    for i in range(len(str1)):
        if str1[i]!= str2[i]:
            return False
    return True
#b
def reversed(str):
    liste_1 = list(str)
    liste_1.reverse()
    return ''.join(liste_1)
#c
def check_palindrome(str):
    a =check_equal(str,reversed(str))
    return a
#d

def contains_string(str1,str2):
    liste = []
    for i in range(0,len(str1)):
        if str1[i:len(str2)+i] == str2:
            return i
    return -1


