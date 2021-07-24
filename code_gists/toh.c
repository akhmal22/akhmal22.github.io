#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CAP 19

struct Rod {
  int pos;
  int top;
  unsigned capacity;
  int array[CAP];
};

struct Rod* createStack(unsigned capacity, int position);

int isFull(struct Rod* rod);

int isEmpty(struct Rod* rod);

int push(struct Rod* rod, int item);

int pop(struct Rod* rod);

int peek(struct Rod* rod);

int isSmaller(struct Rod* rod, int pushing);

void gameCommence(int disk);

int moveDisk(struct Rod* init, struct Rod* dest);

void solveProblem(struct Rod* init, struct Rod* mid, struct Rod* final);

struct Rod* createStack(unsigned capacity, int position){
  struct Rod* rod = (struct Rod*)malloc(sizeof(struct Rod));

  rod->capacity = capacity;
  rod->pos = position;
  rod->top = -1;
  if(rod->pos==0){
    for(int i = rod->capacity - 1; i >= 0; --i){
      push(rod, i);
    }
  }

  return rod;
}

int isFull(struct Rod* rod){
  return rod->top == rod->capacity - 1;
}

int isEmpty(struct Rod* rod){
  return rod->top == -1;
}

int push(struct Rod* rod, int item){
  if(isFull(rod) || isSmaller(rod, item))
    return 0;
  else{
    rod->array[++rod->top] = item;
    return 1;
  }
}

int pop(struct Rod* rod){
    if (isEmpty(rod))
        return INT_MAX;
    return rod->array[rod->top--];
}

int peek(struct Rod* rod){
    if (isEmpty(rod))
        return INT_MAX;
    return rod->array[rod->top];
}

int isSmaller(struct Rod* rod, int pushing) {
  return peek(rod) <= pushing;
}

void gameCommence(struct Rod* init, int disk){
  for(int i = disk - 1; i >= 0; --i){
    push(init, i);
  }
}

int moveDisk(struct Rod* init, struct Rod* dest){
  int disk = peek(init);

  if(push(dest, disk)){
    pop(init);
    return 1;
  }else{
    return 0;
  }
}


void solveProblem(struct Rod* init, struct Rod* mid, struct Rod* final, int disks){
  long counter = 0;
  while(!isFull(final)){
    counter++;
    if(disks % 2 == 0){
      //printf("even\n");
      //printf("step: %d\n", ++counter);
      if(counter % 3 == 1){
        if(!moveDisk(init, mid))
          moveDisk(mid, init);
      }else if(counter % 3 == 2){
        if(!moveDisk(init, final))
          moveDisk(final, init);
      }else{
        if(!moveDisk(mid, final))
          moveDisk(final, mid);
      }
    }else{
      //printf("odd\n");
      //printf("step: %d\n", ++counter);
      if(counter % 3 == 1){
        if(!moveDisk(init, final))
          moveDisk(final, init);
      }else if(counter % 3 == 2){
        if(!moveDisk(init, mid))
          moveDisk(mid, init);
      }else{
        if(!moveDisk(mid, final))
          moveDisk(final, mid);
      }
    }
  }
}


int main(){

  struct Rod* init = createStack(CAP, 0);
  struct Rod* mid = createStack(CAP, 1);
  struct Rod* final = createStack(CAP, 2);

  printf("Welcome, 世界\n" );

  gameCommence(init, init->capacity);
  printf("Game Commenced\n" );

  solveProblem(init, mid, final, init->capacity);
  printf("Problem Solved\n" );
}
