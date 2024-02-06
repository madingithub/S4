#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top=NULL;

void push(int value){
struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
new_node->data=value;
new_node->next=top;
top=new_node;
printf("Pushed %d into the stack\n",value);
}

void pop(){
    if(top==NULL){
        printf("Stack is Underflow\n");
        return;
    }
    struct Node* temp=top;
    top=top->next;
    printf("Popped %d from the stack.\n",temp->data);
    free(temp);
}

void display(){
    if(top==NULL){
        printf("Stack is Empty.\n");
        return;
    }
    printf("Stack Elements:");
    struct Node* temp=top;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int choice,value;

    do{
        printf("\nMenu:\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter Value To Push:");
            scanf("%d",&value);
            push(value);
            break;

            case 2:
            pop();
            break;
            case 3:

            display();
            break;

            case 4:
            printf("Exiting Program\n");
            break;

            default:
            printf("Invalid Choice. Please Try Again...\n");

        }
    }
    while(choice!=4);
    return 0;

}