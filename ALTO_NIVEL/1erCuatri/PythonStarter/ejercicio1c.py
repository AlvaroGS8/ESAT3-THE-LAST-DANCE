import random

lista_tlf = ["674725341"]

for i in range(4):
  tmp = str((random.randint(600000000, 700000000)))


a = input("Introduzca uno de los numeros de telefono de la lista para cerrar el programa\n")
while a not in lista_tlf:
  a = input("\nPrueba otra vez!\n")

print("\nO tienes mucha suerte o te sabes mi numero de telefono")