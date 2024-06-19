#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

// not elegant, but fast.
int numPlaces(int n) {
    if (n < 0) return numPlaces(-n) + 1;
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    return 10;
}

void treadprint(char *msg, ...) {

    char buffer[1024];
    int buffer_loc = 0;
    va_list args;
    va_start(args, msg);
    int num_args = 0;

    // use ':' as a delimeter for format
    for (const char *p = msg; *p != '\0'; p++) { // p starts at the location where msg begins
        if(*p == ':') {
            num_args++;
            p++;
            switch(*p) {
                case 'i': {
                    int i = va_arg(args, int);
                    char temp[16];
                    sprintf(temp, "%d", i);
                    for (int c = 0; c < numPlaces(i); c++) {
                        buffer[buffer_loc] = temp[c];
                        buffer_loc++;
                    }
                    break; 
                }
                /**
                 * Add other cases for floats, doubles, strings, etc.
                 */
            }
        }
        else {
            buffer[buffer_loc] = *p;
            buffer_loc++;
        }
    }
    va_end(args);

    char new_msg[buffer_loc];
    strcpy(new_msg, buffer);
    write(STDOUT_FILENO, new_msg, sizeof(new_msg));
}

int main() {

    treadprint("Can I handle negative numbers? :i \n", -100);
}