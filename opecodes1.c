#include "monty.h"

/**
 * _push - adds a node to the stack
 * @head: double pointer to the head of the stack
 * @line_number: current line number in the file
 */
void _push(stack_t **head, unsigned int line_number)
{
	int n;
	stack_t *new_node;

	if (!bus.arg || !isdigit(*bus.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(bus.arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 * _pall - prints all the values on the stack
 * @head: double pointer to the head of the stack
 * @line_number: current line number in the file
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	(void)line_number;

	while (current != NULL)
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
