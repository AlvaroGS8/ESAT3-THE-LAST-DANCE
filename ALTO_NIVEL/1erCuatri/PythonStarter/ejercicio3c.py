def DiccionarioNuevo(diccionario : dict, maxCaracteres: int = 5) -> dict:
    nuevoDiccionario = {}
    for clave, valor in diccionario.items():
        if len(clave) <= maxCaracteres:
            nuevoDiccionario[clave] = valor
    return nuevoDiccionario


unDiccionario = {"clavebastantelarga":"unvalor", "corto":"dosvalor", "a":"tresvalor", "otraclavemuylarga":"4valor","b":"asd"}
print(DiccionarioNuevo(unDiccionario))