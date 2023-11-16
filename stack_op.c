#include "monty.h"

/**
 * nodeMul - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void nodeMul(stack_t **stack, unsigned int lenn)
{
	int opSum;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		more_err(8, lenn, "mul");

	(*stack) = (*stack)->nxt;
	opSum = (*stack)->nm * (*stack)->previus->nm;
	(*stack)->nm = opSum;
	free((*stack)->previus);
	(*stack)->previus = NULL;
}


/**
 * nodesMod - Computes the modulus of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void nodesMod(stack_t **stack, unsigned int lenn)
{
	int opSum;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)

		more_err(8, lenn, "mod");


	if ((*stack)->nm == 0)
		more_err(9, lenn);
	(*stack) = (*stack)->nxt;
	opSum = (*stack)->nm % (*stack)->previus->nm;
	(*stack)->nm = opSum;
	free((*stack)->previus);
	(*stack)->previus = NULL;
}

