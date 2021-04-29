#include "IntVector.h"
#include <string.h>
#include <stdlib.h>

IntVector *int_vector_new(size_t init_capacity)
{
	IntVector *v = (IntVector *)malloc(sizeof(IntVector));
	if (v == NULL)
	{
		return NULL;
	}
	v->data = calloc(init_capacity, sizeof(size_t));
	if (v->data != NULL)
	{
		v->size = 0;
		v->capacity = init_capacity;
		return v;
	}
	int_vector_free(v);
	return NULL;
}

IntVector *int_vector_copy(const IntVector *v)
{
	IntVector *v_copy = malloc(sizeof(IntVector));
	if (v_copy == NULL)
	{
		return NULL;
	}
	v_copy->data = malloc(v->capacity * sizeof(size_t));
	if (v_copy->data != NULL)
	{
		memcpy(v_copy->data, v->data, v->capacity * sizeof(size_t));
		v_copy->size = int_vector_get_size(v);
		v_copy->capacity = int_vector_get_capacity(v);
		return v_copy;
	}
	int_vector_free(v_copy);
	return NULL;
}

void int_vector_free(IntVector *v)
{
	free(v->data);
	free(v);
}

size_t int_vector_get_capacity(const IntVector *v)
{
	return v->capacity;
}

size_t int_vector_get_size(const IntVector *v)
{
	return v->size;
}

int int_vector_push_back(IntVector *v, int item)
{
	if (v->size == 0)
	{
		int_vector_reserve(v, 1);
		v->data[v->size] = item;
		v->size++;
		return 0;
	}
	if (v->size >= v->capacity)
	{
		if (int_vector_reserve(v, int_vector_get_capacity(v) * 2) != -1)
		{
			v->data[v->size] = item;
			v->size++;
			return 0;
		}
		else
		{
			printf("\nОшибка: не удалось выделить память для добавления элемента\n");
			return -1;
		}
	}
	v->data[v->size] = item;
	v->size++;
	return 0;
}

void int_vector_pop_back(IntVector *v)
{
	if ((v->size != 0))
	{
		v->data[v->size - 1] = 0;
		v->size--;
	}
	else
	{
		printf("\nОшибка: массив пустой\n");
	}
}

int int_vector_get_item(const IntVector *v, size_t index)
{
	if ((index > v->size - 1) || (index < 0))
	{
		printf("\nОшибка: элемент с таким индексом не существует\n");
		return -1;
	}
	return v->data[index];
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{
	if ((index > v->size - 1) || (index < 0))
	{
		printf("\nОшибка: элемент с таким индексом не существует\n");
		return;
	}
	v->data[index] = item;
}

int int_vector_shrink_to_fit(IntVector *v)
{
	if (v->size == v->capacity)
	{
		return 0;
	}
	if (v->size == 0)
	{
		v->capacity = v->size;
		return 0;
	}
	v->data = realloc(v->data, v->size * sizeof(int));
	if (v->data != NULL)
	{
		v->capacity = v->size;
		return 0;
	}
	int_vector_free(v);
	return -1;
}

int int_vector_resize(IntVector *v, size_t new_size)
{
	int *arr = &v->data[v->size];
	size_t difsize = new_size - v->size;
	if (new_size >= (v->size))
	{
		int i = 0;
		while (v->capacity < new_size)
		{
			if (int_vector_reserve(v, int_vector_get_capacity(v) * 2) == -1)
			{
				printf("Ошибка: не удалось изменить размер массива");
				return -1;
			}
		}
		memset(arr, '\0', difsize * sizeof(int));
		v->size = new_size;
		return 0;
	}
	if (new_size < v->size)
	{
		v->size = new_size;
		return 0;
	}
	return -1;
}

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
	if (new_capacity <= int_vector_get_capacity(v))
	{
		return -1;
	}
	v->data = realloc(v->data, new_capacity * sizeof(int));
	if (v->data != NULL)
	{
		v->capacity = new_capacity;
		return 0;
	}
	int_vector_free(v);
	return -1;
}

void int_vector_interface(IntVector *v)
{
	printf("\n");
	int top_side = 0;
	printf("+");
	while (top_side < int_vector_get_capacity(v))
	{
		printf("---+");
		++top_side;
	}
	printf("\n");
	int element_setter = 0;
	int current_element = 0;
	while (element_setter < int_vector_get_size(v))
	{
		printf("|%3d", int_vector_get_item(v, current_element));
		++element_setter;
		++current_element;
	}
	int free_block_setter = 0;
	int diff = int_vector_get_capacity(v) - int_vector_get_size(v);
	while (free_block_setter < diff)
	{
		printf("|   ");
		++free_block_setter;
	}
	printf("|\n");
	int bottom_side = 0;
	printf("+");
	while (bottom_side < int_vector_get_capacity(v))
	{
		printf("---+");
		++bottom_side;
	}
	printf("\n\n");
	printf("Ёмкость вектора: %zu\n", int_vector_get_capacity(v));
	printf("Размер вектора: %zu\n", int_vector_get_size(v));
}

void menu_sorting()
{
	printf("Опции: \n");
	printf("\t1 - Добавить элемент\n");
	printf("\t2 - Изменить элемент\n");
	printf("\t3 - Удалить последний элемент\n");
	printf("\t4 - Изменить ёмкость\n");
	printf("\t5 - Изменить размер\n");
	printf("\t6 - Скопировать вектор\n");
	printf("\t7 - Обрезать вектор до его текущего размера\n");
	printf("\t8 - Выход\n");
}