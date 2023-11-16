#include "monty.h"

/**
 * __our_monty_nop - This function does
 * absolutely nothing for the Monty opcode 'nop'.
 * @stack: This is the pointer to the top mode node of a stack_t linked list.
 * @line_number: ourcurrent working line number of a Monty bytecodes file.
 */
void __our_monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * __our_monty_pchar - This function will
 * print the character in the top value node of a stack_t linked list.
 * @stack: This is the pointer to the top mode
 * node of a stack_t linked list.
 * @line_number: our current working line number of a Monty bytecodes file.
 */
void __our_monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		__monty_set_op_tok_error(__our_pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		__monty_set_op_tok_error(__our_pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * __our_monty_pstr - This function will print
 * the string contained in a stack_t linked list.
 * @stack: This is pointer to the top mode node of a stack_t linked list.
 * @line_number: our current working line number of a Monty bytecodes file.
 */
void __our_monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}