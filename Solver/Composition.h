#pragma once
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

namespace MusicStore {

    class Author;

    /**
     * @brief Класс Композиция
     * Данный класс представляет собой композицию: песню как абстрактный (не физический объект), у неё есть название, жанр и авторы
     */
    class Composition {
    private:
        std::string title;
        std::string genre;
        int releaseYear;
        std::vector<std::shared_ptr<Author>> authors;

    public:

        Composition(std::string title, std::string genre, int releaseYear, std::vector<std::shared_ptr<Author>> authors);
        
        /**
         * @brief Гетер для названия
         * @return Возвращает название
         */
        std::string getTitle() const;

        /**
        * @brief Гетер для жанра
        * @return Возвращает жанр
        */
        std::string getGenre() const;

        /**
        * @brief Гетер для года выпуска
        * @return Возвращает год выпуска 
        */
        int getReleaseYear() const;

        /**
        * @brief Гетер для авторов
        * @return Возвращает вектор авторов композиции
        */
        const std::vector<std::shared_ptr<Author>>& getAuthors() const;
    };
}