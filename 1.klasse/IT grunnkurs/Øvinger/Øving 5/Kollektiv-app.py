
def kollektivpris(alder):
    sykkel = 0
    while sykkel != 'j' and sykkel != 'n':
        sykkel = input('Sykkel(j/n): ')
    if sykkel == 'j':
        if alder < 5:
            print('Billettpris: 50 kr')
        elif 5 <= alder <= 20:
            print('Billettpris: 70 kr')
        elif 21 < alder < 25:
            print('Billettpris: 100 kr')
        elif 26 < alder <= 60:
            print('Billettpris: 130 kr')
        else:
            print('Billettpris: 50 kr')
    elif sykkel == 'n':
        if alder < 5:
            print('Billettpris: Gratis')
        elif 5 <= alder < 20:
            print('Billettpris: 20 kr')
        elif 21 < alder < 25:
            print('Billettpris: 50 kr')
        elif 26 < alder <= 60:
            print('Billettpris: 80 kr')
        else:
            print('Billettpris: Gratis')

alder = int(input())
kollektivpris(alder)