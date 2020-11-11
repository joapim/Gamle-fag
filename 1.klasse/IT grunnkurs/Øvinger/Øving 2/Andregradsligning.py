a = float(input('Skriv inn et tall: '))
b = float(input('Skriv inn et tall: '))
c = float(input('Skriv inn et tall: '))

d = b**2 -(4*a*c)
print('d =',d)

if d < 0:
    print('Andregradslikningen:', a,'* x^2 +', b,'* x +',c, 'er imagniær og har to løsninger')
elif d > 0:
        print('Andregradslikningen:', a, '* x^2 +', b,'x +',c, ' er reel og har to løsninger')
else:
    d = 0
    print('Andregradslikningen:', a, '* x^2 +', b,'x +',c, ' er reel og har en løsning')

