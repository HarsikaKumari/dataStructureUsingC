#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_USERS 100

// Structure to represent a user
typedef struct {
    int id;
    char name[50];
    // Add more fields as needed (e.g., interests)
} User;

// Function to find the shortest path between two users using BFS
int shortestPath(int connections[MAX_USERS][MAX_USERS], int numUsers, int source, int destination) {
    bool visited[MAX_USERS] = {false};
    int queue[MAX_USERS];
    int front = 0, rear = 0;

    queue[rear++] = source;
    visited[source] = true;

    int level = 0;

    while (front < rear) {
        int count = rear - front;
        while (count--) {
            int currUser = queue[front++];
            if (currUser == destination)
                return level;
            for (int i = 0; i < numUsers; ++i) {
                if (connections[currUser][i] && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = true;
                }
            }
        }
        level++;
    }

    return -1; // No path found
}

// Function to identify common connections between two users
void commonConnections(int connections[MAX_USERS][MAX_USERS], int numUsers, int user1, int user2) {
    printf("Common connections between User %d and User %d:\n", user1, user2);
    for (int i = 0; i < numUsers; ++i) {
        if (connections[user1][i] && connections[user2][i])
            printf("User %d\n", i);
    }
}

int main() {
    // Example usage
    int numUsers = 5;
    int connections[MAX_USERS][MAX_USERS] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int source = 0, destination = 4;
    int shortest = shortestPath(connections, numUsers, source, destination);
    if (shortest != -1)
        printf("Shortest path between User %d and User %d is %d\n", source, destination, shortest);
    else
        printf("No path found between User %d and User %d\n", source, destination);

    commonConnections(connections, numUsers, 0, 1);

    return 0;
}
