#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100


struct Task {
    char name[MAX_LENGTH];
};


struct Task tasks[MAX_TASKS];


struct Task *ptr = tasks;

int taskCount = 0;


void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    printf("Enter task: ");
    getchar(); 
    fgets((ptr + taskCount)->name, MAX_LENGTH, stdin);

    (ptr + taskCount)->name[strcspn((ptr + taskCount)->name, "\n")] = '\0';

    taskCount++;
    printf("Task added successfully!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\n--- To-Do List ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, (ptr + i)->name);
    }
}

void deleteTask() {
    int taskNumber;

    if (taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    viewTasks();
    printf("Enter task number to delete: ");
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("Task number not found.\n");
        return;
    }

    for (int i = taskNumber - 1; i < taskCount - 1; i++) {
        strcpy((ptr + i)->name, (ptr + i + 1)->name);
    }

    taskCount--;
    printf("Task deleted successfully!\n");
}

int main() {
    int choice;

    do {
        printf("\n--- To-Do List Menu ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
