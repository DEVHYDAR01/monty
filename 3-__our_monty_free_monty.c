#include "monty.h"
#include <string.h>

void __our_monty_free_tokens(void);
unsigned int __our_monty_token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * __our_monty_free_tokens - Frees the global op_toks array of strings.
 */
void __our_monty_free_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * __our_monty_token_arr_len - This function will
 * sets the length of current op_toks.
 *
 * Return: This is the length of current op_toks (as int).
 */
unsigned int __our_monty_token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", __our_monty_push},
		{"pall", __our_monty_pall},
		{"pint", __our_monty_pint},
		{"pop", __our_monty_pop},
		{"swap", __our_monty_swap},
		{"add", __our_monty_add},
		{"nop", __our_monty_nop},
		{"sub", __our_monty_sub},
		{"div", __our_monty_div},
		{"mul", __our_monty_mul},
		{"mod", __our_monty_mod},
		{"pchar", __our_monty_pchar},
		{"pstr", __our_monty_pstr},
		{"rotl", __our_monty_rotl},
		{"rotr", __our_monty_rotr},
		{"stack", __our_monty_stack},
		{"queue", __our_monty_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * __our_monty_run_monty - Primary function to
 * execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int __our_monty_run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (__our_monty_init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			__our_monty_free_stack(&stack);
			return (__our_monty_malloc_error());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			__our_monty_free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			__our_monty_free_stack(&stack);
			exit_status = __our_monty_unknown_op_error(op_toks[0], line_number);
			__our_monty_free_tokens();
			break;
		}
		prev_tok_len = __our_monty_token_arr_len();
		op_func(&stack, line_number);
		if (__our_monty_token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			__our_monty_free_tokens();
			break;
		}
		__our_monty_free_tokens();
	}
	__our_monty_free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (__our_monty_malloc_error());
	}

	free(line);
	return (exit_status);
}
