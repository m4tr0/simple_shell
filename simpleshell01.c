#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main(void)
{
char command[MAX_COMMAND_LENGTH];
int status;

while (1)
{
printf("simple_shell$ ");
if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
printf("\n");
break; /* End of file condition (Ctrl+D) */
}

command[strcspn(command, "\n")] = '\0'; /* Remove the trailing newline character */

if (strcmp(command, "exit") == 0)
{
printf("Exiting the shell...\n");
break;
}

pid_t pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
char *args[] = {command, NULL};
execvp(args[0], args);

/* If exec fails, print an error message and exit */
perror("exec");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
waitpid(pid, &status, 0);

if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
{
/* Command not found */
printf("Command not found: %s\n", command);
}
}
}

return (0);
}

