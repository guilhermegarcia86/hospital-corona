#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

USER user;

void createUser(){

    printf("Informe os dados do usuario abaixo \n\n");

    printf("CRM ou COREN: ");
    scanf(" %100[^\n]", user.conselho);

    printf("Senha: ");
    scanf(" %100[^\n]", user.pass);

    printf("Nome: ");
    scanf(" %100[^\n]", user.fname);

    printf("Sobrenome: ");
    scanf(" %100[^\n]", user.lname);

}

int registerUser(){

    FILE *userFile;

    createUser();

    userFile = fopen("users.txt", "wb");

    if(userFile == 0){
        printf("Banco de dados de usuarios nao disponivel\n\n");
        exit(1);
    }

    fseek(userFile, 0, SEEK_END);
    fwrite(&user, sizeof(USER), 1, userFile);

    fclose(userFile);

    printf("Usuario cadastrado com sucesso\n");

    return 0;
}

int login(){

    FILE* f;

    char registro[10];
    char pass[10];
    int encontrados = 0;

    printf("Digite o seu CRM ou COREN: ");
    scanf("%s", registro);

    printf("Digite a senha: ");
    scanf("%s", pass);

    f = fopen("users.txt", "r+");
    if(f == 0) {
        printf("Banco de dados de users nao disponivel\n\n");
        exit(1);
    }

    while(fread(&user, sizeof(user), 1, f)){
        if(strcmp(registro, user.conselho) == 0 && strcmp(pass, user.pass) == 0){
            encontrados++;
        }
    }

    fclose(f);

    if(encontrados == 0){
        printf("Nao encontrou nenhum resultado com o registro informado \n");
        return;
    }

    return encontrados;
}
