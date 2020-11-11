def toleransegrense():
    grense = float(input('Skriv inn toleransegrense: '))
    n = 1
    produkt = 1
    endringProdukt = 1
    while endringProdukt > grense:
        parantes = (1 + (1 / (n ** 2)))
        gammeltProdukt = produkt
        produkt = produkt * parantes
        n = n + 1
        endringProdukt = produkt - gammeltProdukt
    print('Total sum:', round(produkt,2), 'antall ledd: ', n-1)
    return produkt, n


prod,count = toleransegrense()
print(prod,count)

