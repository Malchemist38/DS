#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

Node *newNode(int val) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

int height (Node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

int getMax(int a, int b) {
    return (a > b)? a : b;
}

void preOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *z = y->left;

    y->left = x;
    x->right = z;

    x->height = getMax(height(x->left), height(x->right)) + 1;
    y->height = getMax(height(y->left), height(y->right)) + 1;

    return y;
}

Node *rightRotate(Node *x) {
    Node *y = x->left;
    Node *z = y->right;

    y->right = x;
    x->left = z;

    x->height = getMax(height(x->left), height(x->right)) + 1;
    y->height = getMax(height(y->left), height(y->right)) + 1;

    return x;
}

Node *insertBST(Node *node, int newVal) {
    if (node == NULL) {
        return newNode(newVal);
    }
    if (newVal < node->val) {
        node->left = insertBST(node->left, newVal);
    }
    else if (newVal > node->val) {
        node->right = insertBST(node->right, newVal);
    }
    return node; // ignore duplicates
}

Node *insertAVL(Node *node, int newVal) {
    if (node == NULL) {
        return newNode(newVal);
    }
    if (newVal < node->val) {
        node->left = insertAVL(node->left, newVal);
    }
    else if (newVal > node->val) {
        node->right = insertAVL(node->right, newVal);
    }

    node->height = getMax(height(node->left), height(node->right)) + 1;
    
    int balance = getBalanceFactor(node);

    // Perform rotations if needed
    if (balance > 1 && newVal < node->left->val) {
        return rightRotate(node);
    }
    if (balance < -1 && newVal > node->right->val) {
        return leftRotate(node);
    }
    if (balance > 1 && newVal > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && newVal < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main(int argc, char* argv[]) {
    Node *rootBST = NULL;
    Node *rootAVL = NULL;
    int nums[] = { 1, 2, 3, 4, 5 };
    int length = sizeof(nums) / sizeof(nums[0]);
    int i = 0;

    // construct BST
    for (i; i < length; i++) {
        rootBST = insertBST(rootBST, nums[i]);
    }
    printf("BST Tree - PreOrder:\n");
    preOrder(rootBST);
    printf("\n");

    // construct AVL tree
    for (i = 0; i < length; i++) {
        rootAVL = insertAVL(rootAVL, nums[i]);
    }
    printf("AVL Tree - PreOrder:\n");
    preOrder(rootAVL);

    return 0;
}