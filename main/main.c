#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "screen.h"
#include "draw.h"

int lerInt(const char *msg);

int main()
{
    int option = -1;

    int **tela;
    tela = criaTela(nColuna, nLinha);


    do
    {
        limpaTerminal();
        
        printf("\t\t\tMENU\t\t\t");
        printf("\n0 - Sair");
        printf("\n1 - Carregar objeto"); 

        option = lerInt("\nOpcao: ");

        switch (option)
        {
            case 0:
            break;

            case 1: 

            break;
        
            default:
                printf("\nValor nao corresponde as opcoes");
                break;
                
        }
    } 
    while(option != 0);
    
    
    return 0;
}












int lerInt(const char *msg) {
    char buffer[100];
    int valor;
    char *end;

    while (1) {
        printf("%s", msg);

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("\nErro de leitura\n");
            continue;
        }

        valor = strtol(buffer, &end, 10);

        // validação real
        if (end == buffer || (*end != '\n' && *end != '\0')) {
            printf("\nEntrada invalida! Digite um numero.\n");
            continue;
        }

        return valor;
    }
}