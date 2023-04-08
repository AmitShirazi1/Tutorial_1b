#include "linked-list.h"
#include <stdlib.h>


void insert(DLlist *list, Student *student, int side) {
    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    newNode->student = student;
    
    if (side == LEFT) {
        list->left->left = newNode;
        newNode->right = list->left;
        newNode->left = NULL;
        list->left = newNode;
    }
    else {
        list->right->right = newNode;
        newNode->left = list->right;
        newNode->right = NULL;
        list->right = newNode;
    }

    free(newNode);
}


void remove(DLlist *list, Student *student) {
    LNode *tempNode = search(list, student);

    if (tempNode->left == NULL && tempNode->right == NULL) {
        list->left = NULL;
        list->right = NULL;
        return;
    }
    if (tempNode->left == NULL) {
        remove(list, LEFT);
    }
    if (tempNode->right == NULL) {
        remove(list, RIGHT);
    }
    tempNode->left->right = tempNode->right;
    tempNode->right->left = tempNode->left;

    free(tempNode);
}


void removeHead(DLlist *list, int side) {
    if (side == LEFT) {
        list->left = list->left->right;
        list->left->left = NULL;
    }
    else {
        list->right = list->right->left;
        list->right->right = NULL;
    }
}


LNode * search(DLlist *list, Student *student) {
    LNode *tempNode = (LNode *) malloc(sizeof(LNode));
    tempNode = list->left;

    while (tempNode->student != student) {
        tempNode = tempNode->right;
    }

    return tempNode;
}