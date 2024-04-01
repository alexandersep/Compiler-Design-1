#include <stdbool.h>
#ifndef TABLE_H
#define TABLE_H

struct var {
    char * name;
    int value;
    bool set;
};

struct table {
    struct var * vars;
    int size;
};

// create new variables
struct table * table_new();

// get value of variable given name
// return the index of the structure
int table_get_attribute(struct table * t, char * name);

// set table given name of vars array
void table_set_attribute(struct table * t, int value, char * name);

// print all table values and their names 
void table_print(struct table * t);

// free memory for table
void table_free(struct table * t);

#endif
