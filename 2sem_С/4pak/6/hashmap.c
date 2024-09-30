#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>


__attribute__((visibility("default"))) HashMap HM_Init(EqualFunc ef, HashFunc hf, int size) // инициализируем хэш-таблицу
{
    HashMap map;
    map.equalFunc = ef;
    map.hashFunc = hf;
    map.size = size;
    map.hashtable = (cell**)calloc(size, sizeof(cell*));
    return map;
}

__attribute__((visibility("default"))) void HM_Destroy(HashMap *self) // очищаем цепочку
{   
    cell *curr, *next;
    for (int i = 0; i < self->size; i++)
    {
        curr = self->hashtable[i];
        while (curr != NULL) // пробегаемся по всей цепочке
        {
            next = curr->next; 
            free(curr);
            curr = next; // передвигаем
        }
    }
    free(self->hashtable);
}

__attribute__((visibility("default"))) cpvoid HM_Get(const HashMap *self, cpvoid key) // получаем значение по ключу
{
    int index = self->hashFunc(key) % self->size; // индекс по ключу
    cell *curr = self->hashtable[index];
    while (curr != NULL) // пока цепочка не закончилась
    {  
        if (self->equalFunc(key, curr->key) == 1) // ключи совпали
        {
            return curr->value;
        }
        curr = curr->next; // двигаем дальше
    }
    return NULL;
}

__attribute__((visibility("default"))) void HM_Set(HashMap *self, cpvoid key, cpvoid value) // заполняем таблицу
{
    int index = self->hashFunc(key) % self->size; // индекс по ключу
    if (self->hashtable[index] == NULL) // цепочка пустая
    {
        self->hashtable[index] = malloc(sizeof(cell));
        self->hashtable[index]->key = key;
        self->hashtable[index]->value = value;
        self->hashtable[index]->next = NULL;
    } else
    {
        cell *curr = self->hashtable[index];
        while (curr->next != NULL) // пока цепочка не закончилась
        {
            if (self->equalFunc(key, curr->key) == 1) // ключи совпали
            {
                curr->value = value;
                return ;
            }
            curr = curr->next; // двигаем дальше
        }
        if (self->equalFunc(key, curr->key) == 1) // отдельно проверяем последний элемент
        {
            curr->value = value;
            return ;
        }
        cell *newcell = (cell*)malloc(sizeof(cell)); // если у нас не нашлось такого ключа, то мы создаем в конце цепочки новую ячейку
        newcell->key = key;
        newcell->value = value;
        newcell->next = NULL;
        curr->next = newcell;
    }
}