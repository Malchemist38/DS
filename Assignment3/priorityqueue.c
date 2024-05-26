#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* newNode(int d, int p) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

void enqueue(Node** head, int d, int p) {
    Node* temp = newNode(d, p);

    // handle head node or empty list
    if (*head == NULL || (*head)->priority < p) {
        temp->next = *head;
        *head = temp;
    } else {
        // traverse the list and find a position to insert the new node
        Node* current = *head;
        while (current->next != NULL && current->next->priority >= p) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

void dequeue(Node** head) {
    Node* temp = *head;
    if ((*head) == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Dequeued: %d\n", temp->data);
    (*head) = (*head)->next;
    free(temp);
}

void display(Node* head) {
    if (head == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }
    while (head != NULL) {
        printf("(Element: %d, Priority: %d)\n", head->data, head->priority);
        head = head->next;
    }
    printf("---------------------------------\n");
}

void freeQueue(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int length, data, priority;
    
    Node* head = NULL;
    printf("--- P-Queue: 5 = Highest, 1 = Lowest ---\n");
    printf("Enter P-Queue Length: ");
    scanf("%d", &length);

    int i;
    for (i = 1; i <= length; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &data);
        printf("Enter priority of element %d: ", i);
        scanf("%d", &priority);
        if (head == NULL) { // If queue is empty, initialize head
            printf("Initializing head node\n");
            head = newNode(data, priority);
        } else {
            printf("Enqueuing element %d\n", i);
            enqueue(&head, data, priority); // Otherwise, enqueue normally
        }
    }

    printf("----Priority Queue Full----\n");
    printf("Priority Queue Before Dequeue (in descending order):\n");

    display(head);

    int choice = 1;
    while (choice) {
        printf("Dequeue (1 for yes, 0 for exit): ");
        scanf("%d", &choice);
        if (choice) {
            if (head == NULL) {
                printf("Priority Queue is empty\n");
            }
            else {
                dequeue(&head);
                printf("Priority Queue After Dequeue:\n");
                display(head);
            }
        }
    }
    freeQueue(head);

    return 0;
}

