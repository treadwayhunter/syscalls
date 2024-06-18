#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

void treadprint(char *msg, ...) { // from here, I can do all sorts.
    //write(STDOUT_FILENO, msg, strlen(msg));

    // editting the same message I am iterating through sounds dangerous.
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
                    printf("The given int: %d\n", i);
                    break; 
                }
            }
        }
        else {
            buffer[buffer_loc] = p;
        }
    }
    // let's make it take integers
    va_end(args);
    printf("Num args: %d\n", num_args);
    write(STDOUT_FILENO, msg, strlen(msg));
}

int main() {
    //char buffer[10] = "";
    //buffer[0] = 'A';
    //buffer[1] = 'B';
    //printf("%s\n", buffer);
    //treadprint("Hello World :i\n", 5);
}