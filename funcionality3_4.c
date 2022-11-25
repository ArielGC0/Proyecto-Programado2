// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void recorridos();
void recorridoAnchura();
void insertarCola(nodeGraph* aux);
// Funtion to print the wbs tree
void printWBS(){
    FILE *file,*file2;
    file=fopen("graph2.txt","r");
    char name[40],effort[20],time[25];
    char line[2000],line2[2000];
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line,"\n")]=0;
        file2=fopen("tasks.txt","r");
        while (fgets(line2, sizeof(line2), file2))
        {
            line2[strcspn(line2,"\n")]=0;
            if (strcmp(line2,line)==0)
            {
                fgets(line2, sizeof(line2), file2);
                fgets(line2, sizeof(line2), file2);
                line2[strcspn(line2,"\n")]=0;
                strcpy(name,line2);
                fgets(line2, sizeof(line2), file2);
                fgets(line2, sizeof(line2), file2);
                fgets(line2, sizeof(line2), file2);
                fgets(line2, sizeof(line2), file2);
                line2[strcspn(line2,"\n")]=0;
                strcpy(time,line2);
                printf("%s (%s) ",name, time);
            }
            
        }
        printf("\n");
        fclose(file2);
    }
    fclose(file);

}
int graph2(){
    FILE *file;
    int opcion,N,i;
	printf("Type in the number of tasks: ");
    scanf("%i",&N);
    for(i=0;i<N;i++){
    	insertarNodeGraph();
	}
    do{
    	printf("-----------\n");
        printf(" 1. Insert vertex                 \n");
        printf(" 2. Insert edge                  \n");
        printf(" 3. Show lists                   \n");
        printf(" 4. WBS                         \n");
        printf(" 5. Back                            \n");
        printf("------------\n");
        printf("Choose an option:");
        scanf("%i",&opcion);
        switch(opcion){
            case 1:
                    insertarNodeGraph();
                    break;
            case 2: insertaredge();
                    break;
            case 3: visualizarGrafo();
                    break;
            case 4: 
                    file=fopen("graph2.txt","w");
                    fputs("",file);
                    fclose(file);
                    recorridos();
                    printWBS();
			        break;
			case 5: break;
            default: printf("Invalid option\n");
                     break;
        }
        system("pause");
        
    }while(opcion!=5);
    return 1;
}

void recorridos(){
	char vertex;
	nodeGraph*aux=inicio,*aux2=inicio;
  if(inicio!=NULL){
  	 fflush(stdin);
  	 printf("Write a vertex to search: ");
     scanf("%c",&vertex);	
     while(aux!=NULL){
  	    if(aux->data==vertex)
  		break;
	    aux=aux->next;
     }
     if(aux==NULL){
     	printf("Error: vertex doesn't exist\n");
	 }else{
		printf("WBS: ");
		aux->visitado=1;
		insertarCola(aux);
		recorridoAnchura();
		reiniciar();
		printf("\n");
	 }
   }
}

void recorridoAnchura(){
    FILE *file;
    file=fopen("graph2.txt","a");
	nodeGraph*aux=desencolar();
	if(aux==NULL)
	return;
    fprintf(file,"ID:%c\n",aux->data);
	if(aux->adyacencia!=NULL){
		edge*a=aux->adyacencia;
		while(a!=NULL){
			if(a->vrt->visitado==0){
			    insertarCola(a->vrt);
				a->vrt->visitado=1;	
			}
			a=a->next;
		}
	}
    fclose(file);
	recorridoAnchura();
	
}
void insertarCola(nodeGraph*aux){
	Lista*nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->data=aux;
	nuevo->next=NULL;
	if(ini==NULL){
		ini=nuevo;
		final=nuevo;
	}else{
		final->next=nuevo;
		final=nuevo;
	}
}