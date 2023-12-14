#include "monty.h"

/**
 * _push - adds a node to the stack or queue
 * @stack: the node
 * @line_number: the line number of the instruction
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	/** head is the global variable for the stack or queue*/
	add_dnodeint(&head, (*stack)->n); /**stack->n is the value of the new node*/
	free(tmp);
}

/**
 * _pall - prints the stack or queue
 * @stack: the node
 * @line_number: the line number of the instruction
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	/*if (head != NULL)*/
	print_dlistint(head); /** head is the stack or queue*/
}

/**
 * _pint -  prints the value at the top of the stack, followed by a new line
 * @stack: the node
 * @line_number: the line number of the instruction
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	printf("%d\n", head->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: the node
 * @line_number: the line number of the instruction
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) stack; /**stack is not used in this function **/
	(void) line_number;
	tmp = head;
	head = head->next;
	free(tmp);
}

/**
 * _swap -  swaps the top two elements of the stack
 * @stack: the node
 * @line_number: the line number of the instruction
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp = head->n;
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	head->n = (head->next)->n;
	(head->next)->n = tmp;
}
