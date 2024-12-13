#include <string>
#include <vector>
#include <memory>
#include "Product.h"
#include "Author.h"

namespace MusicStore {

    class Store {
    private:
        std::string name;
        std::string address;
        std::vector<std::shared_ptr<Product>> products;
        Store(std::string name, std::string address);

    public:
        static std::shared_ptr<Store> createStore(std::string name, std::string address);
        void addProduct(std::shared_ptr<Product> product);
        std::string getName() const;
        std::string getAddress() const;
        const std::vector<std::shared_ptr<Product>>& getProducts() const;
        std::vector<std::shared_ptr<Product>> getProductsByTitle(const std::string& title) const;
        std::vector<std::shared_ptr<Product>> getProductsByYear(int year) const;
        std::vector<std::shared_ptr<Product>> getProductsByGenre(const std::string& genre) const;
        std::vector<std::shared_ptr<Product>> getProductsByArtist(const std::string& artist) const;
    };
}