#include "monty.h"

/**
 * _push - adds a node to the stack
 * @head: double pointer to the head of the stack
 * @line_number: current line number in the file
 */
bus_t bus = {NULL, NULL, NULL, 0};
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
