#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

void append(int data){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
    if (head==NULL){
        head=new_node;
        return;
    }
    struct Node* last_node=head;
    while(last_node->next!=NULL){
        last_node=last_node->next;
    }
    last_node->next=new_node;
}

void display(){
    struct Node* current=head;
    printf("Linked List:");
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}

void deleteNode(int key){
    struct Node* temp=head;
    struct Node*prev=NULL;
    if(temp!=NULL && temp->data==key){
        head=temp->next;
        free(temp);
        printf("Node with data %d deleted successfully.\n,key");
        return;
    }
    while(temp!=NULL && temp-> data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Node with data %d not found \n",key);
        return;
    }
    prev->next=temp->next;
    free(temp);
    printf("Node with data %d deleted successfully\n",key);
}

int main(){
    int choice,data,key;

    while(1){
        printf("\n1.Append to the Linked List\n");
        printf("Display the Linked List\n");
        printf("Delete a Node\n");
        printf("Exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter Data to Append:");
            scanf("%d",&data);
            append(data);
            break;

            case 2:
            display();
            break;

            case 3:
            printf("Enter the Data of the node to delete:");
            scanf("%d",&key);
            deleteNode(key);
            break;

            case 4:
            printf("Exiting Program\n");
            exit(0);

            default:
            printf("Invalid choice. Please Enter 1.2.3 or 4");
        }
    }
    return 0;
}
