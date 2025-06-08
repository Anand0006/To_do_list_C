
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LEN 100

char tasks[MAX_TASKS][TASK_LEN];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("❌ Task list full!\n");
        return;
    }

    printf("Enter task description: ");
    getchar(); // clear newline buffer
    fgets(tasks[taskCount], TASK_LEN, stdin);
    tasks[taskCount][strcspn(tasks[taskCount], "\n")] = '\0'; 
    taskCount++;

    printf("✅ Task added!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("📭 No tasks to show.\n");
        return;
    }

    printf("📋 To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void deleteTask() {
    if (taskCount == 0) {
        printf("❌ No tasks to delete.\n");
        return;
    }

    int index;
    viewTasks();
    printf("Enter task number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > taskCount) {
        printf("❌ Invalid task number.\n");
        return;
    }

    for (int i = index - 1; i < taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    taskCount--;
    printf("🗑️ Task deleted!\n");
}

int main() {
    int choice;

    do {
        printf("\n=== TO-DO LIST MENU ===\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
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
                printf("👋 Exiting To-Do List. Goodbye!\n");
                break;
            default:
                printf("⚠️ Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
