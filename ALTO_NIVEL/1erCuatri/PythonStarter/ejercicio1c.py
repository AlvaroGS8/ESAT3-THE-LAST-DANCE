def listToDictionary (list1, list2):
    if len(list1) == len(list2):
        dictionary = {}
        for num in range(len(list1)):
            dictionary[list1[num]] = list2[num]
        return dictionary
    return "none"

unalista = [1,2,3,4,5]
otralista = ["coche", "casa", "perro", "dinero", "pareja"]

print(listToDictionary(unalista, otralista))

