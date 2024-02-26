#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef int element;
typedef struct ListNode { 	// ³ëµå Å¸ÀÔ
    element data;
    struct ListNode* link;
} ListNode;


void error(char* message) {
    fprintf(stderr, "%s\n\n", message);
}

ListNode* insert_first(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head;
        ListNode* temp = head;
        while (temp->link != head)
            temp = temp->link;
        temp->link = node;
        head = node;
    }
    return head;
}


/*
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}
*/

ListNode* insert_last(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head;
        ListNode* temp = head;
        while (temp->link != head)
            temp = temp->link;
        temp->link = node;
    }
    return head;
}

/*
ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}
*/

void print_list(ListNode* head)
{
    ListNode* p;

    if (head == NULL) return;
    p = head;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head);
    printf("\n\n");
}

ListNode* delete_first(ListNode* head) {
    if (head == NULL) {
        error("List is Empty.");
        return NULL;
    }


    if (head->link == head) {
        free(head);
        return NULL;
    }

    ListNode* temp = head;
    while (temp->link != head) {
        temp = temp->link;
    }

    ListNode* firstNode = head;
    head = head->link;
    temp->link = head;

    free(firstNode);
     
    return head;
}



ListNode* delete_last(ListNode* head) {
    if (head == NULL) {
        error("List is Empty.");
        return NULL;
    }

    
    if (head->link == head) {
        free(head);
        return NULL;
    }

    ListNode* temp = head;
    while (temp->link->link != head) {
        temp = temp->link;
    }

    ListNode* lastNode = temp->link;
    temp->link = head;

    free(lastNode); 

    return head;
}









int main() {
    int menu_bar, value, pos, i;

    ListNode* head = NULL, * tmp;
    //ListNode* head = NULL;

    // list = 10->20->30->40
    /*
    head = insert_last(head, 20);
    head = insert_last(head, 30);
    
    head = insert_last(head, 40);
    head = insert_last(head, 50);
    ;
    head = delete_last(head);
    //print_list(head);
    
    print_list(head);
    */
    
    //return 0;

    
    while (1) {
        printf("Menu\n");
        printf("(1) Insert First\n");
        printf("(2) Insert Last\n");
        printf("(3) Delete First\n");
        printf("(4) Delete Last\n");
        printf("(5) Print\n");
        printf("(0) Exit\n\n");
        printf("Enter the Menu : ");
        scanf_s("%d", &menu_bar);

        if (menu_bar == 1) {
            printf("Enter the number and position : ");
            scanf_s("%d", &value);

            head = insert_first(head, value);
        }

        else if (menu_bar == 2) {
            printf("Enter the number and position : ");
            scanf_s("%d", &value);

            head = insert_last(head, value);
        }

        else if (menu_bar == 3) {
            head = delete_first(head);
        }

        else if (menu_bar == 4) {
            head = delete_last(head);
        }

        else if (menu_bar == 5) {
            print_list(head);
        }

        else if (menu_bar == 0) {
            error("Exit the program.");
            exit(0);
        }
        else {
            error("Invalid Menu. Please select again..");
        }


            //printf("Move along the link : %d\n\n", pos);

        /*
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
        */
        //print_list(head);
        }
        /*
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
                        printf(
                            "\nMove along the link : %d\n\n", pos);
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
        */
        
}
