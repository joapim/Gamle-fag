#a
def is_six_at_edge(heltallsliste):
    return heltallsliste[0] == 6 or heltallsliste[-1] == 6

print(is_six_at_edge([9,4,6,4]))

#b
def average(liste):
    summerer = sum(liste)
    antall = len(liste)
    gjennomsnitt = summerer/antall
    return gjennomsnitt
print(average([1,2,3]))

#c


def median(listen):
    listen.sort()
    lengde = len(listen)
    midten = (lengde //2)
    indeks = midten
    return listen[indeks]

print(median([9, 2, 5, 6, 7, 8, 1, 9, 7]))




