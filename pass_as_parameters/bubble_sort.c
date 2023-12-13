/******************************************************************************
 * INCLUDES
******************************************************************************/
#include <stdio.h>
#include <stdint.h>
/******************************************************************************
 * TYPEDEFS
******************************************************************************/
/*Function pointer type for the comparison function*/
typedef uint8_t (*Compare_Function)(uint8_t, uint8_t);
/******************************************************************************
 * PROTOTYPES
******************************************************************************/
void swap(uint8_t *a, uint8_t *b);

void bubbleSort(Compare_Function compare);

uint8_t compareAsc(uint8_t a, uint8_t b) {
    return a > b;
}

uint8_t compareDesc(uint8_t a, uint8_t b) {
    return b > a;
}

void printArray(void);
/******************************************************************************
 * VARIABLES
******************************************************************************/
uint8_t arr[] = {64, 34, 25, 12, 22, 11, 90};
uint8_t size = sizeof(arr) / sizeof(arr[0]);
/******************************************************************************
 * CODES
******************************************************************************/
uint8_t main() {
    printf("Original array: ");
    printArray();

    // Sort in ascending order
    bubbleSort(compareAsc);
    printf("Array in ascending order: ");
    printArray();

    // Sort in descending order
    bubbleSort(compareDesc);
    printf("Array in descending order: ");
    printArray();

    return 0;
}

void swap(uint8_t *a, uint8_t *b) {
    uint8_t temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Compare_Function compare) {
    uint8_t i, j;
    for (i = 0; i < size - 1; ++i) {
        for (j = i + 1; j < size; ++j) {
            if (compare(arr[i], arr[j])) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void printArray(void) {
    uint8_t i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}