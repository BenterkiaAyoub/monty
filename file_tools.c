#include "monty.h"

/**
 * open_file - Opens a file.
 * @file_name: The file pathname.
 * Return: void
 */


void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	readFl(fd);
	fclose(fd);
}


/**
 * readFl - Reads a file.
 * @fd: Pointer to the file descriptor.
 * Return: void
 */

void readFl(FILE *fd)
{
	int lenn, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (lenn = 1; getline(&buffer, &len, fd) != -1; lenn++)
	{
		format = parseLn(buffer, lenn, format);
	}
	free(buffer);
}


/**
 * parseLn - Tokenizes each line to determine which function to call.
 * @buffer: Line from the file.
 * @lenn: Line number.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 * If 1, nodes will be entered as a queue.
 * Return: Returns 0 if the opcd corresponds to a stack,
  1 if it corresponds to a queue.
 */


int parseLn(char *buffer, int lenn, int format)
{
	char *opcd, *vl;
	const char *limDe = "\n ";

	if (buffer == NULL)
		err(4);

	opcd = strtok(buffer, limDe);
	if (opcd == NULL)
		return (format);
	vl = strtok(NULL, limDe);

	if (strcmp(opcd, "stack") == 0)
		return (0);
	if (strcmp(opcd, "queue") == 0)
		return (1);

	funFind(opcd, vl, lenn, format);
	return (format);
}

/**
 * funFind - Finds the appropriate function for the opcd.
 * @opcd: Opcode.
 * @vl: Argument of the opcd.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 * If 1, nodes will be entered as a queue.
 * @ln: Line number.
 * Return: void
 */

void funFind(char *opcd, char *vl, int ln, int format)
{
	int ij;
	int flg;

	instruction_t func_list[] = {
		{"push", addStack},
		{"pall", stackPrint},
		{"pint", topPrint},
		{"pop", topPop},
		{"nop", nop},
		{"swap", nodesSwap},
		{"add", nodesAdd},
		{"sub", nodesSub},
		{"div", nodeDiv},
		{"mul", nodeMul},
		{"mod", nodesMod},
		{"pchar", charPrint},
		{"pstr", stringPrint},
		{"rotl", rotll},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcd[0] == '#')
		return;

	for (flg = 1, ij = 0; func_list[ij].opcd != NULL; ij++)
	{
		if (strcmp(opcd, func_list[ij].opcd) == 0)
		{
			call_fun(func_list[ij].f, opcd, vl, ln, format);
			flg = 0;
		}
	}
	if (flg == 1)
		err(3, ln, opcd);
}


/**
 * call_fun - Executes the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: String representing the opcd.
 * @val: String representing a numeric value.
 * @ln: Line number for the instruction.
 * @format: Format specifier. If 0, nodes will be entered as a stack.
 * If 1, nodes will be entered as a queue.
 */

void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flg;
	int ij;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flg = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (ij = 0; val[ij] != '\0'; ij++)
		{
			if (isdigit(val[ij]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flg);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

