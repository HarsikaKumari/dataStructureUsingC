#include <stdio.h>
#include <string.h>

// Define constants for maximum sizes
#define MAX_BOOKS 100
#define MAX_CUSTOMERS 50

// Define structures for book, customer, and order
struct Book {
    char title[100];
    char author[100];
    float price;
    int quantity;
};

struct Customer {
    char name[100];
    char email[100];
};

struct Order {
    struct Book book;
    struct Customer customer;
    int quantity;
};

// Global arrays to store books, customers, and orders
struct Book books[MAX_BOOKS];
struct Customer customers[MAX_CUSTOMERS];
struct Order orders[MAX_BOOKS]; // Assuming one order per book for simplicity

int bookCount = 0;
int customerCount = 0;
int orderCount = 0;

// Function to add a book to the inventory
void addBook(char title[], char author[], float price, int quantity) {
    if (bookCount < MAX_BOOKS) {
        struct Book newBook;
        strcpy(newBook.title, title);
        strcpy(newBook.author, author);
        newBook.price = price;
        newBook.quantity = quantity;
        books[bookCount++] = newBook;
        printf("Book added successfully.\n");
    } else {
        printf("Cannot add more books, maximum limit reached.\n");
    }
}

// Function to search for a book by title
void searchBookByTitle(char title[]) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book found:\nTitle: %s\nAuthor: %s\nPrice: %.2f\nQuantity: %d\n",
                   books[i].title, books[i].author, books[i].price, books[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to search for a book by author
void searchBookByAuthor(char author[]) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printf("Book found:\nTitle: %s\nAuthor: %s\nPrice: %.2f\nQuantity: %d\n",
                   books[i].title, books[i].author, books[i].price, books[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by this author.\n");
    }
}

// Function to handle customer orders
void placeOrder(char title[], char customerName[], char customerEmail[], int quantity) {
    int bookIndex = -1;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            bookIndex = i;
            break;
        }
    }
    if (bookIndex == -1) {
        printf("Book not found in inventory.\n");
        return;
    }
    if (books[bookIndex].quantity < quantity) {
        printf("Insufficient quantity in inventory.\n");
        return;
    }
    // Decrease the quantity of the ordered book in inventory
    books[bookIndex].quantity -= quantity;
    // Record the order
    struct Order newOrder;
    strcpy(newOrder.book.title, books[bookIndex].title);
    strcpy(newOrder.book.author, books[bookIndex].author);
    newOrder.book.price = books[bookIndex].price;
    newOrder.book.quantity = quantity;
    strcpy(newOrder.customer.name, customerName);
    strcpy(newOrder.customer.email, customerEmail);
    orders[orderCount++] = newOrder;
    printf("Order placed successfully.\n");
}

// Function to generate a sales report
void generateSalesReport() {
    printf("Sales Report:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("%-30s%-20s%-20s%-10s\n", "Title", "Author", "Customer", "Quantity");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%-30s%-20s%-20s%-10d\n", orders[i].book.title, orders[i].book.author,
               orders[i].customer.name, orders[i].book.quantity);
    }
    printf("-----------------------------------------------------------------------------\n");
}

int main() {
    // Sample usage of functions
    addBook("The Great Gatsby", "F. Scott Fitzgerald", 10.99, 50);
    addBook("To Kill a Mockingbird", "Harper Lee", 9.99, 30);
    addBook("1984", "George Orwell", 8.99, 20);

    searchBookByTitle("The Great Gatsby");
    searchBookByAuthor("George Orwell");

    placeOrder("The Great Gatsby", "John Doe", "john@example.com", 3);
    placeOrder("1984", "Alice Smith", "alice@example.com", 2);

    generateSalesReport();

    return 0;
}
