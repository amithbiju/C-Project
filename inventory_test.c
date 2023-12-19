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
    char category[25];
} Product;

// Binary tree node
typedef struct TreeNode {
    Product product;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Structure for customer orders
struct Order {
    int orderID;
    int productID;
    int quantity;
    struct Order *nextOrder;
};

// Structure for customer details with orders
struct Customer {
    int customerID;
    char name[50];
    char pass[50];
    struct Order *orders;
    struct Customer *nextCustomer;
};

// Linked list to store products
struct Product *productList = NULL;

// Linked list to store customers
struct Customer *customerList = NULL;
// Function prototypes
TreeNode* insert(TreeNode* root, Product product);
void displayProducts(TreeNode* root);
void displaycate(TreeNode* root, char cate[]);
TreeNode* findProduct(TreeNode* root, int productId);
void processOrder(TreeNode* root, int productId, int quantity);
void freeTree(TreeNode* root);
TreeNode* changedetail(TreeNode* root,int productId);
TreeNode* changestock(TreeNode* root,int productId);
void addCustomer(int id, char cname[],char pass[]) ;
void addOrder(int customerID, int orderID, int productID, int qty);
int addprice(TreeNode* root, int productId, int qty) ;
void displayCustomerOrders();
struct Customer *loginUser(int userID, const char pass[]);
void readFromFile(TreeNode** root, const char* filename);
void saveToFile(TreeNode* root, const char* filename);
void saveDataToFile(const char *filename);
void loadDataFromFile(const char *filename);



int main() {
    TreeNode* root = NULL;

    int choice;
    int choice1;
    int choice2;
    int choice3;
    int choice4;
    readFromFile(&root, "product.txt");
    loadDataFromFile("customer.txt");
    printf("\n--------------------------------------------------------------------------------------------\n");
    printf("welcome to XYZ retail store-your one stop destination for all your needs\n\nAbout us:At XYZ we believe in more than just providing top notch services;\n");
    printf("we are dedicated to creating an unparallel shopping experiences for all our customers\n");
    printf("contact us: 9835378393\nemail id:XYZretails@gmail.com\n");
    printf("location:Austria-Vienna\n\n");
    printf("\n--------------------------------------------------------------------------------------------\n");
   
    do {
        
        printf("please mention your access control");
        printf("\n--------------------------------------------------------------------------------------------\n");
        printf("\n1.Admin \n");
        printf("2. Supplier\n");
        printf("3. Customer\n");
        printf("4. Save to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int pass=2226;
                int val;
                printf("Enter the authentication password : \n");
                scanf("%d",&val);
                if(val!=pass)
                {
                    printf("wrong password,access denied\n");
                    break;
                }
                else{
                do{
                   
                    printf("\n1.Add Product \n2.Display Products\n3.edit product details\n4.displayCustomerOrders\n5.exit\n");
                    printf("Enter your choice : ");
                    scanf("%d", &choice1);
                    switch (choice1){
                    case 1:{
                        Product newProduct;
                        printf("Enter product name : ");
                        scanf("%s", newProduct.productName);
                        printf("Enter product Category : ");
                        scanf("%s", newProduct.category);
                        printf("Enter cost price : ");
                        scanf("%f", &newProduct.costPrice);
                        printf("Enter selling price : ");
                        scanf("%f", &newProduct.sellingPrice);
                        printf("Enter quantity in stock : ");
                        scanf("%d", &newProduct.quantityInStock);

                        newProduct.productId = rand()+1000; // Generating a random product ID for simplicity
                        root = insert(root, newProduct);
                        printf("Product added successfully!\n");
                        
                        break;
                    }
                    case 2 :{
                        displayProducts(root);
                        break;
                    }
                    case 3:
                          {
                            printf("enter the product id : ");
                            int id;
                            scanf("%d",&id);
                            root= changedetail(root,id);
                            break;
                          }
                    case 4:{
                        displayCustomerOrders();
                        break;
                    }
                    case 5:{
                        printf("Exiting the Section.\n");
                        break;
                    }
                    default:
                         printf("Invalid choice. Please try again.\n");
                        break;
                    }

                }while(choice1 !=5);
                }
            break;
            }
            case 2:{
                do{
                   
                    printf("\n1.Add Product \n2.Display Products\n3.Add Quantity\n4.exit\n");
                    printf("Enter your choice : ");
                    scanf("%d", &choice2);
                    switch (choice2){
                    case 1:{
                        Product newProduct;
                        printf("Enter product name : ");
                        scanf("%s", newProduct.productName);
                        
                        printf("Enter product Category : ");
                        scanf("%s", newProduct.category);
                        printf("Enter cost price: ");
                        scanf("%f", &newProduct.costPrice);
                        printf("Enter selling price: ");
                        scanf("%f", &newProduct.sellingPrice);
                        printf("Enter quantity in stock: ");
                        scanf("%d", &newProduct.quantityInStock);

                        newProduct.productId = rand()+1000; // Generating a random product ID for simplicity
                        root = insert(root, newProduct);
                        printf("Product added successfully!\n");
                        
                        break;
                    }
                    case 2 :{
                        displayProducts(root);
                        break;
                    }
                    case 3:
                          {
                            printf("enter the product id : ");
                            int id;
                            scanf("%d",&id);
                            root= changestock(root,id);
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

                }while(choice2 !=4);
                break;

            }
        
            
                
            case 3: {
                do{
                   
                    printf("\n1.New User \n2.Login\n3.exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice3);
                    switch (choice3){
                    case 1:{
                        char name[67], pass[68];
                        int id;
                        printf("Enter Your name : ");
                        scanf("%s",name);
                        printf("Enter the userID : ");
                        scanf("%d",&id);
                        printf("Enter the Password : ");
                        scanf("%s",pass);
                        addCustomer(id,name,pass);
                        saveDataToFile("customer.txt");
                        int productId, quantity;
                        
                        do{
                            printf("1.Display Products \n2.Buy Products \n 3.EXIT\n Enter any option");
                            scanf("%d", &choice4);
                            char cate[25];
                            switch (choice4){
                                case 1:{
                                    printf("Enter the Category you want  :");
                                    scanf("%s",cate);
                                    displaycate(root,cate);
                                    break;
                                }
                                case 2:{
                                    int num;
                                    int sum=0;
                                    printf("How many products do you want?");
                                    scanf("%d",&num);
                                    for(int i=0;i<num;i++){
                                        printf("Enter product ID for the order: ");
                                        scanf("%d", &productId);
                                        printf("Enter quantity for the order: ");
                                        scanf("%d", &quantity);
                                        sum +=addprice(root,productId,quantity );
                                        processOrder(root, productId, quantity);
                                        addOrder(id, rand(),productId ,quantity );
                                    }
                                    printf("\nTotal Amount for the products -> %d",sum);
                                    printf("\nThank You for shopping with us....❤️");
                                    break;
                                }
                                case 3:{
                                    printf("Exiting the Section.\n");
                                    break;
                                }
                            }
                        }while(choice4!= 3);
                        break;
                    }
                    case 2 :{
                        char pass[68];
                        int id;
                        int productId, quantity;
                        printf("Enter the USERID :");
                        scanf("%d",&id);
                        printf("Enter the Password : ");
                        scanf("%s",pass);
                        struct Customer *logedinCustomer = loginUser(id,pass);
                        if (logedinCustomer != NULL){
                            do{
                            printf("1.Display Products \n2.Buy Products \n 3.EXIT\n Enter any option");
                            scanf("%d", &choice4);
                            char cate[25];
                            switch (choice4){
                                case 1:{
                                    printf("Enter the Category you want  :");
                                    scanf("%s",cate);
                                    displaycate(root,cate);
                                    break;
                                }
                                case 2:{
                                    int num;
                                    int sum=0;
                                    printf("How many products do you want?");
                                    scanf("%d",&num);
                                    for(int i=0;i<num;i++){
                                        printf("Enter product ID for the order: ");
                                        scanf("%d", &productId);
                                        printf("Enter quantity for the order: ");
                                        scanf("%d", &quantity);
                                        sum +=addprice(root,productId,quantity );
                                        processOrder(root, productId, quantity);
                                        addOrder(id, rand(),productId ,quantity );
                                    }
                                    printf("\nTotal Amount for the products -> %d",sum);
                                    printf("\nThank You for shopping with us....❤️");
                                    break;
                                }
                                case 3:{
                                    printf("Exiting the Section.\n");
                                    break;
                                }
                            }
                        }while(choice4!= 3);
                        break;
                        }
                        break;
                    }
                    case 3:{
                        printf("Exiting the Section.\n");
                        break;
                    }
                    default:
                         printf("Invalid choice. Please try again.\n");
                        break;
                    }

                }while(choice3 !=3);
                break;
                
            }
            case 4:{
                saveToFile(root, "product.txt");
                printf("Data saved to file successfully!\n");
                break;
            }
            case 5:{
                freeTree(root); // Free allocated memory before exiting
                printf("Exiting the program.\n");
                break;
            }
            default:{
                printf("Invalid choice. Please try again.\n");
                break;
            }
    }} while (choice != 5);
    
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
        printf("ProductID: %d, ProductName: %s,ProductCategory: %s, CostPrice: %.2f, SellingPrice: %.2f, QuantityInStock: %d\n",
               root->product.productId, root->product.productName,root->product.category, root->product.costPrice,
               root->product.sellingPrice, root->product.quantityInStock);
        displayProducts(root->right);
    }
}

void displaycate(TreeNode* root, char cate[25]) {
    int flag =0;
    if (root != NULL) {
        if (strcmp(root->product.category, cate) == 0) {
            printf("ProductID: %d, ProductName: %s, ProductCategory: %s, CostPrice: %.2f, SellingPrice: %.2f, QuantityInStock: %d\n",
                   root->product.productId, root->product.productName, root->product.category, root->product.costPrice,
                   root->product.sellingPrice, root->product.quantityInStock);
            flag =1;
        }
        displaycate(root->left, cate);
        displaycate(root->right, cate);
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
 TreeNode * changedetail(TreeNode* root, int productId) {
    TreeNode* productNode = findProduct(root, productId);
    int newpr;
    if (productNode == NULL) {
        printf("Product not found. Please enter a valid product ID.\n");
        return root;
    }
    printf("ProductID: %d, ProductName: %s, CostPrice: %.2f, SellingPrice: %.2f, QuantityInStock: %d\n",
               productNode->product.productId, productNode->product.productName, productNode->product.costPrice,
               productNode->product.sellingPrice, productNode->product.quantityInStock);
    printf("Enter the New prize");
    scanf("%d",&newpr);
    productNode->product.sellingPrice= newpr;
    printf("You have sucessfully changed the prize!!");
    return root;
}

TreeNode * changestock(TreeNode* root, int productId) {
    TreeNode* productNode = findProduct(root, productId);
    int newpr;
    if (productNode == NULL) {
        printf("Product not found. Please enter a valid product ID.\n");
        return root;
    }
    printf("ProductID: %d, ProductName: %s, CostPrice: %.2f, SellingPrice: %.2f, QuantityInStock: %d\n",
               productNode->product.productId, productNode->product.productName, productNode->product.costPrice,
               productNode->product.sellingPrice, productNode->product.quantityInStock);
    printf("Enter amount of stock you have");
    scanf("%d",&newpr);
    productNode->product.quantityInStock += newpr ;
    printf("You have sucessfully changed the Quantity!!");
    return root;
}

// Function to add a new customer
void addCustomer(int id, char cname[],char pass[]) {
    struct Customer *newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
    if (newCustomer == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newCustomer->customerID = id;
    strcpy(newCustomer->name, cname);
    strcpy(newCustomer->pass, pass);
    newCustomer->orders = NULL;
    newCustomer->nextCustomer = customerList;
    customerList = newCustomer;
    printf("Customer added successfully!\n");
}

// Function to add a customer's order
void addOrder(int customerID, int orderID, int productID, int qty) {
    struct Customer *currentCustomer = customerList;
    while (currentCustomer != NULL) {
        if (currentCustomer->customerID == customerID) {
            struct Order *newOrder = (struct Order*)malloc(sizeof(struct Order));
            if (newOrder == NULL) {
                printf("Memory allocation failed.\n");
                return;
            }
            newOrder->orderID = orderID;
            newOrder->productID = productID;
            newOrder->quantity = qty;
            newOrder->nextOrder = currentCustomer->orders;
            currentCustomer->orders = newOrder;
            printf("Order added successfully for customer ID: %d\n", customerID);
            return;
        }
        currentCustomer = currentCustomer->nextCustomer;
    }
    printf("Customer with ID: %d not found.\n", customerID);
}

// fn to add price

int addprice(TreeNode* root, int productId, int qty) {
    TreeNode* productNode = findProduct(root, productId);
    int newpr;
    if (productNode == NULL) {
        printf("Product not found. Please enter a valid product ID.\n");
        return -1;
    }
    int prodt= productNode->product.sellingPrice *qty;
    return prodt;
   
}

// Function to display customer details with order information
void displayCustomerOrders() {
    printf("Customer ID\tName\tOrder ID\tProduct ID\tQuantity\n");
    struct Customer *currentCustomer = customerList;
    while (currentCustomer != NULL) {
        struct Order *currentOrder = currentCustomer->orders;
        while (currentOrder != NULL) {
            printf("%d\t\t%s\t%d\t\t%d\t\t%d\n", currentCustomer->customerID, currentCustomer->name,
                   currentOrder->orderID, currentOrder->productID, currentOrder->quantity);
            currentOrder = currentOrder->nextOrder;
        }
        currentCustomer = currentCustomer->nextCustomer;
    }
}

// Function to log in users by validating user ID and password
struct Customer *loginUser(int userID, const char pass[]) {
    struct Customer *currentCustomer = customerList;
    while (currentCustomer != NULL) {
        if (currentCustomer->customerID == userID && strcmp(currentCustomer->pass, pass) == 0) {
            // User ID and password match
            printf("Login successful!\n");
            printf("**********************************\n");
            printf("WELCOME BACK %s \n",currentCustomer->name);
            printf("**********************************\n");
            
            return currentCustomer;
        }
        currentCustomer = currentCustomer->nextCustomer;
    }
    printf("Invalid user ID or password. Login failed.\n");
    return NULL;
}

// Function to read product data from a file and build the binary search tree
void readFromFile(TreeNode** root, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    Product product;
    while (fscanf(file, "%d %s %s %f %f %d\n", &product.productId, product.productName,product.category,
                  &product.costPrice, &product.sellingPrice, &product.quantityInStock) == 6) {
        *root = insert(*root, product);
    }

    fclose(file);
}

// Function to save product data from the binary search tree to a file (in-order traversal)
void saveToFileHelper(TreeNode* root, FILE* file) {
    if (root != NULL) {
        saveToFileHelper(root->left, file);
        fprintf(file, "%d %s %s %.2f %.2f %d\n", root->product.productId, root->product.productName,root->product.category,
                root->product.costPrice, root->product.sellingPrice, root->product.quantityInStock);
        saveToFileHelper(root->right, file);
    }
}

// Function to save product data from the binary search tree to a file
void saveToFile(TreeNode* root, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    saveToFileHelper(root, file);

    fclose(file);
}

// Function to save customer data to a file
void saveDataToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    struct Customer *currentCustomer = customerList;
    while (currentCustomer != NULL) {
        // Write customer details to the file
        fwrite(currentCustomer, sizeof(struct Customer), 1, file);

        // Write each order for the customer to the file
        struct Order *currentOrder = currentCustomer->orders;
        while (currentOrder != NULL) {
            fwrite(currentOrder, sizeof(struct Order), 1, file);
            currentOrder = currentOrder->nextOrder;
        }

        currentCustomer = currentCustomer->nextCustomer;
    }

    fclose(file);
    printf("Data saved to file successfully.\n");
}

// Function to load customer data from a file
void loadDataFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    // Clear existing customer list
    while (customerList != NULL) {
        struct Customer *temp = customerList;
        customerList = customerList->nextCustomer;
        free(temp);
    }

    struct Customer tempCustomer;
    struct Order tempOrder;

    // Read customer details and orders from the file
    while (fread(&tempCustomer, sizeof(struct Customer), 1, file) > 0) {
        // Add the customer to the linked list
        struct Customer *newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
        if (newCustomer == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return;
        }
        memcpy(newCustomer, &tempCustomer, sizeof(struct Customer));
        newCustomer->orders = NULL;
        newCustomer->nextCustomer = customerList;
        customerList = newCustomer;

        // Read and add orders for the customer
        while (fread(&tempOrder, sizeof(struct Order), 1, file) > 0) {
            if (tempOrder.orderID == tempCustomer.customerID) {
                struct Order *newOrder = (struct Order*)malloc(sizeof(struct Order));
                if (newOrder == NULL) {
                    printf("Memory allocation failed.\n");
                    fclose(file);
                    return;
                }
                memcpy(newOrder, &tempOrder, sizeof(struct Order));
                newOrder->nextOrder = newCustomer->orders;
                newCustomer->orders = newOrder;
            } else {
                // Order does not belong to the current customer, break the inner loop
                break;
            }
        }
    }

    fclose(file);
    printf("Data loaded from file successfully.\n");
}
