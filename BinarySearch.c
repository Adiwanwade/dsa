#include<stdio.h>
#include<stdlib.h>
struct array{
int size;
int* arr;
};
void BinarySearch(struct array* s,int value){
    int i=0;
    int start=0,end=s->size-1;
    int mid;
   while (start<=end)
   {
    mid=(start+end)/2;
    if(value==s->arr[mid]){
        printf("Element is found ");
        break;
    }
    else if(value>s->arr[mid]){
        start=mid+1;
    }
    else{
        end=mid-1;
    }
   }
   if(start>end)
            printf("The value is not found");


}

int main(){
    int i=0,value;
    struct array *s=(struct array*)malloc(sizeof(struct array));
    printf("Enter the size of array:");
    scanf("%d",&(s->size));
    s->arr=(int*)malloc(s->size*sizeof(int));
    printf("Enter the elements of array:\n");
    for(i=0;i<s->size;i++){
        scanf("%d",&(s->arr[i]));
    }
    printf("Enter the value to search:");
    scanf("%d",&value);
   BinarySearch(s,value);
    return 0;
}