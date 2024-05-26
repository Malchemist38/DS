#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 256

typedef struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
} Node;

typedef struct HeapNode {
    Node *node;
    struct HeapNode *next;
} HeapNode;

typedef struct Heap {
    HeapNode *head;
} Heap;

Node* newNode(char data, unsigned freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

HeapNode* newHeapNode(Node *node) {
    HeapNode* heapNode = (HeapNode*)malloc(sizeof(HeapNode));
    heapNode->node = node;
    heapNode->next = NULL;
    return heapNode;
}

Heap* createHeap() {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->head = NULL;
    return heap;
}

void insertHeap(Heap* heap, HeapNode* heapNode) {
    if (heap->head == NULL) {
        heap->head = heapNode;
        return;
    }
    HeapNode* current = heap->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = heapNode;
}

HeapNode* extractMin(Heap* heap) {
    if (heap->head == NULL) {
        return NULL;
    }
    HeapNode* minNode = heap->head;
    HeapNode* prevMinNode = NULL;
    HeapNode* current = heap->head;
    HeapNode* prev = NULL;
    while (current != NULL) {
        if (current->node->freq < minNode->node->freq) {
            minNode = current;
            prevMinNode = prev;
        }
        prev = current;
        current = current->next;
    }
    if (prevMinNode == NULL) {
        heap->head = minNode->next;
    } else {
        prevMinNode->next = minNode->next;
    }
    return minNode;
}

Node* buildHuffmanTree(char data[], int freq[], int size) {
    Heap* heap = createHeap();
    for (int i = 0; i < size; ++i) {
        insertHeap(heap, newHeapNode(newNode(data[i], freq[i])));
    }
    while (heap->head->next != NULL) {
        HeapNode* left = extractMin(heap);
        HeapNode* right = extractMin(heap);
        Node* top = newNode('$', left->node->freq + right->node->freq);
        top->left = left->node;
        top->right = right->node;
        insertHeap(heap, newHeapNode(top));
    }
    Node* root = heap->head->node;
    free(heap);
    return root;
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void huffmanCodes(char data[], int freq[], int size) {
    Node* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_CHARACTERS], top = 0;
    printCodes(root, arr, top);
}

void printFrequencyTable(char data[], int freq[], int size) {
    printf("Char\tFreq\n");
    for (int i = 0; i < size; ++i) {
        printf("%c\t%d\n", data[i], freq[i]);
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {5, 9, 12, 13, 16};
    int size = sizeof(data) / sizeof(data[0]);
    printf("Huffman Encoding (Variable Bit)\n");
    printFrequencyTable(data, freq, size);
    printf("----------------------\n");
    huffmanCodes(data, freq, size);
    return 0;
}
