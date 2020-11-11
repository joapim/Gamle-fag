# import Multiplikasjon as mp
# mp.toleransegrense()

#Globale verdier

antall_kvinner = 0
antall_menn = 0
antall_itgk = 0
antall_fag = 0
antall_timer_lekser = 0

def sporre():
    print()
    print('For å avslutte programmet skriv "hade" når som helst')
    kjonn = 0
    while kjonn != 'm' and kjonn != 'f': #Bruker må skrive m eller f
        kjonn = input('Kjønn(m/f): ')
        if kjonn == 'f':
            antall_kvinner += 1
        else:
            antall_menn += 1
    alder = input('Alder: ')
    alder = int(alder)
    if alder not in range(16,26):
        print('Ikke riktig alder')
    fag = 0
    while fag != 'j' and fag != 'n': #Bruker må skrive j eller n
        fag = input('Tar du fag et fag(j/n)')
    if fag == 'j':
        if alder < 22:
            medlem_ITGK = input('Tar du ITGK?(j/n): ')
        else:
            medlem_ITGK = 0
            while medlem_ITGK != 'j' and medlem_ITGK != 'n':  # Bruker må skrive j eller n
                medlem_ITGK = input('Tar du virkelig ITGK?(j/n):')
    else:
        medlem_ITGK = 0
    timer_lekser = input('Hvor mange timer bruker du i snitt på lekser: ')
    timer_lekser = int(timer_lekser) #Hvordan få brukeren til å skrive enten desimaltall eller heltall


"""
def slutt(x): #Avslutter funksjoner. Dreper alt
    if x == 'hade':
        break
"""

def hoved(): #sporre() kjører hele tiden
    kjør = True
    while kjør:
        sporre()
        kjør = input("Ny bruker? True/False")
    print(antall_kvinner)

hoved()
print(antall_kvinner)
