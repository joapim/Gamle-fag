#a
def write_to_file(data):
    with open('test.txt','a') as file:
        file.write( data)
print(write_to_file('hei'))

#b
def  read_from_file(filename):
    with open(filename,'r') as file:
        for linje in file.readlines():
            print(linje)
#read_from_file('test.txt')

#c
def main():
    sp1 = 0
    print('Skriv "done" for å avslutte')
    while sp1 != 'done':
        sp1 = input('Vil du lese elle skrive?: ')
        if sp1 == 'skrive':
            setning = input('Hva vil du skrive? ')
            write_to_file(setning)
        else:
            read_from_file('test.txt')
    print('Du er ferdig')

main()

