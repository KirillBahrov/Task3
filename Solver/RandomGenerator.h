#pragma once
#include "Generator.h"
#include <random>
#include <type_traits>

namespace RUT
{
    template <typename T>
    /**
     * @brief Класс RandomGenerator реализует генератор случайных чисел,
     * @tparam T Тип данных, который будет генерироваться (целые или вещественные числа).
     */
    class RandomGenerator : public Generator<T> {
    private:
        std::mt19937 generator;
        typename std::conditional<std::is_integral<T>::value,
            std::uniform_int_distribution<T>,
            std::uniform_real_distribution<T>>::type distribution; /**< Распределение для генерации чисел. */

    public:
        /**
         * @brief Конструктор класса RandomGenerator.
         * @param min Минимальное значение диапазона.
         * @param max Максимальное значение диапазона.
         */
        RandomGenerator(T min, T max)
            : generator(std::random_device{}()), distribution(min, max) {}

        /**
         * @brief Генерирует случайное число в заданном диапазоне.
         * @return Случайное число типа T, сгенерированное в заданном диапазоне.
         */
        T generate() override { return distribution(generator); }
    };
}
