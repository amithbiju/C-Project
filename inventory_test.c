#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct {
    int productId;
    char productName[50];
    float costPrice;
    float sellingPrice;
    int quantityInStock;
} Product;

// Binary tree node
typedef struct TreeNode {
    Product product;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function prototypes
TreeNode* insert(TreeNode* root, Product product);
void displayProducts(TreeNode* root);
TreeNode* findProduct(TreeNode* root, int productId);
void processOrder(TreeNode* root, int productId, int quantity);
void freeTree(TreeNode* root);

int main() {
    TreeNode* root = NULL;

    int choice;
    int choice1;
    do {
        printf("\n1. Product Information\n");
        printf("2. Display Products\n");
        printf("3. Process Order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                do{
            
                    printf("\n1.Add Product \n2.Display Products");
                    printf("Enter your choice: ");
                    scanf("%d", &choice1);
                    switch (choice1){
                    case 1:{
                        Product newProduct;
                        printf("Enter product name: ");
                        scanf("%s", newProduct.productName);
                        printf("Enter cost price: ");
                        scanf("%f", &newProduct.costPrice);
                        printf("Enter selling price: ");
                        scanf("%f", &newProduct.sellingPrice);
                        printf("Enter quantity in stock: ");
                        scanf("%d", &newProduct.quantityInStock);

                        newProduct.productId = rand(); // Generating a random product ID for simplicity
                        root = insert(root, newProduct);
                        printf("Product added successfully!\n");
                        
                        break;
                    }
                    case 2 :{
                        displayProducts(root);
                        break;
                    }
                    case 4:{
                        printf("Exiting the Section.\n");
                        break;
                    }
                    default:
                         printf("Invalid choice. Please try again.\n");
                        break;
                    }

                }while(choice1 !=4);
                
            }
            case 2:
                displayProducts(root);
                break;
            case 3: {
                int productId, quantity;
                printf("Enter product ID for the order: ");
                scanf("%d", &productId);
                printf("Enter quantity for the order: ");
                scanf("%d", &quantity);
                processOrder(root, productId, quantity);
                break;
            }
            case 4:
                freeTree(root); // Free allocated memory before exiting
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to insert a new product into the binary search tree
TreeNode* insert(TreeNode* root, Product product) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->product = product;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (product.productId < root->product.productId) {
        root->left = insert(root->left, product);
    } else if (product.productId > root->product.productId) {
        root->right = insert(root->right, product);
    }

    return root;
}

// Function to display all products in the binary search tree (in-order traversal)
void displayProducts(TreeNode* root) {
    if (root != NULL) {
        displayProducts(root->left);
        printf("ProductID: %d, ProductName: %s, CostPrice: %.2f, SellingPrice: %.2f, QuantityInStock: %d\n",
               root->product.productId, root->product.productName, root->product.costPrice,
               root->product.sellingPrice, root->product.quantityInStock);
        displayProducts(root->right);
    }
}

// Function to find a product in the binary search tree based on product ID
TreeNode* findProduct(TreeNode* root, int productId) {
    if (root == NULL || root->product.productId == productId) {
        return root;
    }

    if (productId < root->product.productId) {
        return findProduct(root->left, productId);
    }

    return findProduct(root->right, productId);
}

// Function to process a customer order
void processOrder(TreeNode* root, int productId, int quantity) {
    TreeNode* productNode = findProduct(root, productId);

    if (productNode == NULL) {
        printf("Product not found. Please enter a valid product ID.\n");
        return;
    }

    if (quantity <= 0 || quantity > productNode->product.quantityInStock) {
        printf("Invalid quantity. Please enter a valid quantity.\n");
        return;
    }

    // Process the order
    printf("Order processed successfully!\n");
    productNode->product.quantityInStock -= quantity;
}

// Function to free memory allocated for the binary search tree (post-order traversal)
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
