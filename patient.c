#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "validator.h"

PATIENT patient;

int age = 0;
int groupRisk = 0;

void createPatient()
{

    printf("Informe os dados do paciente abaixo \n\n");

    printf("Nome: ");
    scanf(" %100[^\n]", patient.name);

    printf("Sobrenome: ");
    scanf(" %100[^\n]", patient.lastname);

    printf("CPF: ");
    scanf(" %100[^\n]", patient.cpf);

    if(!cpfIsValid(patient.cpf))
    {

        printf("***************************************************************\n");
        printf("*                                                             *\n");
        printf("*                     CPF invalido!!!                         *\n");
        printf("*                                                             *\n");
        printf("***************************************************************\n");
        sleep(1);
        exit(1);
    }

    printf("Telefone: ");
    scanf(" %100[^\n]", patient.telephone);

    printf("Endereco\nRua: ");
    scanf(" %100[^\n]", patient.street);

    printf("Numero: ");
    scanf(" %100[^\n]", patient.numberStreet);

    printf("Bairro: ");
    scanf(" %100[^\n]", patient.block);

    printf("Cidade: ");
    scanf(" %100[^\n]", patient.city);

    printf("Estado: ");
    scanf(" %100[^\n]", patient.state);

    printf("CEP (Apenas digitos): ");
    scanf(" %100[^\n]", patient.zip);
    if(!validateZip(patient.zip))
    {
        printf("***************************************************************\n");
        printf("*                                                             *\n");
        printf("*               Formato de CEP invalido!!!                    *\n");
        printf("*                                                             *\n");
        printf("***************************************************************\n");
        sleep(1);
        exit(1);
    }

    printf("Data de nascimento dia/mes/ano: ");
    scanf("%d/%d/%d", &patient.day, &patient.month, &patient.year);
    age = calculateAge(patient.year);

    printf("Email: ");
    scanf(" %100[^\n]", patient.email);

    printf("Data do diagnostico dia/mes/ano: ");
    scanf("%d/%d/%d", &patient.dayD, &patient.monthD, &patient.yearD);

    printf("Escolha se possui comorbidade, se possuir mais de uma selecionar (OUTROS):\n ");
    printf("1 - NAO POSSUI\n ");
    printf("2 - DIABETES\n ");
    printf("3 - OBESIDADE\n ");
    printf("4 - HIPERTENSAO\n ");
    printf("5 - TUBERCULOSE\n ");
    printf("6- OUTROS\n ");
    printf("Opcao: ");

    scanf("%s", patient.comorbidity);

    groupRisk = (!hasComorbidity(patient.comorbidity) && (age >= 65));

}

void saveGroupRisk()
{

    if(groupRisk != 0)
    {

        FILE *groupRiskFile;

        groupRiskFile = fopen("groupRisk.txt", "a+");

        if(groupRiskFile == 0)
        {
            printf("***************************************************************\n");
            printf("*                                                             *\n");
            printf("*      Banco de dados de grupo de risco nao disponivel!!!     *\n");
            printf("*                                                             *\n");
            printf("***************************************************************\n");
            sleep(1);
            exit(1);
        }

        fseek(groupRiskFile, 0, SEEK_END);

        fprintf(groupRiskFile, "\n%s %d", patient.zip, age);

        fclose(groupRiskFile);

        printf("***************************************************************\n");
        printf("*                                                             *\n");
        printf("*          Grupo de risco cadastrado com sucesso!!!           *\n");
        printf("*                                                             *\n");
        printf("***************************************************************\n\n\n");
    }

}

int registerPatient()
{

    createPatient();
    saveGroupRisk();

    FILE *patientFile;

    patientFile = fopen("patient.txt", "a+");

    if(patientFile == 0)
    {
        printf("***************************************************************\n");
        printf("*                                                             *\n");
        printf("*        Banco de dados de pacientes nao disponivel!!!        *\n");
        printf("*                                                             *\n");
        printf("***************************************************************\n");
        sleep(1);
        exit(1);
    }

    fseek(patientFile, 0, SEEK_END);

    fprintf(patientFile, "\n%s %s %s %s %s %s %s %s %s %s %s %s %d %d %d %d %d %d", patient.name, patient.lastname, patient.cpf, patient.telephone, patient.email, patient.street, patient.numberStreet, patient.block, patient.city, patient.state, patient.zip, patient.comorbidity, patient.day, patient.month, patient.year, patient.dayD, patient.monthD, patient.yearD);

    fclose(patientFile);


    printf("***************************************************************\n");
    printf("*                                                             *\n");
    printf("*            Paciente cadastrado com sucesso!!!               *\n");
    printf("*                                                             *\n");
    printf("***************************************************************\n\n\n");

    return 0;
}
