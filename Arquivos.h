
            #include <stdbool.h>  // include para poder utilizar o tipo booleano.
            #include <stdio.h>    // include de output para a manipula��o de arquivos.
            #include "Listas.h"


            //Fun��o que grava os dados do paciente no arquivo
            bool grava_Paciente(Lista *li, char *caminho);

            //Fun��o que l� os dados do arquivo
            Lista *ler_Arquivo_Paciente(char *caminho);

           //Fun��o que grava a atualiza��o dos dados do paciente quando editado
            bool atualizar_arquivo(Lista *li, char *caminho);

