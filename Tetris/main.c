#include <stdio.h>
#include <ncurses.h>


#define MAX_WIDTH_DISPLAY 11
#define MAX_HEIGHT_DISPLAY 21
#define START_RIGHT_MENU_WIDTH 11
#define END_RIGHT_MENU_WIDTH 21
#define Y_SIZE_ARRAY 21
#define X_SIZE_ARRAY 21
#define SIDE_LINE '*'
#define TOP_LINE '*'

typedef enum { // Конечный автома
    STATE_A,// Enum для того, что к енаму можно обращаться только к одному объекту
    STATE_B,
    STATE_C
} State;
void printArrayFieldBound(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]);
void printFieldBound();
void printARRFieldBound(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]);
State Transition(State current, char input);

int main() {
    State currentState = STATE_A;
    char inp[] = {'0', '1', '0', '1', '0'};

    for(size_t i = 0; i < sizeof(inp) / sizeof(inp[0]); i++) {
        currentState = Transition(currentState, inp[i]);
        printf("Input: %c, State: %d\n", inp[i], currentState);
    }
    int arr[Y_SIZE_ARRAY][X_SIZE_ARRAY];
    printARRFieldBound(arr);
    // printFieldBound();

    printArrayFieldBound(arr);
    return 0;
}

void printArrayFieldBound(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]) {
    for(int i = 0; i < Y_SIZE_ARRAY; i++){
        for(int j = 0; j < X_SIZE_ARRAY; j++) {
            printf("%d",array[i][j]);
        }
        printf("\n");
    }
}

void printFieldBound() {
    for(int i = 0; i < MAX_HEIGHT_DISPLAY; i++) {
        for(int j = 0; j < MAX_WIDTH_DISPLAY; j++) {
            printf("%c", (i == 0 || i == MAX_HEIGHT_DISPLAY - 1) ? (j != 0 && j != MAX_WIDTH_DISPLAY - 1 ? TOP_LINE : ' ') : ' ');
            printf("%c", (j == 0 || j == MAX_WIDTH_DISPLAY - 1) ? (i != 0 && i != MAX_HEIGHT_DISPLAY - 1 ? SIDE_LINE : (j == MAX_WIDTH_DISPLAY - 1 && (i == 0 || i == MAX_HEIGHT_DISPLAY - 1) ? SIDE_LINE : ' ')) : ' ');
        }
        printf("\n");
    }
}
void printARRFieldBound(int array[Y_SIZE_ARRAY][X_SIZE_ARRAY]) {
    for(int i = 0; i < Y_SIZE_ARRAY; i++) {
        for(int j = 0; j < X_SIZE_ARRAY; j++) {
            if((i == 0 || i == MAX_HEIGHT_DISPLAY - 1)) {
                array[i][j] = 1;
            } else if(j == 0 || j == MAX_WIDTH_DISPLAY - 1) {
                array[i][j] = 1;
            } else {
                array[i][j] = 0;
            }
        }
    }
}
State Transition(State current, char input) {
    switch (current)
    {
        case STATE_A:
            if(input == '0') {
                return STATE_B;
            } else {
                return STATE_A;
            }
            break;
        case STATE_B:
            if(input == '1') {
                return STATE_C;
            } else {
                return STATE_A;
            }
            break;
        case STATE_C:
            if(input == '0') {
                return STATE_B;
            } else {
                return STATE_C; 
            }
            break;
    }
    return current;
}
    // for(int i = 0; i < MAX_WIDTH_DISPLAY; i++) {
    //     for(int j = 0; j < MAX_HEIGHT_DISPLAY; j++) {
    //         if (i == 0 || i == MAX_WIDTH_DISPLAY - 1) {
    //             if(j != 0 && j != MAX_HEIGHT_DISPLAY - 1) {
    //             printf("%c", TOP_LINE);
    //             } else {
    //                 printf("%s", " ");
    //             }
    //         } else {
    //             printf("%s"," ");
    //         }
    //         if(j == 0 || j == MAX_HEIGHT_DISPLAY - 2) {
    //             if(i != 0 && i != MAX_WIDTH_DISPLAY - 1) {
    //                 printf("%c", SIDE_LINE);
    //             } else if(j == MAX_HEIGHT_DISPLAY - 2 && (i == 0 || i == MAX_WIDTH_DISPLAY - 1)) {
    //                 printf(" %c", SIDE_LINE);
    //             }
    //         } else {
    //             printf("%s", " ");
    //         }
    //     }
    //     printf("\n");
    // }
// }