#pragma once
#include "Generator.h"
#include <vector>
#include <iostream>
#include <iomanip>

namespace RUT
{
    template <typename T>
    /**
     * @brief Класс Matrix представляет собой двумерный массив произвольного типа.
     * @tparam T Тип данных, который будет храниться в матрице.
     */
    class Matrix
    {
    private:
        std::vector<std::vector<T>> data;
    protected:
        size_t rows;
        size_t cols;

    public:
        Generator<T>* gen;
        /**
         * @brief Конструктор класса Matrix.
         * @param rows Количество строк в матрице.
         * @param cols Количество столбцов в матрице.
         * @param defaultValue Значение по умолчанию для элементов матрицы.
         */
        Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<T>(cols)) 
        {
            if (rows < 0 || cols < 0)
            {
                throw std::logic_error("The matrix is not correct");
            }
        }

        /**
         * @brief Оператор доступа к элементам матрицы.
         * @param row Индекс строки, к которой нужно получить доступ.
         * @return std::vector<T>& Ссылка на строку матрицы.
         */
        std::vector<T>& operator[](int row) { return data[row]; }

        /**
         * @brief Оператор доступа к элементам матрицы.
         * @param row Индекс строки, к которой нужно получить доступ.
         * @return const std::vector<T>& Константная ссылка на строку матрицы.
         */
        const std::vector<T>& operator[](int row) const { return data[row]; }

        /**
         * @brief Получает количество строк в матрице.
         * @return size_t Количество строк в матрице.
         */
        size_t getRows() const {
            return rows;
            /*return data.size();*/ }

        /**
         * @brief Получает количество столбцов в матрице.
         * @return size_t Количество столбцов в матрице.
         */
        size_t getCols() const { return data[0].size(); }

        /**
         * @brief Вставляет строку в матрицу на указанную позицию.
         * @param pos Позиция, на которую нужно вставить строку.
         * @param row Вектор, представляющий строку для вставки.
         */
        void insertRow(size_t pos, const std::vector<T>& row)
        {
            if (pos <= data.size())
            {
                data.insert(data.begin() + pos, row);
            }
        }

        /**
        * @brief Заполняет матрицу случайными значениями, используя генератор.
         */
        void fillMatrix(Generator<T>* gen)
        {
            if (gen == nullptr)
            {
                throw std::out_of_range("The generator is not defined");
            }

            for (size_t i = 0; i < this->rows; ++i)
            {
                for (size_t j = 0; j < this->cols; ++j)
                {
                    this->data[i][j] = gen->generate();
                }
            }
        }

        std::string ToString() const {
            std::stringstream buffer{};
            for (const auto& row : data) {
                for (const auto& elem : row) {
                    buffer << elem << " ";
                }
                buffer << "\n";
            }
            return buffer.str();
        }
    };
}
