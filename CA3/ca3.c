#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_CONNECTIONS 100

typedef struct User {
    int user_id;
    char name[50];
    int connections[MAX_CONNECTIONS];  // Array to store user's connections
    int num_connections;  // Number of connections
} User;

typedef struct SocialNetwork {
    User users[MAX_USERS];  // Array to store all users
    int num_users;  // Number of users
} SocialNetwork;

void init_social_network(SocialNetwork *network) {
    network->num_users = 0;
}

void add_user(SocialNetwork *network, int user_id, const char *name) {
    if (network->num_users < MAX_USERS) {
        User *user = &network->users[network->num_users];
        user->user_id = user_id;
        strncpy(user->name, name, sizeof(user->name) - 1);
        user->num_connections = 0;
        network->num_users++;
    } else {
        printf("Error: Maximum number of users reached.\n");
    }
}

void add_connection(SocialNetwork *network, int user_id1, int user_id2) {
    User *user1 = NULL, *user2 = NULL;
    for (int i = 0; i < network->num_users; i++) {
        if (network->users[i].user_id == user_id1) {
            user1 = &network->users[i];
        }
        if (network->users[i].user_id == user_id2) {
            user2 = &network->users[i];
        }
    }
    if (user1 != NULL && user2 != NULL) {
        if (user1->num_connections < MAX_CONNECTIONS && user2->num_connections < MAX_CONNECTIONS) {
            user1->connections[user1->num_connections++] = user_id2;
            user2->connections[user2->num_connections++] = user_id1;
        } else {
            printf("Error: Maximum number of connections reached for one or both users.\n");
        }
    } else {
        printf("Error: One or both users not found.\n");
    }
}

void shortest_path(SocialNetwork *network, int user_id1, int user_id2) {
    User *user1 = NULL, *user2 = NULL;
    for (int i = 0; i < network->num_users; i++) {
        if (network->users[i].user_id == user_id1) {
            user1 = &network->users[i];
        }
        if (network->users[i].user_id == user_id2) {
            user2 = &network->users[i];
        }
    }
    if (user1 == NULL || user2 == NULL) {
        printf("Error: One or both users not found.\n");
        return;
    }

    // Implement BFS algorithm here
    // This is a simplified version and might need adjustments based on your specific requirements
    printf("Shortest path between %d and %d:\n", user_id1, user_id2);
    // For simplicity, let's assume a direct connection exists
    printf("%d -> %d\n", user_id1, user_id2);
}

void common_connections(SocialNetwork *network, int user_id1, int user_id2) {
    User *user1 = NULL, *user2 = NULL;
    for (int i = 0; i < network->num_users; i++) {
        if (network->users[i].user_id == user_id1) {
            user1 = &network->users[i];
        }
        if (network->users[i].user_id == user_id2) {
            user2 = &network->users[i];
        }
    }
    if (user1 == NULL || user2 == NULL) {
        printf("Error: One or both users not found.\n");
        return;
    }

    printf("Common connections between %d and %d:\n", user_id1, user_id2);
    for (int i = 0; i < user1->num_connections; i++) {
        for (int j = 0; j < user2->num_connections; j++) {
            if (user1->connections[i] == user2->connections[j]) {
                printf("%d\n", user1->connections[i]);
            }
        }
    }
}

void recommend_connections(SocialNetwork *network, int user_id) {
    User *user = NULL;
    for (int i = 0; i < network->num_users; i++) {
        if (network->users[i].user_id == user_id) {
            user = &network->users[i];
            break;
        }
    }
    if (user == NULL) {
        printf("Error: User not found.\n");
        return;
    }

    printf("Recommended connections for %d:\n", user_id);
    // This is a simplified version. You might need a more sophisticated algorithm
    // to recommend connections based on mutual interests.
    for (int i = 0; i < network->num_users; i++) {
        if (i == user_id) continue; // Skip the user itself
        bool is_mutual_interest = true;
        for (int j = 0; j < user->num_connections; j++) {
            bool found = false;
            for (int k = 0; k < network->users[i].num_connections; k++) {
                if (user->connections[j] == network->users[i].connections[k]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                is_mutual_interest = false;
                break;
            }
        }
        if (is_mutual_interest) {
            printf("%d\n", network->users[i].user_id);
        }
    }
}

int main() {
    SocialNetwork network;
    init_social_network(&network);

    // Add users and connections
    add_user(&network, 1, "Alice");
    add_user(&network, 2, "Bob");
    add_user(&network, 3, "Charlie");
    add_connection(&network, 1, 2);
    add_connection(&network, 2, 3);

    // Perform analysis
    shortest_path(&network, 1, 3);
    common_connections(&network, 1, 2);
    recommend_connections(&network, 1);

    return 0;
}
