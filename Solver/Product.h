#pragma once
#include <string>
#include <memory>
#include "Composition.h"

namespace MusicStore {

    /**
     * @brief Класс Продукт
     * Данный класс представляет собой товар в музыкальном магазине, носитель песни, знающий свою песню (со всеми её данными), цену, адресс продажи, носитель информации
     */
    class Product {
    private:
        std::shared_ptr<Composition> composition;
        double price;
        std::string address;
        std::string carrier;

    public:
        Product(std::shared_ptr<Composition> composition, double price, std::string address, std::string carrier);

        /**
         * @brief Гетер для указателя на композицию
         * @return Возвращает указатель на композицию
         */
        std::shared_ptr<Composition> getComposition() const;

        /**
         * @brief Гетер для цены
         * @return Возвращает цену
         */
        double getPrice() const;

        /**
         * @brief Гетер для адресса
         * @return Возвращает адресс
         */
        std::string getAddress() const;

        /**
         * @brief Гетер для носителя
         * @return Возвращает информацию название носителя песни
         */
        std::string getCarrier() const;
    };
}