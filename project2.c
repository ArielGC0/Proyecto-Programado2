//Libraries
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

#define Vertice struct nodo
#define Edge struct edge


//Vertice Data
struct vertice{
	char ID[15];
	char description[99];
	char typeOfTask[99];
	char time[15];
	char manager[15];
	
};

//Vertice Nodo
Vertice{
	struct vertice vertice1;
	struct nodo * next;
	Edge * adjacent;
};

//Edge Nodo
Edge{
	Vertice * task;
	int effort;
	struct edge * next;
	
};

//FUNCTIONS
void verticePrinter(Vertice * list);

//VerticeAdder
Vertice * verticeAdder(Vertice * list);

//Edge Adder
Edge * edgeAdder(Edge * listEdge,Vertice * listVertice);
// Edge Inserter
Edge *  edgeInserter(Vertice *aux1, Vertice * aux2, Edge * newEdgeList);

//Edge Viewer
void visualizarGrafo(Vertice * verList, Edge * edgeList);




int main(){
	Vertice * list =NULL;
	int num=0;
	list= verticeAdder(list);
	list= verticeAdder(list);
    list= verticeAdder(list);
	Edge * edgeList = edgeAdder(NULL,list);
	edgeList = edgeAdder(edgeList,list);
	edgeList = edgeAdder(edgeList,list);
	verticePrinter(list);
	
	visualizarGrafo(list, edgeList);
	
		
	
	
	return 0;
}

Vertice * verticeAdder(Vertice * list){
	Vertice  *aux;
	struct vertice vertice1;
	//Save the data for the task 
	printf("Type in the ID: ");
	scanf("%s",&vertice1.ID);
	printf("Type in the description, please dont use space");
	scanf("%s",&vertice1.description);
	printf("Descripcion: %s",vertice1.description);
	printf("Type in the type of Task");
	scanf(" %s",&vertice1.typeOfTask);
	printf("Type in the time ");
	scanf(" %s",&vertice1.time);
	printf("Type in the manager");
	scanf("%s",&vertice1.manager);
	
	//Save the data in the txt
	FILE *file;
	file=fopen("tasks.txt","a");
	if(file==NULL){
		printf("Connection Error: Impossible to connect to the txt \n ");
		return list;
	}
	fputs("-------Task--------\n ",file);
	fputs("ID: ",file);
	fputs(vertice1.ID,file);
	fputs("\n ",file);
	fputs("Description: ",file);
	fputs(vertice1.description,file);
	fputs("\n ",file);
	fputs("Type of Task:  ",file);
	fputs(vertice1.typeOfTask,file);
	fputs("\n ",file);
	fputs("Time:  ",file);
	fputs(vertice1.time,file);
	fputs("\n ",file);
	fputs("Manager:  ",file);
	fputs(vertice1.manager,file);
	fputs("\n ",file);
	fclose(file);
	
	//Creation of the newVertice;
	//Validation of the list
	if(list==NULL){
		list=(Vertice*)malloc(sizeof(Vertice));
		list->vertice1=vertice1;
		list->adjacent=NULL;
		list->next=NULL;
	}else{
		//search for the last item of the vertice list
		aux=list;
		while(aux->next!=NULL){
			aux=aux->next;
		}
		//insertion of the new vertice at the bottom
		aux->next=(Vertice*)malloc(sizeof(Vertice));
		aux->next->vertice1=vertice1;
		aux->next->next=NULL;
		aux->next->adjacent=NULL;
	}
	
	return list;
	
}


Edge * edgeAdder(Edge * listEdge,Vertice * listVertice){
	//Creation of the newEdge
	Edge * newEdgeList = (Edge*)malloc(sizeof(Edge));
	//Creation of the auxiliars for the connection between the vertice
	Vertice * aux1,*aux2;
	//Checkin of there is vertice
	if(listVertice==NULL){
		printf("\n Error: The Graph is empty\n ");
		return NULL;
	}
	//Data enters for the vertices
	char startID[20];
	char endID[20];
	printf("\n Type in the ID of the inital vertice:");
	scanf("%s",&startID);
	printf("\n Type in the ID of the end of the vertice:");
	scanf("%s",endID);
	//auxiliars for roaming the list of Vertice
	aux1= listVertice;
	aux2=  listVertice;
	//Search for the elements
	while(aux2!=NULL){
		//Search inside the list for the ID
		printf("The ID is: %s",aux2->vertice1.ID);
		if(strcmp(aux2->vertice1.ID,endID)==0){
			printf("The End ID is found");
			break;
		}
		
		aux2=aux2->next;
	}
	//If the End ID is not found end function
	if(aux2==NULL){
		printf("Error: The End ID is not found");
		return NULL;
	}
	// Search of the StartID
	while(aux1!=NULL){
		if(strcmp(aux1->vertice1.ID,startID)==0){
			printf("The start ID is found");
			newEdgeList = edgeInserter(aux1,aux2,newEdgeList);
			break;
		}
		aux1=aux1->next;
	}
	if(aux1==NULL){
		printf("Error: The start ID is not found");
		return NULL;
	}
	printf("Sale de la funcion \n");
	return newEdgeList;
}


Edge *  edgeInserter(Vertice *aux1, Vertice * aux2, Edge * newEdgeList){
	Edge * aux;
	newEdgeList->task=aux2;
	newEdgeList->next=NULL;
	if(aux1->adjacent==NULL){
		printf("It works");
		aux1->adjacent=newEdgeList;
		
	}else{
		aux=aux1->adjacent;
		printf("Entra al else");
		while(aux->next!=NULL){
			aux=aux->next;
		}
		newEdgeList->task=aux2;
		aux->next=newEdgeList;
	}
	return newEdgeList;
	
	
}

void verticePrinter(Vertice * list){
	Vertice *aux;
	aux=list;
	while(aux!=NULL){
		printf("\n The ID of the vertice is %s \n",aux->vertice1.ID);
		aux=aux->next;
	}
}


void visualizarGrafo(Vertice * verList, Edge * edgeList){
    Vertice*aux= verList;
    Edge* ar;
    printf("Nodos\n");
    while(aux!=NULL){   
	    printf("%s:    ",aux->vertice1.typeOfTask);
        if(aux->adjacent!=NULL){
            ar=aux->adjacent;
            while(ar!=NULL){ 
			    printf(" %s",ar->task->vertice1.typeOfTask);
                ar=ar->next;
            }
        }
        printf("\n");
        aux=aux->next;
    }
    printf("\n");
}