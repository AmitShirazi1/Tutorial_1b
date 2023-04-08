#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Student {
    int id;
    char name[10];
} Student;

typedef struct Node {
    Student *student;
    LNode *next;
} LNode;

typedef struct DoubleLinkedList {
    LNode *left;
    LNode *right;
} DLlist;

#define LEFT 0
#define RIGHT 1

void insert(DLlist *list, Student *student, int side);

#endif