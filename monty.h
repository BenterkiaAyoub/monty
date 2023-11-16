#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - Doubly linked list representation of a stack or queue
 * @nm: Integer value stored in the node
 * @previus: Points to the previous element in the stack or queue
 * @nxt: Points to the nxt element in the stack or queue
 *
 * Description: Doubly linked list node structure for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
        int nm;
        struct stack_s *previus;
        struct stack_s *nxt;
} stack_t;

/**
 * struct instruction_s - Opcode and its corresponding function
 * @opcd: The opcd
 * @f: Function to handle the opcd
 *
 * Description: Structure representing an opcd and its associated function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
        char *opcd;
        void (*f)(stack_t **stack, unsigned int lenn);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*Operations*/
void opFl(char *file_name);
int parseLn(char *buffer, int lenn, int format);
void readFl(FILE *);
int charLn(FILE *);
void funFind(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int nm);
void free_nodes(void);
void stackPrint(stack_t **, unsigned int);
void addStack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void topPrint(stack_t **, unsigned int);
void topPop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void nodesSwap(stack_t **, unsigned int);

/*Math operations*/
void nodesAdd(stack_t **, unsigned int);
void nodesSub(stack_t **, unsigned int);
void nodeDiv(stack_t **, unsigned int);
void nodeMul(stack_t **, unsigned int);
void nodesMod(stack_t **, unsigned int);

/*String operations*/
void charPrint(stack_t **, unsigned int);
void stringPrint(stack_t **, unsigned int);
void rotll(stack_t **, unsigned int);

/*Errors*/
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif

