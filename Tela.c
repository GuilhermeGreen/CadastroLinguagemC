
              #include"Tela.h"




                 //Função menu
                void menu(){

                 printf(" \n\n Cadastro de Pacientes com Dengue \n");
                 printf("\n\nEscolha uma opção:\n\n");
                 printf(" 1 - Cadastrar pacientes\n");
                 printf(" 2 - Buscar Paciente por CPF(dados completos). \n");
                 printf(" 3 - Listar por bairro\n");
                 printf(" 4 - Listar por cidade\n");
                 printf(" 5 - Listar por hospital\n");
                 printf(" 6 - Editar cadastro de pacientes\n");
                 printf(" 7 - Remover pacientes\n");
                 printf(" 8 - Exibir lista paciente \n");
                 printf(" 9 - Sair \n");
                }


             // Função que exibe os dados do paciente pelo número do CPF
              void exibir_paciente_cpf(struct dengue *paciente) {
                  setlocale(LC_ALL, "Portuguese");

                    int voltar =0;
                    printf("CPF: %s\n", paciente->cpf);
                    printf("Nome: %s\n", paciente->nome);
                    printf("Idade: %d\n", paciente->idade);
                    printf("Cidade: %s\n", paciente->cidade);
                    printf("Bairro: %s\n", paciente->bairro);
                    printf("Rua: %s\n", paciente->rua);
                    printf("Número da casa: %d\n", paciente->numero_casa);
                    printf("Data do diagnóstico: %s\n", paciente->data_diagnostico);
                    printf("Data de início dos sintomas: %s\n", paciente->data_inicio_sintomas);
                    printf("Hospital de tratamento: %s\n", paciente->hospital_tratamento);
                    printf("Tipo de dengue (dengue clássica, dengue Hemorrágica): %s\n", paciente->tipo_dengue);
                    printf("Sintomas: %s\n\n", paciente->sintomas);


                     printf("\n Pressione enter para continuar...");
                     getchar();

                      limpaConsole();

                   }

                //Função usado para listar todos os pacientes da lista
                void imprimir_dados_paciente(struct dengue *paciente) {
                printf("\n\nCPF: %s\n", paciente->cpf);
                printf("Nome: %s\n\n", paciente->nome);
                printf("----------------------------------------");
                   }

              // Função que percorre a lista e exibe os dados de cada paciente
             void exibir_lista(Lista *li) {
             setlocale(LC_ALL, "Portuguese");
             if (li == NULL || *li == NULL) {
                limpaConsole();
                printf(" \n\nA lista está vazia.\n\n");
                usleep(2000000);
                limpaConsole();
                return;
            }

                Item *no = *li;
                printf("\n\nLista de pacientes:\n\n");
                printf("___________________________________\n");
                while (no != NULL) {


                printf("Nome: %s\n", no->dados.nome);
                printf("CPF: %s\n", no->dados.cpf);
                printf("___________________________________\n");
                no = no->prox;

            }


              printf("\n Pressione enter para continuar...");
              getchar();

              limpaConsole();

            }

              //Função que limpa o console, na verdade ele pula várias linhas
              void limpaConsole(){
              printf("\033[H\033[2J");   /* /033: sequência de caracteres que indica o início de uma sequência de controle ANSI
                                         [H: Move o cursor para a posição superior esquerda do console (coordenada 1,1).
                                         [2J: Limpa toda a tela (console).*/
            }
