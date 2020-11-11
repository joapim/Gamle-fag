#a#b
my_family = {}
def add_family_member(rolle,name):
    if rolle in my_family:
        liste = my_family[rolle]
        liste.append(name)
        my_family[rolle] = liste
    else:
        my_family[rolle] = [name]
    return my_family


add_family_member('mor','Jeanette')
add_family_member('bror','Benjamin')
add_family_member('far','Josef')
add_family_member('bror','Reuben')
add_family_member('bror','halvor')

print(my_family)