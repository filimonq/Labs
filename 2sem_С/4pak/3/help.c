#include "sol.h"
#include <stdio.h>
#include <stdlib.h>

int flag = 1;
int index = 0;
int count;
Edge* arr = NULL;

int getVerticesCount(){
    if (flag){
        int help;
        scanf("%d", &count);
        scanf("%d", &help);
        flag = 0;
        arr = malloc(sizeof(Edge)*help);
        for (int i = 0; i<help; i++){
            scanf("%d %d %d", &arr[i].from, &arr[i].to, &arr[i].weight);
        }
    }
    return count;
}

int readEdge(Edge *oEdge){
    if (index<count){
        oEdge->from = arr[index].from;
        oEdge->to = arr[index].to;
        oEdge->weight = arr[index].weight;
        index++;
        return 1;
    }
    return 0;
}