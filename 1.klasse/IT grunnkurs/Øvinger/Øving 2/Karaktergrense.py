poeng = int(input('Skriv inn din poengsum: '))

if 100 >= poeng >= 89:
    print('Du fikk A')
elif 88 >= poeng >= 77:
    print('Du fikk B')
elif 76 >= poeng >= 65:
    print('Du fikk C')
elif 64 >= poeng >= 53:
    print('Du fikk D')
elif 52 >= poeng >= 41:
    print('Du fikk E')
elif poeng > 100:
    print('Error, poengsummen kan ikke være større enn 100')
elif poeng < 0:
    print('Error, poengsummen må være større enn null')
else:
    40 >= poeng >= 0
    print('Du fikk F')
