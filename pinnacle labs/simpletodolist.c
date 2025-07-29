#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_TASKS 100
#define MAX_LENGTH 200
typedef struct {
    int id;
    char description[MAX_LENGTH];
    bool completed;
} Task;
Task tasks[MAX_TASKS];
int taskCount = 0;
void displayMenu() {
    printf("\nTo-Do List Manager\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Edit Task\n");
    printf("4. Mark Task as Complete\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter task description: ");
    getchar();
    fgets(tasks[taskCount].description, MAX_LENGTH, stdin);
    tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = '\0';
    tasks[taskCount].id = taskCount + 1;
    tasks[taskCount].completed = false;
    taskCount++;    
    printf("Task added successfully!\n");
}
void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks in the list.\n");
        return;
    }    
    printf("\nTask List:\n");
    printf("ID | Description | Status\n");
    printf("------------------------\n");    
    for (int i = 0; i < taskCount; i++) {
        printf("%2d | %-50s | %s\n", 
               tasks[i].id, 
               tasks[i].description, 
               tasks[i].completed ? "Completed" : "Pending");
    }
}
void editTask() {
    int id;
    printf("Enter task ID to edit: ");
    scanf("%d", &id);
    if (id < 1 || id > taskCount) {
        printf("Invalid task ID.\n");
        return;
    }
    printf("Current description: %s\n", tasks[id-1].description);
    printf("Enter new description: ");
    getchar();
    fgets(tasks[id-1].description, MAX_LENGTH, stdin);
    tasks[id-1].description[strcspn(tasks[id-1].description, "\n")] = '\0';
    printf("Task updated successfully!\n");
}
void markComplete() {
    int id;
    printf("Enter task ID to mark as complete: ");
    scanf("%d", &id);
    if (id < 1 || id > taskCount) {
        printf("Invalid task ID.\n");
        return;
    }
    if (tasks[id-1].completed) {
        printf("Task is already marked as complete.\n");
        return;
    }
    tasks[id-1].completed = true;
    printf("Task marked as complete!\n");
}
int main() {
    int choice;
    printf("Welcome to the To-Do List Manager!\n");
    while (1) {
        displayMenu();
        scanf("%d", &choice);        
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                editTask();
                break;
            case 4:
                markComplete();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }    
    return 0;
}