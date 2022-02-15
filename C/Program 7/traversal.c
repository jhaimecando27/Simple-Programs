#include <stdio.h>
#include <stdlib.h>

typedef struct
tree
{
    int data;
    struct tree *left, *right;
}
tree;

typedef struct
stack
{
    tree *node;
    struct stack *next;
}
stack;

void
stack_add (stack **top_ref, tree *node_ref)
{
    stack *new_node = (stack*) malloc(sizeof(stack));
    new_node->node = node_ref;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
    return;
}

void
stack_pop (stack **top_ref)
{
    stack *del = (*top_ref);
    (*top_ref) = (*top_ref)->next;
    del->next = NULL;
    free(del);
    return;
}

struct tree*
new_node (int data)
{
    tree *node = (tree*) malloc(sizeof(tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* ============================
 *  Tree Traversal (Iterative)
 * ============================*/

/* Preorder */
void
preorder_iter (tree *root_ref)
{
    stack *top = NULL;
    tree *curr = root_ref;
    do
    {
        /* Display data 
         * and go to deepest left */
        if (curr)
        {
            printf("[%d] ", curr->data);
            stack_add(&top, curr);
            curr = curr->left;
        }
        /* If NULL backlog then go to right */
        else
        {
            curr = top->node;
            stack_pop(&top);
            curr = curr->right;
        }
    } while (top || curr);
    return;
}

void
inorder_iter (tree *root_ref)
{
    stack *top = NULL;
    tree *curr = root_ref;

    do
    {
        /* Go to deepest left */
        if (curr)
        {
            stack_add(&top, curr);
            curr = curr->left;
        }
        /* If NULL Display data
         * and backlog then go to right */
        else
        {
            curr = top->node;
            stack_pop(&top);
            printf("[%d] ", curr->data);
            curr = curr->right;
        }
    } while (top || curr);
}

void
postorder_iter_1s (tree *root_ref)
{
    stack *stack_top = NULL;
    tree *curr = root_ref, *prev = NULL;
    
    do
    {
        while (curr)
        {
            if (curr->right)
                stack_add(&stack_top, curr->right);
            stack_add(&stack_top, curr);
            curr = curr->left;
        }
        
        curr = stack_top->node;
        stack_pop(&stack_top);
        
        if (curr->right && stack_top && stack_top->node == curr->right)
        {
            stack_pop(&stack_top);
            stack_add(&stack_top, curr);
            curr = curr->right;
        }
        else
        {
            printf("[%d] ", curr->data);
            curr = NULL;
        }
    } while (stack_top != NULL);
    return;
}

void
postorder_iter_2s (tree *root_ref)
{
    stack *top1 = NULL, *top2 = NULL;
    tree *curr = root_ref;

    stack_add(&top1, curr);
    tree *node;

    while (top1)
    {
        node = top1->node;
        stack_pop(&top1);
        stack_add(&top2, node);
     
        if (node->left)
            stack_add(&top1, node->left);
        if (node->right)
            stack_add(&top1, node->right);
    }

    while (top2)
    {
        printf("[%d] ", top2->node->data);
        stack_pop(&top2);
    }
    return;
}

/* ============================
 *  Tree Traversal (Recursion)
 * ============================*/

void
preorder_recur (tree *root_ref)
{
    if (!root_ref)
        return;

    printf("[%d] ", root_ref->data);
    preorder_recur(root_ref->left);
    preorder_recur(root_ref->right);
}

void
inorder_recur (tree *root_ref)
{
    if (root_ref == NULL)
        return;

    inorder_recur(root_ref->left);
    printf("[%d] ", root_ref->data);
    inorder_recur(root_ref->right);
}

void
postorder_recur (tree *root_ref)
{
    if (root_ref == NULL)
        return;

    postorder_recur(root_ref->left);
    postorder_recur(root_ref->right);
    printf("[%d] ", root_ref->data);
}
int
main (void)
{
    tree *root = NULL;
    root = new_node(8);
    root->left = new_node(4);
    root->left->left = new_node(2);
    root->left->right = new_node(6);

    root->right = new_node(12);
    root->right->left = new_node(10);
    root->right->right = new_node(14);
    root->right->right->left = new_node(13);
    root->right->right->right = new_node(15);
    printf("\n");

    inorder_iter(root);
    printf("\n");
    inorder_recur(root);
    printf("\n");

    return 0;
}
