#include "../include/floyd.h"

void showcase(size_t sz)
{
    int** a = allocate_matrix(sz);
    int values1[4][4] = {        // for some reason sz does not work - type mismatch
        {0, INF, INF, INF},
        {3, 0, INF, 2},
        {5, 1, 0, INF},
        {INF, INF, 3, 0}
    };

    // insert values into a
    for (int i=0; i<sz; i++)
    {
        for (int j=0; j<sz; j++) {
            a[i][j] = values1[i][j];
        }
    }

    floyd_algorithm(a, sz);

    // test initialization step
    int values2[4][4] = {        // for some reason sz does not work - type mismatch
        {0, 0, 0,},
        {3, 1, 0, 2},
        {5, 1, 0, 0},
        {0, 0, 3, 8}
    };

    // insert values into a
    for (int i=0; i<sz; i++)
    {
        for (int j=0; j<sz; j++) {
            a[i][j] = values2[i][j];
        }
    }

    floyd_algorithm(a, sz);
    free_matrix(a, sz);
}


int main(int argc, char* argv[]) 
{
    size_t sz = 4;
    showcase(sz);
} 