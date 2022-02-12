#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* Stack Structure */
typedef struct
stacks
{
    int operand;
    struct stacks *next;
}
stacks;

/* Prefix Expression */
int
prefix (char *prefix_str)
{
    stacks *top_stack = NULL;

    /* Read the prefix_str from the end */
    int str_len = strlen(prefix_str);
    for (int i = (str_len - 1); i >= 0; --i )
    {
        stacks *new_node = (stacks*) malloc(sizeof(stacks));
        /* Put in the stacks if operand */
        if (isdigit(prefix_str[i]) != 0)
            new_node->operand = (prefix_str[i] - '0');
        /* Else get 2 operand from the stacks */
        else
        {
            int operand[2];
            for (int j = 0; j < 2; ++j)
            {
                stacks *del_node = top_stack;
                top_stack = top_stack->next;
                del_node->next = NULL;
                operand[j] = del_node->operand;
                free (del_node);
            }
            int result;
            switch (prefix_str[i])
            {
                case '*':
                    result = operand[0] * operand[1];
                    break;
                case '/':
                    result = operand[0] / operand[1];
                    break;
                case '+':
                    result = operand[0] + operand[1];
                    break;
                case '-':
                    result = operand[0] - operand[1];
                    break;
                default:
                    puts ("Non-operator found");
            }
            new_node->operand = result;
        }
        /* Stack it */
        new_node->next = top_stack;
        top_stack = new_node;
    }

    return top_stack->operand;
}

/* Main */
int
main (void)
{
    char prefix_str[25] = "-*+4325";

    printf ("==> %d\n", prefix(prefix_str));

    return 0;
}
