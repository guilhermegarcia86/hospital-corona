#ifndef _USER_H_
#define _USER_H_

typedef enum {
    NAO_POSSUI = 1,
    DIABETES = 2,
    OBESIDADE = 3,
    HIPERTENSAO = 4,
    TUBERCULOSE = 5,
    OUTROS = 6
} comorbidity;

typedef enum comorbidity COMORBIDITY;

struct patient {

    char name[64];
    char lastname[64];
    char cpf[11];
    char telephone[11];
    char zip[8];
    int day;
    int month;
    int year;
    comorbidity comorbidity;

};

typedef struct patient PATIENT;

struct group {
    char zip[8];
    comorbidity comorbidity;
};

typedef struct group GROUP;

void createPatient();
int registerPatient();
void saveGroupRisk();

void readPatient();

#endif
