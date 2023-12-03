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

int shellSort(struct array* s,int gap){
     int i=0,j=0;
      j=i+gap;
     int pass;
     while(j!=s->size){
     if(s->arr[i]>=s->arr[j]){
        swap(&s->arr[i],&s->arr[j]);
        if(i-gap>=0){
            if(s->arr[i]<s->arr[i-gap]){
                swap(&s->arr[i],&s->arr[i-gap]);
            }
        }
     }
     i++;
     j++;
     }

    return gap;
}
void divide(struct array* s){
    int gap;
    gap=(s->size)/2;
    while(gap!=0){
        gap=shellSort(s,gap);
        gap=gap/2;

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
    printf("Enter the size of array:");
    scanf("%d",&(s->size));
    s->arr=(int*)malloc(s->size*sizeof(int));
    printf("Enter the elements of array:\n");
    for(i=0;i<s->size;i++){
        scanf("%d",&(s->arr[i]));
    }
    divide(s);
    printf("The sorted array is:");
    printArray(s);
    return 0;
}