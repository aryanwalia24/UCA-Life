#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void **elements;  // Pointer to the elements in the list
    size_t size;      // Current size (number of elements)
    size_t capacity;  // Current capacity (allocated space)
} List;

void initList(List *list) {
    list->elements = NULL;
    list->size = 0;
    list->capacity = 0;
}

void addElement(List *list, void *element) {
    if (list->size >= list->capacity) {
        size_t new_capacity = (list->capacity == 0) ? 1 : 2 * list->capacity;
        list->elements = realloc(list->elements, new_capacity * sizeof(void *));
        list->capacity = new_capacity;
    }
    list->elements[list->size++] = element;
}

void printInt(void *ptr) {
    printf("%d ", *(int *)ptr);
}

void printString(void *ptr) {
    printf("%s ", *(char **)ptr);
}

void printList(List *list, void (*printFunc)(void *)) {
    for (size_t i = 0; i < list->size; ++i) {
        printFunc(list->elements[i]);
    }
    printf("\n");
}

int compareInt(const void *a, const void *b) {
    int intA = **(int **)a;
    int intB = **(int **)b;
    return intA - intB;
}

int compareString(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void sortList(List *list, int (*compareFunc)(const void *, const void *)) {
    qsort(list->elements, list->size, sizeof(void *), compareFunc);
}

int main() {
    List intList;
    initList(&intList);

    int a = 3, b = 1, c = 4, d = 1, e = 5;
    addElement(&intList, &a);
    addElement(&intList, &b);
    addElement(&intList, &c);
    addElement(&intList, &d);
    addElement(&intList, &e);

    printf("Original list of integers: ");
    printList(&intList, printInt);

    sortList(&intList, compareInt);
    printf("Sorted list of integers: ");
    printList(&intList, printInt);

    List stringList;
    initList(&stringList);

    char *str1 = "banana", *str2 = "apple", *str3 = "orange", *str4 = "pear";
    addElement(&stringList, &str1);
    addElement(&stringList, &str2);
    addElement(&stringList, &str3);
    addElement(&stringList, &str4);

    printf("Original list of strings: ");
    printList(&stringList, printString);

    sortList(&stringList, compareString);
    printf("Sorted list of strings: ");
    printList(&stringList, printString);

    return 0;
}

