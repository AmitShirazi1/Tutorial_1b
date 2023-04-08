#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Student {
    int id;
    char name[10];
} Student;

typedef struct Node {
    Student *student;
    LNode *left;
    LNode *right;
} LNode;

typedef struct DoubleLinkedList {
    LNode *left;
    LNode *right;
} DLlist;

#define LEFT 0
#define RIGHT 1

void insert(DLlist *list, Student *student, int side);

void remove(DLlist *list, Student *student);
void removeHead(DLlist *list, int side);

LNode * search(DLlist *list, Student *student);

#endif