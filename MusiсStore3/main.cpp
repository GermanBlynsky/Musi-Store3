#include <iostream> 
#include <memory> 
#include <vector> 
#include "../Solver/Author.h" 
#include "../Solver/Product.h" 
#include "../Solver/Composition.h" 
using namespace MusicStore;
int main() {

    auto author1 = Author::createAuthor("FirstName1", "LastName1", "Patronymic1");
    auto author2 = Author::createAuthor("FirstName2", "LastName2", "Patronymic2");

    std::vector<std::shared_ptr<MusicStore::Author>> authors1 = { author1 };
    std::vector<std::shared_ptr<MusicStore::Author>> authors2 = { author2 };

    // Создаем композиции 
    auto composition1 = Composition::createComposition("ComposiitionName1", "Genre1", 1971, authors1);
    auto composition2 = Composition::createComposition("ComposiitionName2", "Genre2", 1968, authors2);

    // Добавляем композиции к авторам 
    auto result1_1 = author1->AddComposition(composition1);
    auto result1_2 = author2->AddComposition(composition2);


    // Создаем продукты 
    auto product1 = Product::createProduct(9.99, "ProductAdress1", "CD");
    auto product2 = Product::createProduct(12.99, "ProductAdress2", "Vinyl");

    auto result2_1 = product1->AddComposition(composition1);
    auto result2_2 = product2->AddComposition(composition2);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
    // Ищем продукты по различным критериям 
   /* std::cout << "Products by title 'ComposiitionName1':" << std::endl;
    auto productsByTitle = store->getProductsByTitle("ComposiitionName1");
    for (const auto& product : productsByTitle) {
        std::cout << product->getComposition()->getTitle() << std::endl;
    }

    std::cout << "Products by year 1968:" << std::endl;
    auto productsByYear = store->getProductsByYear(1968);
    for (const auto& product : productsByYear) {
        std::cout << product->getComposition()->getTitle() << std::endl;
    }

    std::cout << "Products by artist 'LastName1':" << std::endl;
    auto productsByArtist = store->getProductsByArtist("LastName1");
    for (const auto& product : productsByArtist) {
        std::cout << product->getComposition()->getTitle() << std::endl;
    }

    return 0;
}
*/