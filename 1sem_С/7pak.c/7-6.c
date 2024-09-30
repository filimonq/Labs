#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct item {
	int value;
	struct item * next;
} list;

int iosif(int n,int k)
{
	list * head, * p, * t;
	head = (list*) malloc(sizeof(list));
	head -> value = 1;
	t = head;
	for (int i = 2;i <= n;i++) {
		p = (list*) malloc(sizeof(list));
		p -> value = i;
		t -> next = p;
		t = p;
	}
	t -> next = head;
	while (head -> next != head) 
	{
		for (int i = 1; i < k - 1; i++) 
		{
			head = head -> next;
		}
		p = head -> next;
		head -> next = p -> next;
		head = head -> next;
		printf("%d\n", p -> value);
		free(p);
	}
	return head -> value;
}

int main()
{
    int N, k;
    scanf("%d %d", &N, &k);
    int ans;
    ans = iosif(N, k);
    printf("%d\n", ans);
    return 0;
}

