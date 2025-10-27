#include "ndarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

size_t get_size(dtype_t dtype){
    switch(dtype){
        case DTYPE_FLOAT32: return sizeof(float);
        case DTYPE_FLOAT64: return sizeof(double);
        case DTYPE_INT32: return sizeof(int32_t);
        case DTYPE_INT64: return sizeof(int64_t);
    }
};

int* calculate_strides(int* shape, int ndim, size_t ele_size){
    int* stride_arr=(int*)malloc(ndim*sizeof(int));
    if(!stride_arr){
        return NULL;
    }
    stride_arr[ndim-1]=ele_size;
    for(int i=ndim-2; i>=0; i--){
        stride_arr[i]=shape[i+1]*stride_arr[i+1]  ;
    }
    return stride_arr;
}

ndarray* create_ndarray(int* shape, int ndim, dtype_t dtype){
    ndarray* arr=malloc(sizeof(ndarray));
    if(!arr) return NULL;

    arr->shape=malloc(ndim*sizeof(int));
    if(!arr->shape){
        free(arr);
        return NULL;
    }
    memcpy(arr->shape, shape, ndim*sizeof(int));
    arr->ndim=ndim;
    arr->size=1;
    for(int i=0; i<ndim; i++){
        arr->size*=shape[i];
    }

    size_t item_size=get_size(dtype);
    arr->stride=calculate_strides(shape, ndim, item_size);
    arr->data=calloc(arr->size, item_size);
    
    if(!arr->data || !arr->stride){
        free(arr->shape);
        if(arr->stride) free(arr->stride);
        free(arr);
        return NULL;
    }
    return arr;
}

void free_ndarray(ndarray* arr) {
    if (!arr) return;
    free(arr->data);
    free(arr->shape);
    free(arr->stride);
    free(arr);
}