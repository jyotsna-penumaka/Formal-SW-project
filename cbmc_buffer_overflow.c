// // Prog 1: Buffer Overflow
// void string_to_buf (char *str) {
//     char buf[128];
//     strncat(buf, str, sizeof(buf));
// }

#include <stdio.h>
#include <string.h>

void string_to_buf(char *str) {
  char buffer[128];
  strcpy(buffer, str);
}

int main() {
    // char user_input[128];

    // for (int i = 0; i < 128; i++){
    //   user_input[i] = "a";
    // }
    char* user_input = "aaa";

    string_to_buf(user_input);

}
