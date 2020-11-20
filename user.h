#ifndef _USER_H_
#define _USER_H_

#include <sys/types.h>
#include <windows.h>

struct user
{
    char conselho[10];
    char pass[10];
    char fname[20];
    char lname[20];
};

typedef struct user USER;

void createUser();
int registerUser();
int login();
ssize_t getdelim(char **linep, size_t *n, int delim, FILE *fp);
ssize_t getline(char **linep, size_t *n, FILE *fp);

#endif
