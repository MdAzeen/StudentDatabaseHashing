#include "Database.h"
#include "password.h"
#include "loading.h"
#include "tableForm.h"
#include "text.h"


void main(){
	char Dbase[NAMELEN]= "Database.txt";
     SetColorAndBackground(0,90);
	stud ppl[CAPACITY];
	int i;
	for(i=0;i<CAPACITY;i++)
		ppl[i].enroll=-1;
 
	LoadDatabase(Dbase,ppl);
	char username[80]="Admin";
	char pas[80]="12345";
	 char *takenid=userid();
	 char *takenpassword=pass();
	 printf("\n");
   if(strcmp(username,takenid)==0 && strcmp(pas,takenpassword)==0){
        loading();

	while(i){
		printf("\n--------------------------------------------------------------------\nOptions Available\n\n0.Exit Database\n1.Insert Student Data\n2.Print Entire Database\n3.Delete Student Data\n4.Search Student Data\n\nPlease Enter your choice :-  ");
		scanf("%d",&i);
		switch(i){
			case 0:{
				i=0;
				break;
			}
			case 1:{
				loading();
				SetColorAndBackground(2,15);
				AppendDatabase(ppl);
				break;
			}
			case 2:{
			    loading();
				SetColorAndBackground(3,14);
				display(ppl);
				break;
			}
			case 3:{
			    loading();
				SetColorAndBackground(0,194);
				DeleteDatabase(ppl);
				break;
			}
			case 4:{
			    loading();
                SetColorAndBackground(0,9);
				SearchDatabase(ppl);
				break;
			}
			default :{
				SetColorAndBackground(6,11);
				printf("\nInvalid Choice Made\nPlease try Again\n");
				break;
			}

		}
			UpdateDatabase(Dbase, ppl);
	}
   }
	else{
		 printf("--------your userid or password is invalid----------\n");
	 }
}
