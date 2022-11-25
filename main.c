//The necessary files are called
#include "addTasks.c"
#include "modifyTasks.c"
#include "functionality3-2.c"
#include "requirement3_2_2.c"
#include "registerResources.c"
#include "funcionality3_5.c"
#include "funcionality3_4.c"

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
        printf("1-Add tasks\n2-Modify tasks\n3-Show registered tasks\n4-Manage task's documents \n5-Create the recommended path to finish the project\n6-Register resources\n7-Display project tasks in tree form (WBS)\n8-Display execution order of the tasks\n---> ");
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
                thirdRequirement();
                break;
            case 5:
                createRoute();
                break;
            case 6:
                resourcesRegister();
                break;
            case 7:
                graph2();
                break;
            case 8:
                graph();
                break;
            default:
                printf("The number entered is invalid");
                break;
        }
        printf("\n To exit the system enter 1, to resume enter 0: ");
        scanf("%d",&exit);

        
    }
    printf("\n System successfully completed ");
    
}
