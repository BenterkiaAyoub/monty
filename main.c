#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point
 * @argc: Arguments count
 * @argv: List of arguments
 * Return: Always 0
 */


int main(int argc, char *argv[])
{
        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        opFl(argv[1]);
        free_nodes();
        return (0);
}

/**
 * create_node - Creates a node.
 * @nm: Number to be stored in the node.
 * Return: Upon success, a pointer to the created node. Otherwise, NULL.
 */

stack_t *create_node(int nm)
{
        stack_t *node;

        node = malloc(sizeof(stack_t));
 if (node == NULL)
                err(4);
        node->nxt = NULL;
        node->previus = NULL;
        node->nm = nm;
        return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */

void free_nodes(void)
{
        stack_t *ttmmpp;

        if (head == NULL)
                return;

        while (head != NULL)
        {
                ttmmpp = head;
                head = head->nxt;
                free(ttmmpp);
        }
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: Line number of the opcode.
 */

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
        stack_t *ttmmpp;

        if (new_node == NULL || *new_node == NULL)
                exit(EXIT_FAILURE);
        if (head == NULL)
        {
                head = *new_node;
                return;
        }
        ttmmpp = head;
        while (ttmmpp->nxt != NULL)
                ttmmpp = ttmmpp->nxt;

        ttmmpp->nxt = *new_node;
        (*new_node)->previus = ttmmpp;

}
