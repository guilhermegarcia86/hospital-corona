#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "patient.h"

int operador;

void initApp() {
    printf("/****************/\n");
    printf("/ Hospital de Campanha */\n");
    printf("/****************/\n\n");
}

int menu(){

    //pressione 1 para login ou 2 para cadastro
    printf("Menu principal\n\n");
    printf("1 - Login \n");
    printf("2 - Registrar \n");
    printf("4 - Sair \n");
    printf("Opcao escolhida: ");
    scanf("%d",&operador);

    return operador;
}

int main(){

    initApp();
    int result = menu();

    switch(result){

    case 1:
        {
            //login
            int logado = login();
            if(logado != 0){
                printf("Usuario logado \n");
                registerPatient();
            }
            break;
        }
    case 2:
        {
            registerUser();
            break;
        }
    case 4:
        {
            printf("****** Sistema encerrado ******\n\n");
            break;
        }

    }

    return 0;

}
