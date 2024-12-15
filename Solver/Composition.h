#pragma once
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

namespace MusicStore {

    class Author;
    class Product;
    class Book;

    /**
     * @brief Класс Композиция
     * Данный класс представляет собой композицию, как абстрактный объект, он содержит параметры название, жанр, год выпуска и указатели на продукт на котором он содержится и на список своих авторов
     */
    class Composition : public std::enable_shared_from_this<Composition> {
    private:
        std::string title;
        std::string genre;
        int releaseYear;
        std::weak_ptr<Product> product;
        std::vector<std::shared_ptr<Author>> authors;
        Composition(std::string title, std::string genre, int releaseYear, std::vector<std::shared_ptr<Author>> authors);
    public:
        static std::shared_ptr<Composition> createComposition(std::string title, std::string genre, int releaseYear, std::vector<std::shared_ptr<Author>> authors);
        std::string getTitle() const;
        std::string getGenre() const;
        int getReleaseYear() const;
        const std::vector<std::shared_ptr<Author>>& getAuthors() const;
        std::vector<std::shared_ptr<Author>>& getAuthors();
        std::weak_ptr<Product> getProduct() const;
        void setProduct(const std::shared_ptr<Product>& product);
    };
}