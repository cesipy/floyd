#include "../include/floyd.h"

void floyd_algorithm(int** a, size_t sz) 
{
    int** copied_matrix = allocate_matrix(sz);    // TODO: error handling when allocation fails

    copy_matrix(a, copied_matrix, sz);
    print_matrix(sz, copied_matrix);

    for (int r=0; r<sz; r++)
    {
        for (int i=0; i<sz; i++) 
        {
            for (int j=0; j<sz; j++) 
            {
                int shorter_path_exists = !(a[i][r] == INF ||  a[r][j] == INF) &&  a[i][j] > a[i][r] + a[r][j];
                if (shorter_path_exists)
                {
                    copied_matrix[i][j] = a[i][r] + a[r][j];
                }
            }
        }
        copy_matrix(copied_matrix, a, sz);
    }

    print_matrix(sz, a);
    free_matrix(copied_matrix, sz);
}


void print_matrix(size_t sz, int** a)
{
    for (int i=0; i<sz; i++) 
    {
        for (int j=0; j<sz; j++) 
        {
            int is_infinity = a[i][j] == INF;
            if (is_infinity)
            {
                printf("%*s", PADDING+1, "inf");
            }
            else
            {
                printf("%*d ", PADDING,  a[i][j]);
            }  
        }
        printf("\n");    
    }
    printf("\n");
}


void copy_matrix(int** source, int** target, size_t sz)
{
    for (int i=0; i<sz; i++)
    {
        for (int j=0; j<sz; j++)
        {
            target[i][j] = source[i][j];
        }
    }
}


int** allocate_matrix(size_t sz) 
{
    int** a = (int**)malloc(sz * sizeof(int*));
    if (a == NULL) 
    {
        perror("allocating matrix");
        return NULL;
    }

    for (int i=0; i<sz; i++) 
    {
        a[i] = (int*)malloc(sz * sizeof(int));
        if (a[i] == NULL) 
        {
            perror("allocationg matrix");
            return NULL;
        }   
    }
    return a;
}


void free_matrix(int** a, size_t sz) 
{
    for (int i=0; i<sz; i++)
    {
        free(a[i]);
    }

    free(a);
}

