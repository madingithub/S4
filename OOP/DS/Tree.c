#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* create_node(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(int value) {
    if (root == NULL) {
        root = create_node(value);
        return;
    }
    struct node* current = root;
    struct node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->data)
            current = current->left;
        else if (value > current->data)
            current = current->right;
        else {
            printf("Duplicate value. Ignoring insertion.\n");
            return;
        }
    }

    struct node* newNode = create_node(value);
    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

struct node* smallest_node(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* largest_node(struct node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

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
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = smallest_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

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

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int get_data() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    return data;
}

int main() {
    int userchoice;
    char userActive = 'y';
    int data;
    struct node* result = NULL;

    while (userActive == 'y' || userActive == 'Y') {
        printf("\n\n-----Binary Search Tree------\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Get Larger node Data");
        printf("\n5. Get Smaller node data");
        printf("\n\n-----Traversals------");
        printf("\n6. Inorder");
        printf("\n7. Postorder");
        printf("\n8. Preorder");
        printf("\n9. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &userchoice);
        printf("\n");

        switch (userchoice) {
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
                    printf("\nData was found\n");
                } else {
                    printf("\nData does not found!\n");
                }
                break;

            case 4:
                result = largest_node(root);
                if (result != NULL) {
                    printf("\nLargest data: %d\n", result->data);
                }
                break;

            case 5:
                result = smallest_node(root);
                if (result != NULL) {
                    printf("\nSmallest data: %d\n", result->data);
                }
                break;

            case 6:
                printf("\nInorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 7:
                printf("\nPostorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 8:
                printf("\nPreorder traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 9:
                exit(0);

            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &userActive);
    }

    return 0;
}
