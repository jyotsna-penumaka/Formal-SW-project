#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>


void f (unsigned int n)
            {
              int *p;
              p = malloc(sizeof(int)*n);
              p[n-1] = 0;
            }