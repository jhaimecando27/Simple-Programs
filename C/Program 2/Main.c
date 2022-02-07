#include <stdio.h>
#include <stdlib.h>


/* Clearing the buffer for scanf */
void
clr_buf (void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    return;
}

/* Structure of node */
typedef struct
node
{
    int data;
    struct node *next, *prev;
}
node;

/* Functions for DLL to use to put data */
void
put_data (node **node_ref)
{
    printf("Enter Data: ");
    scanf("%d", &(*node_ref)->data);
    clr_buf();
    return;
}

/* 
 * Functions for DLL 
 */

/* Traversing from top to bottom */
void
traverse_tb (node *head_ref)
{
    if (head_ref == NULL)
        return;
    printf("Data: %d\n", head_ref->data);
    traverse_tb (head_ref->next);
    return;
}
/* Traversing from bottom to top */
void
traverse_bt (node *tail_ref)
{
    if (tail_ref == NULL)
        return;
    printf("Data: %d\n", tail_ref->data);
    traverse_bt (tail_ref->prev);
    return;
}

/* Adding node at the Start */
void
adding_start (node **head_ref, node **tail_ref)
{
    /* Get the variables needed */
    node *new_node = (node*) malloc(sizeof(node));
    
    /* Put the Data */
    put_data(&new_node);

    /* Connect the pointers of new_nde to DLL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    /* Fix the pointers of DLL */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    else {
        (*tail_ref) = new_node;
    }
    (*head_ref) = new_node;
    new_node = NULL;
    return;
}

/* Adding node at the End */
void
adding_end (node **head_ref, node **tail_ref)
{
    /* Get the variables needed */
    node *new_node = (node*) malloc(sizeof(node));
    
    /* Put the Data */
    put_data(&new_node);
    
    /* Connect the pointers of new_node to DLL */
    new_node->next = NULL;
    new_node->prev = (*tail_ref);
    
    /* Fix the pointers of DLL */
    if ((*tail_ref) != NULL)
        (*tail_ref)->next = new_node;
    else
        (*head_ref) = new_node;
    (*tail_ref) = new_node;
    return;
}

/* Adding node After the given Data */
void
adding_after (node **head_ref, node **tail_ref)
{
    /* Get the variables needed */
    int key_data;
    node *current_node = (*head_ref),
         *new_node = (node*) malloc(sizeof(node));
    
    /* Check if empty */
    if (current_node == NULL)
        return;
    
    /* Put the Data */
    put_data (&new_node);

    /* Get data after the key */
    printf("Add after what Data?: ");
    scanf("%d", &key_data);
    clr_buf();
    
    /* Find the location */
    while (current_node->data != key_data && current_node->next != NULL)
        current_node = current_node->next;
    
    /* If not found */
    if (current_node == NULL)
        return;

    /* Connect the pointers of new_node to DLL */
    new_node->next = current_node->next;
    new_node->prev = current_node;

    /* Fix the pointers of DLL */
    if (current_node == (*tail_ref))
        (*tail_ref) = new_node;
    else
        current_node->next->prev = new_node;
    current_node->next = new_node;
    return;
}

/* Adding node Before the given Data */
void
adding_before (node **head_ref, node **tail_ref)
{
    /* Get the variables needed */
    int key_data;
    node *current_node = (*head_ref),
         *new_node = (node*) malloc(sizeof(node));
    
    /* Check if empty */
    if (current_node == NULL)
        return;
    
    /* Put the Data */
    put_data(&new_node);

    /* Get the data before key */
    printf("Add before what Data?: ");
    scanf("%d", &key_data);
    clr_buf();
    
    /* Find the location */
    while (current_node->data != key_data && current_node != NULL)
        current_node = current_node->next;
    
    /* If not found */
    if (current_node == NULL)
        return;

    /* Connect the pointers of new_nde to DLL */
    new_node->next = current_node;
    new_node->prev = current_node->prev;

    /* Fix the pointers of DLL */
    if (current_node == (*head_ref))
        (*head_ref) = new_node;
    else
        current_node->prev->next = new_node;
    current_node->prev = new_node;
    return;
}

/* Deleting node at the Start */
void
del_start (node **head_ref)
{
    /* Get variables needed */
    node *del_node = (*head_ref);
    
    /* Check if empty */
    if (del_node == NULL)
        return;

    /* Fix the head */
    (*head_ref) = (*head_ref)->next;
    (*head_ref)->prev = NULL;

    /* Remove the pointers of del_node */
    del_node->next = NULL;

    /* Free the del_node */
    free (del_node);
    return;
}

/* Deleting node at the End */
void
del_end (node **tail_ref)
{
    /* Get variables needed */
    node *del_node = (*tail_ref);
    
    /* Check if empty */
    if (del_node == NULL)
        return;

    /* Fix the tail */
    (*tail_ref) = (*tail_ref)->prev;
    (*tail_ref)->next = NULL;

    /* Remove the pointers of del_node */
    del_node->prev = NULL;

    /* Free the del_node */
    free (del_node);
    return;
}

/* Deleting node After the given Data */
void
del_after (node **head_ref, node **tail_ref)
{
    /* Get variables needed */
    int key_data;
    node *del_node,
         *current_node = (*head_ref);

    /* Check if empty */
    if (del_node == NULL)
        return;
    
    /* Get the data after the key */
    printf("Delete after what Data?: ");
    scanf("%d", &key_data);
    clr_buf();

    /* Find the location */
    while (current_node != NULL && current_node->data != key_data)
        current_node = current_node->next;
    
    /* If not found */
    if (del_node == NULL)
        return;
    /* Else */
    del_node = current_node->next;

    /* Reconnect the pointers of two nodes around it */
    if (del_node == (*tail_ref))
        (*tail_ref) = (*tail_ref)->prev;
    else
        del_node->next->prev = current_node;
    current_node->next = del_node->next;

    /* Remove the pointers of del_node */
    del_node->next = NULL;
    del_node->prev = NULL;

    /* Free the del_node */
    free (del_node);
    return;
}

/* Deleting node Before the given Data */
void
del_before (node **head_ref, node **tail_ref)
{
    /* Get variables needed */
    int key_data;
    node *del_node,
         *current_node = (*head_ref);

    /* Check if not empty */
    if (current_node == NULL)
        return;
    
    /* Get the key */
    printf("Delete before what Data?: ");
    scanf("%d", &key_data);
    clr_buf();
    
    /* Find the location */
    while (current_node != NULL && current_node->data != key_data)
        current_node = current_node->next;
    
    /* If not found */
    if (current_node == NULL)
        return;
    /* Else */
    del_node = current_node->prev;

    /* Reconnect the pointers of two nodes around it */
    if (del_node == (*head_ref))
        (*head_ref) = (*head_ref)->next;
    else
        del_node->prev->next = current_node;
    current_node->prev = del_node->prev;

    /* Remove the pointers of del_node */
    del_node->next = NULL;
    del_node->prev = NULL;

    /* Free the del_node */
    free (del_node);
    return;
}


int
main (void)
{
    node *head = NULL,
         *tail = NULL;
    /*** Try the fuction/s below ***/
    
    /* Add 5 data */
    for (int i = 0; i < 5; i++) {
        adding_end(&head, &tail);
    }
    traverse_tb(head);
    printf("\n");
    
    printf("- Add After\n");
    adding_after(&head, &tail);
    traverse_tb(head);
    printf("\n");
    
    printf("- Add Before\n");
    adding_before(&head, &tail);
    traverse_tb(head);
    printf("\n");
    
    printf("- Add Start\n");
    adding_start(&head, &tail);

    traverse_tb(head);
    traverse_bt(tail);
    printf("\n");

    /********************************/
    return 0;
}
