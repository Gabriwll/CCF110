#include <stdio.h>

/*
Encontrar uma forma de utilizar as funções e struct contidas nesse arquivo no main.
*/

int investimentoEditor(){   //Essa função será disponível apenas para usuários da categoria administrador.
    int edicao;

    printf("Escolha a ferramenta de edição: \n");
    printf("(1) Adicionar novo investimento;\n");
    printf("(2) Remover investimento existente;\n");
    printf("(3) Editar investimento existente;\n");
    
    while(edicao != 1 || edicao != 2 || edicao != 3){
        scanf("%d", &edicao);
        switch (edicao){
        case 1:
            
            break;
        
        case 2:

            break;

        case 3:

            break;
        
        default:
            printf("Entrada invalida.\n");
            break;
        }
    }
}

int investimentoPoupanca(int tempo, int capital){
    int rendimentoLiquido[tempo], rendimentoBruto[tempo];
    int rendimento = 0.01;  //o rendimento da poupanca será declarado nessa função por enquanto e será
    int imposto = 0.01;     //considerado um rendimento de 1% == 1/100, tal qual o imposto sobre o rendimento;
    
    for(int i = 0; i < tempo; i++){
        rendimentoBruto[i] = ((rendimento * capital) + capital);
        rendimentoLiquido[i] = ((rendimento * capital) + capital) - ((rendimento * capital) * imposto); //tentar reduzir essa expressão

        /*
        Líquido: rendimento obtido após o desconto das taxas;
        Bruto: rendimento obtido desconsiderando as taxas;
        */
    }

    return rendimentoBruto, rendimentoLiquido;
    //não sei se é possível retornar os vetores corretamente dessa forma na saída da função;
}

struct baixoRisco{  //a ideia aqui é criar um array de structs, desse modo, o usuário administrador fica
    int id;         //livre para criar quantos investimentos ele desejar (limitado pelo tamanho do vetor)
    char nome[30];
    int rendimento;
    int taxa;
};