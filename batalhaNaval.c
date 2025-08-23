#include <stdio.h>
#define linhas 15
#define colunas 15

void habilidadeDoCone(int MatrizDoCone[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            MatrizDoCone[i][j] = 2;
        }
    }
}

void habilidadeDoCruz(int MatrizDoCruz[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            MatrizDoCruz[i][j] = 2;
        }
    }
}

void habilidadeDoOctaedro(int MatrizDoOctaedro[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            MatrizDoOctaedro[i][j] = 2;
        }
    }
}
void InicializaçãoDaMatriz(int iniciarmatriz[linhas][colunas], int vetordosnumero[linhas])
{
    for (int i = 0; i < linhas; i++)
    {
        vetordosnumero[i];

        for (int j = 0; j < colunas; j++)
        {
            iniciarmatriz[i][j] = 0;
        }
    }
}

void logicaDojogo(int numeroQueRepresentaNavio, int matriz[linhas][colunas], int matrizdaHabilidadeCone[linhas][colunas], int matrizdaHabilidadeOctaedro[linhas][colunas], int matrizdaHabilidadeCruz[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {

            // navil na
            if ((i == 2 && j == 3) || (i == 2 && j == 4) || (i == 2 && j == 5))
            {
                matriz[i][j] = numeroQueRepresentaNavio;
            }
            else if ((i == 5 && j == 7) || (i == 6 && j == 7) || (i == 7 && j == 7))
            {
                matriz[i][j] = numeroQueRepresentaNavio;
            }
            // Navil na diagonal
            else if ((i == 2 && j == 9) || (i == 1 && j == 8) || (i == 0 && j == 7))
            {
                matriz[i][j] = numeroQueRepresentaNavio;
            }
            else if ((i == 7 && j == 0) || (i == 6 && j == 1) || (i == 5 && j == 2))
            {
                matriz[i][j] = numeroQueRepresentaNavio;
            }
            //habilidades
            else if ((i == 11 && j < 5) || (i == 10 && j > 0 && j < 4) || (i == 9 && j > 1 && j < 3))
            {
                matriz[i][j] = matrizdaHabilidadeCone[i][j];
            }
            else if ((i == 11 && j > 9) || (i == 10 && j > 10 && j < 14) || (i == 9 && j > 11 && j < 13) || (i == 12 && j > 10 && j < 14) || (i == 13 && j > 11 && j < 13))
            {
                matriz[i][j] = matrizdaHabilidadeOctaedro[i][j];
            }
            else if ((i == 5 && j > 8 && j < 14) || (i == 4 && j > 10 && j < 12) || (i == 3 && j > 10 && j < 12) || (i == 6 && j > 10 && j < 12) || (i == 7 && j > 10 && j < 12))
            {
                matriz[i][j] = matrizdaHabilidadeCruz[i][j];
            }
        }
    }
}

void ExibicaoDaEstruturaDoJogo(char vetor1[linhas], int vetor2[linhas],int matriz[linhas][colunas])
{
    printf("    ");
    for (int i = 0; i < linhas; i++)
    {
        printf("%c ", vetor1[i]);
    }

    printf("\n ");

    for (int i = 0; i < linhas; i++)
    {

        i < 9 ? printf(" %d", vetor2[i]), printf(" ") : printf("%d ", vetor2[i]);

        for (int j = 0; j < colunas; j++)
        {

            printf("%d ", matriz[i][j]);
        }

        printf("\n ");

    }
}

void MenuInterativo(char vetor1[linhas], int vetor2[linhas], int matriz[linhas][colunas])
{
    int inicializacao;

    do
    {

    printf("Olá, Seja bem Vindo ao jogo Batalha Naval\n");
    printf("Aperte 1 Para iniciar Jogo\n");
    printf("Aperte 0 Para sair do Jogo\n ");
    scanf("%d", &inicializacao);
    
    switch (inicializacao)
    {
    case 1:
        ExibicaoDaEstruturaDoJogo(vetor1, vetor2, matriz);
        break;

    case 0:
        printf("Você saiu Do Jogo\n ");
        break;
    
    default:
        printf("Opção invalida\n");
        printf("Tente Novamente\n");
        
        break;
    }
       

    } while (inicializacao > 1);
    
}
int main()
{
    int matriz[linhas][colunas];
    char vetor1[linhas] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',};
    int vetor2[linhas] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int navio = 3;

    int matrizdaHabilidadeCone[linhas][colunas];
    int matrizdaHabilidadeCruz[linhas][colunas];
    int matrizdaHabilidadeOctaedro[linhas][colunas];

    habilidadeDoCone(matrizdaHabilidadeCone);
    habilidadeDoCruz(matrizdaHabilidadeCruz);
    habilidadeDoOctaedro(matrizdaHabilidadeOctaedro);

    InicializaçãoDaMatriz(matriz, vetor2);
    logicaDojogo(navio, matriz, matrizdaHabilidadeCone, matrizdaHabilidadeOctaedro, matrizdaHabilidadeCruz);
    MenuInterativo(vetor1, vetor2, matriz);

    return 0;
}
