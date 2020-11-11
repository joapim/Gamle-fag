#A

antall_ledd = int(input('Hvor mange ledd: '))
total_sum = 0
for i in range(1, antall_ledd+1):
    if i%2 == 0:
        total_sum = -(i)**2 + total_sum
    else:
        i % 2 != 0
        total_sum= (i)**2 + total_sum
print('Hvis det er', antall_ledd,'ledd', 'er summen', total_sum)

antall_ledd = int(input('Hvor mange ledd: '))
total_sum = 0
grense_ledd = int(input('Grense på sum: '))
for i in range(1, antall_ledd+1):
    if total_sum > grense_ledd:
        break
        print('Den minste summen av tallserien under', grense_ledd, 'er', total_sum - antall_ledd, 'Tallserien har', antall_ledd, 'elementer' )
    elif i % 2 == 0:
        total_sum = -(i)**2 + total_sum
    else:
        total_sum= (i)**2 + total_sum
print('Hvis det er', antall_ledd,'ledd', 'er summen', total_sum)

#Ble feil