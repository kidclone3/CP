/*
problem1a.c

Driver function for Problem 1 Part A

Skeleton written by Grady Fitzpatrick for COMP20007 Assignment 1 2022
*/
#include <stdio.h>
/* 
leap.h

Visible structs and functions for leap list construction and manipulation.

Skeleton written by Grady Fitzaptrick for COMP20007 Assignment 1 2022
*/
struct leapList;

// enum problemPart;

/* A particular solution to an leapList problem. */
#ifndef SOLUTION_STRUCT
#define SOLUTION_STRUCT
struct solution {
    int queries;
    int *queryResults;
    int *queryElements;
    int *baseAccesses;
    int *requiredAccesses;
    /* Required for part B */
    struct leapList *list;
};
#endif

/* Which part the program should find a solution for. */
#ifndef PART_ENUM
#define PART_ENUM
enum problemPart {
    PART_A=0,
    PART_B=1
};
#endif

/* Value indicating the item is not found. */
#define NOTFOUND (-1)

/* Creates an empty leap list with the given max height and probability. */
struct leapList *newList(int maxHeight, double p, enum problemPart part);

/* Prints the given level of the list. */
void printLevel(struct leapList *list, int level);

/* Adds a new key to the leap list. */
void insertKey(int key, struct leapList **list);

/* Queries the leap list for the given key and places the result in the solution structure. */
int findKey(int key, struct leapList *list, enum problemPart part, struct solution *solution);

/* Deletes a value from the leap list. */
void deleteKey(int key, struct leapList *list, enum problemPart part);

/* Frees all memory associated with the leap list. */
void freeList(struct leapList *list);

/* Frees all memory associated with the solution. */
void freeSolution(struct solution *solution);

/* 
leap.c

Implementations for leap list construction and manipulation.

Skeleton written by Grady Fitzaptrick for COMP20007 Assignment 1 2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct leapList {
    /* IMPLEMENT: Fill in structure. */
    int level;
    int size;
    int data;
    double p;
    struct leaplist *next;
    struct leaplist *down;
    struct leapList *top;
};

// pointer function
struct leapList *newList(int maxHeight, double p, enum problemPart part){
    /* IMPLEMENT: Set up list */
    struct leapList *newList = NULL;
    struct leapList *temp = NULL;
    // Create list, then add p to each list.
    for (int i = 0; i<maxHeight; i++) {
        if (newList == NULL) {
            temp = newList = (struct leapList*) malloc(sizeof(struct leapList));
            assert(newList);
            temp->p = p;
            temp->level = i;
            temp->data = -1;
        } else {
            struct leapList *addition = (struct leapList*) malloc(sizeof(struct leapList));
            addition->p = p;
            addition->level = i;
            addition->data = -1;
            temp->next = addition;
            temp = temp->next;
        }
    }
    return newList;
}

void printLevel(struct leapList *list, int level){
    if(list == NULL) { 
        printf("\n");
        return;
    }
    /* IMPLEMENT (Part B): loop over list at given level, printing out each value. */
    /* Note: while additional next elements, print a space after the key. If no additional next elements, 
    print a new line and then return. */
    if (list->level > level) {
        // return;
    } else if (list->level < level) {
        printLevel(list->down, level);
        // return;
    } else {
        printf("%d ", list->data);
        printLevel(list->next, level);
        // return;
    }
    // printf("\n");
    return;
}

void insertKey(int key, struct leapList **list){
    /* IMPLEMENT: Insert the key into the given leap list. */
    if (*list == NULL) {
        struct leapList *add = (struct Node*)malloc(sizeof(struct leapList));
        add->data = key;
        *list = add;
    } else {
        struct leapList *current = *list;
        struct leapList *previous = NULL;
        int stop = 0;
        while (current != NULL && !stop) {
            if (current->data > key) {
                stop = 1;
            } else {
                previous = current;
                current = current->next;
            }
        }
        struct leapList *add = (struct Node*)malloc(sizeof(struct leapList));
        
        add->data = key;
        add->level = (*list)->level;
        add->p = (*list)->p;
        if (previous == NULL) {
            add->next = *list;
            add->down = (*list)->down;
            (*list)->down = NULL;
            *list = add;
        } else {
            previous->next = add;
            add->next = current;
        }
    }
    printLevel(list, (*list)->level);
    printf("\n");
}

/* Queries the leap list for the given key and places the result in the solution structure. */
int findKey(int key, struct leapList *list, enum problemPart part, struct solution *solution){
    int found = NOTFOUND;
    int element = key;
    int baseAccesses = 0;
    int requiredAccesses = 0;
    assert(solution);
    /* IMPLEMENT: Find the given key in the leap list. */
    struct leapList *current = list;
    while(current->next != NULL && current->next <= key) {
        current = current->next;
        baseAccesses += 1;
    }
    if (current->data == key) {
        found = 1;
    }
    printLevel(list, 0);
    printf("\n");
    /* Insert result into solution. */
    (solution->queries)++;
    solution->queryResults = (int *) realloc(solution->queryResults, sizeof(int) * solution->queries);
    assert(solution->queryResults);
    (solution->queryResults)[solution->queries - 1] = found;
    solution->queryElements = (int *) realloc(solution->queryElements, sizeof(int) * solution->queries);
    assert(solution->queryElements);
    solution->queryElements[solution->queries - 1] = element;
    solution->baseAccesses = (int *) realloc(solution->baseAccesses, sizeof(int) * solution->queries);
    assert(solution->baseAccesses);
    solution->baseAccesses[solution->queries - 1] = baseAccesses;
    solution->requiredAccesses = (int *) realloc(solution->requiredAccesses, sizeof(int) * solution->queries);
    assert(solution->requiredAccesses);
    solution->requiredAccesses[solution->queries - 1] = requiredAccesses;
    if (part == PART_B) {
        solution->list = list;
    }
    return found;
}

void deleteKey(int key, struct leapList *list, enum problemPart part){
    /* IMPLEMENT: Remove the given key from the leap list. */
    if (part == PART_A) return;

    struct leapList *current = list;
    // if head node itself holds the key
    if (current->data == key) {
        list = list->next;
        list->down = current->down;
        free(current);
        return;
    }

    while(current->next && current->next < key) {
        current = current->next;
    }
    if (current->next && current->next == key) { // found
        struct leapList *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    // also delete key in another layer
    deleteKey(key, list->down, part);
}

void freeList(struct leapList *list){
    /* IMPLEMENT: Free all memory used by the list. */
    if (!list) {
        return; 
    }
    if (!list->down && !list->next) {
        free(list);
        return;
    }
    freeList(list->down);
    freeList(list->next);
}

void freeSolution(struct solution *solution){
    if(! solution){
        return;
    }
    freeList(solution->list);
    if(solution->queries > 0){
        free(solution->queryResults);
        free(solution->queryElements);
        free(solution->baseAccesses);
        free(solution->requiredAccesses);
    }
    free(solution);
}

struct dictProblem;

/* Reads the data from the given file pointer and returns a pointer to this 
information. */
struct dictProblem *readProblem(FILE *file, enum problemPart part);

/* Finds a solution for a given problem. */
struct solution *findSolution(struct dictProblem *problem, enum problemPart part);

/* Prints a given solution. */
void printSolution(struct dictProblem *problem, struct solution *solution, enum problemPart part);

/* Frees all data used by problem. */
void freeProblem(struct dictProblem *problem);

/*
utils.c

Implementations for helper functions to do with reading and writing.

Skeleton written by Grady Fitzpatrick for COMP20007 Assignment 1 2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct dictProblem {
    unsigned int seed;
    int length;
    int queryLength;
    int height;
    double p;
    int *elements;
    int *queryElements;
    /* Used in Part B */
    int deleteLength;
    int *deleteElements;
    enum problemPart part;
};

/* Helper function, returns "not found" if the result is not found 
and "present" otherwise */
const char *getResultString(int result);

/* Reads the data from the given file pointer and returns a pointer to this 
information. */
struct dictProblem *readProblem(FILE *file, enum problemPart part){
    struct dictProblem *problem;
    problem = (struct dictProblem *) malloc(sizeof(struct dictProblem));
    assert(problem);
    /* 
    Read in input in form:
    <random seed>
    <length> <query length>
    <height> <p>
    <elements>
    <query elements>
    -- Part B only --
    <delete length>
    <delete elements>
    */
    assert(fscanf(file, "%u ", &(problem->seed)) > 0);
    assert(fscanf(file, "%d ", &(problem->length)) > 0);
    assert(fscanf(file, "%d ", &(problem->queryLength)) > 0);
    assert(fscanf(file, "%d ", &(problem->height)) > 0);
    assert(fscanf(file, "%lf ", &(problem->p)) > 0);
    assert(problem->length > 0);
    problem->elements = (int *) malloc(sizeof(int) * problem->length);
    assert(problem->elements);
    int i;
    for(i = 0; i < problem->length; i++){
        assert(fscanf(file, "%d", &((problem->elements)[i])) == 1);
    }
    assert(problem->queryLength > 0);
    problem->queryElements = (int *) malloc(sizeof(int) * problem->queryLength);
    assert(problem->queryElements);
    for(i = 0; i < problem->queryLength; i++){
        assert(fscanf(file, "%d", &((problem->queryElements)[i])) == 1);
    }
    if(part == PART_B){
        assert(fscanf(file, "%d ", &(problem->deleteLength)) > 0);
        /* Allow for no deletions to help with easier debugging. */
        if(problem->deleteLength > 0){
            problem->deleteElements = (int *) malloc(sizeof(int) * problem->deleteLength);
            assert(problem->deleteElements);
            for(i = 0; i < problem->deleteLength; i++){
                assert(fscanf(file, "%d", &((problem->deleteElements)[i])) == 1);
            }
        }
    }

    problem->part = part;

    return problem;
}

/* Finds a solution for a given problem. */
struct solution *findSolution(struct dictProblem *problem, enum problemPart part){
    struct solution *solution = (struct solution *) malloc(sizeof(struct solution));
    assert(solution);

    solution->queries = 0;
    solution->queryResults = NULL;
    solution->queryElements = NULL;
    solution->baseAccesses = NULL;
    solution->requiredAccesses = NULL;

    struct leapList *list = newList(problem->height, problem->p, part);
    solution->list = list;

    /* Set random seed. */
    srand(problem->seed);

    switch(part){
        case PART_A:
            for(int i = 0; i < problem->length; i++){
                insertKey((problem->elements)[i], &list);
            }


        printf("\n");            for(int i = 0; i < problem->queryLength; i++){
                findKey(problem->queryElements[i], list, part, solution);
            }

            break;

        case PART_B:
            for(int i = 0; i < problem->length; i++){
                insertKey((problem->elements)[i], &list);
            }

            for(int i = 0; i < problem->deleteLength; i++){
                deleteKey(problem->deleteElements[i], list, part);
            }

            for(int i = 0; i < problem->queryLength; i++){
                findKey(problem->queryElements[i], list, part, solution);
            }

            break;
    }

    return solution;
}

const char *getResultString(int result){
    if(result == NOTFOUND){
        return "not found";
    } else {
        return "present";
    }
}

void printSolution(struct dictProblem *problem, struct solution *solution, 
    enum problemPart part){
    int i;
    switch(part){
        case PART_A:
            for(i = 0; i < solution->queries; i++){
                printf("%d (%s): %d %d\n", 
                    solution->queryElements[i], getResultString(solution->queryResults[i]), 
                    solution->baseAccesses[i], solution->requiredAccesses[i]);
            }
            break;

        case PART_B:
            /* Print from the top down. */
            for(i = problem->height - 1; i >= 0; i--){
                printLevel(solution->list, i);
            }
            /* Print the same output as Part A. */
            for(i = 0; i < solution->queries; i++){
                printf("%d (%s): %d %d\n", 
                    solution->queryElements[i], getResultString(solution->queryResults[i]), 
                    solution->baseAccesses[i], solution->requiredAccesses[i]);
            }
            break;
    }
}

/* Frees all data used by problem. */
void freeProblem(struct dictProblem *problem){
    if(!problem){
        return;
    }

    if(problem->elements){
        free(problem->elements);
    }
    if(problem->queryElements){
        free(problem->queryElements);
    }
    
    if(problem->part == PART_B){
        if(problem->deleteElements){
            free(problem->deleteElements);
        }
    }
    free(problem);
    
}



int main(int argc, char **argv){
    /* Read the problem in from stdin. */
    struct dictProblem *problem = readProblem(stdin, PART_A);
    /* Find the solution to the problem. */
    struct solution *solution = findSolution(problem, PART_A);

    /* Report solution */
    printSolution(problem, solution, PART_A);

    freeProblem(problem);
    freeSolution(solution);

    return 0;
}


