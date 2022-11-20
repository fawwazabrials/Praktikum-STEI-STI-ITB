# Program sort
# Program yang menerima input bilangan, misalnya N dan menerima 
# N buah input bilangan yang disimpan di sebuah array. Lalu, 
# implementasikan algoritma sorting, yaitu selection sort untuk 
# mengurutkan bilangan dalam array tersebut dari besar ke kecil. 
# Kemudian, print array yang telah diurutkan ke layar (langsung print(array))
#  saja. Asumsikan input valid, yaitu bilangan integer dan N > 0.

# KAMUS

def get_max(arr, index_start):
    # mendapatkan maksimum array dari indeks indeks_start sampai selesai
    maxi = arr[index_start]
    for i in range(index_start, len(arr)):
        if arr[i] > maxi:
            maxi = arr[i]
    return maxi

def get_idx(arr, number):
    # mendapatkan index dari suatu angka dalam array
    for i in range(len(arr)):
        if arr[i] == number:
            return i

def swap(array, indeks_1, indeks_2):
    # swap elemen array indeks 1 dengan indeks 2
    temp = array[indeks_1]
    array[indeks_1] = array[indeks_2]
    array[indeks_2] = temp

def sort(arr):
    # prosedur untuk sorting array menggunakan selection sort
    for i in range(len(arr)):
        maxArr = get_max(arr, i)
        maxIdx = get_idx(arr, maxArr)
        swap(arr, i, maxIdx)
    print(arr)

def input_array():
    # prosedur untuk menerima input user dan menghasilkan array dari input tersebut
    N = int(input())
    arr = [0 for i in range(N)]

    for i in range(N):
        arr[i] = int(input())
    return arr
    
# ALGORITMA PROGRAM UTAMA
arr = input_array()
sort(arr)