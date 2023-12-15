#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUF 32768
#define MAX_LINES 32768
#define MAX_TOKS 3 /* cuz we only need two token and the 3 tok is a NULL*/
#define NEW_LINE "\n"
#define SPACE " "
#define INSTRCT_EXIST 10 /* instruction does not exist */
#define STACK 1
#define QUEUE 2

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;

extern bus_t bus;
extern stack_t *head;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
stack_t *add_nodeint_queue(stack_t **stack, int n);
ssize_t getstdin(char **lineptr, int file);
size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **stack, int n);
stack_t *create_node(char *str);
char *clean_line(char *content);
int cmd_list(char *input, char *lines[][3]);

/*** pushpull ***/
void _push(stack_t **head, unsigned int line_number);
void _pall(stack_t **head, unsigned int line_number);

void _pint(stack_t **head, unsigned int number);
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void free_stack(stack_t *stack);
void _pop(stack_t **head, unsigned int counter);
void _swap(stack_t **head, unsigned int counter);
void _add(stack_t **head, unsigned int counter);
void _nop(stack_t **head, unsigned int counter);
void _sub(stack_t **head, unsigned int counter);
void _div(stack_t **head, unsigned int counter);
void _mul(stack_t **head, unsigned int counter);
void _mod(stack_t **head, unsigned int counter);
void _pchar(stack_t **head, unsigned int counter);
void _pstr(stack_t **head, unsigned int counter);
void _rotl(stack_t **head, unsigned int counter);
void _rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void free_dlistint(stack_t *head);
void _queue(stack_t **head, unsigned int counter);
void _stack(stack_t **head, unsigned int counter);

/*** miscellaneous ***/
void _launcher(char *lines[][3], int numLines);
void free_grid2(char *grid[][3], int numTokens);
void free_grid(char *lines[][3]);

void exit_err(int flag, char *lines[][3], unsigned int L, char *cmd, int nL);
int func(instruction_t data, char **toks, unsigned int line_number, int mode);

#endif /* MONTY_H */
