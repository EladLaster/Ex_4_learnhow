#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int weight = infinity;
int size;
pnode graph;

int *buildArr(int size)
{

    int *arr = (int *)malloc(sizeof(int) * size);
    if (arr == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    return arr;
}
int *copyArr(int *arr)
{
    int *copy = (int *)malloc(sizeof(int) * size);
    if (copy == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; i++)
    {
        copy[i] = arr[i];
    }
    return copy;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calculateWeight(int myWeight)
{
    // printf("%d\n", myWeight);
    if (myWeight < weight)
    {
        weight = myWeight;
    }
}
void permutations(int start, int *arr, int myWeight)
{
    if (start == size - 1)
    {
        calculateWeight(myWeight);
        return;
    }
    for (int i = start; i < size; ++i)
    {
        int *copy = copyArr(arr);
        swap(&copy[start], &copy[i]);

        int dis = shortsPath_cmd(graph, copy[start], copy[start + 1]);
        if (dis != -1)
        {
            myWeight += dis;
            permutations(start + 1, copy, myWeight);
        }
        free(copy);
    }
}
int TSP_cmd(pnode head)
{
    weight = infinity;
    graph = head;
    size = -1;
    scanf("%d", &size);
    int *arr = buildArr(size);
    int *copy = copyArr(arr);
    permutations(0, copy, 0);
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d, ", arr[i]);
    // }
    // printf("\n");
    free(arr);
    free(copy);
    weight = (weight == infinity) ? -1 : weight;
    return weight;
}