#include <stdio.h>
#include <stdlib.h>
#define ERR_RETURN_VALUE -1
struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode != NULL) {
        newNode->next = NULL;
        newNode->data = data;
        return newNode;
    } else {
        printf("ERR : UNABLE TO CREATE NEW NODE !");
        return NULL;
    }
}

struct Node *push_front(struct Node *head, int data) {
    if(head == NULL) {
        return createNode(data);
    } else {
        struct Node *newNode = createNode(data);
        if(newNode == NULL) return head;
        newNode->next = head;
        return newNode;
    }
}

struct Node *push_back(struct Node *head, int data) {
    if(head == NULL) {
        return createNode(data);
    } else {
        struct Node *tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = createNode(data);
        return head;
    }
}

struct Node *pop_front(struct Node *head) {
    if(head == NULL) {
        printf("ERR : EMPTY LIST");
        return NULL;
    } else {
        struct Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
}

// Still Working On These Functions
// struct Node *push_at(struct Node *head, int index, int data) {
//     if(head == NULL) {
//         if(index == 0) {
//             return createNode(data);
//         } else {
//             printf("ERR : NOT ABLE FOUND THE INSERTION INDEX");
//             return NULL;
//         }
//     } else {
//         struct Node *tmp1 = head, *tmp2;
//         for(int i = 0;( i < index - 1 && tmp1 != NULL); i++) {
//             tmp1 = tmp1->next;
//         }
//         if(tmp1 == NULL) {
//             printf("ERR : NOT ABLE FOUND THE INSERTION INDEX");
//             return head;
//         }
//         tmp2 = tmp1->next;
//         tmp1->next = createNode(data);
//         tmp1->next->next = tmp2;
//         return head;
//     }
// }
// struct Node *pop_at(struct Node *head, int index) {

// }


struct Node *pop_back(struct Node *head) {
    if(head == NULL) {
        printf("ERR : EMPTY LIST");
        return NULL;
    } else {
        struct Node *tmp = head, *tmp2;
        if(tmp->next != NULL) {
            while(tmp->next->next != NULL) {
                tmp = tmp->next;
             }
            tmp2 = tmp->next;
            tmp->next = NULL;
            free(tmp2);
            return head; 
        } else {
            free(head);
            return NULL;
        }
    }
}

void traverse(struct Node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


int front(struct Node *head) {
    if(head == NULL) return ERR_RETURN_VALUE;
    return head->data;
}

int back(struct Node *head) {
    if(head == NULL) return ERR_RETURN_VALUE;
    while(head->next != NULL) {
        head = head->next;
    }
    return head->data;
}

int isEmpty(struct Node *head) {
    return head == NULL;
}

int main() {
    struct Node *head = NULL;
    head = push_front(head, 5);
    head = push_front(head, 15);
    head = push_front(head, 25);
    traverse(head);
    head = push_back(head, 56);
    traverse(head);
    traverse(head);
    printf("%d ", front(head));
    printf("%d ", back(head));
    return 0;
}
