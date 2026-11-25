#ifndef CONTACT_H
#define CONTACT_H

typedef struct {
    char name[32];
    char phone[32];
} Contact;

int find_first_name(Contact contacts[], int count, const char *target);

#endif