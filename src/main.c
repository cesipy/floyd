#include "../include/floyd.h"

int main(int argc, char* argv[]) 
{
    size_t sz = 4;

    int** a = allocate_matrix(sz);
    int values[4][4] = {        // for some reason sz does not work - type mismatch
        {0, INF, -2, INF},
        {4, 0, 3, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0}
    };

    // insert values into a
    for (int i=0; i<sz; i++)
    {
        for (int j=0; j<sz; j++) {
            a[i][j] = values[i][j];
        }
    }

    floyd_algorithm(a, sz);

    free_matrix(a, sz);
} 