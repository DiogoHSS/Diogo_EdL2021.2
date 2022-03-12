#include <stdio.h>
#include <stdlib.h>

// estrutura do nó
struct no
{
    int valor;
    struct no *prox;
}*inicio; // inicio vai guardar sempre o primeiro nó da cadeia



int main()
{
    // declaração de variavel
    int pos, valor;
    int tam = 1;

    struct no *corrente, *aux;
    inicio = (struct no*) malloc(sizeof(struct no)); // criando o primeiro nó vazio
    
    printf("Digite -1 como valor para acabar a lista e 0 para deletar a posicao!\n");

    printf("digite o valor da posicao 0: ");
    scanf("%d", &inicio->valor); // da valor ao inicio
    inicio->prox = NULL; // e começa a cadeia

    while (valor != -1)
    {
        printf("cadeia atual: ");
        // vai imprimir a cadeia usando [aux] para se mover na cadeia
        aux = inicio; // "aponto" [aux] para o primeiro nó
        printf("INICIO ->");
        while (aux != NULL) // enquanto não chegar no final da cadeia
        {
            printf(" %d ->", aux->valor);
            aux = aux->prox; // [aux] "anda" para o proximo nó
        }
        printf(" FIM\n");
        
        printf("valor: ");
        scanf("%d", &valor);
        
        if (valor == 0 && tam == 1) // lidando com cadeias sem inicio
        {
            printf("não pode deletar o ultimo no!");
        }
        else if (valor == 0) // deleta 
        {
            printf("deletar a posicao: ");
            scanf("%d", &pos); // para [pos] >= 0
            corrente = inicio; // nao sei por que usei [corrente] ao inves de [aux] dessa vez e to com preguiça de mudar
            if (pos == 0) // deleta o inicio
            {
                inicio = inicio->prox; // mas nao pode perder o valor do inicio
                corrente->prox = NULL; // "solta" o nó da cadeia
                free(corrente); // puf
            }
            else
            {
                for (int i = 0; i < pos-2; i++) // anda até o nó anterior ao que sera deletado
                {
                    corrente = corrente->prox;
                }
                aux = corrente->prox; // [aux] agora é o nó a ser deletado
                corrente->prox = aux->prox; // "conecta" o anterior ao proximo do que sera deletado
                aux->prox = NULL; // "solta"
                free(aux); // puf
            }
            tam--; // diminui o tamanho
        }
        else if (valor != -1)
        {
            printf("inserir na posicao: ");
            scanf("%d", &pos); // para [pos] >= 0
            if (pos >= tam) // insere na ultima posição se nao existir a posição digitada
            {
                corrente = (struct no*) malloc(sizeof(struct no)); // cria nó "solto"
                corrente->valor = valor;
                corrente->prox = NULL;

                aux = inicio;
                for (int i = 0; i < tam-1; i++) // anda até a ultima posição
                {
                    aux = aux->prox;
                }
                aux->prox = corrente; // "conecta" o nó na cadeia
                
            }
            else
            {
                corrente = (struct no*) malloc(sizeof(struct no)); // "solto"
                corrente->valor = valor;

                if (pos == 0) // se inicio
                {
                    corrente->prox = inicio; // aponta o nó solto para o inicio, "conectando-o" à cadeia
                    inicio = corrente; // o inicio agora é outro
                }
                else
                {
                    aux = inicio;
                    for (int i = 0; i < pos-1; i++) // anda até a posição desejada
                    {
                        aux = aux ->prox;
                    }

                    corrente->prox = aux->prox;
                    aux->prox = corrente;
                }
            }
            tam++; // incrementa o tamanho
        }
    }

    return 0;
}