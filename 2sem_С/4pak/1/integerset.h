#pragma once
typedef struct IntegerSet IntegerSet;

IntegerSet *CreateSet(int *arr, int size);

int IsInSet(IntegerSet *arr, int n);
// pragma once или #ifdef
