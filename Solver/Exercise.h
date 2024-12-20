#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <iostream>

namespace RUT
{
    template <typename T>
    /**
     * @brief Класс Exercise представляет абстрактный базовый класс для работы с матрицами.
     * @tparam T Тип данных, используемый в матрице.
     */
    class Exercise
    {
    public:
        Matrix<T>* matrix;
        std::ostream& out;
        Generator<T>* gen;
    
    
        /**
         * @brief Конструктор класса Exercise.
         * @param rows Количество строк в матрице.
         * @param cols Количество столбцов в матрице.
         * @param gen Ссылка на объект генератора значений.
         */
        Exercise(int rows, int cols, Generator<T>& gen, std::ostream& out);

        /**
        * * @brief Деструктор класса Exercise (виртуальный).
         */
        virtual ~Exercise() { delete this->matrix; }

        /**
         * @brief Чисто виртуальная функция для выполнения задачи 1.
         */
        virtual void Task1() = 0;

        /**
         * @brief Чисто виртуальная функция для выполнения задачи 2.
         */
        virtual void Task2() = 0;

        /**
         * @brief Выводит содержимое матрицы на стандартный вывод.
         */
        void printMatrix() const 
        {
            matrix.ToString();
        }
        
    };
    template<typename T>
    inline Exercise<T>::Exercise(int rows, int cols, Generator<T>& gen, std::ostream& out) : out {out}
        {
        this->matrix = new Matrix<T>{ rows, cols };
        }
}
