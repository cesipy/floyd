#ifndef FLOYD_H
#define FLOYD_H

#include <stdio.h>
#include <stdlib.h>

#define INF 2147483647
#define PADDING 7

/**
 * computes shortest path for squared matrix `a`. 
 * is used to calculate the shortest path from each node to every other node in a directed graph. 
 * O(n^3)
*/
void floyd_algorithm(int** a, size_t sz);

/**
 * initializes matrix `a` for floyd algorithm. sets unreachable nodes to `INF` 
 * and distance from every node to itself to 0.
*/
void init_step_floyd(int** a, size_t sz);

/**
 * allocates squared matrix.
*/
int** allocate_matrix(size_t sz);


/**
 * copy entries for source matrix to target matrix.
*/
void copy_matrix(int** source, int** target, size_t sz);


/**
 * frees memory for allocated squared matrix.
*/
void free_matrix(int** a, size_t sz);


/**
 * prints matrix in stdout.
*/
void print_matrix(size_t sz, int** a);

#endif
