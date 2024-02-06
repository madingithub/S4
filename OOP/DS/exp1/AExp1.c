#include<stdio.h>
#include<string.h>


#define max 100
int top,stack[max];

void push(char x)
{

//Push(Inserting Element in Stack)Operation
if(top==max-1)
{
printf("Stack Overflow");
}
else
{
stack[++top]=x;
}
}

void pop()
{
//Pop(Removing Element from stack)
printf("%c",stack[top--]);
}


void main()
{
char str[]="Sri Lanka";
int len=strlen(str);
int i;

for(i=0;i<len;i++)
push(str[i]);

for(i=0;i<len;i++)
pop();
}

