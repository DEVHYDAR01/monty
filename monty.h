#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* ThIS IS THE GLOBAL OPCODE TOKENS */
extern char **op_toks;

/* THIS  IS OUR PRIMARY INTERPRETER FUNCTIONS */
void __our_monty_free_stack(stack_t **stack);
int __our_monty_init_stack(stack_t **stack);
int __our_monty_check_mode(stack_t *stack);
void __our_monty_free_tokens(void);
unsigned int __our_monty_token_arr_len(void);
int __our_monty_run_monty(FILE *script_fd);
void __monty_set_op_tok_error(int error_code);

/* THIS WILL BE OUR OPCODE FUNCTIONS */
/*THIS IS FOR FUNCTION 1*/
void __our_monty_push(stack_t **stack, unsigned int line_number);
void __our_monty_pall(stack_t **stack, unsigned int line_number);
void __our_monty_pint(stack_t **stack, unsigned int line_number);
void __our_monty_pop(stack_t **stack, unsigned int line_number);
void __our_monty_swap(stack_t **stack, unsigned int line_number);
/*THIS IS FOR FUNCTION 2*/
void __our_monty_add(stack_t **stack, unsigned int line_number);
void __our_monty_sub(stack_t **stack, unsigned int line_number);
void __our_monty_div(stack_t **stack, unsigned int line_number);
void __our_monty_mul(stack_t **stack, unsigned int line_number);
void __our_monty_mod(stack_t **stack, unsigned int line_number);
/*THIS IS FOR FUNCTION 3*/
void __our_monty_nop(stack_t **stack, unsigned int line_number);
void __our_monty_pchar(stack_t **stack, unsigned int line_number);
void __our_monty_pstr(stack_t **stack, unsigned int line_number);
/*THIS IS FOR FUNCTION 4*/
void __our_monty_rotl(stack_t **stack, unsigned int line_number);
void __our_monty_rotr(stack_t **stack, unsigned int line_number);
void __our_monty_stack(stack_t **stack, unsigned int line_number);
void __our_monty_queue(stack_t **stack, unsigned int line_number);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* ERROR MESSAGES & ERROR CODES */
/*THIS IS THE FUNCTION FOR ERROR 1*/
int __our_monty_usage_error(void);
int __our_monty_malloc_error(void);
int __our_monty_f_open_error(char *filename);
int __our_monty_unknown_op_error(char *opcode, unsigned int line_number);
int __our_monty_no_int_error(unsigned int line_number);
/*THIS IS THE FINCTION FOR ERROR 2*/
int __our_monty_pop_error(unsigned int line_number);
int __our_monty_pint_error(unsigned int line_number);
int __our_monty_short_stack_error(unsigned int line_number, char *op);
int __our_monty_div_error(unsigned int line_number);
int __our_pchar_error(unsigned int line_number, char *message);
#endif /* END OF MONTY */
