#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node *left;
    Node *right;
};
Node *Create_Node(int data)
{
    Node *new_node=(Node *) malloc(sizeof(Node));
    if(new_node==NULL)
    {
        printf("Error for creating new node.");
        exit(1);
    }
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}
void add_left_child(Node *node,Node *child)
{
    node->left=child;
}
void add_right_child(Node *node,Node *child)
{
    node->right=child;
}
Node *Create_Tree()
{
    Node *one=Create_Node(1);
    Node *two=Create_Node(2);
    Node *three=Create_Node(3);
    add_left_child(one,two);
    add_right_child(one,three);

    Node *four=Create_Node(4);
    Node *five=Create_Node(5);
    add_left_child(two,four);
    add_right_child(two,five);

    Node *six=Create_Node(6);
    Node *seven=Create_Node(7);
    add_left_child(three,six);
    add_right_child(three,seven);

    return one;
}
void pre_order(Node *node)
{
    printf("%d",node->data);
    if(node->left!=NULL)
    {
        pre_order(node->left);
    }
    if(node->right!=NULL)
    {
        pre_order(node->right);
    }
}
void post_order(Node *node)
{
    if(node->left!=NULL)
    {
        post_order(node->left);
    }
    if(node->right!=NULL)
    {
        post_order(node->right);
    }
    printf("%d",node->data);
}
void in_order(Node *node)
{
    if(node->left!=NULL)
    {
        in_order(node->left);
    }

    printf("%d",node->data);

    if(node->right!=NULL)
    {
        in_order(node->right);
    }
}
int main()
{
    Node *root=Create_Tree();
    //printf("%d",root->data);
    //pre_order(root);
    //post_order(root);
    in_order(root);
}
