
//Libraries
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include <windows.h>

#define Vertice struct nodo
#define Edge struct edge

//graphic interface

//items declaration
#define ID_lbTitulo 1001
#define ID_btnStart 1011


LRESULT CALLBACK ProcedimientoVentana(HWND hwnd,UINT msg, WPARAM wParam,LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstanciaActual,HINSTANCE hInstanciaPrevia,LPSTR lpCmdLinea,int nCmdShow){
    HWND ventana; //window manage
    MSG mensaje; //intermediary for communicating application messages     WNDCLASSEX clase;
    WNDCLASSEX clase; //structure that contains a set of elements that characterize a window.
    clase.cbSize = sizeof(WNDCLASSEX); //class size is equal to structure size    clase.cbClsExtra = 0;
    clase.cbClsExtra = 0; //The number of additional bytes to allocate (The system initializes the bytes to zero.)
    clase.style = CS_HREDRAW | CS_VREDRAW;  //can be drawn horizontally and vertically
    clase.lpfnWndProc = ProcedimientoVentana;
    /* lpfnWndProc:
    It is responsible for everything related to the appearance and behavior of a window.
    Pointer to a function of this type, that function is the one that will be in charge of processing all messages for that window type.
    all the messages for that window class. When we register our window class
    window, we will have to assign to that member the pointer to our window procedure.*/
    clase.hInstance = hInstanciaActual;
    clase.hIcon = LoadIcon(NULL,0);//Icon Identifier
    clase.hIconSm =LoadIcon(NULL,IDI_INFORMATION);//choose the item
    clase.hCursor = LoadCursor(NULL,IDC_ARROW);// cursor identification
    clase.lpszClassName = "windowIdentficator"; //identifier to CreateWindowsEx();
    //clase.hbrBackground = CreateSolidBrush( RGB(21,232,189));
    if(!RegisterClassEx(&clase)){ // if the class is not registered
        MessageBox( NULL,"Error","Error",MB_ICONERROR);
        return EXIT_FAILURE;
    }
    //WS_OVERLAPPED|WS_MINIMIZEBOX|WS_SYSMENU (without this the window will maximize)
    ventana = CreateWindowEx(0,"windowIdentficator","Project manager system",WS_OVERLAPPEDWINDOW |WS_SYSMENU,
                             400,200,400,200,HWND_DESKTOP,NULL,hInstanciaActual,NULL);
		// iteams creations
		
	
	CreateWindow("STATIC","Project manager system", WS_VISIBLE | WS_CHILD | SS_CENTER,120,30,120,30,ventana,(HMENU)ID_lbTitulo,hInstanciaActual,NULL);	
	CreateWindow("STATIC","  start", WS_VISIBLE | WS_CHILD | SS_NOTIFY,120,100,120,30,ventana,(HMENU)ID_btnStart, hInstanciaActual, NULL);
	
	
	
    ShowWindow(ventana, nCmdShow); // show the window
    UpdateWindow(ventana);//update the window
    //We make this cicle to be sure about the info its getting to the user, if it is 0 it means the program its over.
    while(GetMessage(&mensaje,NULL,0,0)>0){
            TranslateMessage(&mensaje);
            DispatchMessage(&mensaje);
    }

}

void mainMenu(void);

LRESULT CALLBACK ProcedimientoVentana(HWND hwnd,UINT msg, WPARAM wParam,LPARAM lParam){
 static HINSTANCE Instancia; // It does not destroy because it´s static

    switch(msg){
                case WM_CREATE:{
                          Instancia =((LPCREATESTRUCT)lParam)->hInstance; //cassting to covert the struct to info that could be put in the window.
                          break;
                }
                case WM_COMMAND:{
                	switch (LOWORD(wParam)){
						case ID_btnStart:{
								mainMenu();
							}
						}
							break;
			
				}
                case WM_DESTROY:{
                PostQuitMessage(0); // This 0 goes into the while to make it stop
                break;
                }
                default:{
                return DefWindowProc(hwnd, msg,wParam,lParam);
                }

    }
    return 0;
}

// Project manager


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
		printf("\n 1. Add a new vertice ");
		printf("\n 2. modify an existing vertice ");
		printf("\n 3. Assign the Edges");
		printf("\n 4. Restore the data");
		printf("\n 5. Print the Graph");
		printf("\n 6. Create a Workflow");
		printf("\n 7. See the WBS of the graph ");
		printf("\n 8. See the fastest rute ");
		printf("\n 9. Exit \n");
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
			printf("It´s lower");
		}else {
			printf("It´s higher");
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
			printf("Type of the document: %s \n",list->document1.type);
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
			printf("It´s lower");
		}else {
			printf("It´s higher");
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
				printf("You are about to modify the Document with ID: %s \n",id);
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
		//Validating of the type of opening of the file
		if(value==0){
			//Open write
			file = fopen("documents.txt","w");
		}else{
			//open append
			file=fopen("documents.txt","a");
		}
		//adding the elements
		fputs("-------Document--------\n",file);
		fputs(list->document1.ID,file);
		fputs("\n",file);
		//Creating of variable rute type char
		char rute[10];
		//Transforming int to char
		sprintf(rute, "%d", list->document1.rute);
		//Adding the elements
		fputs(rute,file);
		fputs("\n",file);
		fputs(list->document1.description,file);
		fputs("\n",file);
		fputs(list->document1.type,file);
		fputs("\n",file);
		//Close file
		fclose(file);
		//Using recursion to continue saving
		documentModifierTXT(list->leftChild,value++);
		documentModifierTXT(list->leftChild,value++);
	}
}

Document * documentTracker(void){
	//Variable tye FILE
	FILE * file;
	//Getting the file documents
	file = fopen("documents.txt","r");
	//Variable Document type Document
	Document * newDocument=NULL;
	//Roam all the lines of the file
	while (!feof(file)){
		//Creation of the structure document
		struct document document1;
		//Creation of extra variables
		char document[90];
		int numero=1;
		//Getting the first line
		fgets(document,90,file);
		//getting the rest of the document
		fgets(document1.ID,10,file);
		//Creating a variable type char
		char rute[10];
		fgets(rute,10,file);
		//Inserting into the structure the variable transformed to int
		document1.rute=atoi(rute);
		fgets(document1.description,90,file);
		fgets(document1.type,90,file);
		//Insert the structure into the document data structure
		newDocument = documentInserter(newDocument,document1);
		//Validating the if the data structure is not NULL
		if(newDocument!=NULL)printf("SUCCESS");
			
	}
	//Closing the file
	fclose(file);
	return newDocument;
}

	

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
		printf("1. Restore the document \n");
		printf("2. Add new document \n");
		printf("3. Modify document \n");
		printf("4. Show all existing documents \n");
		printf("5. Exit ");
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
			printf("Please type in the ID of the Document you want to modify: ");
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



//Validation of Requirement 3

int GraphCreator(Vertice * verList){
	//Creationg of variables to work on
	char type[20];
	//Prints
	printf("\n Welcome to the rutes of work creator ! \n");
	printf("\n Type in  the initial Task:");
	//Getting the type of task
	scanf("%s",&type);
	//Vertice and Edge  type Variables
	Vertice*auxVert= verList;
    Edge* auxEdge;
    //Int variables
    int time=0;
    int effort=0;
    //Roaming all the list of verts
    while(auxVert!=NULL){
    	//Search fot the element that is equal to the type mencioned before
		if(strcmp(auxVert->vertice1.typeOfTask,type)==0)  {
			//Creation of a char variable
			char endTask[20];
			//getting the end task
			printf("\n Type in  the end Task:");
			scanf("%s",&endTask);
			//Print the information of the vertice
			printf("|%s|",auxVert->vertice1.typeOfTask);
			printf("|Time: %s|",auxVert->vertice1.time);
			time = time + atoi(auxVert->vertice1.time);
			printf("|Effort: %d| ",auxVert->vertice1.effort);
			effort= effort+ auxVert->vertice1.effort;
			
			
			//Validating if the graph is created
			if(auxVert->adjacent!=NULL){
        	//Elements of the list of adjacent
	            auxEdge=auxVert->adjacent;
	            //Roam the list of ajdacents
	            while(auxEdge!=NULL){ 
	            //Print the information of the elements
	            	printf("-> |%s|",auxEdge->task->vertice1.typeOfTask);
				    printf("|Time: %s|",auxEdge->task->vertice1.time);
				    //Adding to the final time
				    time = time + atoi(auxEdge->task->vertice1.time);
				    printf("|Effort: %d| ",auxEdge->task->vertice1.effort);
				    //Adding to the final effort
				    effort= effort+ auxEdge->task->vertice1.effort;
	                //Validating if the task is the end task
	            	if(strcmp(auxEdge->task->vertice1.typeOfTask,endTask)==0){
	            		//Prints of the final 
	            		printf("\n The total time to complete the workflow is: %d \n",time);
	            		printf("\n The total effort to complete the workflow is: %d \n", effort);
	            		return 0;
					}
					auxEdge=auxEdge->next;
				    
	            }
        	}else{
        		//prints in case the graph is not created
        		printf("\n The Graph is not created please add some elements \n ");
        		return 1;
			}
			
			
		}
	    
        //Next auxiliar
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
            // Si la izquierda ya estÃ¡ ocupada, recursividad ;)
            WBSCreator(list->left, vertice1);
        }
    }
    
    }
    printf("ENDS FUNCTION");
    return list;
}



int MinimumExpansionTree(Vertice * vertList){
	//Creation of char variable
	char id[10];
	//Getting the ID of the initial start ID
	printf("\n Type in the ID where it is going to start the expansion tree: ");
	scanf("%s",&id);
	//Creation of the Edges and vertice variables
	Vertice * aux;
	Edge * auxEdge;
	//asignattion of aux to the vertList
	aux=vertList;
	//Creation of a WBS tree NULL
	WBS * tree=NULL;
	//Roaming all the list
	while(aux!=NULL){
		//Validating if the ID given is equal to the auxiliar
		if(strcmp(aux->vertice1.ID,id)==0){
			//Adding to the tree the element
			tree=WBSCreator(tree,aux->vertice1);	
		}
		//Validating of the list of adjacent of the auxiliar                                    
		 if(aux->adjacent!=NULL){
		 		//Assignation of the AuxEdge to the auxiliar ajdacent list
				auxEdge = aux->adjacent;
				//Roaming of the auxEdge
				while(auxEdge!=NULL){
					//Inserting the elements into the tree
					tree=WBSCreator(tree,auxEdge->task->vertice1);
					auxEdge=auxEdge->next;
				}
				//Break the cycle
				break;
			}else{
				//No elements to show print
				printf("\n Error: No elements to show \n");
				return 0;
			}
		aux=aux->next;
	}
	//Printer of trees call 
	WBSPrinter(tree);
	return 1;
}


void WBSPrinter(WBS * list) {
	//Validating if the list is not null
    if (list != NULL) {
    	//Recursion with the left child
        WBSPrinter(list->left);
        //prints of the elements
        printf("\n --------------W B S--------------- \n");
        printf("%s \n", list->vertice1.typeOfTask);
        printf("%s \n",list->vertice1.time);
        printf("-------%d--------",list->vertice1.effort);
        printf("\n ----------------------------- \n");
        //Recursion with the right child
        WBSPrinter(list->right);
    }
}

int Dijkstra(Vertice * verList){
	char type[20];
	printf("\n Welcome to the ordenator of work (Dijkstra) \n");
	//getting the first task that the user wants
	printf("\n Type in  the first Task:");
	scanf("%s",&type);
	//Creation of the variables
	Vertice*auxVert= verList;
    Edge* auxEdge;
    //roam all the edge list to display the relations

    while(auxVert!=NULL){
    	//Validating if the types are equal
		if(strcmp(auxVert->vertice1.typeOfTask,type)==0)  {
			char endTask[20];
			//adding the las task 
			printf("\n Type in  the last Task:");
			scanf("%s",&endTask);
			//printing the items of the first item
			printf("|%s|",auxVert->vertice1.typeOfTask);
			printf("|ID: %s|",auxVert->vertice1.ID);
			printf("|Time: %s|",auxVert->vertice1.time);
			printf("|Effort: %d| ",auxVert->vertice1.effort);
			
			
			//validating if the graph is created
			if(auxVert->adjacent!=NULL){
        	//Elements of the list of adjacent
	            auxEdge=auxVert->adjacent;
	            //roaming the graph
	            while(auxEdge!=NULL){ 
	            //prints of the items
	            	printf("-> |%s|",auxEdge->task->vertice1.typeOfTask);
				    printf("|Time: %s|",auxEdge->task->vertice1.time);
				    printf("|ID: %s|",auxEdge->task->vertice1.ID);
				    printf("|Effort: %d| ",auxEdge->task->vertice1.effort);
	                //validating when it is the last task
	            	if(strcmp(auxEdge->task->vertice1.typeOfTask,endTask)==0){
	            		return 0;
					}
					auxEdge=auxEdge->next;
				    
	            }
	            //prints in case the graph is not created
        	}else{
        		printf("\n Error: The Graph is not created please add some elements \n ");
        		return 1;
			}
			
			
		}
	    
        
    	auxVert=auxVert->next;
    }
	
	
}
Assets * assetsAdder(Assets * list,struct resources resources1){
	
	//Creation of variables
	Assets * aux;
	//aux is equal to the list
	aux=list;
	//validating if the list is null
	if(list==NULL){
		//adding space in memory
		list=(Assets*)malloc(sizeof(Assets));
		//adding a structure to the data structure
		list->resources1=resources1;
		//Assigning NULL to the next element
		list->next=NULL;
	}else{
		//Roaming of the elements inside the assets list
		while(aux->next!=NULL){
			//aux equal the next one
			aux=aux->next;
		}
		//Adding some space to the next 
		aux->next=(Assets*)malloc(sizeof(Assets));
		//assigning to the next the structure
		aux->next->resources1=resources1;
		//assigning to the next next NULL
		aux->next->next=NULL;
	}
	return list;
	
}


Assets * assetCreator(Assets*asset){
	//Creation of variables
	int option=0;
	//print
	printf("-----WELCOME TO THE ASSET CREATOR----------\n");
	//Validation of the number to create a menu
	while(option==0){
		//Creation of variables
		int value;
		//prints of information
		printf("1. Add an asset");
		printf("2. Exit");
		//Getting the data inside the value
		scanf("%d",&value);
		//Validating the option 1
		if(value==1){
			//Creation of a structure
			struct resources resource1;
			//Getting the data of the structure
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
			//Creation of a variable type FILE
			FILE * file;
			//assigning file to the assests.txt in type append
			file = fopen("assets.txt","a");
			//Adding the data
			fputs("\n------- ASSETS ------ \n",file);
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
			//Closing the file
			fclose(file);
			//adding the data to the data structure
			asset =assetsAdder(asset, resource1);
		}
		//Exit conditon
		if(value==2){
			break;
		}
		
	}
	
	
	return asset;
	
}


void assetPrinter(Assets * list){
	//Creation of variable type Assets
	Assets * aux;
	//Assigning the variable to the list
	aux=list;
	//Roaming all the list 
	while(aux!=NULL){
		//Prints of the elements inside the data structure
		printf("-----------------------------------");
		printf("\n ID:%s",aux->resources1.ID);
		printf("\n Name:%s",aux->resources1.name);
		printf("\n Type:%s",aux->resources1.type);
		printf("\n Capacity:%s",aux->resources1.capacity);
		printf("\n Quantity:%s",aux->resources1.cantity);
		printf("\n Manager:%s",aux->resources1.manager);
		printf("-----------------------------------");
		//Assignign the auxiliar to the next one
		aux=aux->next;
	}
}


Assets * assetTracker(void){
	//Variable type FILE
	FILE * file;
	//Assignation of the file in assets.txt in type read
	file = fopen("assets.txt","r");
	Assets* asset=NULL;
	//roam all the file 
	while (!feof(file)){
		
		//Creation of the structure
		struct resources asset1;
		//Creation of variables
		char line1[10];
		int numero=1;
		//Getting ride of the first line
		fgets(line1,10,file);
		//Getting the data inside the strcuture
		fgets(asset1.ID,10,file);
		fgets(asset1.name,10,file);
		fgets(asset1.type,10,file);
		fgets(asset1.capacity,10,file);
		fgets(asset1.cantity,10,file);
		fgets(asset1.manager,10,file);
		
		//Adding the structure to the data structure
		asset = assetsAdder(asset,asset1);
			
	}
	//Close the file
	fclose(file);
	return asset;
	
}


//Main Menu
void mainMenu(void){
	//Prints
	printf("-------------- welcome to project the  management system-------------\n");
	//Adding a int to form the menu
	int option=0;
	//Cycle to make the menu
	while(option==0){
		//creation of a value to get inside a multiples menus
		int value;
		printf("\n Type the number of the menu that you want to display  ");
		printf("\n 1. Graph menu");
		printf("\n 2. Document menu");
		printf("\n 3. resource menu");
		printf("\n 4. Exit \n");
		//getting the int 
		scanf("%d",&value);
		//validation if it is number 1 
		if(value==1){
			//call the graph menu
			graphMenu(NULL,NULL);
		}
		//validation if it is number 1 
		if(value==2){
			//Calling the document menu 
			documentMenu(NULL);
		}
		//validation if it is number 1 
		if(value==3){
			//Creation of a variable Assets
			Assets * asset =NULL;
			//Calling the Asset tracker if the input is equal to 1 
			printf("1. If you lost the information");
			scanf("%d",&value);
			if(value==1){
				asset=assetTracker();
			}
			//Calling the asset creator and asset printer
			asset =assetCreator(asset);
			assetPrinter(asset);
			
		}
		//Exit Condition 
		if(value==4){
			break;
		}
	}
	
	
		
}
