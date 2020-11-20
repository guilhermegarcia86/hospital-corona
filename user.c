#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <windows.h>
#include <conio.h>
#include "user.h"

USER user;

ssize_t getdelim(char **linep, size_t *n, int delim, FILE *fp)
{
    int ch;
    size_t i = 0;
    if(!linep || !n || !fp)
    {
        errno = EINVAL;
        return -1;
    }
    if(*linep == NULL)
    {
        if(NULL==(*linep = malloc(*n=128)))
        {
            *n = 0;
            errno = ENOMEM;
            return -1;
        }
    }
    while((ch = fgetc(fp)) != EOF)
    {
        if(i + 1 >= *n)
        {
            char *temp = realloc(*linep, *n + 128);
            if(!temp)
            {
                errno = ENOMEM;
                return -1;
            }
            *n += 128;
            *linep = temp;
        }
        (*linep)[i++] = ch;
        if(ch == delim)
            break;
    }
    (*linep)[i] = '\0';
    return !i && ch == EOF ? -1 : i;
}
ssize_t getline(char **linep, size_t *n, FILE *fp)
{
    return getdelim(linep, n, '\n', fp);
}

void createUser()
{

    char c;
    int i = 0;

    printf("Informe os dados do usuario abaixo \n\n");

    printf("CRM ou COREN: ");
    scanf(" %100[^\n]", user.conselho);

    printf("Senha: ");

    while((c = getch()) != 13)
    {
        user.pass[i] = c;
        i++;
        printf("*");
    }

    printf("\n");
    user.pass[i] = '\0';
    i = 0;

    printf("Nome: ");
    scanf(" %100[^\n]", user.fname);

    printf("Sobrenome: ");
    scanf(" %100[^\n]", user.lname);

}

int registerUser()
{

    FILE *userFile;

    createUser();

    userFile = fopen("users.txt", "a");

    if(userFile == 0)
    {
        printf("***************************************************************\n");
        printf("*                                                             *\n");
        printf("*         Banco de dados de usuarios nao disponivel!!!        *\n");
        printf("*                                                             *\n");
        printf("***************************************************************\n");
        Sleep(1);
        exit(1);
    }

    fseek(userFile, 0, SEEK_END);

    fprintf(userFile, "\n%s %s %s %s", user.conselho, user.pass, user.fname, user.lname);

    fclose(userFile);

    printf("***************************************************************\n");
    printf("*                                                             *\n");
    printf("*            Usuario cadastrado com sucesso!!!                *\n");
    printf("*                                                             *\n");
    printf("***************************************************************\n\n\n");

    return 0;
}

int login()
{

    FILE* f;

    char registro[10];
    char c;
    int i = 0;
    char pass[10];
    int encontrados = 0;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Digite o seu CRM ou COREN: ");
    scanf("%s", registro);

    printf("Digite a senha: ");

    while((c = getch()) != 13)
    {
        pass[i] = c;
        i++;
        printf("*");
    }

    printf("\n");
    pass[i] = '\0';
    i = 0;

    f = fopen("users.txt", "a+");
    if(f == 0)
    {
        printf("***************************************************************\n");
        printf("*                                                             *\n");
        printf("*         Banco de dados de usuarios nao disponivel!!!        *\n");
        printf("*                                                             *\n");
        printf("***************************************************************\n");
        Sleep(1);
        exit(1);
    }

    while ((read = getline(&line, &len, f)) != -1)
    {
        if(strstr(line, registro) && strstr(line, pass))
        {
            encontrados++;
        }
    }

    free(line);

    fclose(f);

    if(encontrados == 0)
    {
        printf("***************************************************************\n");
        printf("*                                                             *\n");
        printf("*  Nao encontrou nenhum resultado com o registro informado!!! *\n");
        printf("*                                                             *\n");
        printf("***************************************************************\n\n\n");
        Sleep(1);
        exit(1);
    }

    return encontrados;
}
