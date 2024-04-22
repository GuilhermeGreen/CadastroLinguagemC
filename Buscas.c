

         #include"Buscas.h"

        //Verificação se este cpf está cadastrado
         int busca_lista_cpf(Lista* li, char* cpf, struct dengue *de) {
            if (li == NULL || *li == NULL)
            return 0;

            Item *no = *li;
            while (no != NULL && strcmp(no->dados.cpf, cpf) != 0) {
           no = no->prox;
           }

        if (no == NULL)
           return 0;
        else {
          *de = no->dados;
        return 1;
            }
        }

         // Função para exibir os pacientes de um determinado bairro
         void exibir_pacientes_por_bairro(Lista *li, char *bairro) {
            setlocale(LC_ALL, "Portuguese");
            int voltar = 0;
            if (li == NULL || *li == NULL) {
                printf("A lista está vazia.\n");
                usleep(2000000);
                limpaConsole();
            return;
        }

            Item *no = *li;
            int encontrou = 0,// Flag para indicar se algum paciente foi encontrado no bairro especificado
            total = 0;

            printf("Pacientes no bairro %s:\n", bairro);
            while (no != NULL) {
            if (strcmp(no->dados.bairro, bairro) == 0) {
            encontrou = 1; // Marca que ao menos um paciente foi encontrado no bairro especificado
            total++;
            imprimir_dados_paciente(&(no->dados));
            }
                no = no->prox;

            }
             if (!encontrou) {
                printf("Nenhum paciente encontrado no bairro %s.\n", bairro);

             }
               printf("\n\nTotal de pacientes neste bairro: %d\n\n",total);
               printf("\n Pressione enter para continuar...");
               getchar();

              limpaConsole();

        }


         // Função para exibir os pacientes de uma determinada cidade
         void exibir_pacientes_por_cidade(Lista *li, char *cidade) {
             setlocale(LC_ALL, "Portuguese");
            if (li == NULL || *li == NULL) {
                printf("A lista está vazia.\n");
                usleep(2000000);
                limpaConsole();
                return;
            }

            Item *no = *li;
            int encontrou = 0,// Flag para indicar se algum paciente foi encontrado no bairro especificado
            total = 0;

            printf("Pacientes na cidade de %s:\n", cidade);
            while (no != NULL) {
            if (strcmp(no->dados.cidade, cidade) == 0) {
            encontrou = 1; // Marca que ao menos um paciente foi encontrado no bairro especificado
            total++;
           imprimir_dados_paciente(&(no->dados));
            }
                no = no->prox;

            }
             if (!encontrou) {
             printf("Nenhum paciente encontrado na cidade de %s.\n", cidade);


         }
             printf("\n\nTotal de pacientes nesta cidade: %d\n\n",total);
             printf("\n Pressione enter para continuar...");
             getchar();

             limpaConsole();
             }

              // Função para exibir os pacientes de um determinado hospital
         void exibir_pacientes_por_hospital (Lista *li, char *hospital) {
              setlocale(LC_ALL, "Portuguese");
            int voltar=0;
            if (li == NULL || *li == NULL) {
                printf("A lista está vazia.\n");
                usleep(2000000);
                limpaConsole();
                return;
            }

            Item *no = *li;
            int encontrou = 0,
            total = 0;

            printf("Pacientes neste hospital %s:\n", hospital);
            while (no != NULL) {
            if (strcmp(no->dados.hospital_tratamento, hospital) == 0) {
            encontrou = 1;
             total++;

           imprimir_dados_paciente(&(no->dados));
            }
                no = no->prox;

            }
             if (!encontrou) {
            printf("Nenhum paciente encontrado no hospital %s.\n", hospital);
            usleep(2000000);
            limpaConsole();
          }
             printf("\n\nTotal de pacientes neste hospital: %d\n\n",total);
             printf("\n Pressione enter para continuar...");
             getchar();

             limpaConsole();

            }

