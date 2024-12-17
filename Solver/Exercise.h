#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace RUT
{
    template <typename T>
    /**
     * @brief Класс Exercise представляет абстрактный базовый класс для работы с матрицами.
     * @tparam T Тип данных, используемый в матрице.
     */
    class Exercise {
    public:
        Matrix<T> matrix;
        Generator<T>& generator;

    
        /**
         * @brief Конструктор класса Exercise.
         * @param rows Количество строк в матрице.
         * @param cols Количество столбцов в матрице.
         * @param gen Ссылка на объект генератора значений.
         */
        Exercise(size_t rows, size_t cols, Generator<T>& gen) : matrix(rows, cols), generator(gen) {}

        /**
        * * @brief Деструктор класса Exercise (виртуальный).
         */
        virtual ~Exercise() = default;

        /**
         * @brief Чисто виртуальная функция для выполнения задачи 1.
         */
        virtual void Task1() = 0;

        /**
         * @brief Чисто виртуальная функция для выполнения задачи 2.
         */
        virtual void Task2() = 0;

        /**
         * @brief Заполняет матрицу случайными значениями, используя генератор.
         */
        void fillMatrix() {
            for (size_t i = 0; i < matrix.getRows(); ++i)
                for (size_t j = 0; j < matrix.getCols(); ++j)
                    matrix[i][j] = generator.generate();
        }

        /*/**
        * @brief функция получения указателя на матрицу
        
        getMatrix() const
        {
            return matrix;
        }*/

        /**
         * @brief Выводит содержимое матрицы на стандартный вывод.
         */
        void printMatrix() const {
            matrix.print();
        }
    };
}
