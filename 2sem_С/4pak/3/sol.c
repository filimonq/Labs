#include "sol.h"
#include <stdlib.h>

// В sol.c нужно реализовать функции
//  init, getEdgesCount и getIncidentEdge
typedef struct Vector {
    Edge *arr;
    int cnt;            //сколько элементов в массиве реально есть
    int cap;            //на сколько элементов выделено место в блоке памяти arr (capacity)
} Vector;

Vector *mas;
Edge edge;

//=========================================5=====
//implement these functions in your solution:
//this function is called first to initialize graph
//you are expected to read graph here and fill internal data structures
void init()
{
    int n = getVerticesCount();
    mas = calloc(n, sizeof(Vector));
    int start = 0, end = 0;
    int c = 0;
    while (readEdge(&edge))
    {
        start = edge.from;
        end = edge.to;
        
        if (mas[start].cnt == 0)
        {
            mas[start].cap = 2;
            mas[start].arr = calloc(mas[start].cap, sizeof(Edge));
        }
        if (mas[end].cnt == 0)
        {
            mas[end].cap = 2;
            mas[end].arr = calloc(mas[end].cap, sizeof(Edge));
        }

        if (mas[start].cap >= mas[start].cnt + 2) // если влезает
        {
            mas[start].arr[mas[start].cnt].from = start;    // mas[start].arr[mas[start].cnt++] = edge;
            mas[start].arr[mas[start].cnt].to = end;
            mas[start].arr[mas[start].cnt++].weight = edge.weight;
        } else // иначе добавляем память
        {
            mas[start].cap *= 2;
            mas[start].arr = realloc(mas[start].arr, mas[start].cap * sizeof(Edge));
            mas[start].arr[mas[start].cnt].from = start;    //
            mas[start].arr[mas[start].cnt].to = end;
            mas[start].arr[mas[start].cnt++].weight = edge.weight;  
        }

            /*int ildar = 0; // меняем местами вершинки
            ildar = edge.from;
            edge.from = edge.to;
            edge.to = ildar;*/
        if (mas[end].cap >= mas[end].cnt + 2) // если влезает
        {
            mas[end].arr[mas[end].cnt].from = end;    //
            mas[end].arr[mas[end].cnt].to = start;
            mas[end].arr[mas[end].cnt++].weight = edge.weight;  
        } else // иначе добавляем память
        {
            mas[end].cap *= 2;
            mas[end].arr = realloc(mas[end].arr, mas[end].cap * sizeof(Edge));
            mas[end].arr[mas[end].cnt].from = end;    //
            mas[end].arr[mas[end].cnt].to = start;
            mas[end].arr[mas[end].cnt++].weight = edge.weight; 
        }
    }
}

//returns number of edges indicent to vertex iVertex
int getEdgesCount(int iVertex)
{
    return mas[iVertex].cnt;
}
//returns iIndex-th edge incident to the vertex iVertex
//it must have .from == Vertex and .to denoting the other end
Edge getIncidentEdge(int iVertex, int iIndex)
{
    return mas[iVertex].arr[iIndex];
}
