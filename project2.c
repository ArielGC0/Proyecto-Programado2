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
	int effort;
	
};


//Document structure
struct document{
	char ID[10];
	int rute;
	char description[90];
	char type[20];
	
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
	
	struct edge * next;
	
};

//typedef struct graph2{
//	
//	int effort;
//	char time[15];
//	char typeTask[20];
//	struct graph2 * next;
//}Graph;

//Resource structure
struct resources{
	char ID[10];
	char name[10];
	char type[10];
	char capacity[10];
	char cantity[10];
	char manager[10];
	
};
//Asset data structura
typedef struct assets{
	struct resources resources1;
	struct assets * next;
}Assets;
//WBS Structure
typedef struct WBS{
	struct vertice vertice1;
	struct WBS * right;
	struct WBS * left;
	
}WBS;
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

//Graph Menu
Edge * graphMenu(Vertice * vertList, Edge * edgeList);

//Data Tracker;
Vertice * dataTracker(void);

//Vertice Modifier
Vertice * verticeModifier(Vertice * list);

//Document Adder
Document * documentAdder(Document * list);
Document *nuevoNodo(struct document document1);

//Document printer
void AVSPrinter(Document * list);
void DocumentPrinter(Document * list);

//Document Modiffier
Document * documentModifier(Document * list, char id[]);

//Document Menu
Document * documentMenu(Document * document);

//WorkFlowCreator 
int GraphCreator(Vertice * verList);


//WBS Creator
WBS * WBSCreator(WBS * list,struct vertice vertice1);
//Minimum Expansion Tree
int MinimumExpansionTree(Vertice * vertList);
//WBS Printer
void WBSPrinter(WBS * list);
//Dikstra
int Dijkstra(Vertice *list);
//lenght function
int len(Vertice * list);
//search for the lower element
Vertice * lowerElement(Vertice * vertList);
//asset tracker
Assets * assetTracker(void);
//asset printer
void assetPrinter(Assets * list);
//asset adder
Assets * assetsAdder(Assets * list,struct resources resources1);
//main menu of functions
void mainMenu(void);
int main(){
	mainMenu();
	
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
	printf(" operativetask\n approvaltask\n contractsign\n managertask\n changes.\n");
	printf("You can only use the tasks mencioned before, if you use other different the system wont work :D");
	printf("\n Please Type in the type of task: ");
	scanf(" %s",&vertice1.typeOfTask);
	printf("Type in the time ");
	scanf(" %s",&vertice1.time);
	printf("Type in the manager");
	scanf("%s",&vertice1.manager);
	printf("Type in the effort: ");
	scanf("%d",&vertice1.effort);
	
	//Save the data in the txt
	FILE *file;
	file=fopen("tasks.txt","a");
	if(file==NULL){
		printf("Connection Error: Impossible to connect to the txt \n ");
		return list;
	}
	fputs("\n-------Task--------\n",file);
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
	char effort[10];
	//Convertion of a int to char 
	sprintf(effort,"%d", vertice1.effort);
	fputs(effort,file);
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
		//Get the first line that is innecesary
		fgets(task,90,file);
		//Search of every element for the Data structure
		
		//ID
		fgets(vertice1.ID,5,file);
		vertice1.ID[strlen(vertice1.ID) - 1] = '\0';
		//Description
			
		fgets(vertice1.description,90,file);
		vertice1.description[strlen(vertice1.description) - 1] = '\0';
		
		//Type of task
		fgets(vertice1.typeOfTask,20,file);
		vertice1.typeOfTask[strlen(vertice1.typeOfTask) - 1] = '\0';
		
			
		//TIME
		fgets(vertice1.time,20,file);
		vertice1.time[strlen(vertice1.time) - 1] = '\0';
		
		//Manager
			
		fgets(vertice1.manager,90,file);
		vertice1.manager[strlen(vertice1.manager) - 1] = '\0';
		//EFFORT
		char effort[10];
		fgets(effort,10,file);
		vertice1.effort=atoi(effort);
		
			
		
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




//GRAPH MENU

Edge * graphMenu(Vertice * vertList, Edge * edgeList){
	//Prints
	printf("\n----------------------------\n");
	printf("Welcome to the Graph System");
	printf("\n----------------------------\n");
	//Number for the while
	int number=0;
	// Creation of the bucle for the menu
	while(number==0){
		int option;
		//Options validation
		printf("\n If you want to add a new Vertice please type in 1 ");
		printf("\n If you want to modifie an existing vertice please type in 2 ");
		printf("\n If you want to Assign the Edges type in 3");
		printf("\n If you had a problem and need to restore the data please type in 4");
		printf("\n If you want to print the Graph type in 5");
		printf("\n If you want to create a Workflow please type in 6");
		printf("\n If you want to see the WBS of the graph type in 7");
		printf("\n If you want to see the fastest rute type in 8");
		printf("\n If you want to exit type in 9 \n");
		//Get the data
		scanf("%d",&option);
		//Validation of options
		if(option==1){
			//call vertice adder
			vertList=verticeAdder(vertList);
		}
		if(option==2){
			// call of vertice modifier
			vertList=verticeModifier(vertList);
		}
		if(option==3){
			//call of edge adder
			edgeList=edgeAdder(edgeList,vertList);
		}
		if(option==4){
			//Getting the data back
			//call the data tracker
			vertList= dataTracker();
			printf("\n Data restore! \n");
		}
		if(option==5){
			//call the vertice printer
			verticePrinter(vertList);
			//call the graphPrinter
			visualizarGrafo(vertList,edgeList);
		}
		if(option==6){
			//call the graph creator
			GraphCreator(vertList);
		}
		if(option==7){
			//Call the minimum expansion tree
			MinimumExpansionTree(vertList);
		
		}
		if(option==8){
			//Call the dijkstra
			Dijkstra(vertList);
		}
		if(option==9){
			//Exit the function
			break;
		}
	}
	
	
	return edgeList;
}





//AVS FUNCTIONS


Document * documentAdder(Document * list){
	//Creation of the varibles
	Document *aux,* father;
	struct document document1;
	//Getting the neccesary data for the structure
	printf("\n Type in the ID of the Document: ");
	scanf("%s",&document1.ID);
	printf("\n Enter the route of the Document: ");
	scanf("%d",&document1.rute);
	printf("\n Enter the description of the Document: ");
	scanf("%s",&document1.description);
	printf("\n Type in the type of the Document");
	scanf("%s",&document1.type);
	
	//Creating the file of the librarie FILE
	FILE * file;
	//Openin the txt 
	file = fopen("documents.txt","a");
	
	//File validation
	if(file==NULL){
		printf("\n Connection Error: Impossible to connect to the txt \n ");
		return list;
	}
	//Entering the elements in the file
	fputs("\n-------Document--------\n",file);
	fputs(document1.ID,file);
	fputs("\n",file);
	//Creation of a char variable
	char rute[10];
	//Convertion of a int to char 
	sprintf(rute, "%d", document1.rute);
	fputs(rute,file);
	fputs("\n",file);
	//Putting the rest of elements in the file
	fputs(document1.description,file);
	fputs("\n",file);
	fputs(document1.type,file);
	//fputs("\n",file);
	fclose(file);
	
	//Validating if the list is empty
	if (list==NULL){
		printf("ENTERS THE IF");
		// Assignation of memory
		list= (Document*)malloc(sizeof(Document));
		//assignation of the structure in the data structure
		list->document1=document1;
		//Assignation of the Left, right and father Nodos
		list->leftChild=NULL;
		list->rightChild=NULL;
		list->father=NULL;
	//if the list is not empty
	}else{
		//The auxiliar is going to roam the list
		aux=list;
		printf("ENTERS THE ELSE");
		//Variable to make a validation later 
		int numero;
		//Checking if the rightChild and the left Child next one are NULL to stop the cycle
		
		while(aux->leftChild!=NULL&& aux->rightChild!=NULL){
			//validation of size of the rute to make the tree
			//Smaller left
			if(aux->document1.rute>document1.rute){
				numero=0;
				if(aux->leftChild==NULL)break;
				aux=aux->leftChild;
			//otherwise right
			}else {
				//adding a number
				numero=1;
				if(aux->rightChild==NULL)break;
				aux=aux->rightChild;
			}
			
			
		}
		//validation of the rute
		if(aux->document1.rute>document1.rute){
			numero=0;
			printf("Es menor");
		}else {
			printf("Es mayor");
			numero=1;
		}
		//Validation of the number to see what side is the new element inside of
		if(numero==0){
			//Assignation of memory
			aux->leftChild=(Document*)malloc(sizeof(Document));
			//Assignation of memory
			aux->leftChild->document1=document1;
			//Assignation of the following  left and  right to NULL
			aux->leftChild->leftChild=NULL;
			aux->leftChild->rightChild=NULL; 
			//aux->rightChild=NULL;
			//The Father is assigned to be the auxiliar
			aux->leftChild->father=aux;
			
		}
		if(numero==1){
			//Assignation of memory
			aux->rightChild=(Document*)malloc(sizeof(Document));
			//Assignation of memory
			aux->rightChild->document1=document1;
			//Assignation of the following  left and  right to NULL
			aux->rightChild->leftChild=NULL;
			aux->rightChild->rightChild=NULL;
			//aux->leftChild=NULL;
			//The Father is assigned to be the auxiliar
			aux->rightChild->father=aux;
			
		}
		
		
	}
	
	
	return list;
	
}

Document *nuevoNodo(struct document document1) {
    // Solicitar memoria
    Document  *nodo = (Document *) malloc(sizeof(Document));
    // Asignar el dato e iniciar hojas
    nodo->document1 = document1;
    nodo->leftChild = nodo->rightChild = NULL;
    return nodo;
}



void AVSPrinter(Document * list){
	//Validating if the list is empty
    if (list != NULL) {
    	//Using recursion to see the left childs of the tree
        AVSPrinter(list->leftChild);
        //Series of prints that shows the tree
        printf("-------------------\n");
		printf("Welcome to the printer of trees\n");
		printf("ID of the document: %s \n",list->document1.ID);
		//printf("ID of the father: %s \n",list->father->document1.ID);
		printf("ID of the right Child: %s \n",list->rightChild->document1.ID);
		printf("ID of the left child: %s \n",list->leftChild->document1.ID);
		printf("-------------------\n");
		//Using recursion to see the right childs of the tree
        AVSPrinter(list->rightChild);
    }
}


void DocumentPrinter(Document * list){
	//Validating if the list is empty
	    if (list != NULL) {
	    	//Using recursion to see the left childs of the tree
	        DocumentPrinter(list->leftChild);
	        //Series of prints that shows the tree
	        printf("-------------------\n");
			printf("Welcome to the printer of documents \n");
			printf("ID of the document: %s \n",list->document1.ID);
			printf("Description of the document: %s \n",list->document1.description);
			printf("Rute of the document: %d \n",list->document1.rute);
			printf("Type of the documented: %s \n",list->document1.type);
			//Using recursion to see the right childs of the tree
			printf("-------------------\n");
	        DocumentPrinter(list->rightChild);
    }
	
}


	

Document * documentInserter(Document * list, struct document document1){
	//Creation of variables
	Document* aux;
	//Validating if the list is empty
	//Validating if the list is empty
	if (list==NULL){
		printf("ENTERS THE IF");
		// Assignation of memory
		list= (Document*)malloc(sizeof(Document));
		//assignation of the structure in the data structure
		list->document1=document1;
		//Assignation of the Left, right and father Nodos
		list->leftChild=NULL;
		list->rightChild=NULL;
		list->father=NULL;
	//if the list is not empty
	}else{
		//The auxiliar is going to roam the list
		aux=list;
		printf("ENTERS THE ELSE");
		//Variable to make a validation later 
		int numero;
		//Checking if the rightChild and the left Child next one are NULL to stop the cycle
		
		while(aux->leftChild!=NULL&& aux->rightChild!=NULL){
			//validation of size of the rute to make the tree
			//Smaller left
			printf("The number is %d \n ",aux->document1.rute);
			if(aux->document1.rute>document1.rute){
				numero=0;
				if(aux->leftChild==NULL)break;
				aux=aux->leftChild;
			
			}else {
				numero=1;
				if(aux->rightChild==NULL)break;
				aux=aux->rightChild;
			}
			
			
		}
		if(aux->document1.rute>document1.rute){
			numero=0;
			printf("Es menor");
		}else {
			printf("Es mayor");
			numero=1;
		}
		//Validation of the number to see what side is the new element inside of
		if(numero==0){
			//Assignation of memory
			aux->leftChild=(Document*)malloc(sizeof(Document));
			//Assignation of memory
			aux->leftChild->document1=document1;
			//Assignation of the following  left and  right to NULL
			aux->leftChild->leftChild=NULL;
			aux->leftChild->rightChild=NULL; 
			//aux->rightChild=NULL;
			//The Father is assigned to be the auxiliar
			aux->leftChild->father=aux;
			
		}
		if(numero==1){
			//Assignation of memory
			aux->rightChild=(Document*)malloc(sizeof(Document));
			//Assignation of memory
			aux->rightChild->document1=document1;
			//Assignation of the following  left and  right to NULL
			aux->rightChild->leftChild=NULL;
			aux->rightChild->rightChild=NULL;
			//aux->leftChild=NULL;
			//The Father is assigned to be the auxiliar
			aux->rightChild->father=aux;
			
		}
		
		
	}
	
	
	return list;
	
}


Document * documentModifier(Document * list, char id[]){
		
	    if (list != NULL) {
	    	//Recursive call 
	        documentModifier(list->leftChild,id);
	        documentModifier(list->rightChild,id);
	        //Checking if the list is null
		     if(strcmp(list->document1.ID,id)==0){
		     	//displaying of information
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
		//validation if the father is null 	
		if(list->father==NULL){
			return list;
		}
	        
    }
}

void documentModifierTXT(Document * list,int value){
	//validation if the list is not null
	if(list!=NULL){
		//type FILE
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
	file = fopen("documents.txt","r");
	Document * newDocument=NULL;
	
	while (!feof(file)){
		struct document document1;
		char document[90];
		int numero=1;
		fgets(document,90,file);
		fgets(document1.ID,10,file);
		char rute[10];
		fgets(rute,10,file);
		document1.rute=atoi(rute);
		fgets(document1.description,90,file);
		fgets(document1.type,90,file);
		
		newDocument = documentInserter(newDocument,document1);
		if(newDocument!=NULL)printf("SUCCESS");
			
	}
	fclose(file);
	return newDocument;
}
//Document * documentTracker(void){
//	FILE * file;
//	//Open the file in reading mode
//	file= fopen("documents.txt","r");
//	//Creation of the variable type vertice
//	Document * newDocument=NULL;
//	//Roam of every line of the file
//	while(feof(file)==0){
//		//Creation of variables 
//		struct document document1;
//		char document[90];
//		int numero=1;
//		//Get the first line that is innecesary
//		fgets(document,90,file);
//		//Search of every element for the Data structure
//
//		while(numero<5){
//			//ID
//			if (numero==1){
//				fgets(document1.ID,10,file);
//				document1.ID[strlen(document1.ID) - 1] = '\0';
//				
//			}
//			//Description
//			if(numero==2){
//				char rute[10];
//				
//				fgets(rute,10,file);
//				
//				document1.rute=atoi(rute);
//			}
//			if(numero==3){
//				fgets(document1.description,90,file);
//				document1.description[strlen(document1.description) - 1] = '\0';
//			}
//			//Type of task 
//			if(numero==4){
//				fgets(document1.type,20,file);
//				document1.type[strlen(document1.type) - 1] = '\0';
//			}
//			numero++;
//		}
//		//Adder to the list
//		newDocument = documentInserter(newDocument,document1);
//		
//	
//	}
//	//Close of the file when all the insertions are made
//	fclose(file);
//	
//	
//	
//	return newDocument;
//		
//}
	

Document * documentMenu(Document * document){
	//Prints of the system
	printf("-------------------------\n ");
	printf("Welcome to the Document System\n");
	printf("-------------------------\n ");
	//int variable
	int numero=0;
	while(numero==0){
		//int variable
		int value;
		//prints that shows the user what it can do 
		printf("If you had a problema and need to restore the document data please type in 1 \n");
		printf("If you want to add new documents to the existing documents, please type in 2 \n");
		printf("If you want to modifie any existing documents, please type in 3 \n");
		printf("If you want to show all the existing documents please type in 4 \n");
		printf("If you want to exit please type in 5: ");
		//Recolection of the data
		scanf("%d",&value);
		//validating the opcion 1 track the documents from txt file
		if(value==1){
			//prints 
			printf("-------------------------\n ");
			printf("Welcome to the Tracker System");
			//Calling the function document tracker
			document= documentTracker();
			//Validating the status of the documents
			if(document==NULL){
				printf("\n Error: The Document is empty try adding some documents ");
			}
			printf("-------------------------\n ");
		}
		//Validating second option add a document
		if(value==2){
			printf("-------------------------\n ");
			//Calling the function documentAdder
			document= documentAdder(document);
			printf("-------------------------\n ");
		}
		//Validation option 3 Modificate a document
		if(value==3){
			//Variables
			char ID[10];
			//Getting the ID for the modifications
			printf("-------------------------\n ");
			printf("Please type in the ID of the Document you want to modifie: ");
			scanf("%s",&ID);
			printf("-------------------------\n ");
			//caling the DocumentModifier
			document= documentModifier(document, ID);
			//Calling the documentModifierTXT
			documentModifierTXT(document,0);
			//document= documentTracker();
		}
		//Validation the option 4 The document printer and the tree printer
		if(value==4){
			printf("-------------------------\n ");
			printf("Welcome to the Document Printer \n");
			//Calling the function document printer
			DocumentPrinter(document);
			printf("-------------------------\n ");
			
			printf("\n -------------------------\n ");
			printf("Welcome to the AVS printer of the documents\n");
			//Caling the AVSPrinter 
			AVSPrinter(document);
			printf("-------------------------\n ");
			
		}
		//Validating the 5 option Exiting
		if(value==5){
			//Break the cycle 
			break;
		}
	}
	//return the AVS of documents
	return document;
	
}



//Validation of Requirmenet 3

int GraphCreator(Vertice * verList){
	char type[20];
	printf("\n Welcome to the creator of rutes of work! \n");
	printf("\n Type in  the initial Task:");
	scanf("%s",&type);
	
	Vertice*auxVert= verList;
    Edge* auxEdge;
    //roam all the edge list to display the relations
    int time=0;
    int effort=0;
    while(auxVert!=NULL){
		if(strcmp(auxVert->vertice1.typeOfTask,type)==0)  {
			char endTask[20];
			printf("\n Type in  the end Task:");
			scanf("%s",&endTask);
			
			printf("|%s|",auxVert->vertice1.typeOfTask);
			printf("|Time: %s|",auxVert->vertice1.time);
			time = time + atoi(auxVert->vertice1.time);
			printf("|Effort: %d| ",auxVert->vertice1.effort);
			effort= effort+ auxVert->vertice1.effort;
			
			
			
			if(auxVert->adjacent!=NULL){
        	//Elements of the list of adjacent
	            auxEdge=auxVert->adjacent;
	            while(auxEdge!=NULL){ 
	            	printf("-> |%s|",auxEdge->task->vertice1.typeOfTask);
				    printf("|Time: %s|",auxEdge->task->vertice1.time);
				    time = time + atoi(auxEdge->task->vertice1.time);
				    printf("|Effort: %d| ",auxEdge->task->vertice1.effort);
				    effort= effort+ auxEdge->task->vertice1.effort;
	                
	            	if(strcmp(auxEdge->task->vertice1.typeOfTask,endTask)==0){
	            		printf("\n The total time to complete the workflow is: %d \n",time);
	            		printf("\n The total effort to complete the workflow is: %d \n", effort);
	            		return 0;
					}
					auxEdge=auxEdge->next;
				    
	            }
        	}else{
        		printf("\n The Graph is not created please add some elements \n ");
        		return 1;
			}
			
			
		}
	    
        
    	auxVert=auxVert->next;
    }
	
	
}


//WBS MINIMUM EXPANSION TREE

WBS * WBSCreator(WBS * list,struct vertice vertice1) {
	WBS *aux;
	if(list==NULL){
		list= (WBS*)malloc(sizeof(WBS));
		list->vertice1=vertice1;
		list->right=NULL;
		list->left=NULL;
	}else{
		if (atoi(vertice1.time) > atoi(list->vertice1.time)) {
        // Tienes espacio a la derecha?
        printf("Time %s",list->vertice1.time);
	        if (list->right == NULL) {
	            list->right = (WBS*)malloc(sizeof(WBS));
				list->right->vertice1=vertice1;
				list->right->right=NULL;
				list->right->left=NULL;
	        } else {
	            
	            WBSCreator(list->right, vertice1);
	        }
		
		}else {
        // Si no, a la izquierda
        if (list->left == NULL) {
        	list->left = (WBS*)malloc(sizeof(WBS));
			list->left->vertice1=vertice1;
			list->left->right=NULL;
			list->left->left=NULL;
            
        } else {
            // Si la izquierda ya está ocupada, recursividad ;)
            WBSCreator(list->left, vertice1);
        }
    }
    
    }
    printf("ENDS FUNCTION");
    return list;
}



int MinimumExpansionTree(Vertice * vertList){
	char id[10];
	printf("\n Type in the ID where it is going to start the expansion tree: ");
	scanf("%s",&id);
	Vertice * aux;
	Edge * auxEdge;
	aux=vertList;
	WBS * tree=NULL;
	while(aux!=NULL){
		if(strcmp(aux->vertice1.ID,id)==0){
			tree=WBSCreator(tree,aux->vertice1);	
		}                                    
		 if(aux->adjacent!=NULL){
				auxEdge = aux->adjacent;
				while(auxEdge!=NULL){
					tree=WBSCreator(tree,auxEdge->task->vertice1);
					auxEdge=auxEdge->next;
				}
				break;
			}else{
				printf("No elements to show");
				return 0;
			}
		aux=aux->next;
	}
	WBSPrinter(tree);
	return 1;
}


void WBSPrinter(WBS * list) {
    if (list != NULL) {
        WBSPrinter(list->left);
        printf("\n --------------WBS--------------- \n");
        printf("%s \n", list->vertice1.typeOfTask);
        printf("%s \n",list->vertice1.time);
        printf("-------%d--------",list->vertice1.effort);
        printf("\n ----------------------------- \n");
        WBSPrinter(list->right);
    }
}

int Dijkstra(Vertice * verList){
	char type[20];
	printf("\n Welcome to the ordenator of work \n");
	printf("\n Type in  the initial Task:");
	scanf("%s",&type);
	
	Vertice*auxVert= verList;
    Edge* auxEdge;
    //roam all the edge list to display the relations

    while(auxVert!=NULL){
		if(strcmp(auxVert->vertice1.typeOfTask,type)==0)  {
			char endTask[20];
			printf("\n Type in  the end Task:");
			scanf("%s",&endTask);
			
			printf("|%s|",auxVert->vertice1.typeOfTask);
			printf("|ID: %s|",auxVert->vertice1.ID);
			printf("|Time: %s|",auxVert->vertice1.time);
			printf("|Effort: %d| ",auxVert->vertice1.effort);
			
			
			
			if(auxVert->adjacent!=NULL){
        	//Elements of the list of adjacent
	            auxEdge=auxVert->adjacent;
	            while(auxEdge!=NULL){ 
	            	printf("-> |%s|",auxEdge->task->vertice1.typeOfTask);
				    printf("|Time: %s|",auxEdge->task->vertice1.time);
				    printf("|ID: %s|",auxEdge->task->vertice1.ID);
				    printf("|Effort: %d| ",auxEdge->task->vertice1.effort);
	                
	            	if(strcmp(auxEdge->task->vertice1.typeOfTask,endTask)==0){
	            		return 0;
					}
					auxEdge=auxEdge->next;
				    
	            }
        	}else{
        		printf("\n The Graph is not created please add some elements \n ");
        		return 1;
			}
			
			
		}
	    
        
    	auxVert=auxVert->next;
    }
	
	
}
Assets * assetsAdder(Assets * list,struct resources resources1){
	Assets * aux;
	aux=list;
	if(list==NULL){
		list=(Assets*)malloc(sizeof(Assets));
		list->resources1=resources1;
		list->next=NULL;
	}else{
		while(aux->next!=NULL){
			aux=aux->next;
		}
		aux->next=(Assets*)malloc(sizeof(Assets));
		aux->next->resources1=resources1;
		aux->next->next=NULL;
	}
	return list;
	
}


Assets * assetCreator(Assets*asset){

	int option=0;
	printf("-----WELCOME TO THE ASSET CREATOR----------\n");
	while(option==0){
		int value;
		printf("Type in 1 if you want to add an asset");
		printf("Type in 2 if you want to exit");
		scanf("%d",&value);
		if(value==1){
			
			struct resources resource1;
			printf("Type in the ID of the resource: ");
			scanf("%s",&resource1.ID);
			
			printf("Type in the name of the resource: ");
			scanf("%s",&resource1.name);
			printf("Type in the type of the resource: ");
			scanf("%s",&resource1.type);
			printf("Type in the capacity of the resource: ");
			scanf("%s",&resource1.capacity);
			printf("Type in the cantity of the resource: ");
			scanf("%s",&resource1.cantity);
			printf("Type in the manager of the resource: ");
			scanf("%s",&resource1.manager);
			
			FILE * file;
			file = fopen("assets.txt","a");
			fputs("\n-------ASSETS------ \n",file);
			fputs(resource1.ID,file);
			fputs("\n",file);
			fputs(resource1.name,file);
			fputs("\n",file);
			fputs(resource1.type,file);
			fputs("\n",file);
			fputs(resource1.capacity,file);
			fputs("\n",file);
			fputs(resource1.cantity,file);
			fputs("\n",file);
			fputs(resource1.manager,file);
			fclose(file);
			
			asset =assetsAdder(asset, resource1);
		}
		if(value==2){
			break;
		}
		
	}
	
	
	return asset;
	
}


void assetPrinter(Assets * list){
	Assets * aux;
	aux=list;
	while(aux!=NULL){
		printf("-----------------------------------");
		printf("\n ID:%s",aux->resources1.ID);
		printf("\n Name:%s",aux->resources1.name);
		printf("\n Type:%s",aux->resources1.type);
		printf("\n Capacity:%s",aux->resources1.capacity);
		printf("\n Cantity:%s",aux->resources1.cantity);
		printf("\n Manager:%s",aux->resources1.manager);
		printf("-----------------------------------");
		aux=aux->next;
	}
}


Assets * assetTracker(void){
	
	FILE * file;
	file = fopen("assets.txt","r");
	Assets* asset=NULL;
	
	while (!feof(file)){
		struct resources asset1;
		char line1[10];
		int numero=1;
		fgets(line1,10,file);
		fgets(asset1.ID,10,file);
		fgets(asset1.name,10,file);
		fgets(asset1.type,10,file);
		fgets(asset1.capacity,10,file);
		fgets(asset1.cantity,10,file);
		fgets(asset1.manager,10,file);
		
		
		asset = assetsAdder(asset,asset1);
			
	}
	fclose(file);
	return asset;
	
}



void mainMenu(void){
	printf("-------------- Welcome to the Work system-------------\n");
	int option=0;
	while(option==0){
		int value;
		printf("\n Type in 1 to enter the Graph menu ");
		printf("\n To enter the Document menu type in 2");
		printf("\n Type in 3 to enter the resource menu");
		printf("\n If you want to exit type in 4");
		scanf("%d",&value);
		if(value==1){
			graphMenu(NULL,NULL);
		}
		if(value==2){
			documentMenu(NULL);
		}
		if(value==3){
			Assets * asset =NULL;
			printf("If you lost the information type in 1");
			scanf("%d",&value);
			if(value==1){
				asset=assetTracker();
			}
			asset =assetCreator(asset);
			assetPrinter(asset);
			
		}
		if(value==4){
			break;
		}
	}
	
	
		
}
