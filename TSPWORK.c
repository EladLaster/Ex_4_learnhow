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
void calculateWeight(int *arr)
{
    int tempWeight = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int dis = shortsPath_cmd(graph, arr[i], arr[i + 1]);
        if (dis == -1)
        {
            tempWeight = infinity;
            return;
        }
        tempWeight += dis;
    }
    if (tempWeight < weight)
    {
        weight = tempWeight;
    }
}

void permutations(int start, int *arr)
{
    if (start == size - 1)
    {
        calculateWeight(arr);
        return;
    }
    for (int i = start; i < size; ++i)
    {
        int *copy = copyArr(arr);
        swap(&copy[start], &copy[i]);
        permutations(start + 1, copy);
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
    permutations(0, copy);
    free(arr);
    free(copy);
    weight = (weight == infinity) ? -1 : weight;
    return weight;
}