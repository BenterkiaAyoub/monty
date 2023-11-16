#include "monty.h"

/**
 * erro - Print an  appropiate errors  message  determine by the error code.
 * @err_cd: The error of the  codes are as the following:
 * (1) => The user didn't provide a file or provided more than one file to the program.
 * (2) => The file provided by the user cannot be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => The program is unable to allocate more memory (malloc).
 * (5) => The parameter passed to the "push" instruction is not an integer.
 * (6) => The stack is empty for the "pint" instruction.
 * (7) => The stack is empty for the "pop" instruction.
 * (8) => The stack is too short for the specified operation.
 */
void erro(int err_cd, ...)
{
	va_list aga;
	char *opp;
	int numL;

	va_start(aga, err_cd);
	switch (err_cd)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(aga, char *));
			break;
		case 3:
			numL = va_arg(aga, int);
			opp = va_arg(aga, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", numL, opp);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(aga, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * moreErors - Handles errors.
 * @err_cd: The error codes are as follows:
 * (6) => The stack is empty for the "pint" instruction.
 * (7) => The stack is empty for the "pop" instruction.
 * (8) => The stack is too short for the specified operation.
 * (9) => Division by zero.
 */

void moreErors(int err_cd, ...)
{
	va_list aga;
	char *opp;
	int numL;

	va_start(aga, err_cd);
	switch (err_cd)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(aga, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(aga, int));
			break;
		case 8:
			numL = va_arg(aga, unsigned int);
			opp = va_arg(aga, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", numL, opp);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(aga, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - Handles errors.
 * @err_cd: The error codes are as follows:
 * (10) => The number inside a node is outside ASCII bounds.
 * (11) => The stack is empty.
 */

void string_err(int err_cd, ...)
{
	va_list aga;
	int numL;

	va_start(aga, err_cd);
	numL = va_arg(aga, int);
	switch (err_cd)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", numL);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", numL);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

