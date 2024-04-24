# Implement a Simple Sorting Algorithm and Compare Performance
# Create a program that implements a basic sorting algorithm (e.g., Bubble Sort, Selection Sort, Insertion Sort) and compare its performance with other sorting algorithms using time complexity analysis.

import time
import random

# Bubble Sort
def sort1(arr, n):
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

# Modified Bubble Sort
def sort2(arr, n):
    for i in range(n):
        swapped = False
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        if (swapped == False):
            break

# Selection Sort
def sort3(arr, n):
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

# Insertion Sort
def sort4(arr, n):
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Quick Sort
def sort5(arr, n):
    if n <= 1:
        return arr
    pivot = arr[n // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return sort5(left, len(left)) + middle + sort5(right, len(right))

# Merge Sort
def sort6(arr, n):
    if n > 1:
        mid = n // 2
        L = arr[:mid]
        R = arr[mid:]
        sort6(L, len(L))
        sort6(R, len(R))
        i, j, k = 0, 0, 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

# Algorithm Implementation
algorithms = {
    "Bubble Sort": sort1,
    "Modified Bubble Sort": sort2,
    "Selection Sort": sort3,
    "Insertion Sort": sort4,
    "Quick Sort": sort5,
    "Merge Sort": sort6
}
n = 10000  # Assumed
data = [random.randint(0, 10000) for _ in range(n)]
for name, func in algorithms.items():
    arr = data.copy()
    start = time.time()
    func(arr, n)
    print(name," Time :",time.time() - start)

# Sample Output Values
'''
Bubble Sort  Time : 4.697738409042358
Modified Bubble Sort  Time : 4.466296672821045
Selection Sort  Time : 1.740370512008667
Insertion Sort  Time : 1.8042662143707275
Quick Sort  Time : 0.03062582015991211
Merge Sort  Time : 0.02695488929748535
'''