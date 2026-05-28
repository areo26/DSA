#include <stdio.h>
#include <stdlib.h>

#define ERR_RETURN_VALUE -1 

struct Stack {
    int top;
    int size;
    int* arr;
};

int isFull(struct Stack *s) {
    return ((s->top+1) == s->size);
}

int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

void push(struct Stack *s, int key) {
    if(!isFull(s)) {
        s->arr[++(s->top)] = key;
    } else {
        printf("ERR : STACK OVERFLOW");
    }
}

int pop(struct Stack *s) {
    if(!isEmpty(s)) {
        int tmp = s->arr[s->top--];
        return tmp;
    } else {
        printf("ERR : STACK UNDERFLOW");
        return ERR_RETURN_VALUE;
    }
}

int top(struct Stack *s) {
    if(!isEmpty(s)) {
        return s->arr[s->top];
    } else {
        printf("STACK IS EMPTY !");
        return ERR_RETURN_VALUE;
    }
}

int main() {
    // setting up stack 
    struct Stack s;
    s.top = -1;
    s.size = 100;
    s.arr = (int*)malloc(s.size*sizeof(int));

    // from here you can use your stack easily
    push(&s, 90);
    push(&s, 89);

    printf("%d", pop(&s));

    // dont forget to free your memeory
    free(s.arr);
    return 0;
}