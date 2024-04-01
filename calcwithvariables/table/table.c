#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "table.h"

// create new variables
struct table * table_new() {
    struct table * t = malloc(sizeof(struct table));
    const int SIZE = 13;
    t->size = SIZE; // default table size
    t->vars = malloc(sizeof(struct var) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        t->vars[i].set = false;
    }
    return t;
}

// get value of variable given name
// return the index of the structure
// return: -1 failure
//         0 or more index
int table_get_attribute(struct table * t, char * name) {
    for (int i = 0; i < t->size; i++) {
        if (t->vars[i].set && (strcmp(t->vars[i].name,name) == 0)) {
            return i; 
        }
    }
    return -1;
}

// set table given name of vars array
void table_set_attribute(struct table * t, int value, char * name) {
    // if tables is full increase size by 2 + 1
    if (t->size == 0 || t->vars[t->size - 1].set) {
        int old_size = t->size;
        int new_size = (old_size << 1) + 1;  // t->size * 2 + 1
        if (realloc(t->vars, sizeof(struct var) * new_size) != NULL) {
            t->size = new_size;
            for (int i = old_size; i < new_size; i++) {
                t->vars[i].set = false;
            } 
        }
        else {
            printf("Error reallocating memory\n");
            return;
        }
    }
    // check and set the variables when not set
    for (int i = 0; i < t->size; i++) {
        if (!t->vars[i].set || (t->vars[i].set && (strcmp(t->vars[i].name, name) == 0))) {
            t->vars[i].name = name;
            t->vars[i].value = value;
            t->vars[i].set = true;
            break; 
        }
    }
}


// print all variables values and their names 
void table_print(struct table * t) {
    printf("| Name\t| Val\t| Set \t|\n");
    for (int i = 0; i < t->size; i++) {
        if (t->vars[i].set) {
            printf("| %s\t|", t->vars[i].name);
            printf(" %d\t|", t->vars[i].value);
            t->vars[i].set ? printf(" true\t|\n") : printf(" false\n|\n");
        }
    }
}

// free memory for table
void table_free(struct table * t) {
    free(t->vars);
    free(t);
}
