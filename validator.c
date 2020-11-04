#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "patient.h"
#include "validator.h"

time_t ts;
struct tm *ct;


int getCheckDigit(char *cpf){
  cpf += strlen(cpf) - 2;
  return atoi(cpf);
}

int validateAlpha(char *cpf){
  do {
	if (! isdigit(*cpf)) {
	  return 1;
	}
  } while(*(++cpf));
  return 0;
}

int validateSingleDigit(char *cpf){
  int singleDigit = 1;
  ++cpf;
  do {
	singleDigit = singleDigit && (*(cpf - 1) == *cpf);
	++cpf;
  } while (*cpf && singleDigit);
  return singleDigit;
}

int checkDigit(char *cpf, int weight){
  int checkDigit = 0;
  int i;
  int len = strlen(cpf);
  for (i = 0; i < len && weight > 1; ++i, --weight) {
	checkDigit += (cpf[i] - '0') * weight;
  }
  int remainder = checkDigit % 11;
  checkDigit = remainder < 2 ? 0 : 11 - remainder;
  return checkDigit;
}

int cpfIsValid(char *cpf){
  int ckDigit, calculatedCkDigit;

  if (cpf == NULL) {
	return 0;
  }
  if (strlen(cpf) != CPF_SIZE) {
	return 0;
  }
  if (validateAlpha(cpf)) {
	return 0;
  }
  if (validateSingleDigit(cpf)) {
	return 0;
  }
  ckDigit = getCheckDigit(cpf);
  calculatedCkDigit = checkDigit(cpf, 10) * 10 + checkDigit(cpf, 11);
  return (ckDigit == calculatedCkDigit);
}

int validateZip(char *zipCode){
    int len = strlen(zipCode);
    if(len < 8 || len > 8){
        return 0;
    }
    return 1;
}

int calculateAge(int year){

    ts = time(NULL);
    ct = localtime(&ts);

    year = (ct->tm_year + 1900) - year - 1;

    return year;

}

int hasComorbidity(char *comorbidity){

    printf("entrou na validacao %s\n", comorbidity);

    int c = atoi(comorbidity);

    printf("valor apos atoi %d\n", c);

    int hasComorbidity = 1;

    switch(c){
    case 1:{
        hasComorbidity = 1;
        break;
    }
    case 2:{
        hasComorbidity = 0;
        break;
    }
    case 3:{
        hasComorbidity = 0;
        break;
    }
    case 4:{
        hasComorbidity = 0;
        break;
    }
    case 5:{
        hasComorbidity = 0;
        break;
    }
    case 6:{
        hasComorbidity = 0;
        break;
    }
    }

    return hasComorbidity;

}
