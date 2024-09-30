#include <stdio.h>
#include <stdlib.h>

void shuffle(int* arr, int size){
    for (int i = 0; i < size; i++) {
        int pos = rand() % (i + 1);
        int temporary = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temporary;
    }
}

typedef struct Node {
    int value;
    int counter;
    struct Node *l, *r;
} Node;

void binary_sort(Node* root, int *arr, int *key)
{
    if (root -> l != NULL)
    {
        binary_sort(root -> l, arr, key); // спускаемся вниз
    }
    for (int i = 0; i < root -> counter; i++)
    {
        arr[*key] = root -> value; // проверяем центральный
        *key = *key + 1;
    }
    if (root -> r != NULL)
    {
        binary_sort(root -> r, arr, key);
    }
}

Node* create_binary_tree(int *arr, int N)
{
    Node* root = malloc(sizeof(Node));
    root -> value = arr[0];
    root -> counter = 1;
    root -> l = NULL;
    root -> r = NULL;

    for (int i = 1; i < N; i++)
    {
        Node* curr = root;
        while (1)
        {
            if (arr[i] < curr -> value)
            {
                if (curr -> l == NULL) // если пустой то добавляем элемент в дерево
                {
                    curr -> l = malloc(sizeof(Node));
                    curr -> l -> value = arr[i];
                    curr -> l -> l = NULL;
                    curr -> l -> r = NULL;
                    curr -> l -> counter = 1;
                    break;
                } else 
                {
                    curr = curr -> l;
                }
            } else if (arr[i] > curr -> value)
            {
                if (curr -> r == NULL)
                {
                    curr -> r = malloc(sizeof(Node));
                    curr -> r -> value = arr[i];
                    curr -> r -> l = NULL;
                    curr -> r -> r = NULL;
                    curr -> r -> counter = 1;
                    break;
                } else
                {
                    curr = curr -> r;
                }
            } else 
            {
                curr -> counter++;
                break;
            }
        }
    }
    return root;
}

int main()
{
    FILE *f_in = fopen("input.bin", "rb");
    FILE *f_out = fopen("output.bin", "wb");
    int N;
    fread(&N, sizeof(int), 1, f_in);
    int arr[500001];
    fread(arr, sizeof(int), N, f_in);
    shuffle(arr, N);
    // fwrite(&arr, sizeof(int), N, f_out);
    Node* root = create_binary_tree(arr, N);
    int key = 0;
    binary_sort(root, arr, &key);
    fwrite(&arr, sizeof(int), N, f_out);
    fclose(f_in);
    fclose(f_out);
    return 0;
}
