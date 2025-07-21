#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Function to execute a command after a delay
void schedule_task(int delay, const char* command) {
    printf("Task scheduled to run after %d seconds...\n", delay);
    sleep(delay);
    printf("Executing: %s\n", command);
    system(command);
}

int main() {
    int delay;
    char command[256];

    printf("Enter time delay in seconds: ");
    scanf("%d", &delay);
    getchar(); // clear newline

    printf("Enter shell command to run: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0; // Remove trailing newline

    if (strlen(command) == 0) {
        printf("No command provided. Exiting.\n");
        return 1;
    }

    schedule_task(delay, command);

    return 0;
}
