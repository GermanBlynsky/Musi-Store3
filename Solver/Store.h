#include <string>
#include <vector>
#include <memory>
#include "Product.h"
#include "Author.h"

namespace MusicStore {

    /**
     * @brief Класс Магазин (возможно удалю, но по заданию как будто не лишний, т.к. не представляю смысл продажи товаров без существования магазина)
     * Данный класс представляет собой музыкальный магазин, он знает название магазина, адресс и продукты, что продаются в нем
     */
    class Store {
    private:
        std::string name;
        std::string address;
        std::vector<std::shared_ptr<Product>> products;

    public:
        Store(std::string name, std::string address);
        void addProduct(std::shared_ptr<Product> product);

        /**
        * @brief Гетер для названия магазина
        * @return Возвращает название магазина
        */
        std::string getName() const;

        /**
        * @brief Гетер для адресса
        * @return Возвращает адресс
        */
        std::string getAddress() const;

        /**
        * @brief Гетер для продуктов
        * @return Возвращает вектор указателей на продукты, что хранятся в магазине
        */
        const std::vector<std::shared_ptr<Product>>& getProducts() const;
        /**
         * @brief Функция, возвращающая продукты с указанынм названием
         * @param tittle - название продуктов, которые она будет возвращать
         * @return продукты с указанным названием (вектор указателей на них)
         */
        std::vector<std::shared_ptr<Product>> getProductsByTitle(const std::string& title) const;

        /**
         * @brief Функция, возвращающая продукты с указанынм годом выпуска их композиции
         * @param year - год выпуска композиции
         * @return продукты с указанным годом выпуска песни
         */
        std::vector<std::shared_ptr<Product>> getProductsByYear(int year) const;

        /**
         * @brief Функция, возвращающая продукты с указанынм жанра их композиции
         * @param genre - жанр композиции
         * @return продукты с указанным жанром
         */
        std::vector<std::shared_ptr<Product>> getProductsByGenre(const std::string& genre) const;

        /**
         * @brief Функция, возвращающая продукты с указанынм автором их композиции
         * @param artist - автор 
         * @return продукты с указанным автором 
         */
        std::vector<std::shared_ptr<Product>> getProductsByArtist(const std::string& artist) const;
    };
}