#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Element {
    struct Element *next;
    int flag;
    int value;
} Element;

uint32_t jenkins(const uint8_t *key, size_t len) 
{
    uint32_t hash = 0;
    for (size_t i = 0; i < len; i++) {
        hash += key[i];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash % 1000000;
}

int main() 
{
    FILE *f_in = fopen("input.bin", "rb");
    FILE *f_out = fopen("output.bin", "wb");
    int N, x;
    fread(&N, sizeof(int), 1, f_in);
    Element *arr = (Element *) calloc(sizeof(Element), 1000000);
    Element *ans = (Element *) calloc(sizeof(Element), 1);
    Element *last = ans;
    uint32_t hash = 0;
    int count = 0;
    int duplicate = 0;

    for (int i = 0; i < N; i++) {
        fread(&x, sizeof(int), 1, f_in);
        hash = jenkins((uint8_t *) &x, sizeof(x));
        if (arr[hash].flag == 0) 
        {
            arr[hash].value = x;
            arr[hash].flag = 1;
            last -> next = (Element *) calloc(sizeof(Element), 1);
            last = last -> next;
            last-> value = x;
            count++;
            //fwrite(&count, sizeof(int), 1, f_out);
        } else 
        {
            duplicate = 0;
            Element *p = &arr[hash];
            if (arr[hash].value == x) 
            {
                duplicate = 1;
            }
            Element *temp = p;
            for (; p != NULL; p = p -> next) // идем до последнего указателя
            {
                if (p -> value == x) {
                    duplicate = 1; // удаляем дубликаты
                    break;
                }
                temp = p;
            }
            p = temp;
            if (duplicate == 0) 
            {
                Element *mas = (Element *) calloc(sizeof(Element), 1); // добавляем новый элемент в список
                mas -> value = x;
                p -> next = malloc(sizeof(Element));
                p -> next = mas;
                last -> next = (Element *) calloc(sizeof(Element), 1);
                last = last -> next;
                last -> value = x;
                count++;
            }
        }
    }

    fwrite(&count, sizeof(int), 1, f_out);
    last = ans -> next;
    for (int i = 0; i < count; i++) 
    {
        fwrite(&last -> value, sizeof(int), 1, f_out);
        last = last -> next;
    }
    free(arr);
    free(last);
    fclose(f_in);
    fclose(f_out);
    return 0;
}
