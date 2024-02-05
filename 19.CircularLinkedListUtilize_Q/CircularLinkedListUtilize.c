#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct DListNode {
    element data[100];
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void error(char* message) {
    fprintf(stderr, "\n%s\n", message);
}

void init_list(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void dinsert(DListNode* before, element* value) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    strcpy_s(newnode->data, 100, value);

    newnode->llink = before;
    newnode->rlink = before->rlink;
    if (before->rlink != NULL) {
        before->rlink->llink = newnode;
    }
    before->rlink = newnode;
}

void ddelete(DListNode* removed) {
    if (removed->llink == removed && removed->rlink == removed) {
        error("List is Empty");
    }
    else {
        removed->llink->rlink = removed->rlink;
        removed->rlink->llink = removed->llink;
        free(removed);
    }
}

DListNode* goNext(DListNode* current, DListNode* phead) {
    if (current->rlink == phead) {
        return phead->rlink;
    }
    else {
        return (current->rlink);
    }
}

DListNode* goPrev(DListNode* current, DListNode* phead) {
    if (current->llink == phead) {
        return phead->llink;
    }
    else {
        return (current->llink);
    }
}


void print_list(DListNode* phead, DListNode* current) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        if (p == current) {
            printf("%s [O]\n", p->data);
        }
        else {
            printf("%s\n", p->data);
        }
    }
    printf("\n");
}

int main() {
    char menu;

    DListNode* List;
    List = (DListNode*)malloc(sizeof(DListNode));
    init_list(List);
    DListNode* current = List;

    while (1) {
        printf("\n==== Menu ====\n");
        printf("(n) Next Fruit\n");
        printf("(p) Previous Fruit\n");
        printf("(d) Delete the current fruit\n");
        printf("(i) Insert fruit after current fruit\n");
        printf("(o) Output the fruit list(Output [O] at end of currently selected fruit)\n");
        printf("(e) Exit the program\n");
        printf("============\n");
        printf("Select a menu : ");
        menu = getchar();

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        if (menu == 'n') {
            current = goNext(current, List);
        }
        else if (menu == 'p') {
            current = goPrev(current, List);
        }
        else if (menu == 'd') {
            DListNode* prev = goPrev(current, List);
            ddelete(current);
            current = prev->rlink;
        }
        else if (menu == 'i') {
            char fruit[100];
            printf("Enter the name of the fruit to add : ");
            fgets(fruit, sizeof(fruit), stdin);
            fruit[strcspn(fruit, "\n")] = '\0';
            dinsert(current, fruit);

            if (current == List) {
                current = current->rlink;
            }
        }
        else if (menu == 'o') {
            print_list(List, current);
        }
        else if (menu == 'e') {
            exit(0);
        }
        else {
            error("Invalid Menu\n");
        }
    }
}
