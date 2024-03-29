#include "../include/floyd.h"

void floyd_algorithm(int** a, size_t sz)    // TODO: return matrix, don't change matrix a.
{
    init_step_floyd(a, sz);
    int** copied_matrix = allocate_matrix(sz);    // TODO: error handling when allocation fails
    copy_matrix(a, copied_matrix, sz);

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

        // copy the changes for current r back to matrix a
        copy_matrix(copied_matrix, a, sz);  
        printf("r = %d\n", r);
        print_matrix(sz, a);
    }

    print_matrix(sz, a);
    free_matrix(copied_matrix, sz);
}


void init_step_floyd(int** a, size_t sz)
{
    for (int i=0; i<sz; i++)
    {
        for (int j=0; j<sz; j++)
        {
            if (a[i][j] == 0)
            {
                a[i][j] = INF;  // node is not reachable, set distance to infinity (defined as INF)
            }

            if (i == j) 
            {
                a[i][j] = 0;    //path to itself is always 0.
            }
        }
    }
}


void print_matrix(size_t sz, int** a)
{
    for (int i=0; i<sz; i++) 
    {
        for (int j=0; j<sz; j++) 
        {
            // more convenient output for INF macro
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

