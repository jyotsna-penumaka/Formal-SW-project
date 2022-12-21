// // Prog 1: Buffer Overflow
// void string_to_buf (char *str) {
//     char buf[128];
//     strncat(buf, str, sizeof(buf));
// }

#include <stdio.h>
//#include "/Library/Developer/CommandLineTools/SDKs/MacOSX13.0.sdk/usr/include/stdio.h"
#include <string.h>

void string_to_buf(char *str) {
   char buffer[128];
   strlcpy(buffer,str,sizeof(buffer));
}

int main() {
    char user_input[128];

    printf("Enter a string : ");
    gets(user_input);

    string_to_buf(user_input);
}
