#include <stdio.h>
#include <stdlib.h>


/* Clearing the buffer for scanf */
void
clr_buf (void)
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
    return;
}

/* Structure of the node */
typedef struct
node
{
    int data;
    struct node *next;
}
node;

/* Functions for SLL to use to put data */
void
put_data (node **node_ref)
{
    printf("Enter New Data: ");
    scanf("%d", &(*node_ref)->data);
    clr_buf();
    return;
}

/*
 * SLL's functions Starts Here
 */

/* Traversing the nodes of SLL */
void
traverse (node *head_ref)
{
    if (head_ref == NULL)
        return;
    printf("Data: %d\n", head_ref->data);
    traverse (head_ref->next);
    return;
}

/* Adding Node at the Start */
void
add_start (node **head_ref)
{
    /* Get variables needed */
    node *new_node = (node*) malloc(sizeof(node));

    /* Put the data */
    put_data (&new_node);

    /* Fix pointer of new_node */
    new_node->next = (*head_ref);

    /* Fix pointer of SLL */
    (*head_ref) = new_node;
    return;
}

/* Adding Node at the End */
void
add_end (node **head_ref)
{
    /* Get variables needed */
    node *current_node = (*head_ref),
         *new_node = (node*) malloc(sizeof(node));
    
    /* Put the data */
    put_data (&new_node);

    /* Find the location */
    while (current_node != NULL && current_node->next != NULL)
        current_node = current_node->next;

    /* Fix pointer of new_node */
    new_node->next = NULL;

    /* Fix pointer of SLL */
    if (current_node == NULL)
        (*head_ref) = new_node;
    else
        current_node->next = new_node;
    return;
}

/* Adding Node After the given Data */
void
add_after (node **head_ref)
{
    /* Get variables needed */
    int key_data;
    node *current_node = (*head_ref),
         *new_node = (node*) malloc(sizeof(node));
    
    /* Check if not empty */
    if (current_node == NULL)
        return;

    /* Put data */
    put_data (&new_node);

    /* Get the the key */
    printf("Add after what Node?: ");
    scanf("%d", &key_data);
    clr_buf();
    
    /* Find location */
    while (current_node->data != key_data && current_node->next != NULL)
        current_node = current_node->next;

    /* Fix pointer of new_node */
    new_node->next = current_node->next;

    /* Fix pointer of SLL */
    current_node->next = new_node;
    return;
}

/* Adding Node Before the given Data */
void
add_before (node **head_ref)
{
    /* Get variables needed */
    int key_data;
    node *prev_node,
         *current_node = (*head_ref),
         *new_node = (node*) malloc(sizeof(node));

    /* Check if not empty */
    if (current_node == NULL)
        return;

    /* Put data */
    put_data (&new_node);

    /* Get the key */
    printf("Add Before what Data?: ");
    scanf("%d", &key_data);
    clr_buf();

    /* Find location */
    while (current_node->data != key_data && current_node != NULL) 
    {
        prev_node = current_node;
        current_node = current_node->next;
    }
    
    /* If not found */
    if (current_node == NULL)
        return;

    /* Fix pointer of new_node */
    new_node->next = current_node;

    /* Fix pointer of SLL */
    if (current_node == (*head_ref))
        (*head_ref) = new_node;
    else
        prev_node->next = new_node;
    return;
}

/* Deleting Node at the Start */
void
del_start (node **head_ref)
{
    /* Get variables needed */
    node *del_node = (*head_ref);
    
    /* Check if empty */
    if (del_node == NULL)
        return;
    
    /* Change pointer of head */
    (*head_ref) = (*head_ref)->next;

    /* Remove pointer of del_node */
    del_node->next = NULL;

    /* Free the del_node */
    free (del_node);
    return;
}

/* Deleting Node at the End */
void
del_end (node **head_ref)
{
    /* Get variables needed */
    node *prev_node,
         *del_node = (*head_ref);
    
    /* Check if empty */
    if (del_node == NULL)
        return;

    /* Find the location */
    while (del_node->next != NULL)
    {
        prev_node = del_node;
        del_node = del_node->next;
    }
    
    /* Change the pointer of prev_node */
    prev_node->next = del_node->next;

    /* Remove the pointer of del_node */
    del_node->next = NULL;

    /* Free the del_node */
    free (del_node);
    return;
}

/* Deleting Node After the given Data */
void
del_after (node **head_ref)
{
    /* Get variables needed */
    int key_data;
    node *del_node,
         *prev_node = (*head_ref);
    
    /* Check if empty */
    if (prev_node == NULL)
        return;
    
    /* Get data after the key */
    printf("Delete after what data?: ");
    scanf("%d", &key_data);
    clr_buf();

    /* Find the location */
    while (prev_node->next != NULL && prev_node->data != key_data)
        prev_node = prev_node->next;
    
    /* If not found */
    if (prev_node == NULL)
        return;

    /* Fix the pointers */
    del_node = prev_node->next;
    prev_node->next = del_node->next;
    del_node->next = NULL;

    /* Free the del_node */
    free (del_node);
    return;
}

/* Deleting Node Before the given Data */
void
del_before (node **head_ref)
{
    /* Get the variables needed */
    int key_data;
    node *prev_node,
         *del_node = (*head_ref);
    
    /* Check if not empty */
    if (del_node == NULL)
        return;
    
    /* Get the data before the key */
    printf("Delete before what data?: ");
    scanf("%d", &key_data);
    clr_buf();

    /* Find the location */
    while (del_node->next != NULL && del_node->next->data != key_data)
    {
        prev_node = del_node;
        del_node = del_node->next;
    }
    if (del_node == NULL || del_node->next == NULL)
        return;

    /* Change the pointer of prev_node */
    if (del_node == (*head_ref))
        (*head_ref) = (*head_ref)->next;
    else
        prev_node->next = del_node->next;

    /* Remove the pointer of del_node */
    del_node->next = NULL;

    /* Free the node */
    free (del_node);
    return;
}


int
main (void)
{
    node *head = NULL;
    /*** Test the function/s below ***/

    /* Add 5 data */
    for (int i = 0; i < 5; i++) {
        add_end(&head);
    }
    traverse(head);
    printf("\n");
    
    printf("- Add After\n");
    add_after(&head);
    traverse(head);
    printf("\n");
    
    printf("- Add Before\n");
    add_before(&head);
    traverse(head);
    printf("\n");
    
    printf("- Add Start\n");
    add_start(&head);
    traverse(head);
    printf("\n");


    /********************************/
    return 0;
}
