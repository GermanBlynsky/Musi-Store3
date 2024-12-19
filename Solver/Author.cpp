#include "Author.h" 
#include "Composition.h" 

namespace MusicStore {

    Author::Author(std::string firstName, std::string lastName, std::string middleName)
        : firstName(firstName), lastName(lastName), middleName(middleName) {
        if (firstName.empty() || lastName.empty()) {
            throw std::invalid_argument("First name and last name cannot be empty.");
        }
    }
    std::shared_ptr<Author> Author::createAuthor(std::string firstName, std::string lastName, std::string middleName)
    {
        return std::make_shared<Author>(Author(firstName, lastName, middleName));
    }

    std::string Author::getFirstName() const {
        return firstName;
    }

    std::string Author::getLastName() const {
        return lastName;
    }

    std::string Author::getMiddleName() const {
        return middleName;
    }

    const std::vector<std::weak_ptr<Composition>>& Author::getCompositions() const {
        return compositions;
    }

    bool Author::AddComposition(std::shared_ptr<Composition> const& composition)
    {
        this->compositions.push_back(composition);
        composition->getAuthors().push_back(shared_from_this());
        return true;
    }
}