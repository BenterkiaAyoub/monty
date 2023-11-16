#include "monty.h"

/**
 * nop - Performs no operation.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void nop(stack_t **stack, unsigned int lenn)
{
	(void)stack;
	(void)lenn;
}


/**
 * nodesSwap - Exchanges the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void nodesSwap(stack_t **stack, unsigned int lenn)
{
	stack_t *ttmmpp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, lenn, "swap");
	ttmmpp = (*stack)->next;
	(*stack)->next = ttmmpp->next;
	if (ttmmpp->next != NULL)
		ttmmpp->next->prev = *stack;
	ttmmpp->next = *stack;
	(*stack)->prev = ttmmpp;
	ttmmpp->prev = NULL;
	*stack = ttmmpp;
}

/**
 * nodesAdd - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void nodesAdd(stack_t **stack, unsigned int lenn)
{
	int opSum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, lenn, "add");

	(*stack) = (*stack)->next;
	opSum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = opSum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodesSub - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */
/
void nodesSub(stack_t **stack, unsigned int lenn)
{
	int opSum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, lenn, "sub");


	(*stack) = (*stack)->next;
	opSum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = opSum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodeDiv - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void nodeDiv(stack_t **stack, unsigned int lenn)
{
	int opSum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, lenn, "div");

	if ((*stack)->n == 0)
		more_err(9, lenn);
	(*stack) = (*stack)->next;
	opSum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = opSum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

