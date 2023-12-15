#include "monty.h"

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
