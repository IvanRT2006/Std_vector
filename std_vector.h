#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t element_size;
} Vector;

Vector CreateVtor (size_t initial_capacity, size_t element_size);
bool VectorPush (Vector *vector, const void* value);
void* VectorGet (const Vector *vector, size_t index);
bool VectorSet (Vector *vector, size_t index, const void* value);
size_t VectorSize (const Vector *vector);
size_t VectorCapacity (const Vector *vector);
bool VectorPop(Vector* vector);
bool VectorInsert (Vector* vector, size_t index, const void *value);
bool VectorErase (Vector* vector, size_t index);
void VectorClear(Vector* vector);
void VectorDestroy(Vector* vector);
void RunTests();
