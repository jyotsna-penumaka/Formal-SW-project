#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

  
int main()
{
    int* p = (int*)malloc(sizeof(int) * 4);
    int i;
  
    // p[] contains some garbage value so
    // below loop does not make any sense.
    for (i = 0; i < 4; i++)
        p[i] += 100;
}