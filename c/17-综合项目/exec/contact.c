#include "contact.h"
#include <string.h>


int find_first_name(Contact contacts[], int count, const char *target) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, target) == 0) {
            return i;
        }
    }
    return -1;
}
