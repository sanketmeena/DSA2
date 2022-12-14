#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
node* root=NULL;

void add_data(int temp)
{
    node* p=(node*)malloc(sizeof(node));
    p->left=NULL;
    p->right=NULL;
    p->data=temp;
    
    if(root==NULL) root=p;
    else
    {
        node* q=root;
        node* r=root;
        
        while(q!=NULL)
        {
            if(q->data > temp) q=q->left;
            else if(q->data < temp) q=q->right;
            else 
            {
                printf("\nEither data is alredy there or can't be add\n");
                return;
            }
            if(q!=NULL) r=q;
        }
        if(temp > r->data) r->right = p;
        else r->left = p;
    }
}

void print_in(node* p)
{
    if(p==NULL) return;
    
    print_in(p->left);
    printf("%d ",p->data);
    print_in(p->right);
}

void print_post(node* p)
{
    if(p==NULL) return;
    
    print_post(p->left);
    print_post(p->right);
    printf("%d ",p->data);
}

void print(node* p)
{
    if(p==NULL) return;
    
    printf("%d ",p->data);
    print(p->left);
    print(p->right);
}

void main()
{
    add_data(7);
    add_data(8);
    add_data(4);
    add_data(5);
    add_data(3);
    add_data(2);
    add_data(1);
    add_data(6);
    
    
    print_in(root); 
    printf("\n");
    
    print_post(root); 
    
    printf("\n");
    print(root);
}