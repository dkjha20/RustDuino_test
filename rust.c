#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// There are several bugs relating to memory on this snippet.
// Find them all!

// Vector type can only hold ints.
typedef struct
{
  int *data;    // Pointer to our array on the heap
  int length;   // How many elements are in our array
  int capacity; // How many elements our array can hold
} vector;

vector *vector_new()
{
  vector v;
  v.data = NULL;
  v.length = 0;
  v.capacity = 0;
  return &v;
}

void vector_push(vector *v, int n)
{
  if (v->length == v->capacity)
  {
    int new_capacity = v->capacity * 2;
    int *new_data = (int *)malloc(new_capacity);
    assert(new_data != NULL);

    for (int i = 0; i < v->length; ++i)
    {
      new_data[i] = v->data[i];
    }

    v->data = new_data;
    v->capacity = new_capacity;
  }

  v->data[v->length] = n;
  ++v->length;
}

void vector_free(vector *v)
{
  free(v);
  free(v->data);
}

void main()
{
  vector *v = vector_new();
  vector_push(v, 107);

  int *n = &v->data[0];
  vector_push(v, 110);
  printf("%d\n", *n);

  free(v->data);
  vector_free(v);
}
