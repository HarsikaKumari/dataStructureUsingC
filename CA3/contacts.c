#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a contact
typedef struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
} Contact;

// Define a structure for the contact manager
typedef struct ContactManager {
    Contact* head;
} ContactManager;

// Function to create a new contact
Contact* create_contact(char name[], char phone[]) {
    Contact* new_contact = (Contact*)malloc(sizeof(Contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    new_contact->next = NULL;
    return new_contact;
}

// Function to add a contact
void add_contact(ContactManager* manager, char name[], char phone[]) {
    Contact* new_contact = create_contact(name, phone);
    if (manager->head == NULL) {
        manager->head = new_contact;
    } else {
        Contact* current = manager->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_contact;
    }
}

// Function to search for a contact by name
Contact* search_by_name(ContactManager* manager, char name[]) {
    Contact* current = manager->head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to search for a contact by phone
Contact* search_by_phone(ContactManager* manager, char phone[]) {
    Contact* current = manager->head;
    while (current != NULL) {
        if (strcmp(current->phone, phone) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to update contact information
void update_contact(Contact* contact, char new_phone[]) {
    strcpy(contact->phone, new_phone);
}

// Function to delete a contact
void delete_contact(ContactManager* manager, char name[]) {
    Contact* current = manager->head;
    Contact* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                manager->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to print a contact
void print_contact(Contact* contact) {
    printf("Name: %s, Phone: %s\n", contact->name, contact->phone);
}

int main() {
    ContactManager manager = {NULL};
    add_contact(&manager, "John Doe", "123-456-7890");
    add_contact(&manager, "Jane Smith", "987-654-3210");

    // Search by name
    Contact* contact = search_by_name(&manager, "John Doe");
    if (contact != NULL) {
        printf("Found: ");
        print_contact(contact);
    } else {
        printf("Contact not found\n");
    }

    // Update contact
    if (contact != NULL) {
        update_contact(contact, "111-222-3333");
        printf("Contact updated successfully\n");
    }

    // Delete contact
    delete_contact(&manager, "Jane Smith");
    printf("Contact deleted successfully\n");

    return 0;
}
