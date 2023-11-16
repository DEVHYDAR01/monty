#include "monty.h"

/**
 * __our_monty_push - This function will
 * pushes a value to a stack_t linked list.
 * @stack: This is the pointer to the top mode node of a stack_t linked list.
 * @line_number: This is the current
 * working line number of a Monty bytecodes file.
 */
void __our_monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		__monty_set_op_tok_error(__our_monty_malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		__monty_set_op_tok_error(__our_monty_no_int_error(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			__monty_set_op_tok_error(__our_monty_no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (__our_monty_check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * __our_monty_pall - This function will Print
 * the values of a stack_t linked list.
 * @stack: This is the pointer to the top mode node of a stack_t linked list.
 * @line_number: This is the current working
 * line number of our Monty bytecodes file.
 */
void __our_monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * __our_monty_pint - This function will
 * prints the top value of a stack_t linked list.
 * @stack: This is the pointer to the
 * top mode node of a stack_t linked list.
 * @line_number: This is the current working
 * line number of a Monty bytecodes file.
 */
void __our_monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		__monty_set_op_tok_error(__our_monty_pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * __our_monty_pop - This function will removes
 * the top value element of a stack_t linked list.
 * @stack: This is the pointer to the
 * top mode node of a stack_t linked list.
 * @line_number: This is the current working
 * line number of a Monty bytecodes file.
 */
void __our_monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		__monty_set_op_tok_error(__our_monty_pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * __our_monty_swap - This function swaps the top
 * two value elements of a stack_t linked list.
 * @stack: This is the pointer to the
 * top mode node of a stack_t linked list.
 * @line_number: This is the current working
 * line number of a Monty bytecodes file.
 */
void __our_monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		__monty_set_op_tok_error(__our_monty_short_stack_error(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
