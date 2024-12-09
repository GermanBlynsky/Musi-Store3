#include "Author.h"
#include "Composition.h"

namespace MusicStore {

    Author::Author(std::string firstName, std::string lastName, std::string middleName)
        : firstName(firstName), lastName(lastName), middleName(middleName) {
        if (firstName.empty() || lastName.empty()) {
            throw std::invalid_argument("First name and last name cannot be empty.");
        }
    }
    void Author::addComposition(std::shared_ptr<Composition> composition) {
        compositions.push_back(composition);
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

    const std::vector<std::shared_ptr<Composition>>& Author::getCompositions() const {
        return compositions;
    }

    std::vector<std::shared_ptr<Composition>> Author::getCompositionsByYearRange(int startYear, int endYear) const {
        std::vector<std::shared_ptr<Composition>> result;
        for (const auto& composition : compositions) {
            if (composition->getReleaseYear() >= startYear && composition->getReleaseYear() <= endYear) {
                result.push_back(composition);
            }
        }
        return result;
    }
}