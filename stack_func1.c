#include "monty.h"


/**
 * addStack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @len: Integer indicating the line number of the opcode.
 */

void addStack(stack_t **newNode, __attribute__((unused))unsigned int len)
{
	stack_t *ttmmpp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	ttmmpp = head;
	head = *newNode;
	head->next = ttmmpp;
	ttmmpp->prev = head;
}


/**
 * stackPrint - Prints the contents of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Line number of the opcode.
 */

void stackPrint(stack_t **stack, unsigned int lenn)
{
	stack_t *ttmmpp;

	(void) lenn;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	ttmmpp = *stack;
	while (ttmmpp != NULL)
	{
		printf("%d\n", ttmmpp->n);
		ttmmpp = ttmmpp->next;
	}
}

/**
 * topPop - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void topPop(stack_t **stack, unsigned int lenn)
{
	stack_t *ttmmpp;

	if (stack == NULL || *stack == NULL)
		more_err(7, lenn);

	ttmmpp = *stack;
	*stack = ttmmpp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(ttmmpp);
}

/**
 * topPrint - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lenn: Integer representing the line number of the opcode.
 */

void topPrint(stack_t **stack, unsigned int lenn)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, lenn);
	printf("%d\n", (*stack)->n);
}

