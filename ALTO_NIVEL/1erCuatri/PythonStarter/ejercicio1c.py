numerosDeTelefono = ["421324912", "421326412", "421321012", "429154292", "111"]

prueba = input("Adivine un número de teléfono: ")

while prueba not in numerosDeTelefono:
    prueba = input("\n\n El número no es correcto. Intente de nuevo: ")

print("\nPerfecto!")