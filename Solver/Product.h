#pragma once
#include <string>
#include <memory>
#include "Composition.h"

namespace MusicStore {

    /**
     * @brief  ласс ѕродукт
     * ƒанный класс представл¤ет собой товар, как физический носитель песни, он содержит параметры цена, адресс, носитель и сырой указатель на композицию, котора¤ хранитс¤ в нем
     */
    class Product : public std::enable_shared_from_this<Product> {
    private:
        std::shared_ptr<Composition> composition;
        double price;
        std::string address;
        std::string carrier;
        Product(double price, std::string address, std::string carrier);

    public:
        static std::shared_ptr<Product> createProduct(double price, std::string address, std::string carrier);
        std::shared_ptr<Composition> getComposition() const;
        double getPrice() const;
        std::string getAddress() const;
        std::string getCarrier() const;
        bool AddComposition(std::shared_ptr<Composition> const& composition);
    };
}