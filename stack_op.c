#include "monty.h"

/**
 * nodeMul - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void nodeMul(stack_t **stack, unsigned int lenn)
{
	int opSum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, lenn, "mul");

	(*stack) = (*stack)->next;
	opSum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = opSum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodesMod - Computes the modulus of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void nodesMod(stack_t **stack, unsigned int lenn)
{
	int opSum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, lenn, "mod");


	if ((*stack)->n == 0)
		more_err(9, lenn);
	(*stack) = (*stack)->next;
	opSum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = opSum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

