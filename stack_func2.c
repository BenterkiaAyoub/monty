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

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		more_err(8, lenn, "swap");
	ttmmpp = (*stack)->nxt;
	(*stack)->nxt = ttmmpp->nxt;
	if (ttmmpp->nxt != NULL)
		ttmmpp->nxt->previus = *stack;
	ttmmpp->nxt = *stack;
	(*stack)->previus = ttmmpp;
	ttmmpp->previus = NULL;
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

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		more_err(8, lenn, "add");

	(*stack) = (*stack)->nxt;
	opSum = (*stack)->nm + (*stack)->previus->nm;
	(*stack)->nm = opSum;
	free((*stack)->previus);
	(*stack)->previus = NULL;
}


/**
 * nodesSub - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void nodesSub(stack_t **stack, unsigned int lenn)
{
	int opSum;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)

		more_err(8, lenn, "sub");


	(*stack) = (*stack)->nxt;
	opSum = (*stack)->nm - (*stack)->previus->nm;
	(*stack)->nm = opSum;
	free((*stack)->previus);
	(*stack)->previus = NULL;
}


/**
 * nodeDiv - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void nodeDiv(stack_t **stack, unsigned int lenn)
{
	int opSum;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		more_err(8, lenn, "div");

	if ((*stack)->nm == 0)
		more_err(9, lenn);
	(*stack) = (*stack)->nxt;
	opSum = (*stack)->nm / (*stack)->previus->nm;
	(*stack)->nm = opSum;
	free((*stack)->previus);
	(*stack)->previus = NULL;
}

