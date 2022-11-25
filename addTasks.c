//The necessary libraries are called
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

/*
inputs: int ID
outputs: 0 if the number of the ID was already used and 1 if not
restrictions: ID has to be greater or equal to 0
*/
//function to validate the name, description and owner
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
/*
inputs: char string[200]
outputs: validates the input
restrictions: string has to have a maximum length of 200
*/
//function to validate the name, description and owner
int validateString(char string[200]) {
	int i ;
	//condition to verify the length of the input
	if (strlen(string)==0) {
		printf("The information is invalid \n");
		return 0;
	}
	//cycle to check that the input contains alphabetical values
	for ( i = 0; i < strlen(string); i++) {
		if (isalpha(string[i])==0 && strncmp(&string[i], " ", 1)!=0) {
			printf("The information is invalid \n");
			return 0;
		}
	}
	return 1;
}
/*
inputs: char type[30]
outputs: validates the input
restrictions: type has to have a maximum length of 20
*/
//function to validate the type
int validateType(char type[30]) {
	int i;
	//condition to verify the length of the input
	if (strlen(type)==0) {
		printf("The type entered is invalid \n");
		return 0;
	}
	//cycle to check that the input contains alphabetical values
	for (i = 0; i < strlen(type); i++) {
		if (isalpha(type[i])==0 && strncmp(&type[i], " ", 1)!=0) {
			printf("The type entered is invalid \n");
			return 0;
		}
		type[i]=tolower(type[i]); //modifies the string for it to be all in lower case

	}
	//condition to check that the type exists
	if (strcmp(type, "operative task")==0||strcmp(type, "approval task")==0||strcmp(type, "contract signing")==0||strcmp(type, "management task")==0||strcmp(type, "changes")==0) {
		return 1;
	}
	printf("The type entered is invalid \n");
	return 0;
}
/*
inputs: char type[30]
outputs: validates the input
restrictions: type has to have a maximum length of 20
*/
//function to validate the effort and time
int validateNumbers(char numbers[80]) {
	int i;
	//condition to verify the length of the input
	if (strlen(numbers)==0) {
		printf("The data entered is invalid \n");
		return 0;
	}
	//cycle to check that the input contains numerical values
	for ( i = 0; i < strlen(numbers); i++) {
		if (isdigit(numbers[i])==0) {
			printf("The data entered is invalid  \n");
			return 0;
		}
	}
	return 1;
}

//function to add the tasks to the txt
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
    int countID=0, validate=0;
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
	while (validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the name of the task: ");
		fgets(name, sizeof(name), stdin);
		// deletes \n from the string
		name[strcspn(name, "\n")] = 0;
		//validates the input
		validate=validateString(name);
	}
    validate=0;
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
	while (validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the description of the task: ");
		fgets(description, sizeof(description), stdin);
		// deletes \n from the string
		description[strcspn(description, "\n")] = 0;
		//validates the input
		validate=validateString(description);
	}
	validate=0;
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

	while(validate==0){
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
		//validates the input
		validate=validateType(type);
	}
	validate=0;
    
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
	while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the effort required for the task: ");
		fgets(effort, sizeof(effort), stdin);
		// deletes \n from the string
		effort[strcspn(effort, "\n")] = 0;
		//validates the input
		validate=validateNumbers(effort);
	}
	validate=0;
   
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

	while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the time, in minutes, required for the task: ");
		fgets(time, sizeof(time), stdin);
		// deletes \n from the string
		time[strcspn(time, "\n")] = 0;
		//validates the input
		validate=validateNumbers(time);
		
	}
	validate=0;
    
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
	while(validate==0){
		// cleans the entry buffer
		fflush(stdin);
		// the user inserts the new data
		printf("\n Insert the task owner: ");
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
//function to show the tasks in the txt
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


