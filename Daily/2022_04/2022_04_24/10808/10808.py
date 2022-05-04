arr = input()
 
result = [0] * 26
 
for i in range(len(arr)):
    result[ord(arr[i]) - 97] += 1

for i in result:
    print(i, end=" ")