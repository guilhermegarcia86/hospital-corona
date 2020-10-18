#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

PATIENT patient;

void createPatient(){

    printf("Informe os dados do paciente abaixo \n\n");

    printf("Nome: ");
    scanf(" %100[^\n]", patient.name);

    printf("Sobrenome: ");
    scanf(" %100[^\n]", patient.lastname);

    printf("CPF: ");
    scanf(" %100[^\n]", patient.cpf);

    printf("Telefone: ");
    scanf(" %100[^\n]", patient.telephone);

    printf("CEP: ");
    scanf(" %100[^\n]", patient.zip);

    printf("Data de nascimento dd/MM/YYYY: ");
    scanf(" %100[^\n]", patient.birthDate);

    printf("Informe se possui comorbidades e quais: ");
    scanf(" %100[^\n]", patient.comorbidity);

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
        printf ("nome = %s sobrenome = %s cpf = %s telefone = %s cep = %s data nasc = %s comorbidades = %s\n", patientReader.name, patientReader.lastname, patientReader.cpf, patientReader.telephone, patientReader.zip, patientReader.birthDate, patientReader.comorbidity);

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

    printf("Paciente cadastrado com sucesso\n");

    return 0;
}
