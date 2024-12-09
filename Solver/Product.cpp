#include "Product.h"

namespace MusicStore {


    Product::Product(std::shared_ptr<Composition> composition, double price, std::string address, std::string carrier)
        : composition(std::move(composition)), price(price), address(address), carrier(carrier) {
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
}