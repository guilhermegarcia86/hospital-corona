#ifndef _PATIENT_H_
#define _PATIENT_H_

#include <windows.h>

struct patient {

    char name[64];
    char lastname[64];
    char cpf[15];
    char telephone[15];
    char street[60];
    char numberStreet[10];
    char block[40];
    char city[40];
    char state[40];
    char zip[10];
    char email[255];
    int dayD;
    int monthD;
    int yearD;
    int day;
    int month;
    int year;
    char comorbidity[5];

};

typedef struct patient PATIENT;

void createPatient();
int registerPatient();
void saveGroupRisk();

#endif
