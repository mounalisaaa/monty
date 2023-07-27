#include "monty.h"
/**
 * main - main function
 * @argc: argc
 * @argv: argv
 * Return: int
 */
int main(int argc, char **argv)
{
	FILE *file;
	stack_t *stack = NULL;
	char buffer[1024];
	int line_number = 0;
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 1024, file))
	{
		line_number++;
		opcode = strtok(buffer, " \t\n");
		if (opcode)
			handle_opcode(opcode, &stack, line_number);
	}
	fclose(file);
	return (0);
}
