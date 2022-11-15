//Libraries are called
#include <stdio.h>
#include <stdlib.h>



//vertices
typedef struct nodo;
//Edges(Aristas)
typedef struct Arista Arista;
//vertices
typedef struct nodo{
	//Variables of a vertice
	char id[15];
	char description[90];
	char typeOfTask[35];
	char effort[15];
	char time[25];
	char manager[70];
	struct nodo * next;
	Arista * adjacent;
}Vertice;

//Edges(Aristas)
typedef struct Arista{
	Vertice * vertice;
	struct Arsita *next;
}Arista;


//Vertice adder
Vertice * verticeAdder(Vertice * list);
// Edge adder

//general_menu 
general_menu();
//Task modifier
task_modifier();





int main(){
	general_menu();
}

void generalMenu(){
	
	int value=0;
	while(value==0){
		printf("\n Welcome to the project managment system \n ");
		printf("If you want to add or modify tasks of a  project press 1");
		//printf("If you want to modify the tasks of a project press 2");
		scanf("%d",&value);
		if(value==1){
			taskModifier();
		}
		
	}
	
	
	
	
}

Vertice * verticeAdder(Vertice * list){
	//Vertice types 
	Vertice * newVertice,*aux;
	//Assignation of space
	newVertice = (Vertice*)malloc(sizeof(Vertice));
	//recolection of the data
	printf("\n Type in the ID: ");
	scanf("%s",&newVertice->id);
	printf("\n Type in the Description: ");
	scanf("%s",&newVertice->description);
	printf("\n Type in the type of task: ");
	scanf("%s",&newVertice->typeOfTask);
	printf("\n Type in the effort: ");
	scanf("%s",&newVertice->effort);
	printf("\n Type in the time: ");
	scanf("%s",&newVertice->time);
	printf("\n Type in the manager: ");
	scanf("%s",&newVertice->manager);
	//Verification of the current vertices
	if(list==NULL){
		list = newVertice;
	}
	else{
		//list auxiliar
		aux = list;
		while(aux!=NULL){
			aux=aux->next;
		}
		aux=newVertice;
	}
	return list;
	
}



