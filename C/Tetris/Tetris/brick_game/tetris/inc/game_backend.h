/**
 * @file game_backend.h
 * @brief Модуль реализации логики игры
 */
#ifndef BACKEND_H
#define BACKEND_H

#include "game.h"
/** @brief Кол-во валидных значений */
#define NUMBER_OF_KEYS 6
/** @brief Стрелка вверх*/
#define UP_ARROW KEY_UP
/** @brief Стрелка вниз */
#define DOWN_ARROW KEY_DOWN
/** @brief Стрелка влево */
#define LEFT_ARROW KEY_LEFT
/** @brief Стрелка вправо */
#define RIGHT_ARROW KEY_RIGHT
/** @brief Макрос для игнорирования регистра
 * @return вернет true, если значение равно Q или q
 */
#define IS_Q(c) ((c == 'q') || (c == 'Q'))
/** @brief Макрос для проверки ввода
 * @return вернет true, если нажата клавиша Enter
 */
#define IS_ENTER(c) (c == '\n')
/** @brief Макрос для проверки ввода
 * @return вернет true, если ввод верный
 */
#define IF_INPUT(c) ((IS_Q(c) == true) )

/**
 * @brief Повышение уровня по счету
 * Каждые 600 очков повышает уровень и понижает скорость
 * @returns Возвращает текущий уровень
 */
int lvlUp(int score);
/**
 * @brief Проверка состояния паузы
 */
bool checkedPause();
/** @brief Включить паузу */
void OnPauseGame();
/** @brief Выключить паузу */
void OffPauseGame();
/**
 * @brief Проверка нажатой клавиши на валидность
 * @returns Если нажатая клавиша не совпадает с валидными, то возвращает false
 */
bool isValidKey(int ch);
/**
 * @brief Ожидание ввода или указанного времени
 * принимает в себя время ожидание и символ 10 = 1 секунде, выполняется либо 1 секунду, либо пока не примет валидное значение
    если значение валидное, то не ждет 1 секунды и возвращает true, иначе ждет и возвращает false
    @param milliseconds время ожидания (10 равна 1 секунде)
    @param ch символ с ввода
    
    @code
    bool myDelay(int milliseconds, int ch) {
    milliseconds *= 100;
    bool checkValid = false;
    clock_t start_time = clock();
    do {
      checkValid = isValidKey(ch);
    } while (((clock() - start_time) * 1000 / CLOCKS_PER_SEC) < milliseconds && !checkValid);
  return checkValid;
}
    @endcode
    @returns true, если валидный ввод, иначе ждет время и false
 */
bool myDelay(int milliseconds, int ch);


// передвижение фигуры и генерация новой фигуры
/*Переворот фигуры*/
/**
 *  @brief Перевород фигуры
 */
void RotateFigure();
/**
 * @brief Проверка коллизии при повороте
 */
bool checkCollissionRotate();
/**
 * @brief Передвижение фигуры вниз
 * Если фигуры внизу не оказалось, то двигаемся вниз\n
 * иначе оставляем фигуру на месте в случае полного ряда добавляем счет в зависимости от того, сколько в ряд и регеним новую фигуру
 * @code 
 * void MoveFigureDown() {
    Current_Figure *figure = getCurrentFigure();
    if (checkCollissionDown()) {
        saveNextMapInFieldMap();
        int countTrue = 0;
        countTrue = checkLines(countTrue);
        addScore(countTrue);
        createRandomTetromino();
    } else {
    figure->Y++;
  }
}
 * @endcode
 */
void MoveFigureDown();
/** @brief Проверка коллизи внизу */
bool checkCollissionDown();
/** 
 * @brief Движение фигуры влево
 * Если фигура слева есть, то чекаем низ и двигаемся или остаемся\n
 * Если фигуры нет, то двигаемся и чекаем низ, если чисто, то спускаем, иначе остаемся
 * @code 
 * void MoveFigureLeft() {
    Current_Figure *figure = getCurrentFigure();
    if (checkCollisionLeft()) {
        MoveFigureDown();
        } else {
        figure->X--;
        updateGameScreen();
        if (checkCollissionDown()) {
        figure->X++;
        MoveFigureDown();
    } else {
      MoveFigureDown();
    }
  }
}
 * @endcode
 */
void MoveFigureLeft();
/**
 * @brief Проверка коллизи слева
 */
bool checkCollisionLeft();
/**
 * @brief Движение фиуры вправо
 * Если фигура справа есть, то чекаем низ и двигаемся или остаемся\n
 * Если фигуры нет, то двигаемся и чекаем низ, если чисто, то спускаем, иначе остаемся
 * @code 
 * void MoveFigureRight() {
    Current_Figure *figure = getCurrentFigure();
    if (checkCollisionRight()) {
    MoveFigureDown();
    } else {
        figure->X++;
        updateGameScreen();
        if (checkCollissionDown()) {
        figure->X++;
        MoveFigureDown();
        } else {
        MoveFigureDown();
        }
    }
}
 * @endcode
 */
void MoveFigureRight();
/**
 * @brief Проверка коллизи справа
 */
bool checkCollisionRight();
/**
 * @brief Передача управления новой фигурой
 * Обнуляет координаты фигуры, которой управляет игрок и записывает(cur) ее в next игровое поле
 */
void ApperanceFigureToNextField();
/**
 * @brief Обновляет фигуру и генерирует следущую
 */
void createRandomTetromino();
/**
 * @brief Перезаписывает игровую карту в карту отрисовки
 */
void saveNextMapInFieldMap();
/**
 * @brief Счет заполненых линий
 * @returns возвращает колличество в ряд линий
 */
int checkLines();
/**
 * @brief Удаление линии по указанному Y в ряд
 * 
 */
void removeLines(int removeLinesY);
/**
 * @brief Проверка полная ли линия по указаному Y
 */
bool isFullLines(int Y);
/**
 * @brief Добавление очков к счету
 * В зависимости от того сколько в ряд, столько и добавляет\n
 * 4 в ряд 1500\n
 * 3 в ряд 700\n
 * 2 в ряд 300\n
 * 1 в ряд 100\n
 */
void addScore(int countTrue);
/**
 * @brief Проверка существующих рекордов с прошлых игр
 * @returns Если файл с рекордами найден, то возвращает рекорд, иначе 0 
 */
int checkRecords(); 



#endif