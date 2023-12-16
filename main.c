#include "monty.h"

unsigned int line_number = 0;

/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * This function initializes the interpreter, reads the Monty
 * bytecode from
 * the specified file, and executes the corresponding
 * operations.
 *
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
	FILE *fpc;
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fpc = fopen(argv[1], "r");
	if (!fpc)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(fpc, &top);
	fclose(fpc);
	free_stack(top);
	return (0);
}
/**
 * read_file - Reads Monty bytecode from a file and executes
 * corresponding operations.
 * @fpc: Pointer to the FILE structure of the Monty bytecode file.
 * @top: Pointer to the top of the stack.
 *
 * This function reads each line from the Monty bytecode file,
 * processes it into
 * tokens, and executes the corresponding stack operations.
 *
 * Return: Always 0.
 */
int read_file(FILE *fpc, stack_t **top)
{
	char *line = NULL;
	size_t size_line = 0;
	ssize_t read;
	int status;

	while ((read = getline(&line, &size_line, fpc)) != -1)
	{
		line_number++;
		status = token_line(line, top);
		if (status == -1)
		{
			fclose(fpc);
			free(line);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = NULL;
		size_line = 0;
	}
	free(line);
	return (0);
}
/**
 * token_line - Processes a line of tokens representing
 * stack operations.
 * @line: Input line containing space/tab-separated tokens.
 * @top: Pointer to the top of the stack.
 *
 * This function tokenizes the input line, identifies
 * stack operations, and executes
 * the corresponding functions with their values on the stack.
 * Return: succes or fail
 */
int token_line(char *line, stack_t **top)
{
	char *token, *value;
	int i;
	instruction_t *ops = init_ops();
	size_t len = strlen(line);

	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
	}
	token = strtok(line, " \t");
	if (token == NULL)
		return (1);
	i = 0;
	while (ops[i].opcode)
	{
		if (strcmp(token, ops[i].opcode) == 0)
		{
			value = strtok(NULL, " \t");
			/* return ops[i].f*/
			if (value)
			{
				ops[i].f(top, atoi(value));
				return (0);
			}
			else if (strcmp(ops[i].opcode, "push") == 0 && !value)
			{
				free_stack(*top);
				fprintf(stderr, "L%d: can't push an empty value", line_number);
				return (-1);
			}
			else
			{
				ops[i].f(top, 0);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

/**
 * init_ops - Initializes the array of operations.
 *
 * This function creates and returns an array of instruction_t
 * structures, each containing an opcode and its corresponding function.
 *
 * Return: Array of operations.
 */
instruction_t *init_ops(void)
{
	static instruction_t ops[] = {
		{"push", _push},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{NULL, NULL}
	};
	return (ops);
}