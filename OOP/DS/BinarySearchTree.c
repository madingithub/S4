#include<stdio.h>
#include<stdlib.h>

// Structure of Node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Globally Initialized root pointer
struct node* root=NULL;

// Function Prototypes
struct node* create_node(int);
void insert(int);
struct node* delete_node(struct node*, int);
int search(int);
void inorder(struct node*);
void postorder(struct node*);
void preorder(struct node*);
struct node* smallest_node(struct node*);
struct node* largest_node(struct node*);
int get_data();

int main() {
    int userChoice;
    char userActive = 'Y';
    int data;
    struct node* result = NULL;

    while (userActive == 'Y' || userActive == 'y') {
        printf("\n\n____Binary Search Tree____\n");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Search");
        printf("\n4.Get larger node data");
        printf("\n5.Get Smaller node data");
        printf("\n\n--Traversals--");
        printf("\n6.Inorder");
        printf("\n7.Postorder");
        printf("\n8.Preorder");
        printf("\n9.Exit");

        printf("\n\nEnter Your Choice:");
        scanf("%d", &userChoice);
        printf("\n");

        switch (userChoice) {
        case 1:
            data = get_data();
            insert(data);
            break;

        case 2:
            data = get_data();
            root = delete_node(root, data);
            break;

        case 3:
            data = get_data();
            if (search(data) == 1) {
                printf("\nData was Found!\n");
            } else {
                printf("\nData does not Found!\n");
            }
            break;

        case 4:
            result = largest_node(root);
            if (result != NULL) {
                printf("\nLargest Data:%d\n", result->data);
            }
            break;

        case 5:
            result = smallest_node(root);
            if (result != NULL) {
                printf("\nSmallest Data:%d\n", result->data);
            }
            break;

        case 6:
            printf("\nInorder Traversal:");
            inorder(root);
            printf("\n");
            break;

        case 7:
            printf("\nPostorder Traversal:");
            postorder(root);
            printf("\n");
            break;

        case 8:
            printf("\nPreorder Traversal:");
            preorder(root);
            printf("\n");
            break;

        case 9:
            exit(0);

        default:
            printf("\nInvalid choice. Please enter a valid option.\n");
        }
        printf("\nDo you want to continue?(Y/N):");
        scanf(" %c", &userActive);  // Added a space before %c to consume the newline character.
    }
    return 0;
}

// Function to insert a new node in BST
void insert(int value) {
 if (root == NULL) {
 root=create_node(value);
return;
    }
    struct node* current = root;
    struct node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            printf("Duplicate value. Ignoring Insertion\n");
            return;
        }
    }
    struct node* newNode=create_node(value);
    if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Function to find the smallest value node in a BST
struct node* smallest_node(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to find the largest value node in a BST
struct node* largest_node(struct node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Function to delete a node with a given value from BST
struct node* delete_node(struct node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = delete_node(root->left, value);
    else if (value > root->data)
        root->right = delete_node(root->right, value);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        struct node* temp = smallest_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

// Function to search for a value in BST
int search(int value) {
    struct node* current = root;

    while (current != NULL) {
        if (value == current->data)
            return 1;
        else if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return 0;
}

// Function to perform inorder traversal of BST
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform postorder traversal of BST
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to perform preorder traversal of BST
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to get user input for data
int get_data() {
    int data;
    printf("Enter Data: ");
    scanf("%d", &data);
    return data;
}
