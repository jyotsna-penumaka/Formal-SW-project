// // Prog 1: Buffer Overflow
// void string_to_buf (char *str) {
//     char buf[128];
//     strncat(buf, str, sizeof(buf));
// }

#include <stdio.h>
#include <string.h>

void *gets(char *str)
{
  __CPROVER_assert(0, "Never use gets() function.");
}

void string_to_buf(char *str) {
   char buffer[128];
   strncpy(buffer,str,sizeof(buffer));
}

int main() {
    char user_input[128];

    printf("Enter a string : ");
    gets(user_input);

    string_to_buf(user_input);
}
