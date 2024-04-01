#include <stdio.h>
#include "table.h"

int main() {
    struct table * global_vars = table_new(); // 13 variables by default
    table_set_attribute(global_vars, 5, "a");
    //printf("%d\n", variables_getvar(global_vars, 3));
    int index = table_get_attribute(global_vars, "a");
    if (index != 1) {
        printf("index of table is %d and value is %d", index, global_vars->vars[index].value);
        printf(" and name is %s\n", global_vars->vars[index].name);
    } else {
        printf("Error, attribute does not exist\n");
        return 1;
    }
    //table_print(global_vars);
    table_free(global_vars);
    return 0;
}
