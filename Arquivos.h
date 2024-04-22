
            #include <stdbool.h>  // include para poder utilizar o tipo booleano.
            #include <stdio.h>    // include de output para a manipulação de arquivos.
            #include "Listas.h"


            //Função que grava os dados do paciente no arquivo
            bool grava_Paciente(Lista *li, char *caminho);

            //Função que lê os dados do arquivo
            Lista *ler_Arquivo_Paciente(char *caminho);

           //Função que grava a atualização dos dados do paciente quando editado
            bool atualizar_arquivo(Lista *li, char *caminho);

