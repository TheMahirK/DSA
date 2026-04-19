import numpy as np


def display(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n):
            print(arr[i][j] , end = ' ')
        print()
    print()

def multiply(arr1, arr2):
    n = len(arr1)
    
    # create result matrix filled with zeros
    result = np.zeros((n, n), dtype=int)

    for i in range(n):
        for j in range(n):
            for k in range(n):
                result[i][j] += arr1[i][k] * arr2[k][j]

    return result


def add(arr1, arr2):
    n = len(arr1)
    result = np.zeros((n, n), dtype=int)
    for i in range(n):
        for j in range(n):
            result[i][j] += arr1[i][j] + arr2[i][j]
    return result

def difference(arr1, arr2):
    n = len(arr1)
    result = np.zeros((n, n), dtype=int)
    for i in range(n):
        for j in range(n):
            result[i][j] += arr1[i][j] - arr2[i][j]
    return result


            
def transpose(arr):
    n = len(arr)
    for i in range(n):
        for j in range(i+1,n):
            temp = arr[i][j]
            arr[i][j] = arr[j][i]
            arr[j][i] = temp
    return arr
        
        


arr1 = np.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
])

arr2 = np.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
])


display(arr1)



display(arr2)



arr3 = add(arr1,arr2)
display(arr3)



arr4 = multiply(arr1, arr2)
display(arr4)


arr5 = difference(arr1,arr2)
display(arr5)


arr1 = transpose(arr1)
display(arr1)
