#include "linked-list.h"

void insert(DLlist *list, Student *student, int side) {
    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    newNode->student = student;
    
    if (side == LEFT) {
        newNode->next = list->left;
        list->left = newNode;
    }
    else {
        newNode->next = list->right;
        list->right = newNode;
    }
}