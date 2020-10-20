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

    printf("Informe comorbidades separando por ',', deixar em branco caso nao possua: ");
    fgets(&patient.comorbidity, 64, stdin);
    //scanf(" %100[^\n]", patient.comorbidity);

    printf("Comorbidades: %s", patient.comorbidity);

    scanf(" %100[^\n]", patient.comorbidity);

    groupRisk = (!hasComorbidity(patient.comorbidity) && (age >= 65));
}

void readPatient(){

    PATIENT patientReader;
    FILE *patientFile;

    patientFile = fopen("patient.txt", "r+");

    if(patientFile == 0){
        printf("Banco de dados de pacientes não disponível\n\n");
        exit(1);
    }

    while(fread(&patientReader, sizeof(PATIENT), 1, patientFile))
        //printf ("nome = %s sobrenome = %s cpf = %s telefone = %s cep = %s data nasc = %s comorbidades = %s\n", patientReader.name, patientReader.lastname, patientReader.cpf, patientReader.telephone, patientReader.zip, patientReader.birthDate, patientReader.comorbidity);

    // close file
    fclose (patientFile);
}

int registerPatient(){

    createPatient();

    FILE *patientFile;

    patientFile = fopen("patient.txt", "r+");

    if(patientFile == 0){
        printf("Banco de dados de pacientes não disponível\n\n");
        exit(1);
    }

    fseek(patientFile, 0, SEEK_END);
    fwrite(&patient, sizeof(PATIENT), 1, patientFile);

    fclose(patientFile);

    //aqui vai entrar a logica de salvar o paciente maior de 65 anos e com comorbidade

    printf("Paciente cadastrado com sucesso\n");

    return 0;
}
