#pragma once
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

namespace MusicStore {

    class Author;

    class Composition {
    private:
        std::string title;
        std::string genre;
        int releaseYear;
        std::vector<std::shared_ptr<Author>> authors;
        Composition(std::string title, std::string genre, int releaseYear, std::vector<std::shared_ptr<Author>> authors);
    public:
        static std::shared_ptr<Composition> createComposition(std::string title, std::string genre, int releaseYear, std::vector<std::shared_ptr<Author>> authors);
        std::string getTitle() const;
        std::string getGenre() const;
        int getReleaseYear() const;
        const std::vector<std::shared_ptr<Author>>& getAuthors() const;
    };
}