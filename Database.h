#ifndef Database

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAMELEN 30
#define CAPACITY 50

typedef struct student{

	char name[NAMELEN];
	long int enroll;
}stud;

int hash(long int roll){
	
	return (1 + roll)%CAPACITY;
}

int Insert(stud person, stud ppl[]){

	int i=hash(person.enroll),k=0;
	while(ppl[i].enroll!=person.enroll && ppl[i].enroll!=-1 && k<CAPACITY){
		++k;
		i=hash((long int)i);
	}
	if(ppl[i].enroll!=-1 || ppl[i].enroll==person.enroll )
		return 0;
	else{
		ppl[i].enroll=person.enroll;
		strcpy(ppl[i].name,person.name);
		return 1;
	}
}

void LoadDatabase(char *Database, stud ppl[]){

	FILE *fp=fopen(Database,"r");
	if(fp!=NULL){
		stud person;
		char s;
		while((s=fgetc(fp))!=EOF){
			fscanf(fp,"%ld\n",&person.enroll);
			fgets(person.name,sizeof(person.name),fp);
			int i =Insert(person, ppl);
			if(!i)
				printf("\n\n----------------------------ERROR!!-----------DATA INSERTION FAILED\n\n");
		}
		printf("\nDatabase Loaded\n");
	}
	fclose(fp);
}


void UpdateDatabase(char *Database, stud ppl[]){

	FILE *fp=fopen(Database,"w");
	if(fp!=NULL){
		int i=0;
		for(i=0;i<CAPACITY;i++)
			if(ppl[i].enroll!=-1 )
				fprintf(fp,"\n\n%ld\n%s",ppl[i].enroll,ppl[i].name);
	}
	fclose(fp);
}

void AppendDatabase(stud ppl[]){
    
	system("cls");
	stud person;
	printf("\nEnter Enroll ID of Student =  ");
	scanf("%ld",&person.enroll);
	getchar();
	printf("Enter Name of Student =  ");
	fgets(person.name,sizeof(person.name),stdin);
	int len=strlen(person.name)-1;
	person.name[len]='\0';
	len = Insert(person, ppl);
	if(len)
		printf("\n\nData Insertion Successfull\n\n");
	else
		printf("\n\n----------------------------ERROR!!-----------DATA INSERTION FAILED\n\n");
}

void SearchDatabase(stud ppl[]){

    system("cls");
	long int enroll;
	printf("\n\nEnter Enroll ID of the Student to be Searched :-      ");
	scanf("%ld",&enroll);
	int i=hash(enroll),k=0;
	while(ppl[i].enroll!=enroll && k<CAPACITY){
		++k;
		i=hash((long int)i);
	}
	if(ppl[i].enroll!=enroll )
		printf("\n\n----------------------------ERROR!!-----------DATA NOT FOUND\n\n");
	else{
		printf("\n\nRequested Student Details :-\n");
		printf("\nStudent's ID :-  %ld",ppl[i].enroll);
		printf("\nStudent's Name :-  %s\n",ppl[i].name);
	}
}

void DeleteDatabase(stud ppl[]){

    system("cls");
	long int enroll;
	printf("\n\nEnter Enroll ID of the Student to be Deleted :-      ");
	scanf("%ld",&enroll);
	int i=hash(enroll),k=0;
	while(ppl[i].enroll!=enroll && k<CAPACITY){
		++k;
		i=hash((long int)i);
	}
	if(ppl[i].enroll!=enroll )
		printf("\n\n----------------------------ERROR!!-----------DATA NOT FOUND\n\n");
	else{
		printf("\n\nDeleted Student Details :-\n");
		printf("\nStudent's ID :-  %ld",ppl[i].enroll);
		printf("\nStudent's Name :-  %s\n",ppl[i].name);
		ppl[i].enroll=-1;
	}
}

#define Database
#endif
