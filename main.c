#include <stdio.h>
#include <string.h>

// #include "./clientes.h"
// #include "./financeiro.h"

/*Tipo de execução define se o sistema executará em um dos modos a seguir:
* Usuário comum == 1:
* - Acesso a cadastro, login e investimentos.
*
* Usuário administrador == 0:
* - Acesso a edição de investimentos disponíveis.
*/
#define TIPO_EXECUCAO 1

/*Quantidade máxima de usuários a serem registrados no sistema.
*
* Essa constante deverá ser substituida futuramente por um sistema de alocação dinâmica
*/
#define MAX_USUARIO 50

typedef struct usuario{
    char nome[30];
    char senha[8]; //o ideal seria ter essa senha criptografada
    char cpf[11];
    int idade; //o ideal seria utilizar a data de nascimento para atualizar a idade de forma dinâmica

    float capital;
} usuario;

typedef struct investimento{
    int risco;        //medida comparativa, 0 é um investimento livre de perca
    float rendimento; //será dado em %
    int tempoMin;
    int tempoMax;
} investimento;

int loginUsuario(int maxUsuario, usuario *usuarios){

    int posicaoLoginUsuario = -1;
    char nomeAux[30];
    char senhaAux[8];

    while (posicaoLoginUsuario == -1){
        puts("Digite o seu nome:");
        scanf(" %s", nomeAux);

        for(int i = 0; i < maxUsuario; i++){
            if(strcmp(nomeAux, usuarios[i].nome) == 0){

                puts("Digite a sua senha:");
                scanf(" %s", senhaAux);

                if(strcmp(senhaAux, usuarios[i].senha) != 0){
                    puts("Senha incorreta. Tente novamente.");
                    posicaoLoginUsuario = -1;

                    break;
                }

                posicaoLoginUsuario = i;

                break;
            }else if(usuarios[i].nome[0] == '\0'){
                printf("Usuario nao encontrado no sistema.\n Tente novamente.\n");
                posicaoLoginUsuario = -1;

                break;
            }
        }
    }

    return posicaoLoginUsuario;
}

int regristrarUsuario(int maxUsuario, usuario *usuarios){
    FILE *arquivoClientes = NULL;
    FILE *arquivoSaldo = NULL;
    
    char nomeAux[30];
    int posicaoLoginUsuario;

    int flag = 1;
    
    if((arquivoClientes = fopen("../Dados clientes/clientes.txt", "a")) == NULL){
        printf("Erro ao acessar a base de dados de cadastro (A).\n");

        return -1;
    }

    if((arquivoSaldo = fopen("../Dados clientes/saldo.txt", "a")) == NULL){
        printf("Erro ao acessar a base de dados de saldo de clientes.\n");

        return -1;
    }

    flag = 1;

    while(flag != 0){
        puts("Cadastro:\n");
        printf("Digite o seu nome:\n");

        scanf("%s", nomeAux);

        for(int i = 0; i < maxUsuario; i++){
            if(strcmp(nomeAux, usuarios[i].nome) == 0){
                printf("Usuario ja cadastrado, tente novamente.");

                break;
            }else if(usuarios[i].nome[0] == '\0'){
                strcpy(usuarios[i].nome, nomeAux);
                fprintf(arquivoClientes, "%s ", usuarios[i].nome);

                puts("Digite o seu cpf:");  //Verificar a validez do cpf
                scanf("%s", usuarios[i].cpf);
                fprintf(arquivoClientes, "%s ", usuarios[i].cpf);

                puts("Digite a sua idade:");
                scanf("%d", &usuarios[i].idade);
                fprintf(arquivoClientes, "%d ", usuarios[i].idade);

                puts("Digite a sua senha:"); //Verificar a validez da senha
                scanf("%s", usuarios[i].senha);
                fprintf(arquivoClientes, "%s\n", usuarios[i].senha);

                usuarios[i].capital = 0.0;
                fprintf(arquivoSaldo, "%.2f\n", usuarios[i].capital);

                posicaoLoginUsuario = i;
                flag = 0;

                break;
            }
        }
    }

    fclose(arquivoClientes);
    fclose(arquivoSaldo);

    return posicaoLoginUsuario;
}

void depositarQuantia(int maxUsuario, int posicaoLoginUsuario, usuario *usuarios, float deposito){
    FILE *arquivoSaldo = NULL;

    usuarios[posicaoLoginUsuario].capital += deposito;
    
    if((arquivoSaldo = fopen("../Dados clientes/saldo.txt", "w")) == NULL){
        printf("Erro ao acessar a base de dados do saldo.\n");
    }

    for(int i = 0; i < maxUsuario; i++){
        if(usuarios[i].nome[0] == '\0'){
            break;
        }

        fprintf(arquivoSaldo, "%.2f\n", usuarios[i].capital);
    }

    fclose(arquivoSaldo);
}
/*Atenção ao utilizar essa função,
* a struct com os dados dos clientes já deve estar preenchida.
* Caso isso não aconteça o capital de todos os clientes será perdido.
*/

void sacarQuantia(int maxUsuario, int posicaoLoginUsuario, usuario *usuarios, float saque){
    FILE *arquivoSaldo = NULL;

    if((usuarios[posicaoLoginUsuario].capital - saque) >= 0){
        usuarios[posicaoLoginUsuario].capital -= saque;
    }else{
        printf("Saldo insuficiente.\n");

       return;
    }
    
    if((arquivoSaldo = fopen("../Dados clientes/saldo.txt", "w")) == NULL){
        printf("Erro ao acessar a base de dados do saldo.\n");
    }

    for(int i = 0; i < maxUsuario; i++){
        if(usuarios[i].nome[0] == '\0'){
            break;
        }

        fprintf(arquivoSaldo, "%.2f\n", usuarios[i].capital);
    }

    fclose(arquivoSaldo);
}
/*Atenção ao utilizar essa função,
* a struct com os dados dos clientes já deve estar preenchida.
* Caso isso não aconteça o capital de todos os clientes será perdido.
*/

float investir(int risco, int tempo, float rendimento, float capital){
    float saldo = 0;

    if(risco == 0){
        saldo = (capital * pow(rendimento / 100, (tempo-1))); //dessa forma, teremos o valor final, apenas

    }else{
        for(int i = 0; i < tempo; i++){
            if((rand() % 1) == 0){
                saldo += (capital * ((rand() % risco) / 100));

            }else{
                saldo -= (capital * ((rand() % risco / 100)));
                
            }
        }
    }

    return saldo;
}

/*
Usuario *lista_usuarios;

lista_usuarios = (Usuario*) calloc(10, sizeof(Usuario));
lista_usuarios = (Usuario*) realoc(lista_usuarios, (10 + 5) * sizeof(Usuario));
*/

int main(){
    FILE *arquivoClientes = NULL;
    FILE *arquivoSaldo = NULL;

    usuario usuarios[MAX_USUARIO];

    char opcaoUsuario;
    int posicaoLoginUsuario;
    float capital;

    int flag;

    for(int i = 0; i < MAX_USUARIO; i++){
        usuarios[i].nome[0] = '\0';
    }

    if((arquivoClientes = fopen("../Dados clientes/clientes.txt", "r")) == NULL){
        printf("Erro ao acessar a base de dados de cadastro (R).\n");

        return 1;
    }

    if((arquivoSaldo = fopen("../Dados clientes/saldo.txt", "r")) == NULL){
        printf("Erro ao abrir a base de dados de saldo (R).\n");

        return 1;
    }

    for(int i = 0; i < MAX_USUARIO; i++){
        if(fscanf(arquivoClientes, "%s %s %d %s\n", usuarios[i].nome, usuarios[i].cpf,
                                                    &usuarios[i].idade, usuarios[i].senha) == EOF){

            break;
        }
        fscanf(arquivoSaldo, "%f\n", &usuarios[i].capital);
    }

    fclose(arquivoClientes);
    fclose(arquivoSaldo);

    if(TIPO_EXECUCAO == 1){
        printf("Deseja fazer o login ou se cadastrar? ('L' = Login e 'C' = Cadastrar)\n");
        scanf(" %c", &opcaoUsuario);

        switch(opcaoUsuario){
            case 'L':
                if((posicaoLoginUsuario = loginUsuario(MAX_USUARIO, usuarios)) == -1){
                    printf("Erro no login.\n");

                    return 1;
                }
                
                break;

            case 'C':
                if((posicaoLoginUsuario = regristrarUsuario(MAX_USUARIO, usuarios)) == -1){
                    printf("Erro ao cadastrar o usuario.\n");

                    return 1;
                }

                break;

            default:
                printf("Entrada inválida.");

                return 1;
        }

        //parte de manipulação dos investimentos em si
        printf("Bem vindo(a), %s\n", usuarios[posicaoLoginUsuario].nome);
        printf("Selecione uma das opcoes abaixo:\n");

        flag = 1;

        while(flag != 0){
            puts("1 - Adicionar saldo;");
            puts("2 - Retirar saldo;");
            puts("3 - Fazer um investimento;");
            puts("4 - Consultar saldo;");
            puts("5 - Sair;");

            scanf(" %c", &opcaoUsuario);

            switch (opcaoUsuario){
                case '1':
                    puts("Insira o valor a ser adicionado:");
                    capital = -1.0;

                    while(capital < 0.0){
                        scanf("%f", &capital);

                        if(capital < 0.0){
                            puts("Entrada invalida. Tente novamente.");

                            continue;
                        }else{
                            depositarQuantia(MAX_USUARIO, posicaoLoginUsuario, usuarios, capital);

                            printf("\nR$ %.2f adicionados com sucesso.\nSaldo atual: R$ %.2f", 
                                    capital, usuarios[posicaoLoginUsuario].capital);
                        }
                    }

                    flag = 0;
                    break;

                case '2':
                    puts("Insira o valor a ser retirado:");
                    capital = -1.0;

                    while(capital < 0.0){
                        scanf("%f", &capital);

                        if(capital < 0.0){
                            puts("Entrada invalida. Tente novamente.");

                            continue;
                        }else{
                            sacarQuantia(MAX_USUARIO, posicaoLoginUsuario, usuarios, capital);

                            printf("\nR$ %.2f retirados com sucesso.\nSaldo atual: R$ %.2f", capital, usuarios[posicaoLoginUsuario].capital);
                        }

                    }

                    flag = 0;
                    break;

                case '3'://fazer um investimento
                    

                    flag = 0;
                    break;

                case '4':
                    printf("Você possui R$ %.2f em conta.\n", usuarios[posicaoLoginUsuario].capital);

                    flag = 0;
                    break;

                case '5':
                    puts("Saindo do sistema.");

                    return 0;

                default:
                    puts("Opcao indisponivel. Tente novamente.");
                    flag = 1;

                    break;
            }
        }

    }else if(TIPO_EXECUCAO == 0){

    }

    return 0;
}