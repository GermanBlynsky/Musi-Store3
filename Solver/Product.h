#pragma once
#include <string>
#include <memory>
#include "Composition.h"

namespace MusicStore {

    class Product {
    private:
        std::shared_ptr<Composition> composition;
        double price;
        std::string address;
        std::string carrier;
        Product(std::shared_ptr<Composition> composition, double price, std::string address, std::string carrier);

    public:
        static std::shared_ptr<Product> createProduct(std::shared_ptr<Composition> composition, double price, std::string address, std::string carrier);
        std::shared_ptr<Composition> getComposition() const;
        double getPrice() const;
        std::string getAddress() const;
        std::string getCarrier() const;
    };
}