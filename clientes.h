typedef struct{
    char nome[30];
    char senha[8]; //o ideal seria ter essa senha criptografada
    char cpf[11];
    int idade; //o ideal seria utilizar a data de nascimento para atualizar a idade de forma dinâmica

    float capital;
}usuario;

int loginUsuario(int maxUsuario, usuario *usuarios);
int regristrarUsuario(int maxUsuario, usuario *usuarios);