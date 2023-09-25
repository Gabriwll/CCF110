#include <stdio.h>
#include <string.h>

int main(){
    //cadastro do cleinte
    int opcao;
    int num_clientes = 0;
    int cliente, tempo;
    char nome_cliente[100][50];
    int idade_cliente[100];
    float capitalInical[100], rendimento[100];

    while(1){
        printf("\n MENU DE CADASTRO DE CLIENTES\n");
        printf("1. Cadastrar clientes;\n");
        printf("2. Listar clientes;\n");
        printf("3. Mostrar Aplicaçoes por clientes;\n");
        printf("4. Realizar um investimento;\n");
        printf("5. Sair.\n");
        printf(" Escolha uma opcao\n");
        scanf("%d", &opcao);


    switch(opcao) {
        case 1:
            //cadastrar clientes

            if(num_clientes <= 100){
            printf("Informe o nome do cliente: ");
            scanf("%s", nome_cliente[num_clientes]);
            printf("\n");
            printf("Informe a idade do cliente: ");
            scanf("%d",&idade_cliente[num_clientes]);
            num_clientes++;
            printf("Clientes cadastrado com sucesso!\n");
            }
            else{
                printf("Limite maximo de clientes atingido!\n");
            }
            break;
            

        case 2:
            //listar clientes

            printf("CLIENTES CADASTRADOS: \n");
            for(int i = 0; i < num_clientes; i++){
            printf("Id: %d Nome: %s, Idade: %d\n" , (i + 1), nome_cliente[i], idade_cliente[i]);
            }

            printf("\nTotal de clientes: %d\n" , num_clientes);
            break;

        case 3:
            //mostrar aplicações por clientes

            for(int i = 0; i <= num_clientes; i++){
                printf("%d | %s: %.2f\n", (i + 1), nome_cliente[i], rendimento[i]);
            }
            
            break;

        case 4:
            //realizar um investimento

                if(num_clientes > 0){
                    
                    printf(" MENU DE INVESTIMENTO!\n");
                    printf("Selecione o cliente (id): \n");
                    scanf("%d", &cliente);

                    cliente--;

                    printf("Bem-vindo %s\n", nome_cliente[cliente]);
                    printf("\nInsira um capital inicial: \n");
                    scanf("%f", &capitalInical[cliente]);

                    printf("Defina o tempo de rendimento: \n");
                    scanf("%d", &tempo);

                    rendimento[cliente] = capitalInical[cliente];

                    for(int i = 0; i < tempo; i++){
                        rendimento[cliente] = (((capitalInical[cliente]) * 0.01) + rendimento[cliente]);
                    }

                    printf("Valor final: R$ %.2f", rendimento[cliente]);

                }else{
                    printf("Cadastre um cliente primeiro.\n");
                }
                

            break;

        case 5:
            //sair

            printf("Saindo do programa.\n");
            return 0;

            break;
        
        default:
            //exceções

            printf("Invalido digite outra opçao.\n");

            break;
        

    }
    
    }

    return 0;
}