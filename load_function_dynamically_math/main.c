/******************************************************************************
 * INCLUDES
******************************************************************************/
#include <stdio.h>
#include <stdint.h>
/******************************************************************************
 * TYPEDEFS
******************************************************************************/
/*Function pointer type for the comparison function*/
typedef uint16_t (*Math_Function)(uint8_t, uint8_t);

typedef enum {
    ADD             = 0,
    SUB             = 1,
    MUL             = 2,
    DIV             = 3,
    MOD             = 4
} math_fuction_t;
/******************************************************************************
 * PROTOTYPES
******************************************************************************/
uint16_t add(uint8_t a, uint8_t b);
uint16_t sub(uint8_t a, uint8_t b);
uint16_t mul(uint8_t a, uint8_t b);
uint16_t div(uint8_t a, uint8_t b);
uint16_t mod(uint8_t a, uint8_t b);
/******************************************************************************
 * VARIABLES
******************************************************************************/
Math_Function math_func[] = {add, sub, mul, div, mod};
/******************************************************************************
 * CODES
******************************************************************************/

void main() {
    uint8_t a = 5;
    uint8_t b = 2;

    printf("%d + %d = %d\n",a, b, math_func[ADD](a, b));

    printf("%d - %d = %d\n",a, b, math_func[SUB](a, b));

    printf("%d * %d = %d\n",a, b, math_func[MUL](a, b));

    printf("%d div %d = %d\n",a, b, math_func[DIV](a, b));

    printf("%d mod %d = %d\n",a, b, math_func[MOD](a, b));


}

uint16_t add(uint8_t a, uint8_t b){
    return a + b;
}

uint16_t sub(uint8_t a, uint8_t b) {
    return a - b;
}

uint16_t mul(uint8_t a, uint8_t b) {
    return a * b;
}

uint16_t div(uint8_t a, uint8_t b) {
    return a / b;
}

uint16_t mod(uint8_t a, uint8_t b) {
    return a % b;
}

/******************************************************************************
 * END OF FILE
******************************************************************************/