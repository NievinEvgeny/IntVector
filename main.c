#include "IntVector.h"

int main()
{
    int option;
    int capacity, item;
    int change_number, new_value;
    int new_capacity, new_size;
    int quit = 1;
    printf("\n");
    printf("Введите ёмкость вектора: ");
    if (scanf("%d", &capacity) != 1)
    {
        printf("Ёмкость вектора должна быть числом\n");
        return -1;
    }
    if (capacity < 0)
    {
        printf("Ёмкость вектора не может быть отрицательной\n");
        return -1;
    }
    IntVector *v = int_vector_new(capacity);
    if (v == NULL)
    {
        printf("Не удалось создать массив");
        return -1;
    }
    int_vector_interface(v);
    printf("\n");
    menu_sorting();
    scanf("%d", &option);
    while (quit != 0)
    {
        switch (option)
        {
        case 1:
            // Добавление элемента
            printf("Введите элемент: ");
            scanf("%d", &item);
            int_vector_push_back(v, item);
            int_vector_interface(v);
            menu_sorting(option);
            scanf("%d", &option);
            break;
        case 2:
            // Изменение элемента
            printf("Введите номер элемента: ");
            scanf("%d", &change_number);
            printf("Введите новое значение: ");
            scanf("%d", &new_value);
            int_vector_set_item(v, change_number, new_value);
            int_vector_interface(v);
            menu_sorting(option);
            scanf("%d", &option);
            break;
        case 3:
            // Удаление последнего элемента
            int_vector_pop_back(v);
            int_vector_interface(v);
            menu_sorting(option);
            scanf("%d", &option);
            break;
        case 4:
            // Изменение ёмкости
            printf("Введите новую ёмкость: ");
            scanf("%d", &new_capacity);
            int_vector_reserve(v, new_capacity);
            int_vector_interface(v);
            menu_sorting(option);
            scanf("%d", &option);
            break;
        case 5:
            // Изменение размера
            printf("Введите новый размер: ");
            scanf("%d", &new_size);
            int_vector_resize(v, new_size);
            int_vector_interface(v);
            menu_sorting(option);
            scanf("%d", &option);
            break;
        case 6:
            // Копирование вектора
            printf("Текущий вектор: \n");
            int_vector_interface(v);
            printf("\n");
            printf("Скопированный вектор: \n");
            IntVector *vector_copy = int_vector_copy(v);
            if (v == NULL)
            {
                printf("Не удалось создать массив");
                break;
            }
            int_vector_interface(vector_copy);
            menu_sorting(option);
            scanf("%d", &option);
            break;
        case 7:
            // Обрезание вектора до его текущего размера
            int_vector_shrink_to_fit(v);
            int_vector_interface(v);
            menu_sorting(option);
            scanf("%d", &option);
            break;
        case 8:
            // Выход
            quit = 0;
            break;
        default:
            printf("Неверный аргумент: введите число от 1 до 8\n\n");
            menu_sorting(option);
            scanf("%d", &option);
            break;
            int_vector_free(vector_copy);
        }
    }
    int_vector_free(v);
    return 0;
}