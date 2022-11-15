//The necessary files are called
#include "addTasks.c"
#include "modifyTasks.c"

//The necessary libraries are called
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// main function that calls each functionality
int main(){
    //defines the variables to be used 
    int action,exit=0;
    while (exit==0){
        // the user inserts the functionality to be executed
        printf("1-Add tasks\n2-Modify tasks\n3-Show registered tasks\n ---> ");
        scanf("%d",&action);
        // executes the functionality chosen
        switch (action){
            case 1:
                addTasks();
                break;
            case 2:
                modifyTasks();
                break;
            case 3:
                showTasks();
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            default:
                printf("The number entered is invalid");
                break;
        }
        printf("To exit the system enter 1, to resume enter 0: ");
        scanf("%d",&exit);

        
    }
    printf("\n System successfully completed ");
    
}
