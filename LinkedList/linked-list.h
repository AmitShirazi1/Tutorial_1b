#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define MAX_NAME_LENGTH 10

typedef struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
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
#define MAX_STUDENTS_NUM 10

void insert(DLlist *list, Student *student, int side);
void remove(DLlist *list, Student *student);
void removeHead(DLlist *list, int side);
LNode * search(DLlist *list, Student *student);

Student * getStudents();
DLlist * createList(Student *students);
void freeList(DLlist *list);

#endif