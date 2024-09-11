import random

archivo = open("dataset.txt", "w")

n = int(input("Cantidad de datos: "))

i = 0
datalist = []

#Añade n enteros a la lista, cada uno random entre 0 y 99
while i < n:
    dato = random.randint(0, 99)
    datalist.append(dato)
    i+=1

#Añade cada elemento de la lista separados por una coma al archivo de salida
archivo.write(','.join(map(str, datalist)))

#Info en consola
print("Se actualizo con exito el dataset")
print("Hay " + str(n) + " datos")

archivo.close()
