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

//VerticeAdderTXT
Vertice * verticeAddertxt(Vertice *list, struct vertice vertice1);

//Edge Adder
Edge * edgeAdder(Edge * listEdge,Vertice * listVertice);
// Edge Inserter
Edge *  edgeInserter(Vertice *aux1, Vertice * aux2, Edge * newEdgeList);

//Edge Viewer
void visualizarGrafo(Vertice * verList, Edge * edgeList);

//Data Tracker;
Vertice * dataTracker(void);




int main(){
	Vertice * list =NULL;
	int num=0;
//	list= verticeAdder(list);
//	list= verticeAdder(list);
//    list= verticeAdder(list);
    list= dataTracker();
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
	printf("\n Type in the ID: ");
	scanf("%s",&vertice1.ID);
	printf("\n Type in the description, please dont use space");
	scanf("%s",&vertice1.description);
	printf("\n Descripcion: %s",vertice1.description);
	printf("\n The type of tasks available are:");
	printf(" operativetask\napprovaltask\ncontractsign\nmanagertask\nchanges.\n");
	printf("You can only use the tasks mencioned before, if you use other different the system wont work :D");
	printf("\n Please Type in the type of task: ");
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
	fputs("-------Task--------\n",file);
	fputs(vertice1.ID,file);
	fputs("\n",file);
	fputs(vertice1.description,file);
	fputs("\n",file);
	fputs(vertice1.typeOfTask,file);
	fputs("\n",file);
	fputs(vertice1.time,file);
	fputs("\n",file);
	fputs(vertice1.manager,file);
	fputs("\n",file);
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
		printf("Espacios");
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
	//If the start ID is not found end function
	if(aux1==NULL){
		printf("Error: The start ID is not found");
		return NULL;
	}
	//Returns the newEdgeList 
	printf("Sale de la funcion \n");
	return newEdgeList;
}


Edge *  edgeInserter(Vertice *aux1, Vertice * aux2, Edge * newEdgeList){
	//Creation of the auxiliars
	Edge * aux;
	//Assignation of the newEdgeList
	newEdgeList->task=aux2;
	newEdgeList->next=NULL;
	// Validate if the aux1 has an adjacent list
	if(aux1->adjacent==NULL){
		//Adjusting the new adjacent list of aux1
		aux1->adjacent=newEdgeList;
		
	}else{
		aux=aux1->adjacent;
		//Search for the last element of the adjacent list
		while(aux->next!=NULL){
			aux=aux->next;
		}
		//The new element is add to de adjacent list
		newEdgeList->task=aux2;
		aux->next=newEdgeList;
	}
	return newEdgeList;
	
	
}

void verticePrinter(Vertice * list){
	//Creation of the auxiliars
	Vertice *aux;
	//aux is equal to the list
	aux=list;
	// roam all the list to display the information inside the vertices
	while(aux!=NULL){
		printf("\n The ID of the vertice is %s \n",aux->vertice1.ID);
		
		aux=aux->next;
	}
}


void visualizarGrafo(Vertice * verList, Edge * edgeList){
	//The vertice Auxiliar is equal to the list
    Vertice*aux= verList;
    Edge* ar;
    printf("Nodos\n");
    //roam all the edge list to display the relations
    while(aux!=NULL){
	//Display of the vertice    
	    printf("%s:    ",aux->vertice1.typeOfTask);
	    //Validation of the list of adjacent of the vertice
        if(aux->adjacent!=NULL){
        	//Elements of the list of adjacent
            ar=aux->adjacent;
            while(ar!=NULL){ 
            	//Display of all the elements inside the adjacent list
			    printf("-> %s",ar->task->vertice1.typeOfTask);
                ar=ar->next;
            }
        }
        printf("\n");
        aux=aux->next;
    }
    printf("\n");
}



Vertice * dataTracker(void){
	FILE * file;
	file= fopen("tasks.txt","r");
	Vertice * newVertice=NULL;
	while(feof(file)==0){
		struct vertice vertice1;
		char task[90];
		int numero=1;
		fgets(task,90,file);
		while(numero<6){
			if (numero==1){
				fgets(vertice1.ID,5,file);
				vertice1.ID[strlen(vertice1.ID) - 1] = '\0';
			}
			if(numero==2){
				fgets(vertice1.description,90,file);
				vertice1.description[strlen(vertice1.description) - 1] = '\0';
			}
			if(numero==3){
				fgets(vertice1.typeOfTask,20,file);
				vertice1.typeOfTask[strlen(vertice1.typeOfTask) - 1] = '\0';
			}
			if(numero==4){
				fgets(vertice1.time,20,file);
				vertice1.time[strlen(vertice1.time) - 1] = '\0';
			}
			if(numero==5){
				fgets(vertice1.manager,90,file);
				vertice1.manager[strlen(vertice1.manager) - 1] = '\0';
			}
			numero++;
		}
		newVertice = verticeAddertxt(newVertice,vertice1);
		
		printf("End route succed");
	}
	fclose(file);
	
	return newVertice;
		
}



Vertice * verticeAddertxt(Vertice *list, struct vertice vertice1){
	Vertice * aux;
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