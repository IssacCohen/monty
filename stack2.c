#include "monty.h"

/**
 * _div - Divides the second top element of the
 * stack by the top element.
 * @top: Double pointer to the top of the stack.
 * @value: The value to be divided (not used).
 *
 */
void _div(stack_t **top, unsigned int value)
{
	stack_t *temp;
	(void)value;

	if (!(*top) || !(*top)->next)
	{
		free_stack(*top);
		fprintf(stderr, "L%d: can't div, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->next;
	temp->n = temp->n / (*top)->n;
	(*top) = temp;
	free(temp->prev);
	temp->prev = NULL;
}
/**
 * _mod - Computes the remainder of the division of
 * the second top element
 * of the stack by the top element.
 * @top: Double pointer to the top of the stack.
 * @value: The value to be used (not used in this function).
 */
void _mod(stack_t **top, unsigned int value)
{
	stack_t *temp;
	(void)value;
	if (!(*top) || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->next;
	temp->n = temp->n % (*top)->n;
	(*top) = temp;
	free(temp->prev);
	temp->prev = NULL;
}
/**
 * _pchar - Prints the char at the top of the stack,
 * followed by a new line.
 * @top: Double pointer to the top of the stack.
 * @value: The value to be printed (not used).
 *
 */
void _pchar(stack_t **top, unsigned int value)
{
	(void)value;

	if (!(*top))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n < 0 || (*top)->n > 128)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*top)->n);
	putchar('\n');
}

/**
 * _pstr - Prints a string from the stack as ASCII characters.
 * @top: Pointer to the top of the stack.
 * @value: Unused parameter.
 */
void _pstr(stack_t **top, unsigned int value)
{
	int idx;
	stack_t *tmp;
	(void)value;

	if (top == NULL || *top == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *top;
	while (tmp != NULL)
	{
		idx = tmp->n;
		if (idx < 0 || idx > 127)
			break;
		putchar(idx);
		tmp = tmp->next;
	}
	putchar('\n');
}