#include "monty.h"

/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: not used (unused parameter)
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return; /* If the stack is empty, there's nothing to print. */
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
