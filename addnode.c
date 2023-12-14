#include "monty.h"

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    aux = *head;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        /* Display an error message and free previously allocated memory */
        fprintf(stderr, "Error: Memory allocation failed\n");

        /* Free existing stack */
        free_stack(*head);

        exit(EXIT_FAILURE);
    }

    if (aux)
        aux->prev = new_node;

    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;
}
