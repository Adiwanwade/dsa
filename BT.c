#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BT", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
int main()
{

    struct node *p = createNode(7);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(9);
    struct node *p3 = createNode(4);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      7
    //     / \
    //    1   9
    //   / \
    //  4   2

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("The preOrder traversal is:");
     preOrder(p);
    printf("\n");
    printf("The postOrder traversal is :");
    postOrder(p);
    printf("\n");
    printf("The InOrder traversal is :");
    inOrder(p);
    insert(p,3);
    printf("\nThe Element is inserted\n");
    insert(p,8);
    printf("The Element is inserted\n");
    printf("\n");
    printf("The preOrder traversal after insertion is:");
    preOrder(p);
    return 0;
}