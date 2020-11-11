#A
sum = 0
tall = 1
while tall <= 100:
    sum += tall
    tall += 1
print(sum)

#B
tot_sum = 1
ant_gang = 1
multipli = 1
while tot_sum < 1000:
    multipli += 1
    tot_sum = multipli * tot_sum
    ant_gang += 1
    if tot_sum > 1000:
        break
print('Antall ganger ', ant_gang,'summen er', tot_sum)


#C
def fåTallfraBruker():
    tall = 0
    while tall < 12 or tall > 12:
        tall = int(input('Hva er 3*4: '))
    return tall

print('Stemmer, svaret er',fåTallfraBruker())

