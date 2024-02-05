#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef char element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType* qptr) {
    qptr->front = qptr->rear = 0;
}

int is_empty(QueueType* qptr) {
    return (qptr->front == qptr->rear);
}

int is_full(QueueType* qptr) {
    return (qptr->rear + 1) % MAX_QUEUE_SIZE == qptr->front;
}

void enqueue(QueueType* qptr, element item) {
    if (is_full(qptr)) {
        fprintf(stderr, "Queue is Full\n");
    }
    else {
        qptr->rear = (qptr->rear + 1) % MAX_QUEUE_SIZE;
        qptr->data[qptr->rear] = item;
    }
}

element dequeue(QueueType* qptr) {
    if (is_empty(qptr)) {
        fprintf(stderr, "Queue is Empty\n");
        return '\0';
    }
    else {
        qptr->front = (qptr->front + 1) % MAX_QUEUE_SIZE;
        return (qptr->data[qptr->front]);
    }
}

bool is_palindrome(QueueType* qptr) {
    int start = (qptr->front + 1) % MAX_QUEUE_SIZE;
    int end = qptr->rear;

    while (start != end && (end + 1) % MAX_QUEUE_SIZE != start) {
        if (qptr->data[start] != qptr->data[end]) {
            return false;
        }
        start = (start + 1) % MAX_QUEUE_SIZE;
        end = (end - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }
    return true;
}

int main() {
    char input_string[MAX_QUEUE_SIZE];
    QueueType queue;

    while (1) {
        init_queue(&queue);
        printf("Enter a string(or input exit) : ");
        scanf_s(" %[^\n]", input_string, 100);

        if (strcmp(input_string, "exit") == 0) {
            break;
        }

        int len = strlen(input_string);
        for (int i = 0; i < len; i++) {
            char ch = tolower(input_string[i]);
            if (isalpha(ch)) {
                enqueue(&queue, ch);
            }
        }

        if (is_palindrome(&queue)) {
            printf("%s is a palindrome.\n", input_string);
        }
        else {
            printf("%s is not a palindrome.\n", input_string);
        }
    }
    return 0;
}
