#include<stdio.h>
#include<stdlib.h>

#define MAX_M_SIZE 10
#define MAX_N_SIZE 10

void view(int *opt)
{
    printf("Gerenciamento de Conjuntos\n\n");
    printf("Menu\n\n");
    printf("1 - Criar um novo conjunto\n");
    printf("2 - Inserir dados em um conjunto\n");
    printf("3 - Remover um conjunto\n");
    printf("4 - Fazer a uniao entre dois conjuntos\n");
    printf("5 - Fazer a inserccao entre dois conjuntos\n");
    printf("6 - Mostrar um conjunto\n");
    printf("7 - Mostrar todos os conjuntos\n");
    printf("8 - Fazer busca por um valor\n");
    printf("9 - Sair do programa\n\n");
    printf("Escolha uma opcao:: ");
    scanf("%d", opt);
    printf("\n");
}

int exists(int count, int i)
{
    return i <= count? 1 : 0;
}

void selectRow(int **mat, int i)
{
    printf("\nConjunto %d:: \n\n", i);

    for (int j = 0; j < MAX_N_SIZE; j++)
    {
        printf("%d", mat[i][j]);

        if (j < MAX_N_SIZE - 1)
        {
            printf(", ");
        }
    }

    printf("\n\n");
}

void insert(int **mat, int i)
{
    printf("\n");

    for (int j = 0; j < MAX_N_SIZE; j++)
    {
        printf("Informe o %d valor:: ", j);
        scanf("%d", &mat[i][j]);
    }

    printf("\n\n");
}

void deleteRow(int **mat, int i)
{
    printf("\n");

    for (i; i <= MAX_N_SIZE; i++)
    {
        mat[i] = mat[i + 1];
    }

    printf("\n\n");
}

void service(int const opt, int **mat, int *count)
{
    switch(opt)
    {
        case 1:
            {
                (*count)++;

                if (*count < MAX_M_SIZE)
                {
                    printf("Cojunto %d criado com sucesso\n\n", *count);
                }
                else
                {
                    printf("Limite maximo atingido\n\n");
                }
            }
            break;
        case 2:
            {
                int i = 0;
                printf("Escolha o indice do conjunto para inserccao dos valores:: ");
                scanf("%d", &i);

                if (exists(*count, i))
                {
                    insert(mat, i);
                    selectRow(mat, i);
                }
                else
                {
                    printf("\nIndice inexistente\n\n");
                }
            }
            break;
        case 3:
            {
                int i = 0;
                printf("Escolha o indice do conjunto a ser removido:: ");
                scanf("%d", &i);

                if (exists(*count, i))
                {
                    deleteRow(mat, i);
                    selectRow(mat, i);
                }
                else
                {
                    printf("\nIndice inexistente\n\n");
                }
            }
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            {
                int i = 0;
                printf("Escolha o indice do conjunto para ser exibido:: ");
                scanf("%d", &i);

                if (exists(*count, i))
                {
                    selectRow(mat, i);
                }
                else
                {
                    printf("\nIndice inexistente\n\n");
                }
            }
            break;
        case 7:
            /* code */
            break;
        case 8:
            /* code */
            break;
        default:
            printf("Opcao invalida\n\n");
            break;
    }
}

int main(int argc, char const *argv[])
{
    int opt = 0, **mat, count = 0;

    // allocate memory dynamically for the mat array using a pointer to a pointer
    mat = (int **) malloc(sizeof(int *) * MAX_M_SIZE);

    for (int i = 0; i < MAX_M_SIZE; i++)
    {
        mat[i] = (int*) malloc(sizeof(int) * MAX_N_SIZE);
    }

    // Main program
    while(opt != 9)
    {
        view(&opt);
        service(opt, mat, &count);
    }

    // free the memory allocated for the mat array
    for (int i = 0; i < MAX_M_SIZE; i++)
    {
        free(mat[i]);
    }

    free(mat);

    return EXIT_SUCCESS;
}