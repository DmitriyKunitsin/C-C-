#include "function.h"
int main() {

    __uint8_t byte1 = 0x0F;
    __uint8_t byte2 = 0xBB;
 printf("byte1 : %d\n", byte1);
    print_u_bit(byte1);
     printf("byte2 : %d\n", byte2);
    print_u_bit(byte2);
    short result = (byte1 << 8) | byte2;
    print_u_bit((byte1 << 8) | byte2);
    printf("\nresult : %d\n", result);
    print_u_bit(result);

printf("\n");
    __uint8_t answer1 = result >> 8;
    printf("answer1 : %d\n", answer1);
    print_u_bit(answer1);
    __uint8_t answer2 = result ;
     printf("answer2 : %d\n", answer2);
    print_u_bit(answer2);
    return 0;
}