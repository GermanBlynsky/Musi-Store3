#include "Product.h"

namespace MusicStore {


    Product::Product(double price, std::string address, std::string carrier)
        : price(price), address(address), carrier(carrier) {
        if (price < 0) {
            throw std::invalid_argument("Price cannot be negative");
        }
        if (address.empty()) {
            throw std::invalid_argument("Address cannot be empty");
        }
        if (carrier.empty()) {
            throw std::invalid_argument("Carrier cannot be empty");
        }
    }


    std::shared_ptr<Product> Product::createProduct(double price, std::string address, std::string carrier)
    {
        return std::make_shared<Product>(Product(price, address, carrier));
    }

    std::shared_ptr<Composition> Product::getComposition() const {
        return composition;
    }

    double Product::getPrice() const {
        return price;
    }

    std::string Product::getAddress() const {
        return address;
    }

    std::string Product::getCarrier() const {
        return carrier;
    }
    bool Product::AddComposition(std::shared_ptr<Composition> const& composition)
    {
        this->composition = composition;
        composition->setProduct(shared_from_this());
        return true;
    }
}