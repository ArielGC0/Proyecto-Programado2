// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define nodeGraph struct nodeGraph
#define edge struct edge
#define Lista struct pila

nodeGraph{
	char data; 
	nodeGraph* next;
	edge* adyacencia; 
	int visitado,terminado;
	int monto;
	char anterior;
    int egdeNumber;
};

edge{
	nodeGraph*vrt; 
	edge*next;
	int peso;
};

Lista{
	nodeGraph* data;
	Lista*next;
};

nodeGraph*inicio=NULL;
Lista*ini=NULL;
Lista*final=NULL; 

void insertarNodeGraph();
void agregaredge(nodeGraph*aux,nodeGraph*aux2,edge*new);
void insertaredge();
void visualizarGrafo();
void insertarPila(nodeGraph* aux);
nodeGraph*desencolar();
void reiniciar();
void dijkstra();



void printDijkstra(){
    FILE *file,*file2;
    file=fopen("graph.txt","r+");
    char line[2000],line2[2000];
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line,"\n")]=0;
        file2=fopen("tasks.txt","r+");
        while (fgets(line2, sizeof(line2), file2))
        {
            line2[strcspn(line2,"\n")]=0;
            if (strcmp(line,line2)==0)
            {
                fgets(line2, sizeof(line2), file2);
                fgets(line2, sizeof(line2), file2);
                line2[strcspn(line2,"\n")]=0;
                printf("%s ",line2);
            }
            
        }
        printf("\n");
        fclose(file2);
    }
    fclose(file);
}

int graph(){
    int opcion,N,i;
	printf("Type in the number of tasks: ");
    scanf("%i",&N);
    for(i=0;i<N;i++){
    	insertarNodeGraph();
	}
    do{
    	printf("-----------\n");
        printf(" 1. Insert a vertex                 \n");
        printf(" 2. Insert edge                  \n");
        printf(" 3. Dijkstra                         \n");
        printf(" 4. Back                            \n");
        printf("------------\n");
        printf("Choose an option:");
        scanf("%i",&opcion);
        switch(opcion){
            case 1:
                    insertarNodeGraph();
                    break;
            case 2: insertaredge();
                    break;
            case 3: dijkstra();
                    printDijkstra();
			        break;
			case 4: break;
            default: printf("Invalid option\n");
                     break;
        }
        system("pause");
        
    }while(opcion!=5);
    return 1;
}

void insertarNodeGraph(){
    nodeGraph* aux;
	nodeGraph* new=(nodeGraph*)malloc(sizeof(nodeGraph));
	fflush(stdin);
	printf("Insert vertex:");
	scanf("%c",&new->data);
	new->next=NULL;
    new->adyacencia=NULL;
    new->visitado=new->terminado=0;
    new->monto=-1;
    new->anterior=0;
    if(inicio==NULL){
        inicio=new;
    }else{
        aux=inicio;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next=new;
      }
 
 }
void insertaredge(){   
    char ini, fin;
    edge* new=(edge*)malloc(sizeof(edge));
    new->next=NULL;
    nodeGraph* aux;
	nodeGraph* aux2;
    if(inicio==NULL){
         printf("Error: The graph is empty\n");
         return;
    }
    fflush(stdin);
    printf("Type in the first and last node:");
    scanf("%c %c",&ini,&fin);
    printf("Type in the value of the edge:");
    scanf("%i",&new->peso);
    aux=inicio;
    aux2=inicio;
    while(aux2!=NULL){
        if(aux2->data==fin){
            break;
        }
        aux2=aux2->next;
    }
    if(aux2==NULL){
    	printf("Error:vertex doesn't exist\n");
    	return;
	}
    while(aux!=NULL){
        if(aux->data==ini){
            agregaredge(aux,aux2,new);
            return;
        }
        aux = aux->next;
    }
    if(aux==NULL)
    	printf("Error:vertex doesn't exit\n");
}

void agregaredge(nodeGraph* aux,nodeGraph* aux2,edge* new){
    edge* a;
    if(aux->adyacencia==NULL){   
	    aux->adyacencia=new;
        new->vrt=aux2;
    }else{   
	    a=aux->adyacencia;
        while(a->next!=NULL)
            a=a->next;
        new->vrt=aux2;
        a->next=new;
    }
}

void visualizarGrafo(){
    nodeGraph*aux=inicio;
    edge* ar;
    printf("Nodes of the graph\n");
    while(aux!=NULL){   
	    printf("ID:%c:    ",aux->data);
        if(aux->adyacencia!=NULL){
            ar=aux->adyacencia;
            while(ar!=NULL){ 
			    printf(" %c",ar->vrt->data);
                ar=ar->next;
            }
        }
        printf("\n");
        aux=aux->next;
    }
    printf("\n");
}
void insertarPila(nodeGraph* aux){
	Lista*new=(Lista*)malloc(sizeof(Lista));
	new->data=aux;
	new->next=NULL;
	if(ini==NULL){
		ini=new;
		final=new;
	}else{
	   new->next=ini;
	   ini=new;    	
	}
}


nodeGraph*desencolar(){
	Lista*aux;
	if(ini==NULL){
		return NULL;
	}else{
		aux=ini;
		ini=ini->next;
		aux->next=NULL;
		if(ini==NULL)
		final=NULL;
	}
	nodeGraph*resultado=aux->data;
	free(aux);
	return resultado;
}

void reiniciar(){
	if(inicio!=NULL){
		nodeGraph*aux=inicio;
		while(aux!=NULL){
			aux->visitado=aux->terminado=0;
		    aux=aux->next;
		}
	}
}
// function to create a route with dijkstra
void dijkstra(){
    FILE *file;
    file=fopen("graph.txt","w");
	nodeGraph*aux=inicio;
	char a,b;
	fflush(stdin);
	printf("Type in the first and last vertex: ");
	scanf("%c %c",&a,&b);
	while(aux!=NULL){
		if(aux->data==a){
			aux->terminado=1;
			aux->monto=0;
			break;
		}
		aux=aux->next;
	}
	if(aux==NULL){
		printf("The vertex doesn't exist\n");
		return;
	}
	while(aux!=NULL){
		edge*a=aux->adyacencia;
	    while(a!=NULL){
		    if(a->vrt->monto==-1 || (aux->monto+a->peso)<a->vrt->monto){
		    	a->vrt->monto=aux->monto+a->peso;
		        a->vrt->anterior=aux->data;
			}
		    a=a->next;
	    }
	    aux=inicio;
	    nodeGraph*min=inicio;
	    while(min->anterior==0 || min->terminado ==1)
	    min=min->next;
	    while(aux!=NULL){
	    	if(aux->monto<min->monto && aux->terminado==0 && aux->anterior!=0)
	    	min=aux;
	    	aux=aux->next;
		}
		aux=min;
		aux->terminado=1;
		if(aux->data==b)
		break;
	}
	while(aux->anterior!=0){
		insertarPila(aux);
		char temp=aux->anterior;
		aux=inicio;
		while(aux->data!=temp){
		   aux=aux->next;	
		}
	}
	insertarPila(aux);
	while(ini!=NULL){
        fprintf(file,"ID:%c\n",desencolar()->data);
	}
		printf("\n");
	reiniciar();
    fclose(file);
}