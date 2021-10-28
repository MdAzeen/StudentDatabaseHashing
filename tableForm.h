#ifndef TABLEFORM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include "Database.h"


void gotoxy(int column, int line);
void display(); //prototype


COORD coord = { 0, 0 };

void gotoxy(int x, int y) {
    coord.X = x; coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void display(stud ppl[]) {


    char true;
    system("cls");



    gotoxy(17, 5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 STUDENT DATABASE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(5, 6);
    printf("====================================================================================");

    gotoxy(5, 7);
    printf("STUDENT NO.\t\t ENROLLMENT NUMBER\t STUDENT NAME\t\n"); //TABLE TITLES !

    gotoxy(5, 8);
    printf("====================================================================================");

    gotoxy(0,10);
    int i,k=1;
    for (i=0;i<CAPACITY;i++) {
       if(ppl[i].enroll !=-1 ){
                printf("\n     %-11d\t\t| %-17ld\t| %s \n\n", k, ppl[i].enroll, ppl[i].name);
                k++;

        }

    }

    printf("\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");



    return ;
}



#define TABLEFORM_H_INCLUDED
#endif // TABLEFORM_H_INCLUDED
