def funcion(list1: list, list2: list) -> dict:
    diccionario = {}
    if len(list1) == len(list2):
        
        for i in range(len(list1)):
            diccionario[list1[i]] = list2[i]
    
    return diccionario
    


list = [1,2,3,4,5]
listt = ["Alvaro", "Alberto", "Elena", "Puppeteers", "nullptr"]

print(funcion(list, listt))
print(funcion(list2=listt, list1=list))