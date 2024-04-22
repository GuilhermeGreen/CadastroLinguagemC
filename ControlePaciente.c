
        #include "ControlePaciente.h"

        //Função que insere paciente na lista
         int insere_Paciente(Lista* li, struct dengue caso){
            if(li==NULL )
            return 0;
        struct dengue paciente_existente;
            //Chamada da função busca_lista_cpf
            if (busca_lista_cpf(li, caso.cpf, &paciente_existente)) {
            printf("Erro: CPF já cadastrado.\n");
            return 0;
         }
            Item* no;

            no = (Item*) malloc(sizeof(Item)); //insere no inicio
            if(no == NULL )
                return 0;
            no->dados = caso;
            no-> prox = (*li);
            *li = no;
            return 1;
         }



        // Função para remover um paciente da lista pelo CPF

         int remove_cadastro(Lista* li, int cpf,char *caminho){

             if (li == NULL || *li == NULL) {
              printf("A lista está vazia.\n");
              usleep(2000000);
              limpaConsole();
              return;
         }
         Item *ant, *no = *li;

         while (no != NULL && strcmp(no->dados.cpf, cpf) != 0) {
          ant = no;
          no = no->prox;
         }
         if(no==NULL){
            printf("Paciente com o CPF %s não encontrado.\n", cpf);
            usleep(2000000);
            limpaConsole();
            return 1;
         }
          char escolha;
          printf("Deseja remover o paciente %s ?\n",no->dados.nome);
          printf("(s)Sim  /  (n)Não:");
          scanf("%c",&escolha);
          if(escolha =='s'){

          if(no == *li)//remover o primeiro?
              *li = no->prox;
           else
                ant -> prox=no->prox;
          free(no);
          atualizar_arquivo(li, caminho); // Atualiza o arquivo após a remoção
          printf("Paciente removido com sucesso.\n");
          usleep(2000000);
          limpaConsole();
            return 1;
          }
          else if(escolha == 'n'){
            printf("Retornando ao menu....");
            usleep(2000000);
            limpaConsole();
            return 0;
          }
         }


         //Função que modifica os dados do paciente
         void editar_paciente(Lista *li, char *cpf,char *caminho) {
            setlocale(LC_ALL, "Portuguese");
            if (li == NULL || *li == NULL) {
            limpaConsole();
            printf("A lista está vazia.\n");
            usleep(2000000);
            limpaConsole();
            return;
         }

            Item *no = *li;
            int encontrado = 0;

            while (no != NULL && !encontrado) {
                if (strcmp(no->dados.cpf, cpf) == 0) {
                    encontrado = 1;
                    printf("\n\nPaciente encontrado!\n");
                    printf("\nDigite as novas informações:\n\n");
                    // Solicita as novas informações do paciente
                    editar_dados(&li,&(no->dados));
                    atualizar_arquivo(li, caminho);
                    limpaConsole();
                    printf("Paciente atualizado com sucesso.\n");
                    usleep(2000000);
                    limpaConsole();
                }
                no = no->prox;
            }

            if (!encontrado) {
                printf("Paciente com o CPF %s não encontrado.\n", cpf);
                usleep(2000000);
                limpaConsole();
             }
         }


          //Função que preenche os dados do paciente com as informações fornecidas
            void solicitar_dados_paciente(Lista *li,struct dengue *paciente) {
             setlocale(LC_ALL, "Portuguese");
             char cpf_busca[15];
              bool cpf_existe = false;
              do {
                  printf("Digite o CPF do paciente: ");
                  fgets(cpf_busca, 15, stdin);
                  if (cpf_busca[strlen(cpf_busca) - 1] == '\n')
                  cpf_busca[strlen(cpf_busca) - 1] = '\0';
                  cpf_existe = busca_lista_cpf(li, cpf_busca, paciente);
                  if (cpf_existe) {

                   return;
                    }

            } while (cpf_existe);

            strcpy(paciente->cpf, cpf_busca);

            printf("Digite o nome do paciente: ");
            fgets(paciente->nome,50,stdin); // %[^\n] para ler uma linha inteira incluindo espaços
            if (paciente->nome[strlen(paciente->nome) - 1] == '\n')
                paciente->nome[strlen(paciente->nome) - 1] = '\0';

            printf("Digite a idade do paciente: ");
            scanf("%d",&paciente->idade);
            setbuf(stdin, 0);

            printf("Digite a cidade do paciente: ");
            fgets(paciente->cidade,20,stdin);
             if (paciente->cidade[strlen(paciente->cidade) - 1] == '\n')
                paciente->cidade[strlen(paciente->cidade) - 1] = '\0';

            printf("Digite o bairro do paciente: ");
            fgets(paciente->bairro,50,stdin);
            if (paciente->bairro[strlen(paciente->bairro) - 1] == '\n')
                paciente->bairro[strlen(paciente->bairro) - 1] = '\0';

             printf("Digite a rua do paciente: ");
            fgets(paciente->rua,50,stdin);
            if (paciente->rua[strlen(paciente->rua) - 1] == '\n')
                paciente->rua[strlen(paciente->rua) - 1] = '\0';

            printf("Digite o numero da casa do paciente: ");
            scanf("%d",&paciente->numero_casa);
            setbuf(stdin, 0);

            printf("Digite a data do diagnostico do paciente (dd/mm/aaaa): ");
            fgets(paciente->data_diagnostico,20,stdin);
             if (paciente->data_diagnostico[strlen(paciente->data_diagnostico) - 1] == '\n')
               paciente->data_diagnostico[strlen(paciente->data_diagnostico) - 1] = '\0';

            printf("Digite de inicio dos sintomas (dd/mm/aaaa): ");
            fgets(paciente->data_inicio_sintomas,20,stdin);
            if (paciente->data_inicio_sintomas[strlen(paciente->data_inicio_sintomas)- 1] == '\n')
               paciente->data_inicio_sintomas[strlen(paciente->data_inicio_sintomas) - 1] = '\0';

            printf("Digite o hospital do paciente: ");
            fgets(paciente->hospital_tratamento,50,stdin);
            if (paciente->hospital_tratamento[strlen(paciente->hospital_tratamento) - 1] == '\n')
               paciente->hospital_tratamento[strlen(paciente->hospital_tratamento) - 1] = '\0';

            printf("Digite o tipo de dengue: ");
            fgets(paciente->tipo_dengue,20,stdin);
             if (paciente->tipo_dengue[strlen(paciente->tipo_dengue) - 1] == '\n')
               paciente->tipo_dengue[strlen(paciente->tipo_dengue) - 1] = '\0';


             printf("Digite os sintomas do paciente: ");
            fgets(paciente->sintomas,200,stdin);
            if (paciente->sintomas[strlen(paciente->sintomas) - 1] == '\n')
            paciente->sintomas[strlen(paciente->sintomas) - 1] = '\0';


                limpaConsole();
          }


          //Função que coleta os dados para editar o cadastro sem busca de CPF na Lista

          void editar_dados(Lista *li,struct dengue *paciente) {
             setlocale(LC_ALL, "Portuguese");

            printf("Digite o nome do paciente: ");
            fgets(paciente->nome,50,stdin);
            if (paciente->nome[strlen(paciente->nome) - 1] == '\n')
                paciente->nome[strlen(paciente->nome) - 1] = '\0';

            printf("Digite a idade do paciente: ");
            scanf("%d",&paciente->idade);
            setbuf(stdin, 0);

            printf("Digite a cidade do paciente: ");
            fgets(paciente->cidade,20,stdin);
             if (paciente->cidade[strlen(paciente->cidade) - 1] == '\n')
                paciente->cidade[strlen(paciente->cidade) - 1] = '\0';

            printf("Digite o bairro do paciente: ");
            fgets(paciente->bairro,50,stdin);
            if (paciente->bairro[strlen(paciente->bairro) - 1] == '\n')
                paciente->bairro[strlen(paciente->bairro) - 1] = '\0';

             printf("Digite a rua do paciente: ");
            fgets(paciente->rua,50,stdin);
            if (paciente->rua[strlen(paciente->rua) - 1] == '\n')
                paciente->rua[strlen(paciente->rua) - 1] = '\0';

            printf("Digite o numero da casa do paciente: ");
            scanf("%d",&paciente->numero_casa);
            setbuf(stdin, 0);

            printf("Digite a data do diagnostico do paciente (dd/mm/aaaa): ");
            fgets(paciente->data_diagnostico,20,stdin);
             if (paciente->data_diagnostico[strlen(paciente->data_diagnostico) - 1] == '\n')
               paciente->data_diagnostico[strlen(paciente->data_diagnostico) - 1] = '\0';

            printf("Digite de inicio dos sintomas (dd/mm/aaaa): ");
            fgets(paciente->data_inicio_sintomas,20,stdin);
            if (paciente->data_inicio_sintomas[strlen(paciente->data_inicio_sintomas)- 1] == '\n')
               paciente->data_inicio_sintomas[strlen(paciente->data_inicio_sintomas) - 1] = '\0';

            printf("Digite o hospital do paciente: ");
            fgets(paciente->hospital_tratamento,50,stdin);
            if (paciente->hospital_tratamento[strlen(paciente->hospital_tratamento) - 1] == '\n')
               paciente->hospital_tratamento[strlen(paciente->hospital_tratamento) - 1] = '\0';

            printf("Digite o tipo de dengue: ");
            fgets(paciente->tipo_dengue,20,stdin);
             if (paciente->tipo_dengue[strlen(paciente->tipo_dengue) - 1] == '\n')
               paciente->tipo_dengue[strlen(paciente->tipo_dengue) - 1] = '\0';


             printf("Digite os sintomas do paciente: ");
            fgets(paciente->sintomas,200,stdin);
            if (paciente->sintomas[strlen(paciente->sintomas) - 1] == '\n')
            paciente->sintomas[strlen(paciente->sintomas) - 1] = '\0';


                limpaConsole();
          }
