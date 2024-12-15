#include "CppUnitTest.h"
#include "..\Solver\Author.h"
#include "..\Solver\Composition.h"
#include "..\Solver\Product.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace MusicStore;
namespace Tests
{
	TEST_CLASS(ProductTests)
	{
	public:

		TEST_METHOD(Product_ValidData_Success)
		{
			auto author = Author::createAuthor("FirstName", "LastName", "Patronymic");
			std::vector<std::shared_ptr<MusicStore::Author>> authors = { author };
			auto composition = Composition::createComposition("ComposiitionName", "Genre", 1971, authors);
			auto result1 = author->AddComposition(composition);
			const double price = 9.99;
			const std::string productAdress = "ProductAdress";
			const std::string carrier = "CD";
			auto product = Product::createProduct(price, productAdress, carrier);
			auto result2 = product->AddComposition(composition);
			Assert::IsTrue(product != nullptr);
			Assert::IsTrue(product->getComposition() == composition);
			Assert::IsTrue(product->getPrice() == price);
			Assert::IsTrue(product->getAddress() == productAdress);
			Assert::IsTrue(product->getCarrier() == carrier);
		}

		TEST_METHOD(AddComposition_ValidData_True)
		{
			auto author = Author::createAuthor("FirstName", "LastName", "Patronymic");
			std::vector<std::shared_ptr<MusicStore::Author>> authors = { author };
			auto composition = Composition::createComposition("ComposiitionName", "Genre", 1971, authors);
			auto result1 = author->AddComposition(composition);
			const double price = 9.99;
			const std::string productAdress = "ProductAdress";
			const std::string carrier = "CD";
			auto product = Product::createProduct(price, productAdress, carrier);

			auto result2 = product.get()->AddComposition(composition);

			Assert::IsTrue(result2);
		}
	};
}