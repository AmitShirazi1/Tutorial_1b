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
}


void remove(DLlist *list, Student *student) {
    LNode *removed = search(list, student);

    if (removed->left == NULL && removed->right == NULL) {
        list->left = NULL;
        list->right = NULL;
    }
    else if (removed->left == NULL) {
        remove(list, LEFT);
    }
    else if (removed->right == NULL) {
        remove(list, RIGHT);
    }
    else {
        removed->left->right = removed->right;
        removed->right->left = removed->left;
    }
    
    free(removed);
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
    LNode *tempNode = list->left;

    while (tempNode->student != student) {
        tempNode = tempNode->right;
    }

    return tempNode;
}