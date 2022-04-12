
// A simple C program for traversal of a linked list
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct leapList {
    /* IMPLEMENT: Fill in structure. */
    int level;
    int size;
    struct leapList *next;
    struct leapList *down;
    int data;
};

// pointer function
struct leapList *heads[100];
int height = 0;
double probability;

struct leapList *newList(int maxHeight, double p){
    /* IMPLEMENT: Set up list */
    height = maxHeight;
    probability = p;
    struct leapList *newList = NULL;
    struct leapList *temp = NULL;
    // Create levels.
    for (int i = 0; i<maxHeight; i++) {
        if (newList == NULL) {
            temp = newList = (struct leapList*) malloc(sizeof(struct leapList));
            temp->level = i;
            temp->data = -1;
            heads[i] = temp;
        } else {
            struct leapList *addition = (struct leapList*) malloc(sizeof(struct leapList));
            addition->level = i;
            addition->data = -1;

            temp->down = addition;
            temp = temp->down;

            heads[i] = temp;
        }
    }
    return newList;
}

void printLevel(struct leapList *list, int level){
    /* IMPLEMENT (Part B): loop over list at given level, printing out each value. */
    /* Note: while additional next elements, print a space after the key. If no additional next elements, 
    print a new line and then return. */
    struct leapList* head = heads[height-level-1];
    while (head != NULL) {
        if (head->data != -1)
            printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}
void printAllLevel() {
    for(int i = 0; i < height; ++i) {
        printLevel(NULL, i);
    }
}
struct leapList* insertLevel(int key, struct leapList *list, int level) {
    // Insert key to this level.
    struct leapList* head = heads[level];
    if (head->next == NULL) {
        struct leapList* add = (struct leapList*)malloc(sizeof(struct leapList));
        add->data = key;
        head->next = add;
        return &(*add);
    } else {
        struct leapList* current = heads[level];
        struct leapList* previous = NULL;
        int stop = 0;
        while (current != NULL && !stop) {
            if (current->data == key) return NULL;
            if (current->data > key) {
                stop = 1;
            } else {
                previous = current;
                current = current->next;
            }
        }
        struct leapList* add = (struct leapList*)malloc(sizeof(struct leapList));
        add->data = key;
        add->next = current;
        previous->next = add;
        return &(*add);
    }
}

void insertKey(int key, struct leapList *list){
    /* IMPLEMENT: Insert the key into the given leap list. */
    // We just insert to the lowest level.
    int i = height - 1;
    struct leapList* lower = insertLevel(key, list, i);
    struct leapList* higher = NULL;
    // rand();
    double pp = (double) rand() / RAND_MAX;
    while (i >= 0 && pp < probability && lower != NULL) {
        i--;
        higher = insertLevel(key, list, i);
        if (higher != NULL) {
            higher->down = lower;
            lower = higher;
        } else break;
        if (i >= 0) pp = (double) rand() / RAND_MAX;
    }
}

// Find the element in lastest base first
int _found = 0;
int findBaseAccesses(int key) {
    int position = 0;
    _found = 0;
    struct leapList* head = heads[height-1];
    while (head != NULL && head->data < key) {
        head = head->next; 
        position++;
    }

    if (head == NULL || head->data != key) {
        _found = 0;
    } else {
        _found = 1;
    }
    return position;
}
int visited[1000]; // To mark the visited node.
int findRequiredAccess(int key) {
    // If cannot find in base, return 0;
    memset(visited, 0, sizeof(visited));
    int i = 0;
    while(i < height && heads[i]->next == NULL) {
        i++; // skip the null levels.
    }
    struct leapList* current = heads[i]->next;
    int answer = 1;
    while(i < height) {
        printf("curr: %d, ans: %d\n", current->data, answer);
        if (current->data == key) return answer;
        if (!visited[current->data]) {
            visited[current->data] = 1;
            answer++;
        }
        if (current->data > key) {
            if (i+1 < height) current = heads[++i]->next;
            else return answer;
        } else if (current->next == NULL || current->next->data > key) {
            if (current->down != NULL) {
                current = current->down;
                i++;
            } else {
                if (i+1 < height) {
                    current = heads[++i]->next;
                } else break;
            }
        } else {
            current = current->next;
        }
        
    }
    return answer;
}
/* Queries the leap list for the given key and places the result in the solution structure. */
int findKey(int key, struct leapList *list){
    
    int found = 0;
    int element = key;
    int baseAccesses = 0;
    int requiredAccesses = 0;
    
    /* IMPLEMENT: Find the given key in the leap list. */
    
    baseAccesses = findBaseAccesses(key);
    if (_found) found = 1;
    requiredAccesses = findRequiredAccess(key);
    printf("found: %d, base: %d, require: %d\n", _found, baseAccesses, requiredAccesses);
}

void deleteKey(int key, struct leapList *list){
    /* IMPLEMENT: Remove the given key from the leap list. */
    if (!findBaseAccesses(key)) return;
    int i;
    for(i = 0; i < height; ++i) {
        struct leapList *head = heads[i];
        struct leapList *previous = NULL;
        while (head != NULL && head->data < key) {
            previous = head;
            head = head->next;
        }
        if (head == NULL || head->data > key) {
            continue;
        }
        if (head->data == key) {
            previous->next = head->next;
            free(head);
        }
    }
}
int main()
{
    struct leapList* list = newList(4, 0.2);
    // insertKey(1, list);
    int seed;
    scanf("%d", &seed);
    srand(seed);
    int n1, n2, n3;
    scanf("%d %d", &n1, &n2);
    int inp[n1], inp2[n2];
    int height;
    scanf("%d %f", &height, &probability);
    for(int i = 0; i < n1; ++i) {
        scanf("%d ", inp+i);
        insertKey(inp[i], list);
    }
    for(int i = 0; i < n2; ++i) {
        scanf("%d", inp2+i);
    }
    scanf("%d", &n3);
    int inp3[n3];
    for(int i = 0; i < n3; ++i) {
        scanf("%d", inp3+i);
        deleteKey(inp3[i], list);
    }
    // deleteKey(100, list);
    for(int i = 0; i < n2; ++i) {
        findKey(inp2[i], list);
    }
    
	return 0;
}
