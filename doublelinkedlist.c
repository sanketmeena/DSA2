#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
node* root=NULL;

void add_data()
{
    //form a node
    node* p=(node*)malloc(sizeof(node));
    p->left=NULL;
    p->right=NULL;
    printf("\nEnter the data : ");
    scanf("%d",&p->data);
    //node is ready
    
    if(root==NULL) root=p;
    else
    {
        node* q=root;
        
        //going to end of list
        while(q->right!=NULL)
        {
            q=q->right;
        }
        
        //link the node at the end
        q->right=p;
        p->left=q;
    }
}

void delete_data()
{
    node* p=root;
    printf("\nEnter the data to delete : ");
    int k;
    scanf("%d",&k);
    
    //for root
    if(k==root->data)
    {
        root=root->right;
        root->left=NULL;
        free(p);
    }
    else
    {
        //traverse to the node
        while(p->data!=k) p=p->right;
        
        if(p->right==NULL)
        {
            p->left->right=NULL;
            free(p);
            return;
        }
        
        p->right->left=p->left;
        p->left->right=p->right;
        free(p);
    }
}

void print()
{
    node* p=root;
    printf("\nThe data present is : \n");
    
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->right;
    }
}

void print_rev()
{
    node* p=root;
    printf("\nThe data in reverse order is : \n");
    
    while(p->right!=NULL) p=p->right;
    
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->left;
    }
}

int main()
{
    while(1)
    {
        printf("\n1. Add data\n");
        printf("2. Delete data\n");
        printf("3. Print Data\n");
        printf("4. print reverse data\n");
        
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : add_data();
            break;
            case 2 : delete_data();
            break;
            case 3 : print();
            break;
            case 4 : print_rev();
            break;
            default: printf("\nEnter right choise\n");
            break;
        }
    }
    return 0;
}