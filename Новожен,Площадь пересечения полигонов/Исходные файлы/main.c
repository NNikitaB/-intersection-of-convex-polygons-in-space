#include <stdio.h>
#include <stdlib.h>
#include"LIST_K.h"
#include"fileio.h"
#include"poligon.h"
#include <math.h>
#define N_NAME 100
int main()
{
   char lname[N_NAME],name[N_NAME];
   List p1={NULL,NULL,0},p2={NULL,NULL,0};
   int flag=0;
   printf("write poligon input and output in files=1 or terminals=0  \n");
   scanf("%i",&flag);
   FILE *f=stdin,*d=stdout;
//flag=1;
   if(flag)
    {
        printf("write name file in  \n");
        fscanf(stdin,"%s",name);
        f=fopen(name,"r+t");
        if(f==NULL){fputs("can not open file  \n",stdout);exit(1);}
    }
   fscan_poligon(f,&p1);
   fscan_poligon(f,&p2);
double square=square_poligon(&p1,&p2);
printf(" S=%f\n",square);
printf("----------\n");
//flag=0;

   if(flag)
    {
        printf("write name file out  \n");
        fscanf(stdin,"%s",lname);
        d=fopen(lname,"w+t");
        if(d==NULL){fputs("can not open file  \n",stdout);exit(1);}
    }
fprintf(d," S=%f\n",square);
fprintf(d,"----------\n");
fprint_poligon(d,&p1);
fprint_poligon(d,&p2);

List_done(&p1);
List_done(&p2);
printf("ERRORS %i \n",ListError);
fclose(f);
fclose(d);
    return 0;
}
