#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct
{
    int codigo;
    char nome[30];
    char sobrenome[30];
    char email[100];
    char cidade[6];
    long cpf;
} cliente;

FILE *arquivo = NULL;

int appendFile();
int cutFile();
int readCliente();
int readFile();

int main(int argc, char const *argv[])
{
    char op;

    if (arquivo = fopen("clientes.bin", "rb"))
    {
        fclose(arquivo);
    }
    else
    {
        arquivo = fopen("clientes.bin", "wb");
        if (!arquivo)
        {
            puts("sem permissao para criar o arquivo\nsaindo...");
            exit(1);
        }
        fclose(arquivo);
    }

    do
    {
        printf("\na - adicionar cliente\n"
               "r - remover cliente\n"
               "l - ler cliente\n"
               "t - ler todos os clientes\n"
               "0 - fechar\n"
               "digite uma tecla... ");
        scanf("%c", &op);
        getchar();
        switch (op)
        {
        case '0':
            puts("tchau tchau");
            break;
        case 'a':
            if (appendFile())
            {
                // TODO error handling
                puts("erro encontrado\nsaindo...");
                exit(1);
            }
            break;
        case 'r':
            if (cutFile())
            {
                // TODO error handling
                puts("erro encontrado\nsaindo...");
                exit(1);
            }
            break;
        case 'l':
            if (readCliente())
            {
                // TODO error handling
                puts("erro encontrado\nsaindo...");
                exit(1);
            }
            break;
        case 't':
            if (readFile())
            {
                // TODO error handling
                puts("erro encontrado\nsaindo...");
                exit(1);
            }
            break;
        default:
            puts("\nOPERADOR NÃO ENCONTRADO!!\nTENTE NOVAMENTE");
            break;
        }
    } while (op != '0');

    return 0;
}

int appendFile()
{
    char aux[13];
    char *eptr;

    if (arquivo = fopen("clientes.bin", "rb"))
    {
        fclose(arquivo);

        fputs("codigo: ", stdout);
        fgets(aux, 4, stdin);
        cliente.codigo = strtol(aux, &eptr, 10);
        fputs("nome: ", stdout);
        fgets(cliente.nome, 30, stdin);
        cliente.nome[strlen(cliente.nome) - 1] = '\0';
        fputs("sobrenome: ", stdout);
        fgets(cliente.sobrenome, 30, stdin);
        cliente.sobrenome[strlen(cliente.sobrenome) - 1] = '\0';
        fputs("email: ", stdout);
        fgets(cliente.email, 100, stdin);
        cliente.email[strlen(cliente.email) - 1] = '\0';
        fputs("cidade: ", stdout);
        fgets(cliente.cidade, 7, stdin);
        cliente.cidade[5] = '\0';
        fputs("cpf: ", stdout);
        fgets(aux, 13, stdin);
        cliente.cpf = strtol(aux, &eptr, 10);

        arquivo = fopen("clientes.bin", "ab");
        fwrite(&cliente, sizeof(cliente), 1, arquivo);
        fclose(arquivo);
    }
    else
    {
        return 1;
    }

    return 0;
}

int cutFile()
{
    FILE *temp = fopen("temp.bin", "wb");
    char aux[4];
    char *eptr;
    int codigo;
    int localizado = FALSE;

    if (!temp)
    {
        return 1;
    }

    if (arquivo = fopen("clientes.bin", "rb"))
    {
        printf("digite o codigo a ser removido: ");
        fgets(aux, 4, stdin);
        codigo = strtol(aux, &eptr, 10);

        while (fread(&cliente, sizeof(cliente), 1, arquivo) != 0)
        {
            if (cliente.codigo == codigo)
            {
                printf("cliente localizado.\nremovendo...");
                localizado = TRUE;
            }
            else
            {
                fwrite(&cliente, sizeof(cliente), 1, temp);
            }
        }
        fclose(temp);
        fclose(arquivo);
        if (localizado)
        {
            remove("clientes.bin");
            rename("temp.bin", "clientes.bin");
        }
        else
        {
            // TODO adicionar saida
            remove("temp.bin");
        }
    }
    else
    {
        return 1;
    }

    return 0;
}

int readCliente()
{
    char aux[4];
    char *eptr;
    int codigo;
    int localizado = FALSE;

    fputs("codigo para ler: ", stdout);
    fgets(aux, 4, stdin);
    codigo = strtol(aux, &eptr, 10);

    if (arquivo = fopen("clientes.bin", "rb"))
    {
        while (fread(&cliente, sizeof(cliente), 1, arquivo) != 0)
        {
            if (cliente.codigo == codigo)
            {
                localizado = TRUE;
                printf("nome: %s %s\n"
                       "e-mail: %s\n"
                       "cidade: %s\n"
                       "cpf: %ld\n",
                       cliente.nome, cliente.sobrenome,
                       cliente.email,
                       cliente.cidade,
                       cliente.cpf);
            }
        }
        fclose(arquivo);
        if (!localizado)
        {
            puts("cliente nao existe");
        }
    }
    else
    {
        return 1;
    }

    return 0;
}

int readFile()
{
    int localizado = FALSE;

    if (arquivo = fopen("clientes.bin", "rb"))
    {
        while (fread(&cliente, sizeof(cliente), 1, arquivo) != 0)
        {
            localizado = TRUE;
            printf("codigo: %d\n"
                   "nome: %s %s\n"
                   "e-mail: %s\n"
                   "cidade: %s\n"
                   "cpf: %ld\n",
                   cliente.codigo,
                   cliente.nome, cliente.sobrenome,
                   cliente.email,
                   cliente.cidade,
                   cliente.cpf);
        }
        fclose(arquivo);
        if (!localizado)
        {
            puts("arquivo vazio");
        }
    }
    else
    {
        return 1;
    }

    return 0;
}
