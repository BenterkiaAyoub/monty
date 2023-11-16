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

	ascii = (*stack)->n;
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
		ascii = ttmmpp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		ttmmpp = ttmmpp->next;
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

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	ttmmpp = *stack;
	while (ttmmpp->next != NULL)
		ttmmpp = ttmmpp->next;

	ttmmpp->next = *stack;
	(*stack)->prev = ttmmpp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *ttmmpp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	ttmmpp = *stack;

	while (ttmmpp->next != NULL)
		ttmmpp = ttmmpp->next;

	ttmmpp->next = *stack;
	ttmmpp->prev->next = NULL;
	ttmmpp->prev = NULL;
	(*stack)->prev = ttmmpp;
	(*stack) = ttmmpp;
}

