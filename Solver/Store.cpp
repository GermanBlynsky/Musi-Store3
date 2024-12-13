#include "Store.h"

namespace MusicStore {

    Store::Store(std::string name, std::string address)
        : name(name), address(address) {
        if (name.empty()) {
            throw std::invalid_argument("Store name cannot be empty.");
        }
        if (address.empty()) {
            throw std::invalid_argument("Store address cannot be empty.");
        }
    }

    std::shared_ptr<Store> Store::createStore(std::string name, std::string address)
    {
        return std::make_shared<Store>(Store(name, address));
    }

    void Store::addProduct(std::shared_ptr<Product> product) {
        products.push_back(product);
    }

    // ... реализация геттеров и сеттеров ...

    std::string Store::getName() const {
        return name;
    }

    std::string Store::getAddress() const {
        return address;
    }

    const std::vector<std::shared_ptr<Product>>& Store::getProducts() const {
        return products;
    }

    std::vector<std::shared_ptr<Product>> Store::getProductsByTitle(const std::string& title) const {
        std::vector<std::shared_ptr<Product>> result;
        for (const auto& product : products) {
            if (product->getComposition()->getTitle() == title) {
                result.push_back(product);
            }
        }
        return result;
    }

    std::vector<std::shared_ptr<Product>> Store::getProductsByYear(int year) const {
        std::vector<std::shared_ptr<Product>> result;
        for (const auto& product : products) {
            if (product->getComposition()->getReleaseYear() == year) {
                result.push_back(product);
            }
        }
        return result;
    }

    std::vector<std::shared_ptr<Product>> Store::getProductsByGenre(const std::string& genre) const {
        std::vector<std::shared_ptr<Product>> result;
        for (const auto& product : products) {
            if (product->getComposition()->getGenre() == genre) {
                result.push_back(product);
            }
        }
        return result;
    }

    std::vector<std::shared_ptr<Product>> Store::getProductsByArtist(const std::string& artist) const {
        std::vector<std::shared_ptr<Product>> result;
        for (const auto& product : products) {
            for (const auto& author : product->getComposition()->getAuthors()) {
                if (author->getLastName() == artist) {
                    result.push_back(product);
                    break;
                }
            }
        }
        return result;
    }
}