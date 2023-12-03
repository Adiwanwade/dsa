#include<stdio.h>
#include<stdlib.h>
struct array{
int size;
int* arr;
};

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(struct array*s, int low, int high) {


  int pivot = s->arr[high];


  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (s->arr[j] <= pivot) {


      i++;

      swap(&s->arr[i], &s->arr[j]);
    }
  }


  swap(&s->arr[i + 1], &s->arr[high]);


  return (i + 1);
}

void quickSort(struct array*s, int low, int high) {
  if (low < high) {


    int pi = partition(s, low, high);


    quickSort(s, low, pi - 1);


    quickSort(s, pi + 1, high);
  }
}


void printArray(struct array* s) {
  for (int i = 0; i < s->size; i++) {
    printf("%d  ", s->arr[i]);
  }
  printf("\n");
}




int main(){
    int i=0;
    struct array *s=(struct array*)malloc(sizeof(struct array));
    printf("Enter the size of array");
    scanf("%d",&(s->size));
    s->arr=(int*)malloc(s->size*sizeof(int));
    printf("Enter the elements of array:\n");
    for(i=0;i<s->size;i++){
        scanf("%d",&(s->arr[i]));
    }
    quickSort(s,0,s->size-1);
    printf("The sorted array is:");
    printArray(s);
}