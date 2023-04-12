/*
 * pointer.c
 *
 *  Created on: Feb 15, 2016
 *      Author: jiaziyi
 *  Updated: JACF, 2020
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "idserver.h"

int main(int argc, char* argv[]){

    idserver cmok, albi;
    idserver *s1, *s2;

    cmok.latency = 600;
    cmok.region = (char *) malloc(strlen("eur")+1);
    strcpy(cmok.region, "eur");
    cmok.id = (char *) malloc(strlen("cmok")+1);
    strcpy(cmok.id, "cmok");
    strncpy(cmok.status, "up", strlen("up") + 1);
    int p = 70;
    cmok.nthreads = &p;
    s1 = &cmok;

    //step 1: pointer observation
    puts("=========step 1===========");
    printf("cmok gpt1 (its address): %p\n", (void *)&cmok);
    printf("cmok gpt2 (its lu value): %lu\n", *(unsigned long *)&cmok);
    printf("s1: %p\n", (void *)s1);
    printf("*s1 (needs to be changed in accordance to cmok): %p\n", *s1); //Ask about this
    printf("cmok's name: %s\n", cmok.id);
    printf("cmok's latency: %d \n", cmok.latency);
    printf("cmok's nthreads - first try: %p\n", (void *)cmok.nthreads);
    printf("cmok's nthreads - second try: %d\n", *cmok.nthreads);
    printf("cmok's nthreads through pointer - first try: %p\n", (void *)s1->nthreads);
    printf("cmok's nthreads through pointer - second try: %d\n", *s1->nthreads);
    puts("=========================");
    puts("");

    //step 2: print idserver
    puts("========step 2==========");
    puts("--results of print_idserver--");
    print_idserver(cmok);
    puts("==========================");
    puts("");


    //step 3: modification
    puts("========step 3==========");
    modify(cmok, "cmok", 13000, "unknown");
    /* The 'modify' function will not modify the true cmok,
       It would modify a copy of cmok that will be created inside the function.
       So basically it's worth nothing. */

    puts("--results of modify--");
    print_idserver(cmok);

    modify_by_pointer(&cmok,"cmok", 13000, "unknown");
    /* The 'modify_by_pointer' function will indeed modify cmok,
       Because it's been given a pointer. */

    puts("--results of modify_by_pointer--");
    print_idserver(cmok);
    puts("=======================");
    puts("");

	//step 4: pointers
	puts("========step 4========");
	albi = cmok; //Albi is now a copy of cmok
	s2 = &albi;

	modify_by_pointer(s2, "albi", 9000, "down");
	puts("--*s2--");
	print_idserver(*s2); //Albi idserver
	puts("--albi--");
	print_idserver(albi); //Albi idserver
	puts("--cmok--");
	print_idserver(cmok); //Cmok idserver
	puts("=====================");
	puts(""); //What do they mean by 'explain the output'?

    free(cmok.id); free(cmok.region);
    free(albi.id); free(albi.region);


	//step 5: create idservers
	puts("========step 5=======");
	int nthreads = 20;

	idserver *s3 = create_idserver("thorn", "afr", 5200, "up", &nthreads);
	puts("--results of creating thorn, printed outside--");
	print_idserver(*s3);
	puts("=====================");
	puts("");


    return EXIT_SUCCESS;
}


