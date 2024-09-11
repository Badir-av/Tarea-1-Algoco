

def selec_sort(lista):
    i = 0
    j = 0
    while i < len(lista):
        minimo = lista[i]
        min_index = i
        j = i
        while j < len(lista):
            if lista[j] < minimo:
                minimo = lista[j]
                min_index = j
            j += 1
        lista[i], lista[min_index] = lista[min_index], lista[i]
        i += 1
    return lista
        
