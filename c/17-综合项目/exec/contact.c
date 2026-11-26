#include "contact.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>

int find_first_name(Contact contacts[], int count, const char *target) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, target) == 0) {
            return i;
        }
    }
    return -1;
}

int save_contacts(const Contact contacts[], int count, const char *path) {
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        return 0;
    }
    for (int i = 0; i < count; i++) {
        if (fprintf(fp, "%s\t%s\n", contacts[i].name, contacts[i].phone) < 0) {
            fclose(fp);
            return 0;
        }
    }
    if (fclose(fp) != 0) {
            return 0;
    }
    return 1;
}

int load_contacts(Contact contacts[], int capacity,
                  int *count, const char *path)
{
    *count = 0;

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return errno == ENOENT;
    }

    char line[128];
    int ok = 1;

    while (*count < capacity && fgets(line, sizeof line, fp) != NULL) {
        char *newline = strchr(line, '\n');
        if (newline != NULL) {
            *newline = '\0';
        } else if (!feof(fp)) {
            ok = 0;
            break;
        }

        char *tab = strchr(line, '\t');
        if (tab == NULL) {
            ok = 0;
            break;
        }

        *tab = '\0';
        char *name = line;
        char *phone = tab + 1;

        if (name[0] == '\0' || phone[0] == '\0' ||
            strchr(phone, '\t') != NULL ||
            strlen(name) >= sizeof contacts[0].name ||
            strlen(phone) >= sizeof contacts[0].phone) {
            ok = 0;
            break;
        }

        strcpy(contacts[*count].name, name);
        strcpy(contacts[*count].phone, phone);
        (*count)++;
    }

    if ((ok == 1) && (*count == capacity)) {
        if (fgets(line, sizeof line, fp) != NULL) {
            ok = 0;
        }
    }

    if (ferror(fp)) {
        ok = 0;
    }
    if (fclose(fp) != 0) {
        ok = 0;
    }

    return ok;
}
