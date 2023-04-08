#include "linked-list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Student * getStudents() {
    Student *students = (Student *) malloc(MAX_STUDENTS_NUM*sizeof(Student));
    printf("Please enter student's details:");
    char sId[3], name[MAX_NAME_LENGTH], another;
    int i=0;
    for (; i<MAX_STUDENTS_NUM; i++) {
        printf("\nID of student number %d:\t", i+1);
        fgets(sId, sizeof(sId), stdin);
        students[i].id = atoi(sId);

        printf("\nName (up to %d characters):\t", MAX_NAME_LENGTH);
        fgets(name, sizeof(name), stdin);
        strcpy(students[i].name, name);

        printf("\nWould you like to enter another one? (Y or N)\t");
        fgets(another, sizeof(another), stdin);
        if (another == 'N') {
            break;
        }
    }
    for (; i<MAX_STUDENTS_NUM; i++) {
        students[i].id = -1;
        strcpy(students[i].name, NULL);
    }

    return students;
}


DLlist * createList(Student *students) {
    DLlist *list = (DLlist *) malloc(sizeof(DLlist));
    list->left = NULL;
    list->right = NULL;

    for(int i=0; i<MAX_STUDENTS_NUM; i++) {
        if (students[i].id < 0) {
            break;
        }
        insert(list, students+i, LEFT);
    }

    return list;
}


void freeList(DLlist *list) {
    LNode *curr = list->left;
    while (curr != NULL) {
        LNode *next = curr->right;
        free(curr);
        curr = next;
    }
}


int main() {
    Student *students = getStudents();
    DLlist *list = createList(students);
    
    free(students);
    freeList(list);
    return 0;
}