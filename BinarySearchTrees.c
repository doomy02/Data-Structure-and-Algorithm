#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left, *right;
} NodeT;

void preorder(NodeT *p)
{
    if(p != NULL)
    {
        printf("%d ", p -> key);
        preorder(p -> left);
        preorder(p -> right);
    }
}

void postorder(NodeT *p)
{
    if(p != NULL)
    {
        postorder(p -> left);
        postorder(p -> right);
        printf("%d ", p -> key);
    }
}

void inorder(NodeT *p)
{
    if(p != NULL)
    {
        inorder(p -> left);
        printf("%d ", p -> key);
        inorder(p -> right);
    }
}

NodeT *insert(NodeT *root, int x)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    NodeT *croot;
    NodeT *aux = NULL;

    croot = root;
    p -> key = x;
    p -> left = NULL;
    p -> right = NULL;

    if(root == NULL)
        return p;

    while(root != NULL)
    {
        aux = root;
        if(root -> key > x)
            root = root -> left;
        else if(root -> key < x)
            root = root -> right;
    }

    if(aux -> key > x)
        aux -> left = p;
    else if(aux -> key < x)
        aux -> right = p;

    return croot;
}

NodeT *insert_rec(NodeT *root, int x)
{
    if(root == NULL)
    {
        NodeT *p = (NodeT*)malloc(sizeof(NodeT));
        p -> key = x;
        p -> left = NULL;
        p -> right = NULL;
        return p;
    }
    else if(root -> key == x)
        return -1;
    else if(root -> key > x)
        return insert_rec(root -> left, x);
    else if(root -> key < x)
        return insert_rec(root -> right, x);
    return root;
}

NodeT *search(NodeT *root, int x)
{
    if(root == NULL || root -> key == x)
        return root;
    else if(root -> key > x)
        return search(root -> left, x);
    else if(root -> key < x)
        return search(root -> right, x);
}

NodeT *MIN(NodeT *root)
{
    if(root == NULL)
        return NULL;
    else if(root -> left != NULL)
    {
        root = root -> left;
        return MIN(root);
    }
    return root -> key;
}

NodeT *MAX(NodeT *root)
{
    if(root == NULL)
        return NULL;
    else if(root -> right != NULL)
    {
        root = root -> right;
        return MAX(root);
    }
    return root -> key;
}

NodeT *del(NodeT *root, int x)
{
    NodeT *p;
    if(root == NULL)
        return root;
    else if(root -> key > x)
        root -> left = del(root -> left, x);
    else if(root -> key < x)
        root -> right = del(root -> right, x);
    else
    {
        if(root -> left == NULL)
        {
            p = root -> right;
            free(root);
            return p;
        }
        else if(root -> right == NULL)
        {
            p = root -> left;
            free(root);
            return p;
        }
        p = MIN(root -> right);
        root -> key = p -> key;
        root -> right = del(root -> right, p -> key);
    }
    return p;
}

NodeT *succesor(NodeT *node, NodeT *root)
{
    if(root == NULL || node == NULL)
        return NULL;

    if(node -> right != NULL)
        return MIN(node -> right);

    NodeT *p = root;
    NodeT *succ = NULL;

    while(p -> key != node -> key)
    {
        if(p -> key > node -> key)
            succ = p;
        if(node -> key < p -> key)
            p = p -> left;
        else if(node -> key > p -> key)
            p = p -> right;
    }
    return succ;
}

NodeT *predeccesor(NodeT *node, NodeT *root)
{
    if(root == NULL || node == NULL)
        return NULL;

    if(node -> left != NULL)
        return MAX(node -> left);

    NodeT *p = root;
    NodeT *pred = NULL;

    while(p -> key != node -> key)
    {
        if(p -> key > node -> key)
            pred = p;
        if(node -> key < p -> key)
            p = p -> left;
        else if(node -> key > p -> key)
            p = p -> right;
    }
    return pred;
}

int main()
{
    NodeT *r = NULL;
    NodeT *t = NULL;

    r = insert_rec(r, 10);
    r = insert(r, 33);
    r = insert(r, 3);
    r = insert(r, 999);
    r = insert(r, 2);

    printf("PREORDER: ");
    preorder(r);
    printf("\nINORDER: ");
    inorder(r);
    printf("\nPOSTORDER: ");
    postorder(r);

    r = search(r, 10);
    if(r != NULL)
        printf("\nFOUND!");
    else
        printf("\nNOT FOUND!");

    printf("\nMIN: %d \nMAX: %d", MIN(r), MAX(r));
    printf("\nSUCCESOR: %d\nPREDECCESOR: %d", succesor(MIN(r), r), predeccesor(MAX(r), r));

    return 0;
}
