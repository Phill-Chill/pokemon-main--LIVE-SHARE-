#include <stdio.h>

int main() {
    FILE *arquivo;
    char nomeArquivo[] = "n.txt"; // Nome do arquivo

    char linha[100];

    // Abre o arquivo para leitura
    arquivo = fopen(nomeArquivo, "r");

    // Lê e imprime cada linha do arquivo
    printf("Conteúdo do arquivo %s:\n", nomeArquivo);
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}


           






                                                        
                                                            

