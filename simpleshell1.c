#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void print_environment(void)
{
char **env = environ;

while (*env != NULL)
{
printf("%s\n", *env);
env++;
	}
}

int main(void)
{
print_environment();
return (0);
}
