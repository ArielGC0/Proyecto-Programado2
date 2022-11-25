//The necessary libraries are called
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

int defineID2(int ID){
    //opens the txt file
    FILE *file;
    file=fopen("Resources.txt","r+");
    char line[300];
    char *var;
    char ID2[50];
    //converts int to char
    snprintf(ID2, 50, "%d\n", ID);
    // adds "ID" to the beginning of the str
    var=strdup(ID2);
    strcpy(ID2,"ID:");
    strcat(ID2,var);
    
    while (fgets(line, sizeof(line), file)){
        // deletes \n from the string
        line[strcspn(line,"\n")]=0;
        ID2[strcspn(ID2,"\n")]=0;
        if ((strcmp(line, "----Resources ID----"))){
            //compares the line with ID
            if ((strcmp(line,ID2))==0){
                fclose(file);
                return 0;
            }
            
            
        }
        
    }
    fclose(file);
    return 1;
       
}
/*
inputs: char task
outputs: 1 if the task doesn't exist| 0 if the task exist
restrictions: 
*/
// function to validate the id
int validateIDTasks(char task[20]){
    FILE *file;
    file=fopen("tasks.txt","r+"); 
    char line[2000];
    task[strcspn(task,"\n")]=0;
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line,"\n")]=0;
        if (strcmp(line,task)==0)
        {
            return 1;
        }
        
    }
    fclose(file);
	printf("The ID was not found\n");
    return 0;
}

void resourcesRegister(){
	//defines the file to be used and it is opened in append mode
	FILE *file;
	file = fopen("Resources.txt", "a");
	//condition to validate if the file was successfully opened
	if (file==NULL) {
		printf("An error ocurred while trying to save the data \n");
		exit(-1);
	}
    //defines the variables to be used 
    int countID=0, validate=0;
    char taskID[80], resourceName[100], resourceType[80], resourceCapacity[80], resourceQuantity[100], owner[100];
    char *tmp;
    // insert data to the txt file 
	fputs("----Resources ID----\n", file);
    while(defineID2(countID)!=1){
        countID++;
    }
    char ID[50];
    //converts int to char
    snprintf(ID, 50, "%d\n", countID);
    // adds "ID" to the beginning of the str
    tmp=strdup(ID);
    strcpy(ID,"ID:");
    strcat(ID,tmp);
    //adds ID to the txt file
    fputs(ID,file);
    
    // insert data to the txt file 
	fputs("----Task----\n", file);
	while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the ID of the task: ");
		fgets(taskID, sizeof(taskID), stdin);
		// deletes \n from the string
		taskID[strcspn(taskID, "\n")] = 0;
		//validates the input
		validate=validateNumbers(taskID);
		if(validate==1){
			//adds str to the beginning of the input
			tmp = strdup(taskID);
			strcpy(taskID, "ID:");
			strcat(taskID, tmp);
			//frees the memory
			free(tmp);
			//adds \n from the string
			strcat(taskID, "\n");
			//validates de ID
			validate=validateIDTasks(taskID);
		}
		
	}
	validate=0;
    
    //adds str to the beginning of the input
	tmp = strdup(taskID);
	strcpy(taskID, "ID:");
	strcat(taskID, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(taskID, "\n");
	// inserts data to the txt file 
	fputs(taskID, file);
	
	// insert data to the txt file 
	fputs("--Info.Resources--\n", file);

	while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the resource name : ");
		fgets(resourceName, sizeof(resourceName), stdin);
		// deletes \n from the string
		resourceName[strcspn(resourceName, "\n")] = 0;
		//validates the input
		validate=validateString(resourceName);

	}
	validate=0;
	
    //adds str to the beginning of the input
	tmp = strdup(resourceName);
	strcpy(resourceName, "Name:");
	strcat(resourceName, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(resourceName, "\n");
	// inserts data to the txt file 
	fputs(resourceName, file);
	
	while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the resource Type : ");
		fgets(resourceType, sizeof(resourceType), stdin);
		// deletes \n from the string
		resourceType[strcspn(resourceType, "\n")] = 0;
		//validates the input
		validate=validateString(resourceType);
	}
	validate=0;
	
    //adds str to the beginning of the input
	tmp = strdup(resourceType);
	strcpy(resourceType, "Type:");
	strcat(resourceType, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(resourceType, "\n");
	// inserts data to the txt file 
	fputs(resourceType, file);
	
	while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the resource Capacity : ");
		fgets(resourceCapacity, sizeof(resourceCapacity), stdin);
		// deletes \n from the string
		resourceCapacity[strcspn(resourceCapacity, "\n")] = 0;
		//validates the input
		validate=validateNumbers(resourceCapacity);
	}
	validate=0;
	
    //adds str to the beginning of the input
	tmp = strdup(resourceCapacity);
	strcpy(resourceCapacity, "Capacity:");
	strcat(resourceCapacity, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(resourceCapacity, "\n");
	// inserts data to the txt file 
	fputs(resourceCapacity, file);
	
	while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the resource quantity : ");
		fgets(resourceQuantity, sizeof(resourceQuantity), stdin);
		// deletes \n from the string
		resourceQuantity[strcspn(resourceQuantity, "\n")] = 0;
		//validates the input
		validate=validateNumbers(resourceQuantity);
	}
	validate=0;
	
    //adds str to the beginning of the input
	tmp = strdup(resourceQuantity);
	strcpy(resourceQuantity, "Quantity:");
	strcat(resourceQuantity, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(resourceQuantity, "\n");
	// inserts data to the txt file 
	fputs(resourceQuantity, file);
	
	while(validate==0){
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the Owner : ");
		fgets(owner, sizeof(owner), stdin);
		// deletes \n from the string
		owner[strcspn(owner, "\n")] = 0;
		//validates the input
		validate=validateString(owner);
	}
	validate=0;
	
    //adds str to the beginning of the input
	tmp = strdup(owner);
	strcpy(owner, "Owner:");
	strcat(owner, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(owner, "\n");
	// inserts data to the txt file 
	fputs(owner, file);
	
	
    // inserts data to the txt file 
	fputs("------------------------ \n", file);
 
    //closes the file
	fclose(file);
	
}



