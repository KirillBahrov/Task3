#pragma once
#include "Exercise.h"
#include <algorithm>
#include <cmath>

namespace RUT
{
    template <typename T>
    /**
     * @brief Класс MyExercise представляет собой производный класс от Exercise,который реализует конкретные задачи работы с матрицей.
     * @tparam T Тип данных, который будет храниться в матрице.
     */
    class MyExercise : public Exercise<T>
    {
    public:
        /**
         * @brief Конструктор класса MyExercise.
         * @param rows Количество строк в матрице.
         * @param cols Количество столбцов в матрице.
         * @param gen Генератор значений для инициализации матрицы.
         */
        MyExercise(size_t rows, size_t cols, Generator<T>& gen)
            : Exercise<T>(rows, cols, gen) {}

        /**
        * @brief Устанавливает генератор значений для инициализации матрицы.
        * @param gen Генератор значений.
        */
        void setGenerator(Generator<T>& gen)
        {
            this->generator = &gen; 
            this->matrix.fillWithGenerator(*this->generator);
        }

        /**
         * @brief Задача 1: Замена максимального по модулю элемента в каждой строке на его противоположное значение.
         */
        void Task1() override 
        {
            for (size_t i = 0; i < this->matrix.getRows(); ++i) 
            {
                auto& row = this->matrix[i];
                auto maxElem = std::max_element(row.begin(), row.end(),
                    [](T a, T b) { return std::abs(a) < std::abs(b); });
                if (maxElem != row.end())
                {
                    *maxElem = -*maxElem;
                }
            }
        }

        /**
         * @brief Задача 2: Вставка первой строки после каждой второй строки матрицы.
         */
        void Task2() override
        {
            size_t initialRows = this->matrix.getRows();
            for (size_t i = 0; i < initialRows; ++i) 
            {
                if ((i + 1) % 2 == 0) 
                {
                    this->matrix.insertRow(i + 1, this->matrix[0]);
                    ++i;
                }
            }
        }
    };
}
