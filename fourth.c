#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// There are several bugs relating to memory on this snippet.
// Find them all!

// Vector type can only hold ints.
typedef struct vector
{
  int *data;    // Pointer to our array on the heap
  int length;   // How many elements are in our array
  int capacity; // How many elements our array can hold
}vector ;

vector *vector_new()
{
  vector *v;
  v=calloc(1,sizeof(vector));
  v->length = 0;
  v->capacity = 1;
  v->data = calloc((v->capacity),sizeof(int));
  return v;
}

void vector_push(vector *v, int n)
{
  if (v->length == v->capacity)
  {
    int new_capacity = v->capacity * 2;
    int *new_data = (int *)malloc(new_capacity*sizeof(int));
    assert(new_data != NULL);

    for (int i = 0; (i < (v->length)); i++)
    {
      new_data[i] = (v->data)[i];
    }

    int *x= (v->data);
    v->data = new_data;
    v->capacity = new_capacity;
    free(x);
  }

   int p=(v->length);
   (v->data)[p] = n;
   (v->length) = (v->length) + 1;
   return;
}

void vector_free(vector *v)
{
  free(v->data);
  free(v);
  return;
}

int main()
{
  vector *v = vector_new();
  vector_push(v, 150);

  int n = (v->data)[0];
  vector_push(v, 110);
  vector_push(v, 110);
  vector_push(v, 110);
  vector_push(v, 110);
  vector_push(v, 110);
  printf("%d\n", n);
  for(int i=0;i<(v->length);i++) {
      printf("%d ",(v->data)[i]);
  }

  vector_free(v);
  return 0;
}
