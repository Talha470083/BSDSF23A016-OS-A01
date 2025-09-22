#include "../include/mystrfunctions.h"
#include <stddef.h> /* for size_t */
#include <stdlib.h>

int mystrlen(const char* s) {
    if (!s) return -1;
    const char* p = s;
    while (*p) ++p;
    return (int)(p - s);
}

/* Copies src into dest. Returns the number of characters copied (not counting '\0'),
   or -1 on error (e.g., NULL pointers). Ensures dest is null-terminated. */
int mystrcpy(char* dest, const char* src) {
    if (!dest || !src) return -1;
    char* d = dest;
    const char* s = src;
    while (*s) {
        *d++ = *s++;
    }
    *d = '\0';
    return (int)(d - dest);
}

/* Copies up to n characters from src to dest. Always null-terminates dest.
   Returns number of characters copied (<= n), or -1 on error. */
int mystrncpy(char* dest, const char* src, int n) {
    if (!dest || !src || n < 0) return -1;
    int i = 0;
    for (; i < n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    /* Ensure null termination */
    dest[i] = '\0';
    return i;
}

/* Appends src to the end of dest. Assumes dest has enough space.
   Returns length of resulting dest (excluding '\0') or -1 on error. */
int mystrcat(char* dest, const char* src) {
    if (!dest || !src) return -1;
    int dest_len = mystrlen(dest);
    if (dest_len < 0) return -1;
    char* d = dest + dest_len;
    const char* s = src;
    while (*s) {
        *d++ = *s++;
    }
    *d = '\0';
    return (int)(d - dest);
}

