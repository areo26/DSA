#include <stdio.h>
#include <stdlib.h>
#define ERR_RETURN_VALUE -1 

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    if(new != NULL) {
        new->data = data;
        new->next = NULL;
        return new;
    } else {
        printf("ERR : FAILED TO CREATE NEW NODE");
        return NULL;
    }
}

struct Node *push(struct Node *head, int data) {
    if(head == NULL) {
        return createNode(data);
    } else {
        struct Node *new = createNode(data);
        new->next = head;
        return new;
    }
}

struct Node *pop(struct Node *head) {
    if(head == NULL) {
        printf("ERR : EMPTY STACK CAN'T POP ANY FURTHER");
        return head;
    } else {
        struct Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
}

int top(struct Node *head) {
    if(head == NULL) {
        printf("EMPTY STACK");
        return ERR_RETURN_VALUE;
    } else {
        return head->data;
    }
}

int main() {
    // Init Stack
    struct Node *stack = NULL;

    stack = push(stack, 5);
    stack = push(stack, 15);
    stack = push(stack, 25);

    printf("%d ", top(stack));
    stack = pop(stack);
    printf("%d ", top(stack));
    stack = pop(stack);
    printf("%d ", top(stack));
    stack = pop(stack);

    free(stack);
    return 0;
}