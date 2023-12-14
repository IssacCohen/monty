#include "monty.h"

/**
 * _push - Pushes an element onto the stack.
 * @head: Pointer to the head of the stack
 * @number: Value to be pushed onto the stack
 */
void _push(stack_t **head, unsigned int number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->prev = NULL;

	if (*head)
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*head = new_node;
}

/**
 * _pall - Prints all the values on the stack.
 * @head: Pointer to the head of the stack
 * @line_number: Line number in the file
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
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
