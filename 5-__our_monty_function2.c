#include "monty.h"
/**
 * __our_monty_add - This function will add the
 * top two values of a stack_t linked list.
 * @stack: This is the pointer to the top mode
 * node of a stack_t linked list.
 * @line_number: This is the current working line
 * number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 * from the top and the top value  is removed.
 */
void __our_monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		__monty_set_op_tok_error(__our_monty_short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	__our_monty_pop(stack, line_number);
}

/**
 * __our_monty_sub - This function will subtract
 * the second value from the top of
 * a stack_t linked list by the top value.
 * @stack: This is the pointer to the top
 * mode node of a stack_t linked list.
 * @line_number: This our current working
 * line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */
void __our_monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		__monty_set_op_tok_error(__our_monty_short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	__our_monty_pop(stack, line_number);
}

/**
 * __our_monty_div - This function divides the
 * second value from the top of
 * a stack_t linked list by the top value.
 * @stack: This is the pointer to the top mode node of a stack_t linked list.
 * @line_number: This the current working line
 * number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */
void __our_monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		__monty_set_op_tok_error(__our_monty_short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		__monty_set_op_tok_error(__our_monty_div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	__our_monty_pop(stack, line_number);
}

/**
 * __our_monty_mul - This function will
 * multiply the second value from the top of
 * a stack_t linked list by the top value.
 * @stack: This is the pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */
void __our_monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		__monty_set_op_tok_error(__our_monty_short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	__our_monty_pop(stack, line_number);
}

/**
 * __our_monty_mod - This function computes the
 * modulus of the second value from the
 * top of a stack_t linked list  by the top value.
 * @stack: This is the pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */
void __our_monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		__monty_set_op_tok_error(__our_monty_short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		__monty_set_op_tok_error(__our_monty_div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	__our_monty_pop(stack, line_number);
}
