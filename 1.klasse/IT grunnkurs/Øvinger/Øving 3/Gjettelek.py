import random
random_number = random.randint(1,100)

a = 0
while a != random_number:
   a = int(input('Gjett et tall: '))
   if a > random_number:
       print('Det riktige tallet er mindre')
   elif a < random_number:
       print('Det riktige tallet er større')
print('Du gjettet riktig! Det riktige tallet er', random_number)

