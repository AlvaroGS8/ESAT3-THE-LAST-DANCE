def funcion(list1: list, list2: list) -> dict:
    if len(list1) == len(list2):
        return dict(zip(list1, list2))
    
    return None
   


list = [1,2,3,4,5]
listt = ["cadena", "cadenota", "cadenon", "Puppeteers", "nullptr"]

print(funcion(list, listt))
print(funcion(list2=listt, list1=list))