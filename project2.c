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


//Document structure
struct document{
	char ID[10];
	int rute;
	char description[90];
	char type[20];
	int visited;
};
//AVS Structure

typedef struct documents{
	struct document document1;
	struct documents * leftChild;
	struct documents * rightChild;
	struct documents * father;
	
	
	
}Document;

//Vertice Nodo
Vertice{
	struct vertice vertice1;
	struct nodo * next;
	Edge * adjacent;
	Document * documents;
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

//Vertice Modifier
Vertice * verticeModifier(Vertice * list);

//Document Adder
Document * documentAdder(Document * list);

//Document printer
void AVSPrinter(Document * list);
void DocumentPrinter(Document * list);

//Document Modiffier
Document * documentModifier(Document * list, char id[]);

//Document Menu
Document * documentMenu(Document * document);

int main(){
//	Vertice * list =NULL;
//	int num=0;
//	list= verticeAdder(list);
//	list= verticeAdder(list);
//    list= verticeAdder(list);
//    //list= dataTracker();
//    list= verticeModifier(list);
//    list= dataTracker();
//	Edge * edgeList = edgeAdder(NULL,list);
//	edgeList = edgeAdder(edgeList,list);
//	edgeList = edgeAdder(edgeList,list);
//	verticePrinter(list);
//	
//	visualizarGrafo(list, edgeList);

//	Document * 	list=NULL;
//	list=documentAdder(list);
//	list= documentAdder(list);
//	list = documentModifier(list, "123");
//	AVSPrinter(list);
//	DocumentPrinter(list);
	documentMenu(NULL);
	
	
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
		list->documents=NULL;
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
		aux->next->documents=NULL;
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
	//Creation of the variable type FILE
	FILE * file;
	//Open the file in reading mode
	file= fopen("tasks.txt","r");
	//Creation of the variable type vertice
	Vertice * newVertice=NULL;
	//Roam of every line of the file
	while(feof(file)==0){
		//Creation of variables 
		struct vertice vertice1;
		char task[90];
		int numero=1;
		//Get the first line that is innecesary
		fgets(task,90,file);
		//Search of every element for the Data structure
		while(numero<6){
			//ID
			if (numero==1){
				fgets(vertice1.ID,5,file);
				vertice1.ID[strlen(vertice1.ID) - 1] = '\0';
			}
			//Description
			if(numero==2){
				fgets(vertice1.description,90,file);
				vertice1.description[strlen(vertice1.description) - 1] = '\0';
			}
			//Type of task 
			if(numero==3){
				fgets(vertice1.typeOfTask,20,file);
				vertice1.typeOfTask[strlen(vertice1.typeOfTask) - 1] = '\0';
			}
			//Time
			if(numero==4){
				fgets(vertice1.time,20,file);
				vertice1.time[strlen(vertice1.time) - 1] = '\0';
			}
			//Manager
			if(numero==5){
				fgets(vertice1.manager,90,file);
				vertice1.manager[strlen(vertice1.manager) - 1] = '\0';
			}
			numero++;
		}
		//Adder to the list
		newVertice = verticeAddertxt(newVertice,vertice1);
		
	
	}
	//Close of the file when all the insertions are made
	fclose(file);
	
	return newVertice;
		
}



Vertice * verticeAddertxt(Vertice *list, struct vertice vertice1){
	Vertice * aux;
	if(list==NULL){
		//Assignation of the memory
		list=(Vertice*)malloc(sizeof(Vertice));
		//Asignation of the structure
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



Vertice * verticeModifier(Vertice * list){
	//Creation of the variables
	Vertice * aux;
	char id[16];
	//Search the task by ID
	printf("Type in the ID of the task you want to edit: ");
	scanf("%s",&id);
	//Creation of the index to rewrite the txt file
	int index=0;
	aux=list;
	//Roam of all the list 
	while(aux!=NULL){
		//Search for the ID entered
		if(strcmp(aux->vertice1.ID,id)==0){
			//Ask for the new changed descriptions
			printf("\nType in the new Description: ");
			scanf("%s",&aux->vertice1.description);
			printf("\nType in the new manager: ");
			scanf("%s",&aux->vertice1.manager);
			printf("\nType in the new time: ");
			scanf("%s",&aux->vertice1.time);
			printf("\nType in the new type of task: ");
			scanf("%s",&aux->vertice1.typeOfTask);
			
			
		}
	//Save the data in the txt
		FILE *file;
		//If is the first element the txt is rewrited
		if (index==0){
			file=fopen("tasks.txt","w");
		//If is not the first element it just add the element
		}else{
			file=fopen("tasks.txt","a");
		}
		//Verification of the Conecction with the file
		if(file==NULL){
			printf("Connection Error: Impossible to connect to the txt \n ");
			return list;
		}
		//Add the elements
		fputs("-------Task--------\n",file);
		fputs(aux->vertice1.ID,file);
		fputs("\n",file);
		fputs(aux->vertice1.description,file);
		fputs("\n",file);
		fputs(aux->vertice1.typeOfTask,file);
		fputs("\n",file);
		fputs(aux->vertice1.time,file);
		fputs("\n",file);
		fputs(aux->vertice1.manager,file);
		fputs("\n",file);
		fclose(file);
		aux=aux->next;
		index++;
	}
	
	return list;
	
	
}



//AVS FUNCTIONS


Document * documentAdder(Document * list){
	//Creation of the varibles
	Document *aux,* father;
	struct document document1;
	printf("\n Type in the ID of the Document: ");
	scanf("%s",&document1.ID);
	printf("\n Enter the route of the Document: ");
	scanf("%d",&document1.rute);
	printf("\n Enter the description of the Document: ");
	scanf("%s",&document1.description);
	printf("\n Type in the type of the Document");
	scanf("%s",&document1.type);
	
	
	FILE * file;
	file = fopen("documents.txt","a");
	if(file==NULL){
		printf("\n Connection Error: Impossible to connect to the txt \n ");
		return list;
	}
	fputs("-------Document--------\n",file);
	fputs(document1.ID,file);
	fputs("\n",file);
	char rute[10];
	sprintf(rute, "%d", document1.rute);
	fputs(rute,file);
	fputs("\n",file);
	fputs(document1.description,file);
	fputs("\n",file);
	fputs(document1.type,file);
	fputs("\n",file);
	fclose(file);
	
	if (list==NULL){
		list= (Document*)malloc(sizeof(Document));
		list->document1=document1;
		list->leftChild=NULL;
		list->rightChild=NULL;
		list->father=NULL;
		list->document1.visited=0;
	}else{
		aux=list;
		int numero;
		while(aux->leftChild!=NULL&& aux->rightChild!=NULL){

			if(aux->document1.rute>document1.rute){
				aux=aux->leftChild;
				numero=0;
				printf("Es menor ");
			}else{
				aux=aux->rightChild;
				numero=1;
				printf("Es mayor");
			}
		}
		if(numero==0){
			aux->leftChild=(Document*)malloc(sizeof(Document));
			aux->leftChild->document1=document1;
			aux->leftChild->leftChild=NULL;
			aux->leftChild->rightChild=NULL;
			aux->rightChild=NULL;
			aux->leftChild->father=aux;
			aux->leftChild->document1.visited=0;
		}
		if(numero==1){
			aux->rightChild=(Document*)malloc(sizeof(Document));
			aux->rightChild->document1=document1;
			aux->rightChild->leftChild=NULL;
			aux->rightChild->rightChild=NULL;
			aux->leftChild=NULL;
			aux->rightChild->father=aux;
			aux->rightChild->document1.visited=0;
		}
		
		
	}
	
	
	return list;
	
}


void AVSPrinter(Document * list){
    if (list != NULL) {
        AVSPrinter(list->leftChild);
        printf("-------------------\n");
		printf("Welcome to the printer of trees\n");
		printf("ID of the document: %s \n",list->document1.ID);
		printf("ID of the father: %s \n",list->father->document1.ID);
		printf("ID of the right Child: %s \n",list->rightChild->document1.ID);
		printf("ID of the left child: %s \n",list->leftChild->document1.ID);
		printf("-------------------\n");
        AVSPrinter(list->rightChild);
    }
}


void DocumentPrinter(Document * list){
	    if (list != NULL) {
	        DocumentPrinter(list->leftChild);
	        printf("-------------------\n");
			printf("Welcome to the printer of documents \n");
			printf("ID of the document: %s \n",list->document1.ID);
			printf("Description of the document: %s \n",list->document1.description);
			printf("Rute of the document: %d \n",list->document1.rute);
			printf("Type of the documented: %s \n",list->document1.type);
			printf("-------------------\n");
	        DocumentPrinter(list->rightChild);
    }
	
}


	

Document * documentInserter(Document * list, struct document document1){
	Document* aux;
	if (list==NULL){
		list= (Document*)malloc(sizeof(Document));
		list->document1=document1;
		list->leftChild=NULL;
		list->rightChild=NULL;
		list->father=NULL;
	}else{
		aux=list;
		int numero;
		while(aux->leftChild!=NULL&& aux->rightChild!=NULL){

			if(aux->document1.rute>document1.rute){
				aux=aux->leftChild;
				numero=0;
				printf("Es menor ");
			}else{
				aux=aux->rightChild;
				numero=1;
				printf("Es mayor");
			}
		}
		if(numero==0){
			aux->leftChild=(Document*)malloc(sizeof(Document));
			aux->leftChild->document1=document1;
			aux->leftChild->leftChild=NULL;
			aux->leftChild->rightChild=NULL;
			aux->rightChild=NULL;
			aux->leftChild->father=aux;
		}
		if(numero==1){
			aux->rightChild=(Document*)malloc(sizeof(Document));
			aux->rightChild->document1=document1;
			aux->rightChild->leftChild=NULL;
			aux->rightChild->rightChild=NULL;
			aux->leftChild=NULL;
			aux->rightChild->father=aux;
			
		}
		
	return list;

}
}

Document * documentModifier(Document * list, char id[]){
		
	    if (list != NULL) {
	        documentModifier(list->leftChild,id);
	        documentModifier(list->rightChild,id);
		     if(strcmp(list->document1.ID,id)==0){
				printf("---------------\n");
				printf("Welcome to the modifier of Documents \n");
				printf("You are about to modifie the Document with ID: %s \n",id);
				printf("\n Type in the new Description: ");
				scanf("%s",&list->document1.description);
				printf("\n Type in the new route: ");
				scanf("%d",&list->document1.rute);
				printf("\n Type in the new type: ");
				scanf("%s",&list->document1.type);
				printf("---------------\n");
				
			}
			
		if(list->father==NULL){
			return list;
		}
	        
    }
}

void documentModifierTXT(Document * list,int value){
	if(list!=NULL){
		FILE * file;
		if(value==0){
			file = fopen("documents.txt","w");
		}else{
			file=fopen("documents.txt","a");
		}
		fputs("-------Document--------\n",file);
		fputs(list->document1.ID,file);
		fputs("\n",file);
		char rute[10];
		sprintf(rute, "%d", list->document1.rute);
		fputs(rute,file);
		fputs("\n",file);
		fputs(list->document1.description,file);
		fputs("\n",file);
		fputs(list->document1.type,file);
		fputs("\n",file);
		fclose(file);
		documentModifierTXT(list->leftChild,value++);
		documentModifierTXT(list->leftChild,value++);
	}
}


Document * documentTracker(void){
	FILE * file;
	//Open the file in reading mode
	file= fopen("documents.txt","r");
	//Creation of the variable type vertice
	Document * newDocument=NULL;
	//Roam of every line of the file
	while(feof(file)==0){
		//Creation of variables 
		struct document document1;
		char document[90];
		int numero=1;
		//Get the first line that is innecesary
		fgets(document,90,file);
		//Search of every element for the Data structure
		while(numero<4){
			//ID
			if (numero==1){
				fgets(document1.ID,10,file);
				document1.ID[strlen(document1.ID) - 1] = '\0';
			}
			//Description
			if(numero==2){
				char rute[10];
				
				fgets(rute,10,file);
				document1.rute=atoi(rute);
			}
			if(numero==3){
				fgets(document1.description,90,file);
				document1.description[strlen(document1.description) - 1] = '\0';
			}
			//Type of task 
			if(numero==4){
				fgets(document1.type,20,file);
				document1.type[strlen(document1.type) - 1] = '\0';
			}
			numero++;
		}
		//Adder to the list
		newDocument = documentInserter(newDocument,document1);
		
	
	}
	//Close of the file when all the insertions are made
	fclose(file);
	
	return newDocument;
		
}
	

Document * documentMenu(Document * document){
	printf("-------------------------\n ");
	printf("Welcome to the Document System\n");
	printf("-------------------------\n ");
	int numero=0;
	while(numero==0){
		int value;
		printf("If you had a problema and need to restore the document data please type in 1 \n");
		printf("If you want to add new documents to the existing documents, please type in 2 \n");
		printf("If you want to modifie any existing documents, please type in 3 \n");
		printf("If you want to show all the existing documents please type in 4 \n");
		printf("If you want to exit please type in 5: ");
		scanf("%d",&value);
		if(value==1){
			printf("-------------------------\n ");
			printf("Welcome to the Tracker System");
			document= documentTracker();
			if(document==NULL){
				printf("\n Error: The Document is empty try adding some documents ");
			}
			printf("-------------------------\n ");
		}
		if(value==2){
			printf("-------------------------\n ");
			document= documentAdder(document);
			printf("-------------------------\n ");
		}
		if(value==3){
			char ID[10];
			printf("-------------------------\n ");
			printf("Please type in the ID of the Document you want to modifie: ");
			scanf("%s",&ID);
			printf("-------------------------\n ");
			document= documentModifier(document, ID);
			documentModifierTXT(document,0);
		}
		if(value==4){
			printf("-------------------------\n ");
			printf("Welcome to the Document Printer \n");
			DocumentPrinter(document);
			printf("-------------------------\n ");
			
			printf("\n -------------------------\n ");
			printf("Welcome to the AVS printer of the documents\n");
			AVSPrinter(document);
			printf("-------------------------\n ");
			
		}
		
		if(value==5){
			break;
		}
	}
	return document;
	
}
