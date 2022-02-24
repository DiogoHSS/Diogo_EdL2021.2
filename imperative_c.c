#include <stdio.h>

/**
 * Este programa inicializa uma lista de inteiros fora de ordem,
 * ordena ela e no final imprime o resultado
 */

int main(int argc, char const *argv[])
{
    int lista[] = {8, 1, 0, 4, 2, 3, 7, 9, 10, 6, 5};
    int tamanho = sizeof(lista) / sizeof(lista[0]); // o tamanho da lista
    int aux = 0;                                    // variavel pra guardar o valor durante a troca de posicao

    // primeiro vamos imprimir como é originalmente
    printf("antes: {%d", lista[0]);
    for (int i = 1; i < tamanho; i++)
    {
        printf(", %d", lista[i]);
    }
    printf("}\n");

    // realiza a ordernacao
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i + 1; j < tamanho; j++)
        {
            if (lista[i] > lista[j])
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }

    // imprime o resultado
    printf("depois: {%d", lista[0]);
    for (int i = 1; i < tamanho; i++)
    {
        printf(", %d", lista[i]);
    }
    printf("}\n");

    return 0;
}
