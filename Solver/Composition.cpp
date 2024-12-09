#include "Composition.h"

namespace MusicStore {

    Composition::Composition(std::string title, std::string genre, int releaseYear, std::vector<std::shared_ptr<Author>> authors)
        : title(title), genre(genre), releaseYear(releaseYear), authors(std::move(authors)) {
        if (this->authors.empty()) {
            throw std::invalid_argument("Composition must have at least one author");
        }
    }

    // ... ���������� �������� � �������� ...

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
}