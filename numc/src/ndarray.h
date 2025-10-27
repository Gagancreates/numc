#ifndef NDARRAY_H
#define NDARRAY_H
#include <stddef.h>
#include <stdbool.h>

typedef enum{
    DTYPE_FLOAT32,
    DTYPE_FLOAT64,
    DTYPE_INT32,
    DTYPE_INT64
} dtype_t;

typedef struct{
    void* data;
    int* shape;
    int* stride;
    int ndim;
    size_t size;
    dtype_t dtype;
    bool owns_data;
} ndarray;

ndarray* create_ndarray(int* shape, int ndim, size_t size);
void* free_ndarray(ndarray* arr);
void* ndarray_getptr(ndarray* arr, int* indices);

#endif