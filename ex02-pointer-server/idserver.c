/*
 * idserver.c
 *
 *  Created on: Feb 15, 2016
 *      Author: jiaziyi
 *  Updated: JACF, 2020
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "idserver.h"

/**
 * print the server's information
 */
void print_idserver(idserver s)
{
    printf("Id: %s\n", s.id);
    printf("Region: %s\n", s.region);
    printf("Latency (usec): %d\n", s.latency);
    printf("Status: %s\n", s.status);
    printf("Nbr of threads: %d\n", *s.nthreads);
}

/**
 * try to modify the server information
 */
void modify(idserver s, char *id, int latency, char status[])
{
    s.id = (char *) malloc(strlen(id)+1);
    /* Why did it need a malloc here and not in status?
       Possible answer - because status's size is defined as 8 in the struct,
       Unlike id, which does not have size defined in advance? */
    strcpy(s.id, id);
    s.latency = latency;
    strncpy(s.status, status, strlen(status)+1);
    free(s.id);
}

/**
 * try to modify the student information using pointer
 */
void modify_by_pointer(idserver *s, char *id, int latency, char status[])
{
    free(s->id);
    s->id = (char *) malloc(strlen(id)+1);
    strcpy(s->id, id);
    s->latency = latency;
    strncpy(s->status, status, strlen(status)+1);
}

idserver create_idserver(char *id, char *region, int latency,
                          char *status, int *nthreads)
{

    idserver s;
    s.id = (char *) malloc(strlen(id)+1);
    strcpy(s.id, id);
    s.region = (char *) malloc(strlen(region)+1);
    strcpy(s.region, region);
    s.latency = latency;
    strncpy(s.status, status, strlen(status)+1);
    s.nthreads = nthreads;
    puts("---print inside create_idserver function---");
    print_idserver(s);
    puts("---end of print inside");
    return s;
}
