#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main()
{
top=-1;
printf("\nEnter The Size Of Stack[max=100]:");
scanf("%d",&n);
printf("\n\tStack Operations Using Array");
printf("\n\t__________________");
printf("\n\t1.PUSH \n\t2.POP \n\t3.Display \n\t4.Exit");
do
{
printf("\nEnter The Choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
push();
break;
}
case 2:
{
pop();
break;
}
case 3:
{
display();
break;
}
case 4:
{
printf("\n\tExit Point");
break;
}
default:
{
printf("Please Enter a Valid Choice(1/2/3/4)");
}
}
}
while(choice!=4);
return 0;
}
void push()
{
if(top>=n-1)
{
printf("\nStack Is Over Flow");
}
else
{
printf("Enter A Value To Be Pushed:");
scanf("%d",&x);
top++;
stack[top]=x;
}
}
void pop()
{
if(top<=-1)
{
printf("\n\tStack Is Under Flow");
}
else
{
printf("\n\tThe Popped Elements is %d",stack[top]);
top--;
}
}
void display()
{
if(top>=0)
{
printf("\nThe Elements in Stack");
for(i=top;i>=0;i--)
printf("\n %d",stack[i]);
printf("\n Press Next Choice");
}
else
{
printf("\n The Stack is Empty");
}
}
