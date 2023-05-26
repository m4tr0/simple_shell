#include "main.h"

/**
 * main - Initializes data.
 * @argc: Size of the @argv array.
 * @argv: Array of command line arguments.
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	data d;
	(void)argc;
	init_data(&d, argv[0]);
	_exec(&d);

	return (0);
}
