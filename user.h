#ifndef _USER_H_
#define _USER_H_

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

#endif
