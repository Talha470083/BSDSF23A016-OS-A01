#include "../include/myfilefunctions.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* Count lines, words, characters in file.
   words: whitespace-separated tokens.
   Returns 0 on success, -1 on failure.
*/
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file || !lines || !words || !chars) return -1;
    if (fseek(file, 0, SEEK_SET) != 0) return -1;

    int c;
    int inword = 0;
    int l = 0, w = 0, ch = 0;

    while ((c = fgetc(file)) != EOF) {
        ch++;
        if (c == '\n') l++;
        if (isspace((unsigned char)c)) {
            if (inword) {
                w++;
                inword = 0;
            }
        } else {
            inword = 1;
        }
    }
    if (inword) w++; /* last word if file didn't end with space */

    *lines = l;
    *words = w;
    *chars = ch;
    return 0;
}

/* Search file for lines containing search_str.
   On success: allocate *matches (caller must free each string and the array).
   Returns number of matches (>=0). Returns -1 on failure.
*/
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str || !matches) return -1;
    if (fseek(fp, 0, SEEK_SET) != 0) return -1;

    char buffer[1024];
    char** res = NULL;
    int count = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, search_str) != NULL) {
            char* copy = malloc(strlen(buffer) + 1);
            if (!copy) {
                /* cleanup */
                for (int i = 0; i < count; ++i) free(res[i]);
                free(res);
                return -1;
            }
            strcpy(copy, buffer);
            char** tmp = realloc(res, sizeof(char*) * (count + 1));
            if (!tmp) {
                free(copy);
                for (int i = 0; i < count; ++i) free(res[i]);
                free(res);
                return -1;
            }
            res = tmp;
            res[count++] = copy;
        }
    }

    if (count == 0) {
        *matches = NULL;
    } else {
        *matches = res;
    }
    return count;
}

