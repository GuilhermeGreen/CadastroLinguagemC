
               #include "Arquivos.h"


                //Fun��o que grava os dados do paciente no arquivo
                bool grava_Paciente(Lista *li, char *caminho) {
                    if (li == NULL || *li == NULL)
                        return false;

                    FILE *arquivo;
                    if ((arquivo = fopen(caminho, "w")) == NULL)
                        return false;

                    Item *no = *li;
                    while (no != NULL) {
                        fwrite(&(no->dados), sizeof(struct dengue), 1, arquivo);
                        no = no->prox;
                    }

                    fclose(arquivo);
                    return true;
                }

                //Fun��o que l� os dados do arquivo
                Lista *ler_Arquivo_Paciente(char *caminho) {
                    Lista *li = criaLista();
                    FILE *arquivo;
                    if ((arquivo = fopen(caminho, "rb")) == NULL)
                        return NULL;


                    struct dengue paciente;

                    while (fread(&paciente, sizeof(struct dengue), 1, arquivo) == 1) {
                        insere_Paciente(li, paciente);
                    }

                    fclose(arquivo);
                    return li;
                }

                //Fun��o que grava a atualiza��o dos dados do paciente quando editado
                bool atualizar_arquivo(Lista *li, char *caminho) {

                if (li == NULL || *li == NULL){
                return false;

                FILE *arquivo;
                if ((arquivo = fopen(caminho, "wb")) == NULL)
                    return false;
                fclose(arquivo);
                return true;
                }
                 FILE *arquivo;
                 if ((arquivo = fopen(caminho, "wb")) == NULL)
                 return false;

                Item *no = *li;
                while (no != NULL) {
                fwrite(&(no->dados), sizeof(struct dengue), 1, arquivo);
                no = no->prox;
                }
                    fclose(arquivo);
                    return true;
                    }
