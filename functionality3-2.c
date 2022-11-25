//The necessary files are called
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
// create the node of the binary tree
struct Nodo {
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

// the struct of the node is created
struct Nodo *nuevoNodo(int dato) {
    // request memory
    size_t tamanioNodo = sizeof(struct Nodo);
    struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);
    // Assign the data and start sheets
    nodo->dato = dato;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

void insertar(struct Nodo *nodo, int dato) {
    
    // If it is higher it goes to the right.
    if (dato > nodo->dato) {
        // Tienes espacio a la derecha?
        if (nodo->derecha == NULL) {
            nodo->derecha = nuevoNodo(dato);
        } else {
            // Si la derecha ya está ocupada, recursividad ;)
            insertar(nodo->derecha, dato);
        }
    } else {
        // Si no, a la izquierda
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo(dato);
        } else {
            // Si la izquierda ya está ocupada, recursividad ;)
            insertar(nodo->izquierda, dato);
        }
    }
}

void inorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        inorden(nodo->izquierda);
        printf("Document ID:%d | ", nodo->dato);
        inorden(nodo->derecha);
    }
}
int searchNumber(struct Nodo *nodo,int i){
    if (nodo != NULL) {
        searchNumber(nodo->izquierda,i);
        if (nodo->dato==i)
        {
            printf("ID found \n");
            return 0;
        }
        searchNumber(nodo->derecha,i);
        
    }
    
    return 1;
}
/*
inputs: int ID
outputs: 0 if the number of the ID was already used and 1 if not
restrictions: ID has to be greater or equal to 0
*/
//function to define the id of th document
int defineID3(int ID){
    //opens the txt file
    FILE *file;
    file=fopen("tasksDocuments.txt","r+");
    char line[300];
    char *var;
    char ID2[50];
    //converts int to char
    snprintf(ID2, 50, "%d\n", ID);
    // adds "ID" to the beginning of the str
    var=strdup(ID2);
    strcpy(ID2,"Document ID:");
    strcat(ID2,var);
    
    while (fgets(line, sizeof(line), file)){
        // deletes \n from the string
        line[strcspn(line,"\n")]=0;
        ID2[strcspn(ID2,"\n")]=0;

            if ((strcmp(line,ID2))==0){
                fclose(file);
                return 0;
            }   
    }
    fclose(file);
    return 1;
       
}
/*
inputs: int ID
outputs: the requested document
restrictions: ID has to be greater or equal to 0
*/
//function to search a document
void searchDocument(){
    struct Nodo *raiz;
    int ID,round=0,IDsearch,verify=0;
    char line[2000],*var;
    FILE *file;
    file=fopen("tasksDocuments.txt","r+");
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line,"\n")]=0;
        if (strcmp(line,"----Document----")==0)
        {
            fgets(line,sizeof(line), file);
            // converts char to int
            var=line;
            ID=atoi(var);
            if(round==0){
                raiz = nuevoNodo(ID);
                round++;
            }else{
                insertar(raiz, ID);
            }

        }
        
    }
    fclose(file);
    
    printf("\nRegistered Documents:\n");
    inorden(raiz);

    printf("\nType the number of the ID of the document you want to check: ");
    scanf("%d",&IDsearch);
    searchNumber(raiz,IDsearch);
    char ID2[50];
    snprintf(ID2, 50, "%d\n", IDsearch);
    ID2[strcspn(ID2,"\n")]=0;
    file=fopen("tasksDocuments.txt","r");
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line,"\n")]=0;
        if (strcmp(line,ID2)==0)
        {
            fgets(line, sizeof(line), file);
            printf("---Document---\n");
            printf("%s",line);
            fgets(line, sizeof(line), file);
            printf("%s",line);
            fgets(line, sizeof(line), file);
            printf("%s",line);
            fgets(line, sizeof(line), file);
            printf("%s\n",line);
            verify=1;
            break;
        }
        
    }
    if (verify==0)
    {
        printf("The ID was not found\n");
    }
    fclose(file);
}
/*
inputs: char task
outputs: 1 if the task doesn't exist| 0 if the task exist
restrictions: 
*/
// function to validate the id
int validateID(char task[20]){
    FILE *file;
    file=fopen("tasks.txt","r+"); 
    char line[2000];
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
    printf("The ID was not found\n");
    return 1;
}
/*
inputs: char task
outputs: 1 if the task doesn't exist| 0 if the task exist
restrictions: 
*/
// function to validate the id
int validateIDDocs(char task[20]){
    FILE *file;
    file=fopen("tasksDocuments.txt","r+"); 
    char line[2000];
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
    return 1;
}


/*
inputs: int ID, char description, char type
outputs: registered document information
restrictions: 
*/
//function to add a document 
void addDocument(){
    int amountD,round=0,countID=0,validate=1;
    char description[50],type[20],*tmp,line[2000],taskName[50],amountTmp[50];
    char *var;
    char ID2[50];    
    while (validate==1){
        printf("Type the ID of the task you want to add a document to: ");
        fflush(stdin);
        fgets(ID2,sizeof(ID2),stdin);
        ID2[strcspn(ID2,"\n")]=0;
        validateNumbers(ID2);
        // adds "ID" to the beginning of the str
        var=strdup(ID2);
        strcpy(ID2,"ID:");
        strcat(ID2,var);
        ID2[strcspn(ID2,"\n")]=0;
        validate=validateID(ID2);
    }
    FILE *taskFile;
    taskFile=fopen("tasks.txt","r+");
    while (fgets(line, sizeof(line), taskFile))
    {
        line[strcspn(line,"\n")]=0;
        if (strcmp(line,ID2)==0)
        {
            fgets(line, sizeof(line), taskFile);
            fgets(line, sizeof(line), taskFile);
            line[strcspn(line,"\n")]=0;
            strcpy(taskName,line);
            break;
        }
        
    }
    fclose(taskFile);
    printf("How many documents do you want to add? ");
    fflush(stdin);
    fgets(amountTmp,sizeof(amountTmp),stdin);
    amountTmp[strcspn(amountTmp,"\n")]=0;
    validateNumbers(amountTmp);
    var=amountTmp;
    amountD=atoi(var);
    while (round<amountD)
    {
        FILE *file;
        file= fopen("tasksDocuments.txt","a");
        fputs("----Document----\n", file);
        while(defineID3(countID)!=1){
            countID=countID+1;
        }
        fprintf(file,"%d\n",countID);
        char ID[50];
        //converts int to char
        snprintf(ID, 50, "%d\n", countID);
        // adds "ID" to the beginning of the str
        tmp=strdup(ID);
        strcpy(ID,"Document ID:");
        strcat(ID,tmp);
        //adds ID to the txt file
        fputs(ID,file);

        printf("Add a description for the document: ");
        fflush(stdin);
        fgets(description,sizeof(description),stdin);
        
        tmp=strdup(description);
        strcpy(description,"Description:");
        strcat(description,tmp);
        fputs(description,file);

        printf("Add the type of the document: ");
        fflush(stdin);
        fgets(type,sizeof(type),stdin);
        tmp=strdup(type);
        strcpy(type,"Type:");
        strcat(type,tmp);
        fputs(type,file);

        fprintf(file,"Route:%s/%s",taskName,ID);
        round=round+1;

        fclose(file);

    }
    
}
void editDescription(){
    
    FILE *file;
    FILE *tempFile;
    char line[2000],documentId[20],description[50],type[20],*tmp;
    file=fopen("tasksDocuments.txt","r+");
    tempFile=fopen("replace.tmp","w");
    int validate=1;
    char *var;
    char ID2[50];    
    while (validate==1)
    {
        printf("Write the ID of the document that you want to edit: ");
        fflush(stdin);
        fgets(ID2,sizeof(ID2),stdin);
        ID2[strcspn(ID2,"\n")]=0;
        validateNumbers(ID2);
        // adds "ID" to the beginning of the str
        var=strdup(ID2);
        strcpy(ID2,"Document ID:");
        strcat(ID2,var);
        ID2[strcspn(ID2,"\n")]=0;
        validate=validateIDDocs(ID2);
    }

    while (fgets(line,sizeof(line),file))
    {
        fputs(line,tempFile);
        line[strcspn(line,"\n")]=0;
        if (strcmp(ID2,line)==0)
        {
            fgets(line,sizeof(line),file);

            printf("Add the new description for the document: ");
            fflush(stdin);
            fgets(description,sizeof(description),stdin);

            tmp=strdup(description);
            strcpy(description,"Description:");
            strcat(description,tmp);
            fputs(description,tempFile);                  
        }
    }
    fclose(file);
    fclose(tempFile);

    remove("tasksDocuments.txt");
    rename("replace.tmp","tasksDocuments.txt");
}
void editType(){
    
    FILE *file;
    FILE *tempFile;
    int count=0;
    char line[2000],type[50],*tmp;
    char *var;
    char ID2[50];    
    file=fopen("tasksDocuments.txt","r+");
    tempFile=fopen("replace.tmp","w");
    int validate=1;
    while (validate==1)
    {
        printf("Write the ID of the document that you want to edit: ");
        fflush(stdin);
        fgets(ID2,sizeof(ID2),stdin);
        ID2[strcspn(ID2,"\n")]=0;
        validateNumbers(ID2);
        // adds "ID" to the beginning of the str
        var=strdup(ID2);
        strcpy(ID2,"Document ID:");
        strcat(ID2,var); 
        ID2[strcspn(ID2,"\n")]=0;   
        validate=validateIDDocs(ID2);  
    }
    
    while (fgets(line,sizeof(line),file))
    {
        fputs(line,tempFile);
        line[strcspn(line,"\n")]=0;
        if (strcmp(ID2,line)==0)
        {
           
            while (fgets(line,sizeof(line),file)){
                if (count==1)
                {
                    printf("Add the new type: ");
                    fflush(stdin);
                    fgets(type,sizeof(type),stdin);

                    tmp=strdup(type);
                    strcpy(type,"Type:");
                    strcat(type,tmp);
                    fputs(type,tempFile);    
                    break;                 
                }else{
                    fputs(line,tempFile);
                    count++;
                }
                
 
            }

                
        }
    }
    fclose(file);
    fclose(tempFile);

    remove("tasksDocuments.txt");
    rename("replace.tmp","tasksDocuments.txt");
}
void deleteDocument(){
    char line[2000],ID2[50],tempLine[2000];
    char *var;
    int count=1,tempCount=1,tempCount2=1;
    FILE *file;
    FILE *tempFile;
    file=fopen("tasksDocuments.txt","r+");
    tempFile=fopen("replace.tmp","w");
    int validate=1;
    while (validate==1)
    {
        printf("Write the ID of the document that you want to delete: ");
        fflush(stdin);
        fgets(ID2,sizeof(ID2),stdin);
        ID2[strcspn(ID2,"\n")]=0;
        validateNumbers(ID2);
        // adds "ID" to the beginning of the str
        var=strdup(ID2);
        strcpy(ID2,"Document ID:");
        strcat(ID2,var);
        ID2[strcspn(ID2,"\n")]=0;
        validate=validateIDDocs(ID2);       
    }
    

    while (fgets(tempLine,sizeof(tempLine),file))
    {
        tempLine[strcspn(tempLine,"\n")]=0;
        if (strcmp(tempLine,ID2)==0)
        {
            break;
        }
        count++;
    }
    if (count==3){
        count=1;
    }
    else{
        count=count-3;
    }
    
    fclose(file);
    file=fopen("tasksDocuments.txt","r+");
    while (fgets(line,sizeof(line),file))
    {
        fputs(line,tempFile);
        if (count==tempCount)
        {
            while (fgets(line,sizeof(line),file))
            {
                if (tempCount2==6)
                {
                    while (fgets(line,sizeof(line),file))
                    {
                        fputs(line,tempFile);
                    }
                }else{
                    tempCount2++;
                }
                
            }
        }
        tempCount++;
    }
    fclose(file);
    fclose(tempFile);

    remove("tasksDocuments.txt");
    rename("replace.tmp","tasksDocuments.txt");


}
void editDocument(){
    int action;
    printf("1-Modify the description\n2-Modify the type\n-> ");
    scanf("%d",&action);
    if (action==1)
    {
        editDescription();
    }else if (action==2)
    {
        editType();
    }else{
        printf("The number entered is invalid \n");
    }
    
}
void thirdRequirement(){
    int action;
    while (1==1)
    {
        printf("1-Add a document\n2-Edit a document\n3-Delete a document\n4-Search a document\n5-Back\n->");
        scanf("%d",&action);
        if (action==1)
        {
            addDocument();
        }else if (action==2)
        {
            editDocument();
        }else if (action==3)
        {
            deleteDocument();
        }else if (action==4)
        {
            searchDocument();
        }else if (action==5)
        {
            break;
        }else{
            printf("The number entered is invalid\n");
            
        }
            
    }
    

    
    
    
}

