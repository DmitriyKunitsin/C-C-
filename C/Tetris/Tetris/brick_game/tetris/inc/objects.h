/**
 * @file objects.h
 * @brief Модуль для работы с объектами
 */
#ifndef OBJECTS_H
#define OBJECTS_H

#include "game.h"
/**
 * @brief 
 */
#define MAX_DEMISION 4

/**
 * @brief Структура положения фигуры
 * @param [Y] Координата по Y
 * @param [X] Координата по Х
 * @param [dimension] Размер фигуры 4х4
 * @param [curFigure] текущая фигура на игровом поле
 * @param [nextFigure] следущая фигура на поле
 */
typedef struct
{
    int Y;
    int X;
    int dimension;
    int curFigure[MAX_DEMISION][MAX_DEMISION];
    int nextFigure[MAX_DEMISION][MAX_DEMISION];
}Current_Figure;
/**
 * @brief Перечисление фигур
 * 
 */
typedef enum {
    LINE,
    G_LEFT,
    G_RIGHT,
    CUBE,
    Z_RIGHT_UP,
    CROSS,
    Z_LEFT_UP,
    FIGURE_COUNT
} FigureType;
/**
 * @brief Функция для работы со статической локальной переменной
 * @code 
 *    Current_Figure *getCurrentFigure() {
        static Current_Figure figure;
        return &figure;
    }
 * @endcode
 * Через полученый адрес позволяет получить значение структуры в данный момент
 * @returns Возвращает адрес в памяти, где хранится структура
 */
Current_Figure *getCurrentFigure();


/**
 * @brief Генерация следующей фигуры
 * Получает текущую структуру с фигурой\n
 * Получается рандомное число фигуры (enum)\n
 * Получает по рандомному числу, нужную фигуру\n
 * Записывает ее в структуру в следущую фигуру
 * @code 
 * void GenereatedNextFigure() {
  Current_Figure *figure = getCurrentFigure();
  int figureNumber = getRandNumberFigures();
  int *figurePointer = getFigure(figureNumber);
  figure->dimension = 4;
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figurePointer + i * figure->dimension + j);
      figure->nextFigure[i][j] = value;
    }
  }
}
 * @endcode
    @returns после выполнения функции, в структуре Current_Figure в массиве nextFigure лежит рандомная фигура
 */
void GenereatedNextFigure();
/**
 * @brief Генерация рандомного числа от 0 до 6
 */
int getRandNumberFigures();
/**
 * @brief Возвращает указатель на матрицу с нужной фигурой
 * После получения конкретного перечисления, возвращает нужный матрицу с нужной фигурой
 * @returns возвращает указатель на матрицу с фигурой
 */
int *getFigure(FigureType type);
/**
 * @brief Меняет местами следущую структуру с текущей
 * @returns После вызова функции, в структуре Current_Figure следущая фигура будет храниться в текущей
 */
void SwapFigureOldToNew();

#endif