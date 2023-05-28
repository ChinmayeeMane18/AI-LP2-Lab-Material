import sys

# Take input from the user
A = []
n = int(input("Enter the number of elements: "))
for i in range(n):
    element = int(input("Enter element {}: ".format(i+1)))
    A.append(element)

# Sorting using selection sort
for i in range(len(A)):
    min_idx = i
    for j in range(i+1, len(A)):
        if A[min_idx] > A[j]:
            min_idx = j
    
    A[i], A[min_idx] = A[min_idx], A[i]

# Print the sorted array
print("Sorted array:")
for i in range(len(A)):
    print(A[i], end=" ")