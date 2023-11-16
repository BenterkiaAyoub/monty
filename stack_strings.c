#include "monty.h"

/**
 * charPrint - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void charPrint(stack_t **stack, unsigned int lenn)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, lenn);

	ascii = (*stack)->nm;
	if (ascii < 0 || ascii > 127)
		string_err(10, lenn);
	printf("%c\n", ascii);
}

/**
 * stringPrint - Prints a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */

void stringPrint(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *ttmmpp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	ttmmpp = *stack;
	while (ttmmpp != NULL)
	{
		ascii = ttmmpp->nm;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		ttmmpp = ttmmpp->nxt;
	}
	printf("\n");
}

/**
 * rotll - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */

void rotll(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *ttmmpp;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		return;

	ttmmpp = *stack;
	while (ttmmpp->nxt != NULL)
		ttmmpp = ttmmpp->nxt;

	ttmmpp->nxt = *stack;
	(*stack)->previus = ttmmpp;
	*stack = (*stack)->nxt;
	(*stack)->previus->nxt = NULL;
	(*stack)->previus = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *ttmmpp;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		return;

	ttmmpp = *stack;

	while (ttmmpp->nxt != NULL)
		ttmmpp = ttmmpp->nxt;

	ttmmpp->nxt = *stack;
	ttmmpp->previus->nxt = NULL;
	ttmmpp->previus = NULL;
	(*stack)->previus = ttmmpp;
	(*stack) = ttmmpp;
}

