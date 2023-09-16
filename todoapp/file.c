#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

struct Task {
    char description[100];
    int completed;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

// Function to add a task to the list
void addTask(const char *description) {
    if (taskCount < MAX_TASKS) {
        strcpy(tasks[taskCount].description, description);
        tasks[taskCount].completed = 0; // Task is initially not completed
        taskCount++;
        printf("Task added: %s\n", description);
    } else {
        printf("Error: Task list is full\n");
    }
}

// Function to list all tasks
void listTasks() {
    printf("To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s %s\n", i + 1, tasks[i].completed ? "[X]" : "[ ]", tasks[i].description);
    }
}

// Function to mark a task as completed
void completeTask(int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskCount) {
        tasks[taskIndex - 1].completed = 1;
        printf("Task marked as completed: %s\n", tasks[taskIndex - 1].description);
    } else {
        printf("Error: Invalid task index\n");
    }
}

// Function to remove a task
void removeTask(int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskCount) {
        printf("Task removed: %s\n", tasks[taskIndex - 1].description);
        for (int i = taskIndex - 1; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
    } else {
        printf("Error: Invalid task index\n");
    }
}

int main() {
    int choice;
    char description[100];
    int taskIndex;

    while (1) {
        printf("\nTo-Do List Program\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Remove Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]", description);
                addTask(description);
                break;
            case 2:
                listTasks();
                break;
            case 3:
                printf("Enter task index to mark as completed: ");
                scanf("%d", &taskIndex);
                completeTask(taskIndex);
                break;
            case 4:
                printf("Enter task index to remove: ");
                scanf("%d", &taskIndex);
                removeTask(taskIndex);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
