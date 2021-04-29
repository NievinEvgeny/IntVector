#pragma once
#include <stdio.h>

typedef struct
{
	int *data;
	size_t size;
	size_t capacity;
} IntVector;

IntVector *int_vector_new(size_t init_capacity);

IntVector *int_vector_copy(const IntVector *v);

size_t int_vector_get_capacity(const IntVector *v);

size_t int_vector_get_size(const IntVector *v);

int int_vector_push_back(IntVector *v, int item);

int int_vector_shrink_to_fit(IntVector *v);

int int_vector_resize(IntVector *v, size_t new_size);

int int_vector_reserve(IntVector *v, size_t new_capacity);

int int_vector_get_item(const IntVector *v, size_t index);

void menu_sorting();

void int_vector_set_item(IntVector *v, size_t index, int item);

void int_vector_free(IntVector *v);

void int_vector_pop_back(IntVector *v);

void int_vector_interface(IntVector *v);