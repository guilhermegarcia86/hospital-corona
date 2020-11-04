
# include <stdio.h>
# include <conio.h>
# include <string.h>

struct teledir{
        long teleno ;
        char name[20];
        char address[20];
};

main()
{
    struct teledir t;
    FILE *fp;
    long tno;
    char sname[20],c;
    int ch;
    while(1)
    {
        clrscr();
        printf(\"\\t\\t\\t\\tMENU\\n\");
        printf(\"1. TO ADD THE RECORD IN THE FILE.\\n\");
        printf(\"2. TO SEARCH THE RECORD BY NAME.\\n\");
        printf(\"3. TO SERACH THE RECORD BY TELEPHONE NUMBER.\\n\");
        printf(\"4. TO SEE ALL THE RECORD.\");
        printf(\"5. TO EXIT.\\n\");
        printf(\"ENTER YOUR CHOICE:->\");
        scanf(\"%d\",&ch);
        switch(ch)
        {
            case 1:
                    fp=fopen(\"telephon.txt\",\"ab\");
                    while (1)
                    {
                      clrscr();
                      printf(\"ENTER THE TELEPHONE NUMBER:->\");
                      scanf(\"%ld\",&t.teleno);
                      fflush(stdin);
                      printf(\"\\nENTER THE NAME               :->\");
                      scanf(\"%s\",t.name);
                      fflush(stdin);
                      printf(\"\\nENTER THE ADDRESS            :->\");
                      scanf(\"%s\",t.address);
                      fwrite(&t,sizeof(t),1,fp);
                      fflush(stdin);
                      printf(\"\\n\\nWISH TO CONTINUE?(Y/N)\");
                      scanf(\"%c\",&c);
                      if(c==\'n\' || c==\'N\')
                            break;
                    }
                    fclose(fp);
                    break;
            case 2:
                    fp=fopen(\"telephon.txt\",\"rb\");
                    clrscr();
                    printf(\"ENTER THE NAME    :->\");
                    scanf(\"%s\",sname);
                    while(fread(&t,sizeof(t),1,fp))
                    {
                        if(strcmp(sname,t.name)==0)
                        {
                            printf(\"\\n\\t%ld\\t %s\\t %s\",t.teleno,t.name,t.address);
                            getch();
                            break;
                        }
                    }
                    fclose(fp);
                    getch();
                    break;
            case 4:
                    exit(1);
        }
    }
        getch();

}
