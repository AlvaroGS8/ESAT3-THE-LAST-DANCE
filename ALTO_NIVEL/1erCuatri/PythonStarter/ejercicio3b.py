def pasarAMinusculas(lalista: list) -> list:

    for i in range(len(lalista)):
        lalista[i] = lalista[i].lower()

def pasarAMayusculas(lalista: list) -> list:
    
    for i in range(len(lalista)):
        lalista[i] = lalista[i].upper()

cadena = ["mHasuJsakSaASJajSAS", "jaJSNAASHiajsDKlaskjHAS", "lEtRa"]


pasarAMinusculas(cadena)
print(cadena)

pasarAMayusculas(cadena)
print(cadena)