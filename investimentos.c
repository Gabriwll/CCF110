#include <stdio.h>
#include <stdlib.h>

#define n 10    //número de espaços para investimentos
                //10 = baixo risco | 10 = alto risco

/*
Reformular o sistema de detecção se o espaço no vetor está ocupado ou não

ao invés de utilizar uma variável flag, utilizar um contador que marca o último espaço ocupado.
*/

/*
Encontrar uma forma de utilizar as funções e struct contidas nesse arquivo no main.
*/

struct investimentos{
    int id;
    int tipo;   //baixoRisco = 1 && altoRisco = 2;    
    char nome[30];
    float rendimento;
    float taxa;
};

int investimentoEditor(){   //Essa função será disponível apenas para usuários da categoria administrador.
    int edicao = 0, selectInvestimento;
    int contBaixo = 0, contAlto = 0;
    struct investimentos baixoRisco[n], altoRisco[n];

    printf("Escolha a ferramenta de edição: \n");
    printf("(1) Adicionar novo investimento;\n");
    printf("(2) Remover investimento existente;\n");
    printf("(3) Editar investimento existente;\n");
    printf("(4) Listar investimentos;\n");
    
    while(edicao != 1 || edicao != 2 || edicao != 3){
        scanf("%d", &edicao);

        switch (edicao){
        case 1: //adicionar investimento
            for(int i = 0; i < n; i++){
                printf("Defina o tipo de investimento: \n");
                printf("(1) Investimento de baixo risco.\n(2) Investimento de alto risco.\n"); //possível bug quando usuário digita algo diferente de 1 ou 2
                scanf("%d", &selectInvestimento);                                             //fazer um get pra esse tipo de coisa
                
                if(selectInvestimento == 1){
                    printf("Digite o nome do investimento:\n");           //otimizar através de uma função que 
                    scanf("%c", &baixoRisco[i].nome);                     //insere os dados no vetor correto
                    baixoRisco[i].id = i;

                    printf("Defina a taxa e o rendimento (float):\n");
                    scanf("%f%f", &baixoRisco[i].taxa, &baixoRisco[i].rendimento);
                    contBaixo++;

                }else if(selectInvestimento == 2){
                    printf("Digite o nome do investimento:\n");           //otimizar através de uma função que
                    scanf("%c", &altoRisco[i].nome);                      //insere os dados no vetor correto
                    altoRisco[i].id = (10 + i);

                    printf("Defina a taxa e o rendimento (float):\n");
                    scanf("%f%f", &altoRisco[i].taxa, &altoRisco[i].rendimento);
                    contAlto++;

                }else{
                    printf("Entrada invalida.\n");
                }
                /*
                if(investimento[i].flag == 0){ //flag == 1 (espaço preenchido) //flag == 0 (espaço vago)
                    printf("Digite o nome do investimento:\n");
                    fgets(investimento[i].nome, sizeof(investimento[i].nome), stdin); //preenche o vetor de caracteres 'nome' contando com espaços

                    printf("Defina o tipo de investimento:\n");
                    printf("(1) Investimento de baixo risco.\n(2) Investimento de alto risco."); //possível bug quando usuário digita algo diferente de 1 ou 2
                    scanf("%d", &investimento[i].tipo);                                          //fazer um get pra esse tipo de coisa

                    printf("Defina a taxa e o rendimento (float):\n");
                    scanf("%f%f", &investimento[i].taxa, &investimento[i].rendimento);

                    investimento[i].flag = 1;
                }
                */
            }

            break;
        
        case 2: //remover investimento
            

            /*
            for(int i = 0; i < n; i++){
                printf("Id: %d /nNome: %c/n", i, investimento[i].nome);
            }

            printf("\nInsira o id do investimento a ser removido:\n");
            scanf("%d", &selectInvestimento);

            /*
            O restante das informações não precisa ser alterada uma vez que a variável que será mostra se o
            investimento existe está setada em 0 (false).
            *comentado

            investimento[selectInvestimento].flag = 0;
            */

            break;

        case 3: //editar investimento
            printf("Selecione o id:\n");            

            /*
            printf("Selecione o investimento:\n");
            scanf("%d", &selectInvestimento);

            printf("Defina o nome(string):\n");
            scanf("%c", &investimento[selectInvestimento].nome);

            printf("Defina o tipo(int '1 ou 2'):\n");               //possível bug quando usuário digita algo diferente de 1 ou 2
            scanf("%d", &investimento[selectInvestimento].tipo);    //fazer um get pra esse tipo de coisa

            printf("Defina a taxa e o rendimento(float):\n");
            scanf("%f%f", &investimento[selectInvestimento].taxa, &investimento[selectInvestimento].rendimento);
            */

            break;

        case 4: //listar investimentos.
            for(int i = 0; i < n*2; i++){
                
                if(i < 10){
                    printf("Id: 0%d | Nome: %c\n", baixoRisco[i].id, baixoRisco[i].nome);
                }else{
                    printf("Id: %d | Nome: %c\n", baixoRisco[i].id, baixoRisco[i].nome);
                }

            }

            break;
        
        default:
            printf("Entrada invalida.\n");
            break;
        }
    }
}

/*
struct investimentos{
    //id = posição no vetor
    int tipo;   //baixoRisco = 1 && altoRisco = 2;    
    char nome[30];
    float rendimento;
    int taxa;
};
*/

int investimentoBaixoRisco(int tempo, int capital){
    int rendimentoLiquido[tempo], rendimentoBruto[tempo];
    float rendimento = 0.01;  //o rendimento da poupanca será declarado nessa função por enquanto e será
                             //considerado um rendimento de 1% == 1/100, tal qual o imposto sobre o rendimento;
    
    for(int i = 0; i < tempo; i++){
        float taxa = ((rendimento * capital) * 0.01);

        rendimentoBruto[i] = ((rendimento * capital) + capital);
        rendimentoLiquido[i] = (((rendimento * capital) + capital) - taxa);

        /*
        Líquido: rendimento obtido após o desconto das taxas;
        Bruto: rendimento obtido desconsiderando as taxas;
        */
    }

    return rendimentoBruto, rendimentoLiquido;
    //não sei se é possível retornar os vetores corretamente dessa forma na saída da função;
}

int investimentoAltoRisco(int tempo, int capital){
    int rendimentoLiquido[tempo], rendimentoBruto[tempo];
    int taxa = (capital / 100);
    
    for(int i = 0; i < tempo; i++){
        int min = -10, max = 10;
        float rendimento = (((min + rand()) + (max - min + 1)) / 100);
        //Encontrar solução para o número aleatório gerado ser diferente a cada execução do sistema
        
        rendimentoBruto[i] = ((rendimento * capital) + capital);
        rendimentoLiquido[i] = (((rendimento * capital) + capital) - taxa);
    }

    return rendimentoBruto, rendimentoLiquido;
}

/*
    O modificador de rendimento dos investimentos de alto risco se dará por um valor pseudo-aleatório que
    simulará as flutuações de valores de ações. Dessa forma, para fins de teste a função elaborada nessa
    versão do projeto se baseia na função rand() da biblioteca <stdlib.h>. Essa função gera um número pseudo-
    -aleatório com um intervalo definido nessa função de -10 a 10. Nesse caso o rendimento mensal pode variar
    em 10% do valor bruto do capital investido.
*/

