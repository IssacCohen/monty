#include "monty.h"
/**
 * _pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void _pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		/* Display an error message if attempting to pop from an empty stack. */
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
