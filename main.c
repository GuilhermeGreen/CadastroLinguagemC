        #include<stdio.h>
        #include<stdlib.h>
        #include<locale.h> // impressão de texto formatado corretamente em português
        #include "Listas.h"
        #include "EstruturaDados.h"
        #include "Buscas.h"
        #include "Tela.h"
        #include "Arquivos.h"
        #include "ControlePaciente.h"

            //Função principal
            int main()
            {

                setlocale(LC_ALL, "Portuguese"); //definindo a configuração de localização
                char caminho[] = "Arquivo.txt";  //// Caminho do arquivo para armazenar os dados dos pacientes


                Lista * listaCadastro = ler_Arquivo_Paciente(caminho);    // Carrega os dados dos pacientes a partir do arquivo e armazena em uma lista encadeada

                struct dengue paciente;// Variável para armazenar os dados de um paciente
                char resposta;// Variável para armazenar a resposta do usuário no menu

                // Loop principal para exibir o menu e processar a escolha do usuário
                while(1)
                {

                    menu();
                    scanf("%d", &resposta);
                    limpaConsole();

                    switch(resposta)
                    {

                    case 1:
                        setbuf(stdin, NULL);
                        printf("\n Cadastrar paciente:\n");
                        solicitar_dados_paciente(listaCadastro, &paciente);
                        if (insere_Paciente(listaCadastro,paciente))
                        {
                            printf("\n\nPaciente inserido com sucesso na lista!\n\n");
                            if (grava_Paciente(listaCadastro, caminho));
                            printf("Paciente salvo no arquivo");
                            usleep(2000000);// Pausa a execução do programa por 2 segundos
                            limpaConsole();

                        }
                        else
                        {
                            printf("Erro ao inserir paciente na lista!\n");
                            usleep(2000000);
                            limpaConsole();
                        }
                        break;

                    case 2:
                        setbuf(stdin, NULL);
                        printf("\n Buscar paciente por CPF(Dados Completos):\n");
                        char cpf_busca[15];
                        printf("Digite o CPF: ");
                        scanf("%[^\n]", cpf_busca);
                        setbuf(stdin, NULL);
                        if (busca_lista_cpf(listaCadastro, cpf_busca, &paciente))
                        {
                            limpaConsole();
                            printf("Paciente encontrado:\n\n");
                            exibir_paciente_cpf(&paciente);
                        }
                        else
                        {
                            printf("Paciente não encontrado.\n");
                            usleep(2000000);
                            limpaConsole();
                        }
                        break;

                    case 3:
                        setbuf(stdin, NULL);
                        printf("\n Listar casos por bairro:\n");
                        char bairro[50];
                        printf("Digite o bairro para buscar: ");
                        scanf("%[^\n]", bairro);
                        setbuf(stdin, NULL);
                        exibir_pacientes_por_bairro(listaCadastro, bairro);
                        break;


                    case 4:
                        setbuf(stdin, NULL);
                        printf("\n Listar por cidade:\n");
                        char cidade[20];
                        printf("Digite a cidade para buscar: ");
                        scanf("%[^\n]", cidade);
                        setbuf(stdin, NULL);
                        exibir_pacientes_por_cidade(listaCadastro, cidade);
                        break;

                    case 5:
                        setbuf(stdin, NULL);
                        printf("\n Listar por hospital:\n");
                        char hospital[50];
                        printf("Digite o nome do hospital para buscar: ");
                        scanf("%[^\n]", hospital);
                        setbuf(stdin, NULL);
                        exibir_pacientes_por_hospital(listaCadastro, hospital);
                        break;

                    case 6:
                        setbuf(stdin, NULL);
                        printf("\nEditar cadastro de pacientes:\n\n");
                        char cpf_edicao[15];
                        printf("Digite o CPF do paciente que deseja editar: ");
                        scanf("%[^\n]", cpf_edicao);
                        setbuf(stdin, NULL);
                        editar_paciente(listaCadastro, cpf_edicao,caminho);
                        break;

                    case 7:
                        setbuf(stdin, NULL);
                        printf("\n Remover paciente:\n");
                        char cpf[15];
                        printf("Digite o CPF para excluir paciente: ");
                        scanf("%[^\n]", cpf);
                        setbuf(stdin, NULL);
                        remove_cadastro(listaCadastro, cpf,caminho);
                        break;

                    case 8:
                        setbuf(stdin, NULL);
                        printf("\n Exibir lista paciente:\n");
                        exibir_lista(listaCadastro);
                        break;

                    case 9:
                        libera_Lista(listaCadastro);
                        printf("\n Aperte qualquer tecla para finalizar a execução do programa.\n");
                        exit(0);

                    default:
                        setbuf(stdin, NULL);
                        limpaConsole();
                        printf("\n Opção inválida...\n");
                    }
                }
                libera_Lista(listaCadastro);
                return 0;
            }
