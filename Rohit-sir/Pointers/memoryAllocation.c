#include <stdio.h>
#include <stdlib.h>

void *calloc_using_malloc(int n)
{
	char *arr = (char *)malloc(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = '\0';
	}
	return (void *)arr;
}

int main()
{
	int n;
	scanf("%d", &n);

	int *temp = calloc_using_malloc(n);

	// malloc
	int *arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}

	// calloc
	int *arr_calloc = (int *)calloc(n, sizeof(int));
	if (arr_calloc == NULL)
	{
		printf("Memory allocation failed\n");
		free(arr);
		return 1;
	}

	// realloc
	int *arr_realloc = (int *)realloc(arr, 2 * n * sizeof(int));
	if (arr_realloc == NULL)
	{
		printf("Memory reallocation failed\n");
		free(arr);
		free(arr_calloc);
		return 1;
	}

	free(arr);
	free(arr_calloc);
	free(arr_realloc);

	return 0;
}

/*
Malloc :
	* Allocates memory for an array of elements.
	* Syntax : int *arr = (int *)malloc(size_req * sizeof(int));  // sizeof() coz of diff compilers
	* Parameters:
		size: Size of the memory block in bytes.
	`malloc` function allocates `size` bytes of memory and returns a pointer to the first byte of the memory block.
	`malloc` does not initialize the memory block. The content of the newly allocated memory is not initialized, remaining with indeterminate values.
	`malloc` returns a null pointer if the memory allocation fails.

Calloc :
	* Allocates memory for an array of elements and initializes all the bytes to zero.
	* Syntax : (void *) calloc(size_t num, size_t size);
	* Parameters:
		num: Number of elements to allocate.
		size: Size of each element.

Realloc :
	* Reallocates memory for an array, preserving its contents.
	* Syntax : (void *) realloc(void *ptr, size_t size);
	* Parameters:
		ptr: A pointer to the previously allocated memory block.
		size: The new size of the memory block in bytes.
	The `realloc` function changes the size of the memory block pointed to by `ptr` to `size` bytes.

Free :
	* Deallocates memory previously allocated by a call to calloc, malloc, or realloc.
	* Syntax : free(ptr);
	* Parameters:
		ptr: A pointer to the memory block to deallocate.
 */
