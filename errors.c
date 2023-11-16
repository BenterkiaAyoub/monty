#include "monty.h"

/**
 * err - Prints appropriate error messagges determined by their error code.
 * @error_code: The error codes are as follows:
 * (1) => The user does not provide any file or provides more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to allocate more memory (malloc).
 * (5) => When the parameter passed to the "push" instruction is not an int.
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When the stack is too short for the operation.
 */

void err(int error_code, ...)
{
	va_list agg;
	char *opp;
	int lenn;

	va_start(agg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USaggE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(agg, char *));
			break;
		case 3:
			lenn = va_arg(agg, int);
			opp = va_arg(agg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lenn, opp);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usagge: push integer\n", va_arg(agg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - Handles errors.
 * @error_code: The error codes are as follows:
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When the stack is too short for the operation.
 * (9) => Division by zero.
 */

void more_err(int error_code, ...)
{
	va_list agg;
	char *opp;
	int lenn;

	va_start(agg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(agg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(agg, int));
			break;
		case 8:
			lenn = va_arg(agg, unsigned int);
			opp = va_arg(agg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lenn, opp);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(agg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - Handles errors.
 * @error_code: The error codes are as follows:
 * (10) => The number inside a node is outside ASCII bounds.
 * (11) => The stack is empty.
 */

void string_err(int error_code, ...)
{
	va_list agg;
	int lenn;

	va_start(agg, error_code);
	lenn = va_arg(agg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lenn);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lenn);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

