#include <stdio.h>

#define MAX 100

int parent[MAX];

// MakeSet
void makeSet(int n) {
    printf("SET:");
    for(int i=1; i<=n; i++)
    {    parent[i] = i;
        printf("%d",i);
    }
}

// Find with path compression
int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union
void unionSets(int x, int y) {
    int px = find(x);
    int py = find(y);
    if(px != py)
        parent[px] = py;
}

int main() {
    int n = 5; // number of elements
    makeSet(n);

    unionSets(1, 2);
    unionSets(3, 4);
    unionSets(2, 4);

    for(int i=1; i<=n; i++)
        printf("Parent of %d = %d\n", i, find(i));

    return 0;
}

