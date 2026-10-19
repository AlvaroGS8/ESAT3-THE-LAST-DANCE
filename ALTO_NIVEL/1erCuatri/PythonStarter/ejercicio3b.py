def pasarAMinusculas(lalista: list) -> list:

    for i in range(len(lalista)):
        lalista[i] = lalista[i].lower()

def pasarAMayusculas(lalista: list) -> list:
    
    for i in range(len(lalista)):
        lalista[i] = lalista[i].upper()

"""
def a_minusculas(lista):
    return [e.lower() if isinstance(e, str) else e for e in lista]


def a_mayusculas(lista):
    return [e.upper() if isinstance(e, str) else e for e in lista]
"""

cadena = ["mHasuJsakSaASJajSAS", "jaJSNAASHiajsDKlaskjHAS", "lEtRa"]

pasarAMinusculas(cadena)
print(cadena)

pasarAMayusculas(cadena)
print(cadena)