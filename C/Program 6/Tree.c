#include <stdio.h>
#include <stdlib.h>

typedef struct
tree
{
    int data;
    struct tree *left, *right;
}
tree;

/* ==========
 * Tree Search, Insertion, & Deletion 
 * ========== */

/* Tree Insertion */
void
insert (tree **parent, int key)
{
    /* Create new_node */
    tree *new_node = (tree*) malloc(sizeof(tree));
    new_node->data = key;
    new_node->left = NULL;
    new_node->right = NULL;

    tree *curr = (*parent), *prev = NULL;

    /* Locate using inorder */
    while (curr)
    {
        prev = curr;
        curr = (key < curr->data)? curr->left: curr->right;
    }

    /* Place the new_node */
    if (!prev)
        (*parent) = new_node;
    else if (key < prev->data)
        prev->left = new_node;
    else
        prev->right = new_node;
}

/* Tree Search */
void
search (tree *parent, int key)
{
    /* Locate using inorder */
    while (parent && parent->data != key)
        parent = (key < parent->data)? parent->left: parent->right;

    if (!parent)
        printf("Not found\n");
    else
        printf("Found\n");
}


/* Tree Delete */
tree * 
del_node_iter(tree *root, int key)
{
    tree *curr = root, *prev = NULL;

    /* Find key */
    while (curr && curr->data != key)
    {
        prev = curr;
        curr = (key < curr->data)? curr->left: curr->right;
    }

    if (!curr)
        return root;

    /* Possible num of child of the node to be deleted */
    /* Case 1: 0 or 1 child */
    if (!curr->left || !curr->right)
    {
        /* new_curr will replace
         * the node to be deleted */
        tree *new_curr = (curr->left)? curr->left: curr->right;
     
        /* Check if the node to
         * be deleted is the root */
        if (!prev)
            return new_curr;
     
        /* Replace the deleted node as new_curr */
        if (curr == prev->left)
            prev->left = new_curr;
        else
            prev->right = new_curr;
     
        free(curr);
    }
    
    /* Case 2: 2 child */
    else
    {
        tree *p = NULL, *temp = curr->right;
     
        /* Compute the inorder successor */
        while (temp->left)
        {
            p = temp;
            temp = temp->left;
        }
     
        /* Check if the parent of the inorder successor
         * is the curr or not */
        if (p)
            p->left = temp->right;
        else
            curr->right = temp->right;
     
        curr->data = temp->data;
        free(temp);
    }
    return root;
}

tree* 
del_node_recur(tree *root, int key)
{
    if (!root)
        return root;

    /* Find Key */
    if (key < root->data)
        root->left = del_node_recur(root->left, key);
    else if (key > root->data)
        root->right = del_node_recur(root->right, key);
    /* Possible num of child of the node to be deleted */
    else
    {
        /* Case 1: 0 or 1 child */
        if (!root->left)
        {
            tree *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right)
        {
            tree *temp = root->left;
            free(root);
            return temp;
        }
     
        /* Case 2: 2 child */
        tree *temp = root->right;
        while (temp && temp->left)
            temp = temp->left;
     
        root->data = temp->data;
     
        /* Deleted the inorder successor */
        root->right = del_node_recur(root->right, temp->data);
    }
    return root;
}

void
trav (tree *root_ref)
{
    if (root_ref == NULL)
        return;

    trav (root_ref->left);
    printf("[%d] ", root_ref->data);
    trav (root_ref->right);
}

void
free_tree (tree *root_ref)
{
    if (root_ref == NULL)
        return;

    free_tree((root_ref)->left);
    free_tree((root_ref)->right);
    free(root_ref);
}

int
main (void)
{
    tree *root = NULL;
    
    /* Example tree */
    insert(&root, 8),
    insert(&root, 12),
    insert(&root, 4),
    insert(&root, 14),
    insert(&root, 10),
    insert(&root, 2),
    insert(&root, 15),
    insert(&root, 13),
    insert(&root, 11),
    insert(&root, 9),
    insert(&root, 1),
    insert(&root, 5),

    trav(root);
    printf("\n");
    printf("\n");

    root = del_node_recur(root, 12);
    printf("\n");

    trav(root);
    printf("\n");

    free_tree(root);
    
    return 0;
}
