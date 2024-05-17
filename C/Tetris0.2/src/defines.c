#include "../inc/objects.h"

Current_Figure *getCurrentFigure() {
    static Current_Figure figure;
    return &figure;
}
