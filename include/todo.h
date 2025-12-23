#ifndef TODO_H
#define TODO_H

#define MAX_TASKS 100
#define MAX_LENGTH 100


struct Task {
    char name[MAX_LENGTH];
};


void addTask();
void viewTasks();
void deleteTask();

#endif
