#include <stdio.h>
#include <stdlib.h>
struct array
{
    int size;
    int *arr;
};


int linearSearch(struct array *s, int value)
{
    int i = 0;
    for (i = 0; i < s->size; i++)
    {
        if (s->arr[i] == value)
        {
            printf("The value has been found at:%d", i + 1);
            return;
        }
    }

    printf("The value is not found");
}

int main()
{
    int i = 0, value;
    struct array *s = (struct array*)malloc(sizeof(struct array));
    printf("Enter the size of array:");
    scanf("%d", &(s->size));
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Enter the elements of array:\n");
    for (i = 0; i < s->size; i++)
    {
        scanf("%d", &(s->arr[i]));
    }
    printf("Enter the value to search:");
    scanf("%d", &value);
    linearSearch(s, value);
    return 0;
}