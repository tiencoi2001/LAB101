#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sub_str_func(char *main_str, char *sub_str)
{
    if (main_str == NULL || sub_str == NULL) {
        return -1;
    }

    int main_len = strlen(main_str);
    int sub_len = strlen(sub_str);

    if (main_len < sub_len) {
        return -1;
    }

    if (sub_len == 0) {
        return 0;
    }

    int i, j;
    int bad_steps[128];
    for (i = 0; i < 128; i++) {
        bad_steps[i] = sub_len;
    }
    for (i = 0; i < sub_len; i++) {
        bad_steps[sub_str[i]] = sub_len - 1 - i;
    }
    int *good_steps = malloc(sub_len * sizeof(int));
    for (i = 0; i < sub_len; i++) {
        good_steps[i] = sub_len;
        for (j = i - 1; j >= 0; j--) {
            if (!memcmp(sub_str + i, sub_str + j, sub_len - i)) {
                good_steps[i] = i - j;
                break;
            }
        }
    }

    char *p = main_str + sub_len - 1;
    char *q = sub_str + sub_len - 1;
    char *r = p;
    while (p - main_str < main_len) {
        int step = 0;
        for (i = 1; i <= sub_len && *p == *q; i++) {
            if (q == sub_str) {
                return p - main_str;
            }
            if (good_steps[sub_len - i] > step) {
                step = good_steps[sub_len - i];
            }
            p--;
            q--;
        }

        if (i == 1 && bad_steps[*p] > step) {
            step = bad_steps[*p];
        }
        r += step;
        p = r;
        q = sub_str + sub_len - 1;
    }

    return -1;
}

static int strStr(char *main_str, char *sub_str)
{
    unsigned int main_len = strlen(main_str);
    unsigned int sub_len = strlen(sub_str);

    if (sub_len == 0) {
        return 0;
    }

    int i, j;
    for (i = 0; i < main_len; i++) {
        int found = 1;
        if (main_str[i] == sub_str[0]) {
	    for (j = 1; j < sub_len; j++) {
                if (i + j < main_len) {
                    if (main_str[i + j] != sub_str[j]) {
                        found = 0;
                        break;
                    }
                } else {
                    return -1;
                }
	    }
	    if (found) {
    		return i;
    	    }
	}
    }

    return -1;
}

int main(void)
{
   	char main_str[50];
   	printf("Please enter main string: ");
   	fgets(main_str, sizeof(main_str), stdin);
	char sub_str[50];
	printf("Please enter substring: ");
	fgets(sub_str, sizeof(sub_str), stdin);
    printf("\nStarting position of the substring in the main string: %d\n", sub_str_func(main_str, sub_str));
    return 0;
}

