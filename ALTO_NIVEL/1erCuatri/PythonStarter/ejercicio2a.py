onelist = []

total = 0;

for i in range(10):
    num = int(input("Deme un número: "))
    total += num;
    onelist.append(num)

print("Media = ",total/len(onelist))
print("Min = ",min(onelist))
print("Max = ",max(onelist))