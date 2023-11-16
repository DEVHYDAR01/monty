#include "monty.h"
/**
 * __our_monty_usage_error - This function will
 * prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int __our_monty_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * __our_monty_malloc_error - Function to print malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int __our_monty_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * __our_monty_f_open_error - This function will print
 * file opening error messages w/ file name.
 * @filename: This is the name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int __our_monty_f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * __our_monty_unknown_op_error - A function to
 * print unknown instruction error messages.
 * @opcode: Our Opcode where error occurred.
 * @line_number: This is the line number
 * in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int __our_monty_unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * __our_monty_no_int_error - Function to print invalid
 * monty_push argument error messages.
 * @line_number: This the line number in Monty bytecodes
 * file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int __our_monty_no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
