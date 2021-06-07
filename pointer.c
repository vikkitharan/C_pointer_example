#include<stdlib.h>
#include<stdio.h>

int main() {
  int* p = NULL;
  p = (int*) malloc(10 * sizeof(int));

  for(int i = 0; i < 10; i++) {
    *(p + i) = i;
  }

  for(int i = 0; i < 10; i++) {
    printf("%d\n",*(p + i));
  }

  free(p);
  p = NULL;
  return 1;
}
