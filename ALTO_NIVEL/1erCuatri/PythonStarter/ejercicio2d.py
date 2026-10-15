cadena = input("Introduce una cadena en castellano sin tildes o ingles: ")
numVocales = []

num = cadena.count("a")
numVocales.append(num)
num = cadena.count("e")
numVocales.append(num)
num = cadena.count("i")
numVocales.append(num)
num = cadena.count("o")
numVocales.append(num)
num = cadena.count("u")
numVocales.append(num)

print(numVocales)

"""
frase = input("Introduce una frase (sin tildes): ")

vocales = "aeiou"
frase_min = frase.lower()

resultado = [frase_min.count(v) for v in vocales]

print(resultado)
"""