#pragma once

namespace RUT
{
    template <typename T>
    /**
     * @brief Абстрактный класс Generator представляет генератор значений.
     * @tparam T Тип данных, которые будет генерировать класс-наследник.
     */
    class Generator
    {
    public:
        /**
        * @brief Виртуальный деструктор
         */
        virtual ~Generator() {}

        /**
         * @brief Чисто виртуальная функция для генерации значения типа T
         * @return T Сгенерированное значение типа T.
         */
        virtual T generate() = 0;
    };
}
