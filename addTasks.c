//The necessary libraries are called
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

int defineID(int ID){
    //opens the txt file
    FILE *file;
    file=fopen("tasks.txt","r+");
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
        if ((strcmp(line, "----Task----"))){
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

void addTasks(){
    //defines the file to be used and it is opened in append mode
	FILE *file;
	file = fopen("tasks.txt", "a");
	//condition to validate if the file was successfully opened
	if (file==NULL) {
		printf("An error ocurred while trying to save the data \n");
		exit(-1);
	}
    //defines the variables to be used 
    int countID=0;
	char name[80], description[200], type[30], effort[20], time[20], owner[80];
	char *tmp;
    // insert data to the txt file 
	fputs("----Task----\n", file);

    while(defineID(countID)!=1){
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
	fputs("--Info.Task--\n", file);
    // cleans the entry buffer
	fflush(stdin);
	// the user inserts the new data
	printf("\n Insert the name of the task: ");
	fgets(name, sizeof(name), stdin);
	// deletes \n from the string
	name[strcspn(name, "\n")] = 0;
    //adds str to the beginning of the input
	tmp = strdup(name);
	strcpy(name, "Name:");
	strcat(name, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(name, "\n");
	// inserts data to the txt file 
	fputs(name, file);

    // cleans the entry buffer
	fflush(stdin);
	// the user inserts the new data
	printf("\n Insert the description of the task: ");
	fgets(description, sizeof(description), stdin);
	// deletes \n from the string
	description[strcspn(description, "\n")] = 0;
    //adds str to the beginning of the input
	tmp = strdup(description);
	strcpy(description, "Description:");
	strcat(description, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(description, "\n");
	// inserts data to the txt file 
	fputs(description, file);

    // cleans the entry buffer
	fflush(stdin);
	// the user inserts the new data
	printf("\n Insert the type of the task: ");
    printf("\n Operative task");
    printf("\n Approval task");
    printf("\n Contract signing");
    printf("\n Management task");
    printf("\n Changes \n");
	fgets(type, sizeof(type), stdin);
	// deletes \n from the string
	type[strcspn(type, "\n")] = 0;
    //adds str to the beginning of the input
	tmp = strdup(type);
	strcpy(type, "Type:");
	strcat(type, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(type, "\n");
	// inserts data to the txt file 
	fputs(type, file);

    // cleans the entry buffer
	fflush(stdin);
	// the user inserts the new data
	printf("\n Insert the effort required for the task: ");
	fgets(effort, sizeof(effort), stdin);
	// deletes \n from the string
	effort[strcspn(effort, "\n")] = 0;
    //adds str to the beginning of the input
	tmp = strdup(effort);
	strcpy(effort, "Effort:");
	strcat(effort, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(effort, "\n");
	// inserts data to the txt file 
	fputs(effort, file);

    // cleans the entry buffer
	fflush(stdin);
	// the user inserts the new data
	printf("\n Insert the time required for the task: ");
	fgets(time, sizeof(time), stdin);
	// deletes \n from the string
	time[strcspn(time, "\n")] = 0;
    //adds str to the beginning of the input
	tmp = strdup(time);
	strcpy(time, "Time:");
	strcat(time, tmp);
	//frees the memory
	free(tmp);
	//adds \n from the string
	strcat(time, "\n");
	// inserts data to the txt file 
	fputs(time, file);

    // cleans the entry buffer
	fflush(stdin);
	// the user inserts the new data
	printf("\n Insert the task owner: ");
	fgets(owner, sizeof(owner), stdin);
	// deletes \n from the string
	owner[strcspn(owner, "\n")] = 0;
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
void showTasks(){
    //defines the file to be used and it is opened in reading mode
	FILE *file;
	file = fopen("tasks.txt", "r");
	//condition to validate if the file was successfully opened
	if (file==NULL) {
		printf("An error ocurred while trying to save the data \n");
		exit(-1);
	}
    char line[300];
    while (fgets(line, sizeof(line), file)){
        printf("%s", line);
    }
}


