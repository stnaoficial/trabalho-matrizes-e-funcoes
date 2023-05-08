#include <stdio.h>

#define M 8
#define N 10

int buscaSequencial(int* conjuntos, int tamanho, int valor)
{
    int i;

    for(i = 0; i < tamanho; i++)
    {
        if(conjuntos[i] == valor)
        {
            return i;
        }
    }

    return -1;
}

void criarNovoConjunto(int * contador)
{
    if((*contador) < M)
    {
        (*contador)++;
        printf("Conjunto %d criado.\n\n", *contador);
    }
    else
    {
        printf("Nao e possivel criar mais conjuntos.\n\n");
    }
}

void inserirDadosEmConjunto(int conjuntos[M][N], int *contador)
{
    int i;

    printf("Informe o indice do conjunto (0 <= i < %d): ", *contador);
    scanf("%d", &i);

    if (i < 0 || i >= *contador)
    {
        printf("Indice invalido.\n");
        return;
    }

    int j = 0, valor;

    while (j < N)
    {
        printf("Digite o valor para a posicao [%d][%d]: ", i, j);
        scanf("%d", &valor);
        if (valor == 0 || j == N)
        {
            break;
        }
        if (buscaSequencial(conjuntos[i], N, valor) != -1)
        {
            printf("Valor ja inserido no conjunto.\n");
        } else {
            conjuntos[i][j] = valor;
            j++;
        }
    }

    printf("Valores inseridos com sucesso.\n");
}


void removerConjunto(int conjuntos[][N], int *contador)
{
    int i;

    printf("Informe o índice do conjunto a ser removido (0 a %d): ", *contador-1);
    scanf("%d", &i);

    if (i < 0 || i >= *contador)
    {
        printf("Índice inválido.\n");
        return;
    }

    // Zera a linha do conjunto a ser removido
    for (int j = 0; j < N; j++)
    {
        conjuntos[i][j] = 0;
    }

    // Move os conjuntos abaixo do conjunto removido para cima
    for (int k = i+1; k < *contador; k++)
    {
        for (int j = 0; j < N; j++)
        {
            conjuntos[k-1][j] = conjuntos[k][j];
        }
    }

    // Decrementa o contador
    (*contador)--;

    printf("Conjunto removido com sucesso.\n");
}

void fazerUniaoEntreConjuntos(int conjuntos[M][N], int *contador)
{
    int indice1, indice2;

    printf("Informe o índice do primeiro conjunto: ");
    scanf("%d", &indice1);

    printf("Informe o índice do segundo conjunto: ");
    scanf("%d", &indice2);

    if (indice1 < 0 || indice1 >= *contador || indice2 < 0 || indice2 >= *contador)
    {
        printf("Índice inválido.\n");
        return;
    }

    // cria um novo conjunto vazio
    int novoConjunto[N] = {0};

    // realiza a união entre os conjuntos
    int novoContador = 0;

    for (int i = 0; i < N; i++)
    {
        if (conjuntos[indice1][i] != 0)
        {
            int valor = conjuntos[indice1][i];
            
            if (buscaSequencial(conjuntos[indice2], N, valor) == -1 && buscaSequencial(novoConjunto, N, valor) == -1)
            {
                novoConjunto[novoContador++] = valor;
            }
        }

        if (conjuntos[indice2][i] != 0)
        {
            int valor = conjuntos[indice2][i];
        
            if (buscaSequencial(novoConjunto, N, valor) == -1)
            {
                novoConjunto[novoContador++] = valor;
            }
        }
    }

    // adiciona o novo conjunto à matriz
    if (novoContador == 0)
    {
        printf("Não foi possível criar um novo conjunto. A união resultaria em um conjunto vazio.\n");
    }
    else if (*contador == M)
    {
        printf("Não foi possível criar um novo conjunto. O número máximo de conjuntos foi atingido.\n");
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            conjuntos[*contador][i] = novoConjunto[i];
        }

        (*contador)++;
        
        printf("A união entre os conjuntos %d e %d resultou no conjunto %d.\n", indice1, indice2, *contador - 1);
    }
}

void fazerInsercaoEntreConjuntos(int conjuntos[M][N], int *contador)
{
    int indice, posicao, valor;

    printf("Informe o índice do conjunto: ");
    scanf("%d", &indice);

    if (indice < 0 || indice >= *contador)
    {
        printf("Índice inválido.\n");
        return;
    }

    printf("Informe a posição na linha do conjunto: ");
    scanf("%d", &posicao);

    if (posicao < 0 || posicao >= N)
    {
        printf("Posição inválida.\n");
        return;
    }

    printf("Informe o valor a ser inserido: ");
    scanf("%d", &valor);

    if (buscaSequencial(conjuntos[indice], N, valor) != -1)
    {
        printf("O valor já está presente no conjunto.\n");
        return;
    }

    int i = posicao;

    while (i < N && conjuntos[indice][i] != 0)
    {
        i++;
    }

    if (i == N)
    {
        printf("Não foi possível fazer a inserção. O conjunto está cheio.\n");
        return;
    }

    conjuntos[indice][i] = valor;

    printf("O valor %d foi inserido com sucesso no conjunto %d, posição %d.\n", valor, indice, i);
}

void mostrarConjunto(int conjuntos[M][N], int contador)
{
    int indice;

    printf("Informe o índice do conjunto: ");
    scanf("%d", &indice);

    if (indice < 0 || indice >= contador)
    {
        printf("Índice inválido.\n");
        return;
    }

    printf("Conjunto %d = ", indice);

    if (conjuntos[indice][0] == 0)
    {
        printf("vazio\n");
    }
    else
    {
        printf("%d", conjuntos[indice][0]);

        for (int i = 1; i < N && conjuntos[indice][i] != 0; i++)
        {
            printf(", %d", conjuntos[indice][i]);
        }

        printf("\n");
    }
}

void mostrarTodosConjuntos(int conjuntos[M][N], int contador)
{
    printf("Temos %d conjuntos:\n", contador);

    for (int i = 0; i < contador; i++)
    {
        printf("Conjunto %d = ", i);
        
        if (conjuntos[i][0] == 0)
        {
            printf("vazio\n");
        }
        else
        {
            for (int j = 0; j < N; j++)
            {
                if (conjuntos[i][j] != 0)
                {
                    printf("%d, ", conjuntos[i][j]);
                }
            }

            printf("\n");
        }
    }
}

void buscarValor(int conjuntos[M][N], int contador)
{
    int valor;
    int encontrados = 0;

    printf("Informe o valor a ser buscado: ");
    scanf("%d", &valor);

    printf("Índices dos conjuntos que contêm o valor %d:\n", valor);

    for (int i = 0; i < contador; i++)
    {
        if (buscaSequencial(conjuntos[i], N, valor) != -1)
        {
            printf("%d ", i);
            encontrados++;
        }
    }

    if (encontrados == 0)
    {
        printf("Valor não encontrado em nenhum conjunto.\n");
    }
    else
    {
        printf("\n");
    }
}

int main()
{
    int conjuntos[M][N] = {{0}}; // Inicializa a matriz com todos os valores iguais a zero
    int contador = 0; // Inicializa o contador de conjuntos com zero
    int opt;

    do {
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
        printf("Escolha uma opcao: ");
        scanf("%d", &opt);
        printf("\n");
        
        switch (opt)
        {
            case 1:
                criarNovoConjunto(&contador);
                break;
            case 2:
                inserirDadosEmConjunto(conjuntos, &contador);
                break;
            case 3:
                removerConjunto(conjuntos, &contador);
                break;
            case 4:
                fazerUniaoEntreConjuntos(conjuntos, &contador);
                break;
            case 5:
                fazerInsercaoEntreConjuntos(conjuntos, &contador);
                break;
            case 6:
                mostrarConjunto(conjuntos, contador);
                break;
            case 7:
                mostrarTodosConjuntos(conjuntos, contador);
                break;
            case 8:
                buscarValor(conjuntos, contador);
                break;
            case 9:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        
    } while (opt != 9);

    return 0;
}