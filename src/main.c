#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main(void) {
    printf("--- Testing String Functions ---\n");

    char buf[256];
    const char* s1 = "Hello";
    const char* s2 = " World!";
    int len;

    /* mystrlen */
    len = mystrlen(s1);
    printf("mystrlen('%s') = %d\n", s1, len);

    /* mystrcpy */
    mystrcpy(buf, s1);
    printf("After mystrcpy: buf = '%s'\n", buf);

    /* mystrcat */
    mystrcat(buf, s2);
    printf("After mystrcat: buf = '%s'\n", buf);
    printf("Length now = %d\n", mystrlen(buf));

    /* mystrncpy */
    char dst[8];
    mystrncpy(dst, "ABCDEFGHIJK", 5);
    printf("mystrncpy dst (n=5) = '%s'\n", dst);

    printf("\n--- Testing File Functions ---\n");

    /* create a sample test file */
    const char* fname = "test_input.txt";
    FILE* fw = fopen(fname, "w");
    if (!fw) {
        perror("fopen for writing test file");
        return 1;
    }
    fprintf(fw, "The quick brown fox\n");
    fprintf(fw, "jumps over the lazy dog\n");
    fprintf(fw, "Another line with fox inside\n");
    fprintf(fw, "last line\n");
    fclose(fw);

    FILE* fr = fopen(fname, "r");
    if (!fr) {
        perror("fopen for reading test file");
        return 1;
    }

    int lines=0, words=0, chars=0;
    if (wordCount(fr, &lines, &words, &chars) == 0) {
        printf("wordCount -> lines=%d words=%d chars=%d\n", lines, words, chars);
    } else {
        printf("wordCount failed\n");
    }

    char** matches = NULL;
    int found = mygrep(fr, "fox", &matches);
    if (found >= 0) {
        printf("mygrep found %d lines containing 'fox'\n", found);
        for (int i = 0; i < found; ++i) {
            printf("MATCH %d: %s", i+1, matches[i]);
            free(matches[i]); /* free each matched string */
        }
        free(matches); /* free pointer array */
    } else {
        printf("mygrep failed\n");
    }

    fclose(fr);

    /* cleanup (optional) */
    /* remove(fname); */

    return 0;
}

