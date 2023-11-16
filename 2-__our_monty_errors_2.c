#include "monty.h"

/**
 * __our_monty_pop_error - A function to print pop
 * error messages for empty stacks.
 * @line_number: Our line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int __our_monty_pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * __our_monty_pint_error - This function will
 * prints pint error messages for empty stacks.
 * @line_number: our line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int __our_monty_pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * __our_monty_short_stack_error - Function to print
 * monty math function error messages
 * for stacks/queues smaller than two nodes.
 * @line_number: ou line number in
 * Monty bytecodes file where error occurred.
 * @op: The Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int __our_monty_short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * __our_monty_div_error - This function will print
 * division error messages for division by 0.
 * @line_number: Our line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int __our_monty_div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * __our_pchar_error - This function will print
 * pchar error messages for empty stacks
 * empty stacks and non-character values.
 * @line_number: our line number in Monty bytecodes file where error occurred.
 * @message: This is the corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int __our_pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
