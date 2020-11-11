avreiseDag = int(input('Dager til du skal reise? '))


if avreiseDag >= 14:
    print('Minipris 199,- kan ikke refunderes/endres')
    minipris = input('Ønskes dette (JA/NEI)? ')
    if minipris == 'JA':
        print('Takk for pengene, god reise!')
    else:
        alder = int(input('Skriv inn din alder: '))
        if alder < 16:
            print('Prisen på billett blir: 220,-')
        elif alder > 60:
            print('Pris på billett blir: 330,-')
        elif 16 <= alder <= 60:
            rabatt = input('Er du student eller i militæret(JA/NEI)? ')
            if rabatt == 'JA':
                print('Pris på billett blir: 330,-')

elif 1 <= avreiseDag <= 13:
    print('For sent for minipris; fullpris 440,-')
    alder = int(input('Skriv inn din alder: '))
    if alder < 16:
        print('Prisen på billett blir: 220,-')
    elif alder > 60:
        print('Pris på billett blir: 330,-')
    elif 16 <= alder <= 60:
        rabatt = input('Er du student eller i militæret(JA/NEI)? ')
        if rabatt == 'JA':
            print('Pris på billett blir: 330,-')
        else:
            print('Pris på billett blir: 440,-')
else:
    avreiseDag = 0
    print('Ikke mulig å bestille')