"""
Este programa é mais um exemplo de programação imperativa
neste caso, em python, podemos observar mais uma vez
a mesma estrutura
"""

lista = [8, 1, 0, 4, 2, 3, 7, 9, 10, 6, 5]

print(f"antes: {lista}")

for i in range(0, len(lista)):
    for j in range(i + 1, len(lista)):
        if lista[i] > lista[j]:
            aux = lista[i]
            lista[i] = lista[j]
            lista[j] = aux

print(f"depois: {lista}")
