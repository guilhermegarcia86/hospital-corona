#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

#define CPF_SIZE 11

int cpfIsValid(char *cpf);
int checkDigit(char *cpf, int weight);
int getCheckDigit(char *cpf);
int validateAlpha(char *cpf);
int validateSingleDigit(char *cpf);

int validateZip(char *zipCode);

int calculateAge(int year);

int hasComorbidity(char *comorbidity);

#endif
