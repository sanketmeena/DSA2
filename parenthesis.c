#include<stdio.h>
#include<strings.h>
#include<string.h>
#define CAPACITY 100

char stack[CAPACITY];
int top=-1;

void push(char* c)
{
    top++;
    stack[top]= *c;
}
void pop(char c)
{
    if((c==']' && stack[top]!='[') || (c=='}' && stack[top]!='{') || (c==')' && stack[top]!='('))
    {
        top--;
        return;
    }
    else top--;
}
void main()
{
    char eq[100];
    printf("Enter the eqn : \n");
    scanf("%s",eq);
    
    for(int i=0; i<sizeof(eq)/sizeof(char); i++)
    {
        if(eq[i]=='(' || eq[i]=='{' || eq[i]=='[')
        {
            push(eq+i);
        }
        if(eq[i]==')' || eq[i]=='}' || eq[i]==']')
        {
            pop(eq[i]);
        }
    }
    
    if(top!= -1) printf("\nUnbalanced\n");
    else printf("\nBalanced\n");
}