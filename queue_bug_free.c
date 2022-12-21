#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

#define ERR_NULL_PTR      -1
#define ERR_MEM_EXHAUSTED -2
#define ERR_INDEX_BOUNDS  -3
#define ERR_OBJECT_EMPTY  -4
#define ERR_INVALID_BOUND -5
#define ERR_INVALID_SIZE  -6
#define SUCCESS           0

#define MAX_ARRAY_BOUND   8

#define handle_error_en(en, msg) do { errno = en; printf("%s: ", msg); exit(EXIT_FAILURE); } while (0)

int nondet_int(void);
char nondet_char(void);

typedef char elem;

typedef struct ubarray_record ubarray;
struct ubarray_record {
  int size;
  int bound;
  elem *data;
};

unsigned char valid_ubarray(ubarray *a)
{
  return a != NULL && a->size >= 0 && a->bound >= 0 && a->data != NULL && a->size <= a->bound;
}

ubarray *ubarray_new(int init_bound)
{
  if(init_bound <= 0 || init_bound > MAX_ARRAY_BOUND)
    return NULL;

  ubarray *a = malloc(sizeof(ubarray));
  if(a != NULL) {
    a->size = 0;
    a->bound = init_bound;
    a->data = calloc(init_bound, sizeof(elem));  
  }

  return a;
}

int uba_size(ubarray *a)
{
  return a->size;
}

int uba_resize(ubarray *a, int new_bound)
{
  if(new_bound > MAX_ARRAY_BOUND)
    handle_error_en(ERR_MEM_EXHAUSTED, "out of memory");

  elem *b = calloc(new_bound, sizeof(elem));
  int d =  a->size;

  for(int i = 0; i < d; i++)
    b[i] = a->data[i];
  free(a->data);
  a->bound = new_bound;
  a->data = b;

  return SUCCESS;
}

int uba_add(ubarray *a, elem e)
{
  int s = a->size;
  int b = a->bound;
  if(s == b){
    printf("max bound size reached");
    return 0;
    }
  
  s++;
  a->data[s] = e;
  return SUCCESS;
}

elem uba_get(ubarray *a, int idx)
{
  return a->data[idx];
}

int uba_set(ubarray *a, int idx, elem e)
{
  a->data[idx] = e;
  return SUCCESS;
}

int uba_rem(ubarray *a)
{
  a->size--;
  return SUCCESS;
}

int ubarray_harness() {
  /* Write your test harness for the unbounded array implementation here */
   /* Write your test harness for the unbounded array implementation here */
  ubarray *a = ubarray_new(7);
  int s;
  s = uba_size(a);
  elem c = 'c';
   uba_resize(a , 5); 
    s = uba_get(a, 0);
    uba_rem(a);

elem d = 'b';
 
for (int i = 0; i < 5; i++){
      uba_add(a ,c);

printf("Hi %d", s);

  }

  uba_set(a , 0, d);

return 0;

}

typedef struct queue_header queue;
struct queue_header {
  ubarray* data;
  int front;
  int back;
};

char queue_empty(queue* Q)
{
  return Q->front == Q->back;
}

queue* queue_new(int init_bound)
{
  queue* Q = malloc(sizeof(queue));

  if(Q != NULL) {
    Q->data = ubarray_new(init_bound);
    if(Q->data == NULL) return NULL;
    Q->front = 0;
    Q->back = 0;
  }

  return Q;
}

int enq(queue* Q, elem s)
{
  uba_add(Q->data, s);
  Q->back++;
  return SUCCESS;
}

elem deq(queue* Q)
{
  elem s = uba_get(Q->data, Q->front);
  Q->front++;
  return s;
}

typedef queue* queue_t;

queue_t queue_copy(queue_t Q)
{
  queue_t Qp = queue_new(1);

  for(int i = 0; i < Q->data->bound; i++) 
    Qp->data->data[i] = Q->data->data[i];

  Qp->front = Q->front;
  Qp->back = Q->back;

  return Qp;
}

void queue_harness()
{
  /* Write your test harness for the queue implementation here */
   queue *q = queue_new(7);
  enq(q, 1);
  enq(q,2);
  enq(q,3);

}

void queue_copy_harness()
{
  /* Write your test harness for queue_copy here */
}