#ifndef CONTACT_H
#define CONTACT_H

typedef struct {
    char name[32];
    char phone[32];
} Contact;

int find_first_name(Contact contacts[], int count, const char *target);

int save_contacts(const Contact contacts[], int count, const char *path);

int load_contacts(Contact contacts[], int capacity, int *count, const char *path);

#endif