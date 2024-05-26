#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StackNode {
    char data;
    struct StackNode* next;
};

struct StackNode* newNode(char data) {
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(struct StackNode** top, char data) {
    struct StackNode* node = newNode(data);
    node->next = *top;
    *top = node;
    // printf("%c pushed to stack\n", data); for debugging
}

char pop(struct StackNode** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct StackNode* temp = *top;
    char popped = temp->data;
    *top = (*top)->next;
    free(temp);
    // printf("%c popped from stack\n", popped); for debugging
    return popped;
}

bool isOpenParenthesis(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

bool isClosedParenthesis(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}

bool areMatchingParenthesis(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

bool isBalanced(char* exp) {
    struct StackNode* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isOpenParenthesis(exp[i])) {
            push(&stack, exp[i]);
        } else if (isClosedParenthesis(exp[i])) {
            if (stack == NULL || !areMatchingParenthesis(pop(&stack), exp[i])) {
                return false; /* will return false if the stack has no open parenthesis or if there are no
                                matching parenthesis */
            }
        }
    }

    return (stack == NULL); // will return true if the stack is empty
}

int main(int argc, char* argv[]) {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%[^\n]", expression);

    if (isBalanced(expression)) {
        printf("It's Balanced (^_^)\n");
    } else {
        printf("It's Not Balanced (O_O)\n");
    }

    return 0;
}
