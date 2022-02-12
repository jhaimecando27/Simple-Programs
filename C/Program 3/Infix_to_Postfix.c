#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* infix_postfix (char *, size_t);

int
main (void)
{
    //char infix[] = "A+B*(C^D-E)"; /* Outout -> "ABCD^E-*+" */
    char infix[] = "a/b-(c+d)-e"; /* Outout -> "ab/cd+e--" */

    printf ("%s\n",infix_postfix(infix, strlen(infix)));

    return 0;
}


typedef struct
stack
{
    char operator;
    struct stack *next;
}
stack;

void
stack_add (stack **top_ref, char c)
{
    stack *new_top = (stack*) malloc(sizeof(stack));
    new_top->operator = c;
    new_top->next = (*top_ref);
    (*top_ref) = new_top;
    return;
}

void
stack_pop (stack **top_ref)
{
    stack *pop_top = (*top_ref);
    (*top_ref) = (*top_ref)->next;
    pop_top->next = NULL;
    free (pop_top);
    return;
}

int
is_operand (char c)
{
    if (isdigit(c) != 0 || isalpha(c) != 0)
        return -1;
    return 0;
}

int
get_prio (char c)
{
    /* By GEMDAS w/o G */
    switch (c)
    {
        case '^':
            return 5;
        case '*':
            return 4;
        case '/':
            return 3;
        case '+':
            return 2;
        case '-':
            return 1;
        /* Not an operator */
        default:
            return 0;
    }
}

char*
infix_postfix (char *infix_ref, size_t len)
{
    stack *top_stack = NULL;
    char *output = (char*) malloc(sizeof(infix_ref) * len);
    
    for (int i = 0; i < len; ++i)
    {
        /* Operand */
        if (is_operand(infix_ref[i]) != 0)
            strncat(output, &infix_ref[i], 1);
        /* Operator Presedence */
        else if (infix_ref[i] == '(')
            stack_add (&top_stack, infix_ref[i]);
        else if (infix_ref[i] == ')')
        {
            while (top_stack->operator != '(')
            {
                strncat(output, &top_stack->operator, 1);
                stack_pop(&top_stack);
            }
            /* Pop the opening parenthesis */
            stack_pop(&top_stack);
        }
        else
        {
            while (top_stack != NULL && (get_prio(infix_ref[i]) < get_prio(top_stack->operator)))
            {
                strncat(output, &top_stack->operator, 1);
                stack_pop(&top_stack);
            }
            stack_add(&top_stack, infix_ref[i]);
        }
    }

    /* Put all remaining operator/s in output */
    while (top_stack != NULL)
    {
        strncat(output, &top_stack->operator, 1);
        stack_pop(&top_stack);
    }

    return output;
}
