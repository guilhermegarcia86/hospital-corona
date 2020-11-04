#ifndef _USER_H_
#define _USER_H_

struct patient {

    char name[64];
    char lastname[64];
    char cpf[15];
    char telephone[15];
    char zip[10];
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
