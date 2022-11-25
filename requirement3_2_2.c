//The necessary libraries are called
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

//Se crea la estructura de las partes de la lista
typedef struct nodoL {
    char taskName[40];
    int edge;
	struct nodoL * siguiente;	
    struct nodoL * anterior;

} nodoL;

//Se crea la estructura que incluye el inicio y el final de la lista
typedef struct listaD {
	nodoL * inicio;	
    nodoL * final;
} listaDoble;

//Se crea una lista vacía
listaDoble* crearLista(void){
    listaDoble *L;
	L = (listaDoble *) malloc(sizeof(listaDoble));
	L->inicio = NULL;
	L->final = NULL;
	return L;
}
/*
entradas: dato (int)
salidas: nuevo nodo
restricciones: --
*/
//Se crea un nodo para el nuevo dato ingresado
nodoL* crearNodoLista(char taskName[50],int edge){
    nodoL* new;
    new = (nodoL *) malloc(sizeof(nodoL));
	new->anterior = NULL;
	new->siguiente = NULL;
    strcpy(new->taskName,taskName);
	new->edge=edge;
	return new;
}

/*
entradas: *L (listaDoble), dato (int)
salidas: la lista con el nuevo dato insertado
restricciones: --
*/
//Se inserta el nuevo dato a la lista
listaDoble* insertarDato(listaDoble *L, char taskName[50],int edge){
    // Se valida si la lista esta vacía
	if(L->inicio == NULL) {
		//Inserta al inicio de la lista
		L->inicio = crearNodoLista(taskName,edge);
		L->final = L->inicio;
		return L;
	}
	//Inserta el dato al final de la lista, no necesita un ciclo porque tiene el puntero final
	L->final->siguiente = crearNodoLista(taskName,edge);
	L->final->siguiente->anterior = L->final;
	L->final = L->final->siguiente;
    
    return L;
}
void imprimirLista(listaDoble*L){
    nodoL *i=L->inicio;
    printf("The created route is: \n");
    printf("Start->");
    //Se crea un búcle para imprimir la nueva lista creada
    for(i = L->inicio; i!= NULL; i = i->siguiente)
        printf("(%s)-%d->",i->taskName,i->edge);

	printf("end");
    // Se libera el espacio de memoria de i
    free(i);
}
int validateTaskName(char task[50]){
    FILE *file;
    file=fopen("tasks.txt","r+"); 
    char line[200];
    task[strcspn(task,"\n")]=0;
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line,"\n")]=0;
        if (strcmp(line,task)==0)
        {
            return 0;
        }
        
    }
    fclose(file);
    printf("The name entered was not found \n");
    return 1;


}
int createEdge(char taskName[30]){
    FILE *file;
    file=fopen("tasks.txt","r+");
    char line[2000],tempEffort[30],tempTime[30],*remaining;
    long effort,time;
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line,"\n")]=0;
        if (strcmp(line,taskName)==0)
        {
            fgets(line, sizeof(line), file);
            fgets(line, sizeof(line), file);
            fgets(line, sizeof(line), file);
            line[strcspn(line,"\n")]=0;
            strcpy(tempEffort,line);
            int j = 0, t;
            //ciclo para eliminar todos los caracteres del string y dejar solo los digitos
            for (t = 0; tempEffort[t]; t++){
                if (tempEffort[t] >= '0' && tempEffort[t] <= '9'){
                    tempEffort[j] = tempEffort[t];
                    j++;
                }
            }
            tempEffort[j] = '\0';
            //se convierte la variable char a int long
            effort=strtol(tempEffort, &remaining, 10);
            j=0;
            fgets(line, sizeof(line), file);
            line[strcspn(line,"\n")]=0;
            strcpy(tempTime,line);
            //ciclo para eliminar todos los caracteres del string y dejar solo los digitos
            for (t = 0; tempTime[t]; t++){
                if (tempTime[t] >= '0' && tempTime[t] <= '9'){
                    tempTime[j] = tempTime[t];
                    j++;
                }
            }
            tempTime[j] = '\0';
            //se convierte la variable char a int long
            time=strtol(tempTime, &remaining, 10);
            break;          
        }

    }
    int edge;
    edge=time+effort;
    fclose(file);
    return edge;
}
void createRoute(){
    listaDoble *L;
    L=crearLista();
    char line[2000],taskName[30],tmpTaskName[30],*var,tmpEffort[20],tmpTime[20];
    int count=0,round=0,taskNumber=1,validate=1,effort,time,edge;
    FILE *file;
    file=fopen("tasks.txt","r+");
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line,"\n")]=0;
        if (strcmp(line,"----Task----")==0)
        {
            count++;
        }
        
    }
    while (round<count)
    {
        while (validate==1)
        {
            printf("Write the name of the task number %d: ",taskNumber);
            fflush(stdin);
            fgets(taskName,sizeof(taskName),stdin);
            strcpy(tmpTaskName,taskName);
            tmpTaskName[strcspn(tmpTaskName,"\n")]=0;
            var=strdup(taskName);
            strcpy(taskName,"Name:");
            strcat(taskName,var);   
            validate=validateTaskName(taskName); 
             
        }
        validate=1;

        edge=createEdge(taskName);
        L=insertarDato(L,tmpTaskName,edge);

        taskNumber++;
        round++;
    }
    imprimirLista(L);
    fclose(file);
    
}


