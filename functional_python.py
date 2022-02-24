# utilizando o método list.sort() que modifica diretamente o objeto
lista = [8, 1, 0, 4, 2, 3, 7, 9, 10, 6, 5]
print(f"antes: {lista}")

lista.sort()

print(f"depois: {lista}")

# utizando o método sorted() que retorna a lista modificada
lista = [8, 1, 0, 4, 2, 3, 7, 9, 10, 6, 5]
print(f"antes: {lista}")

lista = sorted(lista)

print(f"depois {lista}")
