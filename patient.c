#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "validator.h"

PATIENT patient;

int age = 0;
int groupRisk = 0;

void createPatient(){

    printf("Informe os dados do paciente abaixo \n\n");

    printf("Nome: ");
    scanf(" %100[^\n]", patient.name);

    printf("Sobrenome: ");
    scanf(" %100[^\n]", patient.lastname);

    printf("CPF: ");
    scanf(" %100[^\n]", patient.cpf);

    if(!cpfIsValid(patient.cpf)){
        printf("CPF invalido \n\n");
        exit(1);
    }

    printf("Telefone: ");
    scanf(" %100[^\n]", patient.telephone);

    printf("CEP (Apenas digitos): ");
    scanf(" %100[^\n]", patient.zip);
    if(!validateZip(patient.zip)){
        printf("Formato de CEP invalido \n\n");
        exit(1);
    }

    printf("Data de nascimento dia/mes/ano: ");
    scanf("%d/%d/%d", &patient.day, &patient.month, &patient.year);
    age = calculateAge(patient.year);

    printf("Escolha se possui comorbidade, se possuir mais de uma selecionar (OUTROS):\n ");
    printf("1 - NAO POSSUI\n ");
    printf("2 - DIABETES\n ");
    printf("3 - OBESIDADE\n ");
    printf("4 - HIPERTENSAO\n ");
    printf("5 - TUBERCULOSE\n ");
    printf("6- OUTROS\n ");
    printf("Opcao: ");

    groupRisk = (!hasComorbidity(patient.comorbidity) && (age >= 65));

}

void saveGroupRisk(){

    if(groupRisk != 0){

        printf("Vai salvar grupo de risco\n");

        FILE *groupRiskFile;

        groupRiskFile = fopen("groupRisk.txt", "r+");

        if(groupRiskFile == 0){
            printf("Banco de dados de pacientes de grupo de risco nao disponivel\n\n");
            exit(1);
        }

        fseek(groupRiskFile, 0, SEEK_END);

        fprintf(groupRiskFile, "\n%s %s", patient.zip, patient.comorbidity);

        fclose(groupRiskFile);

        printf("Grupo de risco cadastrado com sucesso!!!\n");
    }

}

int registerPatient(){

    createPatient();
    saveGroupRisk();

    FILE *patientFile;

    patientFile = fopen("patient.txt", "r+");

    if(patientFile == 0){
        printf("Banco de dados de pacientes nao disponivel\n\n");
        exit(1);
    }

    fseek(patientFile, 0, SEEK_END);

    fprintf(patientFile, "\n%s %s %s %s %s %s %d %d %d", patient.name, patient.lastname, patient.cpf, patient.telephone, patient.zip, patient.comorbidity, patient.day, patient.month, patient.year);

    fclose(patientFile);

    printf("Paciente cadastrado com sucesso\n");

    return 0;
}
