#pragma once 
#include <string> 
#include <vector> 
#include <memory> 
#include <stdexcept> 

namespace MusicStore {

    class Composition;

    class Author;

    /**
     * @brief Класс Автор
     * Данный класс представляет собой автора композиции, у него есть ФИО и вектор его композиций
     */
    class Author : public std::enable_shared_from_this<Author> {
    private:
        std::string firstName;
        std::string lastName;
        std::string middleName;
        std::vector<std::weak_ptr<Composition>> compositions;
        Author(std::string firstName, std::string lastName, std::string middleName);
    public:
        static std::shared_ptr<Author> createAuthor(std::string firstName, std::string lastName, std::string middleName);

        /**
         * @brief Гетер для Имени
         * @return Возвращает Имя
         */
        std::string getFirstName() const;

        /**
         * @brief Гетер для фамилии
         * @return Возвращает фамилию
         */
        std::string getLastName() const;

        /**
         * @brief Гетер для отчества
         * @return Возвращает отчество
         */
        std::string getMiddleName() const;

        /**
         * @brief Гетер для композиция данного автора
         * @return Возвращает цену
         */
        const std::vector<std::weak_ptr<Composition>>& getCompositions() const;

        /**
         * @brief функция добавления композиции
         * @param composition - композиция, которую мы добавляем автору
         */
        bool AddComposition(std::shared_ptr<Composition> const& composition);
    };
}