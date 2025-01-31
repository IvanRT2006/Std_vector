#include "std_vector.h"

Vector CreateVtor (size_t initial_capacity, size_t element_size)
{
    Vector vector;
    vector.size = 0;
    vector.capacity = initial_capacity;
    vector.element_size = element_size;
    vector.data = malloc(element_size*initial_capacity);
    if (vector.data == NULL)
    {
        fprintf(stderr, "Allocation error\n");
    }
    return vector;
}

bool VectorPush (Vector *vector, const void* value)
{
    if (vector->size == vector->capacity)
    {
        size_t new_capacity = vector->capacity == 0? 1: vector->capacity*2;
        void *new_data = realloc(vector->data, vector->element_size*new_capacity);
        if (new_data == NULL)
        {
            fprintf(stderr, "Reallocation error\n");
            return false;
        }
    vector->data = new_data;
    vector->capacity = new_capacity;
    }

    memcpy((char*)vector->data + vector->size * vector->element_size, value, vector->element_size);
    vector->size++;

    return true;
}

void* VectorGet (const Vector *vector, size_t index)
{
    if (index >= vector->size)
    {
        fprintf(stderr, "Index out of bounds\n");
    }
    return (char*)vector->data + index * vector->element_size;
}

bool VectorSet (Vector *vector, size_t index, const void* value)
{
    if (index >= vector->size)
    {
        fprintf(stderr, "Index out of bounds\n");
        return false;
    }
    memcpy((char*)vector->data + index * vector->element_size, value, vector->element_size);
    return true;
}

size_t VectorSize (const Vector *vector)
{
    return vector->size;
}

size_t VectorCapacity (const Vector *vector)
{
    return vector->capacity;
}

bool VectorPop(Vector* vector)
{
    if(vector->size == 0)
    {
        fprintf(stderr, "Vector is empty\n");
        return false;
    }

    vector->size--;
    return true;
}

bool VectorInsert (Vector* vector, size_t index, const void *value)
{
    if (index > vector->size)
    {
        fprintf(stderr, "Index out of bounds\n");
        return false;
    }
    if (vector->size == vector->capacity)
    {
        size_t new_capacity = vector->capacity == 0 ? 1 : vector->capacity * 2;
        void* new_data = realloc(vector->data, vector->element_size * new_capacity);
        if (new_data == NULL)
        {
           fprintf(stderr, "Reallocation error\n");
           return false;
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    for (size_t i = vector->size; i > index; --i)
    {
        memcpy((char*)vector->data + i * vector->element_size, (char*)vector->data + (i - 1) * vector->element_size, vector->element_size);
    }

    memcpy((char*)vector->data + index * vector->element_size, value, vector->element_size);
    vector->size++;

    return true;
}


bool VectorErase (Vector* vector, size_t index)
{
    if (index >= vector->size)
    {
        fprintf(stderr, "Index out of bounds\n");
        return false;
    }
    for (size_t i = index; i < vector->size - 1; ++i)
    {
        memcpy((char*)vector->data + i * vector->element_size, (char*)vector->data + (i + 1) * vector->element_size, vector->element_size);
    }

    vector->size--;
    return true;
}

void VectorClear(Vector* vector)
{
    vector->size = 0;
}

void VectorDestroy(Vector* vector)
{
    free(vector->data);
    vector->size = 0;
    vector->capacity = 0;
    vector->element_size = 0;
}

void RunTests()
{
    Vector int_vec = CreateVtor(2, sizeof(int));
    int num1 = 10, num2 = 20, num3 = 30, num4 = 100;

    assert(VectorPush(&int_vec, &num1) && "Fail push 1");
    assert(VectorPush(&int_vec, &num2) && "Fail push 2");
    assert(VectorPush(&int_vec, &num3) && "Fail push 3");
    assert(VectorInsert(&int_vec, 1, &num4) && "Fail insert 1");
    assert(VectorSize(&int_vec) == 4 && "Fail check 4 push size");
    assert(VectorCapacity(&int_vec) == 4 && "Fail check 4 push capacity");

    int num5 = 5;

    assert(VectorSet(&int_vec, 0, &num5) && "Fail set 1");
    assert(VectorErase(&int_vec, 2) && "Fail erase 1");
    assert(VectorSize(&int_vec) == 3 && "Fail check 4 push size");
    assert(VectorPop(&int_vec) && "Fail pop 1");
    assert(VectorSize(&int_vec) == 2 && "Fail pop 2");

    VectorDestroy(&int_vec);

    Vector str_vec = CreateVtor(2, sizeof(char*));

    char* str1 = "hello";
    char* str2 = "world";
    char* str3 = "again";
    char* str4 = "!!!";

    assert(VectorPush(&str_vec, &str1) && "Fail push string 1");
    assert(VectorPush(&str_vec, &str2) && "Fail push string 2");
    assert(VectorPush(&str_vec, &str3) && "Fail push string 3");
    assert(VectorInsert(&str_vec, 1, &str4) && "Fail insert string 1");

    char* str5 = "new value";

    assert(VectorSet(&str_vec, 0, &str5) && "Fail set string 1");
    assert(VectorErase(&str_vec, 2) && "Fail erase string 1");
    assert(VectorPop(&str_vec) && "Fail pop string 1");

    VectorDestroy(&str_vec);
}


