#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void error(char* message) {
    fprintf(stderr, "%s\n\n", message);
}

ListNode* insert_first(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    return p;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode* head) {
    ListNode* p = head;
    printf("List : ");
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("\n\n");
}

int main() {
    int menu_bar, value, pos, i;

    ListNode* head = NULL, * tmp;

    while (1) {
        printf("Menu\n");
        printf("(1) Insert\n");
        printf("(2) Delete\n");
        printf("(3) Print\n");
        printf("(0) Exit\n\n");
        printf("Enter the Menu : ");
        scanf_s("%d", &menu_bar);

        if (menu_bar == 1) {
            printf("Enter the number and position : ");
            scanf_s("%d %d", &value, &pos);

            if (head == NULL || pos == 0) {
                if (pos != 0) {
                    error("List is empty, Insert at position 0..\n");
                    pos = 0;
                }
                head = insert_first(head, value);
                printf("Move along the link : %d\n\n", pos);
            }
            else {
                tmp = head;
                int list_len = 0;
                while (tmp != NULL) {
                    tmp = tmp->link;
                    list_len++;
                }
                if (pos > list_len) {
                    printf("The last index is %d, Insert at the end of the list..\n\n", list_len - 1);
                    pos = list_len;
                }

                tmp = head;
                for (i = 0; i < pos - 1 && tmp != NULL; i++) {
                    tmp = tmp->link;
                }

                if (tmp != NULL) {
                    head = insert(head, tmp, value);
                    printf("Move along the link : %d\n\n", i + 1);
                }
                else {
                    error("Position out of range");
                }
            }
        }
        else if (menu_bar == 2) {
            if (head == NULL) error("List is Empty.");
            else {
                printf("Enter the position to delete: ");
                scanf_s("%d", &pos);

                if (pos == 0) {
                    if (head != NULL) {
                        tmp = head;
                        head = head->link;
                        free(tmp);
                        printf("\nMove along the link : %d\n\n", pos);
                    }
                    else {
                        error("List is Empty.");
                    }
                }
                else {
                    tmp = head;
                    for (i = 0; i < pos - 1 && tmp != NULL; i++) {
                        tmp = tmp->link;
                    }
                    if (tmp != NULL && tmp->link != NULL) {
                        head = delete(head, tmp);
                        printf("Move along the link : %d\n\n", i + 1);
                    }
                    else {
                        error("Position out of range");
                    }
                }
            }
        }
        else if (menu_bar == 3) {
            print_list(head);
        }
        else if (menu_bar == 0) {
            error("Exit the program.");
            exit(0);
        }
        else {
            error("Invalid Menu. Please select again..");
        }
    }
}
