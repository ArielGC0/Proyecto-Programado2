//The necessary libraries are called
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to modify the name 
void modifyName(char ID[50]){
    //opens the txt files
    FILE *file;
    FILE *tempFile;
    file=fopen("tasks.txt","r+");
    tempFile=fopen("replace.tmp", "w");
    //condition to validate if the file was successfully opened
	if (file==NULL||tempFile==NULL) {
		printf("An error ocurred while trying to save the data \n");
		exit(-1);
	}
    //defines the variables to be used 
    char newName[80];
    char line[300];
    int counter=1, validate=0;
    char *tmp;
    while (validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the new name of the task: ");
		fgets(newName, sizeof(newName), stdin);
		// deletes \n from the string
		newName[strcspn(newName, "\n")] = 0;
		//validates the input
		validate=validateString(newName);
	}
    validate=0;
    //adds str to the beginning of the input
	tmp = strdup(newName);
	strcpy(newName, "Name:");
	strcat(newName, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(newName, "\n");
    //cycle to place each line in the temporary file
    while (fgets(line, sizeof(line), file)) {
        fputs(line, tempFile);
        //condition to get to the task that is going to be edited
        if (strcmp(line,ID)==0){
            //cycle to keep placing each line in the temporary file
            while (fgets(line, sizeof(line), file)){
                //condition to get to the value that is going to be edited
                if (counter==2){
                    //inserts the new data
                    fputs(newName, tempFile);
                    break;
                }
                counter++;
                fputs(line, tempFile);
            }
        } 
    }
    //closes the files
    fclose(file);
    fclose(tempFile);
    //deletes the main file and it is replaced by the temporary file that contains the new data
    remove("tasks.txt");
    rename("replace.tmp", "tasks.txt");
}
//function to modify the description
void modifyDescription(char ID[50]){
    //opens the txt files
    FILE *file;
    FILE *tempFile;
    file=fopen("tasks.txt","r+");
    tempFile=fopen("replace.tmp", "w");
    //condition to validate if the file was successfully opened
	if (file==NULL||tempFile==NULL) {
		printf("An error ocurred while trying to save the data \n");
		exit(-1);
	}
    //defines the variables to be used 
    char newDescription[200];
    char line[300];
    int counter=1, validate=0;
    char *tmp;
    while (validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the new description of the task: ");
		fgets(newDescription, sizeof(newDescription), stdin);
		// deletes \n from the string
		newDescription[strcspn(newDescription, "\n")] = 0;
		//validates the input
		validate=validateString(newDescription);
	}
	validate=0;
    //adds str to the beginning of the input
	tmp = strdup(newDescription);
	strcpy(newDescription, "Description:");
	strcat(newDescription, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(newDescription, "\n");
    //cycle to place each line in the temporary file
    while (fgets(line, sizeof(line), file)) {
        fputs(line, tempFile);
        //condition to get to the task that is going to be edited
        if (strcmp(line,ID)==0){
            //cycle to keep placing each line in the temporary file
            while (fgets(line, sizeof(line), file)){
                //condition to get to the value that is going to be edited
                if (counter==3){
                    //inserts the new data
                    fputs(newDescription, tempFile);
                    break;
                }
                counter++;
                fputs(line, tempFile);
            }
        } 
    }
    //closes the files
    fclose(file);
    fclose(tempFile);
    //deletes the main file and it is replaced by the temporary file that contains the new data
    remove("tasks.txt");
    rename("replace.tmp", "tasks.txt");
}
//function to modify the type
void modifyType(char ID[50]){
    //opens the txt files
    FILE *file;
    FILE *tempFile;
    file=fopen("tasks.txt","r+");
    tempFile=fopen("replace.tmp", "w");
    //condition to validate if the file was successfully opened
	if (file==NULL||tempFile==NULL) {
		printf("An error ocurred while trying to save the data \n");
		exit(-1);
	}
    //defines the variables to be used 
    char newType[30];
    char line[300];
    int counter=1, validate=0;
    char *tmp;
    
    while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the new type of the task: ");
		printf("\n Operative task");
		printf("\n Approval task");
		printf("\n Contract signing");
		printf("\n Management task");
		printf("\n Changes \n");
		fgets(newType, sizeof(newType), stdin);
		// deletes \n from the string
		newType[strcspn(newType, "\n")] = 0;
		//validates the input
		validate=validateType(newType);
	}
	validate=0;
    //adds str to the beginning of the input
	tmp = strdup(newType);
	strcpy(newType, "Type:");
	strcat(newType, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(newType, "\n");
    //cycle to place each line in the temporary file
    while (fgets(line, sizeof(line), file)) {
        fputs(line, tempFile);
        //condition to get to the task that is going to be edited
        if (strcmp(line,ID)==0){
            //cycle to keep placing each line in the temporary file
            while (fgets(line, sizeof(line), file)){
                //condition to get to the value that is going to be edited
                if (counter==4){
                    //inserts the new data
                    fputs(newType, tempFile);
                    break;
                }
                counter++;
                fputs(line, tempFile);
            }
        } 
    }
    //closes the files
    fclose(file);
    fclose(tempFile);
    //deletes the main file and it is replaced by the temporary file that contains the new data
    remove("tasks.txt");
    rename("replace.tmp", "tasks.txt");
}
//function to modify the effort
void modifyEffort(char ID[50]){
    //opens the txt files
    FILE *file;
    FILE *tempFile;
    file=fopen("tasks.txt","r+");
    tempFile=fopen("replace.tmp", "w");
    //condition to validate if the file was successfully opened
	if (file==NULL||tempFile==NULL) {
		printf("An error ocurred while trying to save the data \n");
		exit(-1);
	}
    //defines the variables to be used 
    char newEffort[20];
    char line[300];
    int counter=1, validate=0;
    char *tmp;
    while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the new effort required for the task: ");
		fgets(newEffort, sizeof(newEffort), stdin);
		// deletes \n from the string
		newEffort[strcspn(newEffort, "\n")] = 0;
		//validates the input
		validate=validateNumbers(newEffort);
	}
	validate=0;
    //adds str to the beginning of the input
	tmp = strdup(newEffort);
	strcpy(newEffort, "Effort:");
	strcat(newEffort, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(newEffort, "\n");
    //cycle to place each line in the temporary file
    while (fgets(line, sizeof(line), file)) {
        fputs(line, tempFile);
        //condition to get to the task that is going to be edited
        if (strcmp(line,ID)==0){
            //cycle to keep placing each line in the temporary file
            while (fgets(line, sizeof(line), file)){
                //condition to get to the value that is going to be edited
                if (counter==5){
                    //inserts the new data
                    fputs(newEffort, tempFile);
                    break;
                }
                counter++;
                fputs(line, tempFile);
            }
        } 
    }
    //closes the files
    fclose(file);
    fclose(tempFile);
    //deletes the main file and it is replaced by the temporary file that contains the new data
    remove("tasks.txt");
    rename("replace.tmp", "tasks.txt");
}
//function to modify the time
void modifyTime(char ID[50]){
    //opens the txt files
    FILE *file;
    FILE *tempFile;
    file=fopen("tasks.txt","r+");
    tempFile=fopen("replace.tmp", "w");
    //condition to validate if the file was successfully opened
	if (file==NULL||tempFile==NULL) {
		printf("An error ocurred while trying to save the data \n");
		exit(-1);
	}
    //defines the variables to be used 
    char newTime[20];
    char line[300];
    int counter=1, validate=0;
    char *tmp;
    while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the new time, in minutes, required for the task: ");
		fgets(newTime, sizeof(newTime), stdin);
		// deletes \n from the string
		newTime[strcspn(newTime, "\n")] = 0;
		//validates the input
		validate=validateNumbers(newTime);
	}
	validate=0;
    //adds str to the beginning of the input
	tmp = strdup(newTime);
	strcpy(newTime, "Time:");
	strcat(newTime, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(newTime, "\n");
    //cycle to place each line in the temporary file
    while (fgets(line, sizeof(line), file)) {
        fputs(line, tempFile);
        //condition to get to the task that is going to be edited
        if (strcmp(line,ID)==0){
            //cycle to keep placing each line in the temporary file
            while (fgets(line, sizeof(line), file)){
                //condition to get to the value that is going to be edited
                if (counter==6){
                    //inserts the new data
                    fputs(newTime, tempFile);
                    break;
                }
                counter++;
                fputs(line, tempFile);
            }
        } 
    }
    //closes the files
    fclose(file);
    fclose(tempFile);
    //deletes the main file and it is replaced by the temporary file that contains the new data
    remove("tasks.txt");
    rename("replace.tmp", "tasks.txt");
}
//function to modify the owner
void modifyOwner(char ID[50]){
    //opens the txt files
    FILE *file;
    FILE *tempFile;
    file=fopen("tasks.txt","r+");
    tempFile=fopen("replace.tmp", "w");
    //condition to validate if the file was successfully opened
	if (file==NULL||tempFile==NULL) {
		printf("An error ocurred while trying to save the data \n");
		exit(-1);
	}
    //defines the variables to be used 
    char newOwner[20];
    char line[300];
    int counter=1, validate=0;
    char *tmp;
    while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the new task owner: ");
		fgets(newOwner, sizeof(newOwner), stdin);
		// deletes \n from the string
		newOwner[strcspn(newOwner, "\n")] = 0;
		//validates the input
		validate=validateString(newOwner);
	}
	validate=0;
    //adds str to the beginning of the input
	tmp = strdup(newOwner);
	strcpy(newOwner, "Owner:");
	strcat(newOwner, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(newOwner, "\n");
    //cycle to place each line in the temporary file
    while (fgets(line, sizeof(line), file)) {
        fputs(line, tempFile);
        //condition to get to the task that is going to be edited
        if (strcmp(line,ID)==0){
            //cycle to keep placing each line in the temporary file
            while (fgets(line, sizeof(line), file)){
                //condition to get to the value that is going to be edited
                if (counter==7){
                    //inserts the new data
                    fputs(newOwner, tempFile);
                    break;
                }
                counter++;
                fputs(line, tempFile);
            }
        } 
    }
    //closes the files
    fclose(file);
    fclose(tempFile);
    //deletes the main file and it is replaced by the temporary file that contains the new data
    remove("tasks.txt");
    rename("replace.tmp", "tasks.txt");
}
//function to modify the tasks in the txt
void modifyTasks(){
    //opens the txt files
    FILE *file;
    file = fopen("tasks.txt", "r");
    if (file==NULL){
        printf("An error ocurred while trying to save the data \n");
        exit(-1);
    }
    //defines the variables to be used 
    char ID[50];
    char line[300];
    int choice, verify=0,  validate=0;
   
    while (validate==0){
        // cleans the entry buffer
        fflush(stdin);
        // the user inserts the ID
        printf("Insert the ID of the task you would like to modify: \n");
        fgets(ID, sizeof(ID), stdin);
        // deletes \n from the string
        ID[strcspn(ID, "\n")] = 0;
        // deletes the spaces from the string
        ID[strcspn(ID, " ")] = 0;
        //validates the input
		validate=validateNumbers(ID);
    }
    validate=0;
    //adds \n from the string
    strcat(ID, "\n");
    //adds str to the beginning of the input
    char *tmp = strdup(ID);
    strcpy(ID, "ID:");
    strcat(ID, tmp); 
    //frees the memory
	free(tmp);
    //cycle to go through each line of the file
    while (fgets(line, sizeof(line), file)) {
        //condition if the ID entered is found
        if (strcmp(line,ID)==0){
            verify=1;
            printf("The ID has been found\n");

            printf("Insert what you would like to modify from the task %s \n", ID);
            printf("1. The name of the task\n");
            printf("2. The description of the task\n");
            printf("3. The type of task\n");
            printf("4. The effort required for the task\n");
            printf("5. The time required for the task\n");
            printf("6. The owner of the task\n");
            scanf("%i", &choice);
            if(choice==1){
                fclose(file);
                modifyName(ID);
                printf("\n The name was successfully modified");
            }
            else if(choice==2){
                fclose(file);
                modifyDescription(ID);
                printf("\n The description was successfully modified");
            }
            else if(choice==3){
                fclose(file);
                modifyType(ID);
                printf("\n The type was successfully modified");
            }
            else if(choice==4){
                fclose(file);
                modifyEffort(ID);
                printf("\n The effort was successfully modified");
            }
            else if(choice==5){
                fclose(file);
                modifyTime(ID);
                printf("\n The time was successfully modified");
            }
            else if(choice==6){
                fclose(file);
                modifyOwner(ID);
                printf("\n The owner was successfully modified\n");
            }
            else{
                printf("\nThe number entered is invalid \n");
            }
        }
        
    }
    //condition if the ID entered is not found
    if (verify==0){
        printf("The ID entered was not found \n");
    }
    //closes the file
    fclose(file);
}

