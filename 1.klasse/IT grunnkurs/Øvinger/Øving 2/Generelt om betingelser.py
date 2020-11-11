#Oppgave A:

tall_1 = int(input('Skriv inn et tall: '))
tall_2 = int(input('Skriv inn et tall: '))

gange = tall_1*tall_2
pluss = tall_1+tall_2

if gange < pluss:
    print('Tallene ble ganget sammen',gange)
elif gange > pluss:
    print('Tallene ble plusset sammen',pluss)
else:
    print('Tallet ditt er null')

#Oppgave B:
print()

tall = int(input('Hva er 3*4 ?:'))

if tall == 12:
    print('Det stemmer!')
elif tall != 12:
    print('Dette stemmer ikke!')
else:
    print('tekst')
