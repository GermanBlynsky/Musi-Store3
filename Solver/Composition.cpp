#include "Composition.h"

namespace MusicStore {

    std::shared_ptr<Composition> Composition::createComposition(std::string title, std::string genre, int releaseYear, std::vector<std::shared_ptr<Author>> authors)
    {
        return std::make_shared<Composition>(Composition(title, genre, releaseYear, authors));
    }
    Composition::Composition(std::string title, std::string genre, int releaseYear, std::vector<std::shared_ptr<Author>> authors)
        : title(title), genre(genre), releaseYear(releaseYear), authors(std::move(authors)) {
        if (this->authors.empty()) {
            throw std::invalid_argument("Composition must have at least one author");
        }
    }

    // ... реализация геттеров и сеттеров ...

    std::string Composition::getTitle() const {
        return title;
    }

    std::string Composition::getGenre() const {
        return genre;
    }

    int Composition::getReleaseYear() const {
        return releaseYear;
    }

    const std::vector<std::shared_ptr<Author>>& Composition::getAuthors() const {
        return authors;
    }

    std::vector<std::shared_ptr<Author>>& Composition::getAuthors() {
        return authors;
    }

    void Composition::setProduct(const std::shared_ptr<Product>& product)
    {
        this->product = product;
    }

}