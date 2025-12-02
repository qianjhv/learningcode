#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum Status {
    OK = 0,
    WARN = 1, 
    ERROR = 2
} Status;

// stacknode
typedef struct StackNode {
    int value;
    struct StackNode *next;
} StackNode, *LinkStackPoint;

// linkstack
typedef struct LinkStack {
    unsigned int size;
    LinkStackPoint top;
} LinkStack;

// init stact
LinkStack* initLinkStack() {
    LinkStack* lstack = (LinkStack*)malloc(sizeof(LinkStack));
    lstack->size = 0;
    lstack->top = NULL;
    return lstack;
}

// push
Status push(LinkStack *lstack, int val) {
    if (!lstack) return ERROR;

    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->value = val;
    node->next = lstack->top;
    lstack->top = node;
    lstack->size++;

    return OK;
}

// pop
Status pop(LinkStack *lstack, int *val) {
    if (!lstack || lstack->size == 0) return ERROR;

    StackNode* node = lstack->top;
    *val = node->value;
    lstack->top = node->next;
    lstack->size--;
    free(node);

    return OK;
}

// peek
Status peek(LinkStack *lstack, int *val) {
    if (!lstack || lstack->size == 0) return ERROR;
    *val = lstack->top->value;
    return OK;
}

// 
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

//
int calc(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if ( b == 0) {
                printf("Error: can't divide 0\n");
                return 0;
            }
            return a / b;
    }
    return 0;
}

int main(void) {
    const int MAX = 1000;
    char expr[MAX];

    while (1) {
        printf("Please input expression below(type exit to close): \n");
        if (!fgets(expr, MAX, stdin)) break;
        expr[strcspn(expr,"\n")] = 0;

        if (strcmp(expr, "exit") == 0) break;
        
        LinkStack* numStack = initLinkStack();
        LinkStack* opStack = initLinkStack();

        int i = 0;
        int res = 0;
        int a, b;
        int topOpValue;
        
        while (expr[i] != '\0') {
            // 
            if (isspace(expr[i])) {
                i++;
                continue;
            }

            // 
            if (isdigit(expr[i])) {
                res = 0;
                while (isdigit(expr[i])) {
                   res = res * 10 + (expr[i] - '0'); 
                   i++;
                }
                push(numStack, res);
                continue;
            }

            // 
            while (opStack->size > 0) {
                peek(opStack, &topOpValue);
                char topOp = (char)topOpValue;

                if (priority(topOp) >= priority(expr[i])) {
                    pop(numStack, &b);
                    pop(numStack, &a);
                    pop(opStack, &topOpValue);

                    res = calc(a, b, topOp);
                    push(numStack, res);
                } else {
                    break;
                }
            }

            push(opStack, (int)expr[i]);
            i++;
        }

        // 
        while (opStack->size > 0) {
            pop(opStack, &topOpValue);
            char topOp = (char)topOpValue;
            pop(numStack, &b);
            pop(numStack, &a);

            res = calc(a, b, topOp);
            push(numStack, res);
        }

        //
        if (pop(numStack, &res) == OK && numStack->size == 0) {
            printf("%d\n", res);
        } else {
            printf("Expression error!\n");
            while (numStack->size > 0) {
                int temp;
                pop(numStack, &temp);
            }
        }

        free(numStack);
        free(opStack);
    }

    return 0;
}
