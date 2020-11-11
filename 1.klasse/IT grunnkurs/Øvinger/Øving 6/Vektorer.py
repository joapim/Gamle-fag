import math
#a
def tre_komponenter(x,y,z):
    return [x,y,z]

a = tre_komponenter(1.5,3.7,4.5)
a = [1.5,3.7,4.5]

#b
def skriver_ut(vec1):
    #print('vec1', '=', vec1)
    print(vec1)

skriver_ut(a)


#c
def skalar_multipliserer():
    skalar = float(input('Skalar: '))
    vec1 = tre_komponenter(1.5, 3.7, 4.5)
    vec2 = [round(vec1[0]*skalar,2),round(vec1[1]*skalar,2),round(vec1[2]*skalar,2)]
    lengde_vec1 = round(math.sqrt(vec1[0]**2 + vec1[1]**2 + vec1[2]**2),2)
    print('Lengde vec1: ',lengde_vec1)
    lengde_vec2 = round(math.sqrt(vec2[0]**2 + vec2[1]**2 + vec2[2]**2),2)
    print('Lengde vec2: ',lengde_vec2)
    #return vec2, lengde_vec1
    print('Forholdet vec1/vec2: ',(lengde_vec1/lengde_vec2))
print(skalar_multipliserer())

#d
def prikkproduktet(vektor_1,vektor_2):
    prikk = vektor_1[0]*vektor_2[0]+vektor_1[1]*vektor_2[1]+vektor_1[2]*vektor_2[2]
    return prikk
print(prikkproduktet([1,1,1],[3,3,3]))




