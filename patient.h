#ifndef _USER_H_
#define _USER_H_

struct patient {

    char name[64];
    char lastname[64];
    char cpf[64];
    char telephone[64];
    char zip[64];
    char birthDate[64];
    char comorbidity[64];

};

typedef struct patient PATIENT;

void createPatient();
int registerPatient();

void readPatient();

#endif
