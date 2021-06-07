/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//         File: pointer.c
//               Explains memory allocation, update and usage are done by
//               separate functions.
//   Created by: vikgna
//   Created on: 2021/06/07
//  Modified by: vikgna
//  Modified on: 2021/06/07
//      Version: 1.0.0
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <stdlib.h>

/*++++++++++++++++++++++++++++++++ PRIVATE Function ++++++++++++++++++++++++/
//     Function: allocate_memory ()
//  Description: Allocates heap for 10 integers and update the dereference of argument
//               with allocated memory address.
//   Parameters: pointer of pointer of memory.
//               Double pointer is used because pass by reference of a pointer
//      Return : 0 - if memory allocation succeeds
//               1 - if memory allocation fails
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int allocate_memory(int** ptr_ptr_memory) {
  *ptr_ptr_memory = (int*)malloc(10 * sizeof(int));
  if (*ptr_ptr_memory == NULL) {
    printf("memory allocation fails");
    return 1;
  }
  return 0;
}

/*++++++++++++++++++++++++++++++++ PRIVATE Function ++++++++++++++++++++++++/
//     Function: update_memory ()
//  Description: Update the memory in heap
//   Parameters: pointer of memory
//               Single pointer is used (pass by reference)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void update_memory(int* ptr_memory) {
  for (int i = 0; i < 10; i++) {
    *(ptr_memory + i) = i;
  }
}

/*++++++++++++++++++++++++++++++++ PRIVATE Function ++++++++++++++++++++++++/
//     Function: use_memory ()
//  Description: prints values in the heap
//   Parameters: constant pointer of memory
//               const is use to prevent the memory from modifying accidentally
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void use_memory(int* const ptr_memory) {
  for (int i = 0; i < 10; i++) {
    printf("%d\n", *(ptr_memory + i));
  }
}

int main() {
  /* pointer which points the allocated memory */
  int* ptr_memory = NULL;
  /* pointer which points the pointer of allocated memory */
  int** ptr_ptr_memory = &ptr_memory;

  allocate_memory(ptr_ptr_memory);

  update_memory(ptr_memory);

  use_memory(ptr_memory);

  free(ptr_memory);
  ptr_memory = NULL;

  return 1;
}
