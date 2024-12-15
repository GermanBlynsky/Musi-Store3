#include "CppUnitTest.h"
#include "..\Solver\Author.h"
#include "..\Solver\Composition.h"
#include "..\Solver\Product.h"
#include "..\Solver\Store.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace MusicStore;
namespace Tests
{
	TEST_CLASS(AuthorTests)
	{
	public:

		TEST_METHOD(Author_ValidData_Success)
		{
			const std::string firstName = "testFirstName";
			const std::string lastName = "testLastName";
			const std::string middleName = "testMiddleName";
			auto author = Author::createAuthor(firstName, lastName, middleName);
			Assert::IsTrue(author != nullptr);
			Assert::IsTrue(author->getFirstName() == firstName);
			Assert::IsTrue(author->getLastName() == lastName);
			Assert::IsTrue(author->getMiddleName() == middleName);
		}

		TEST_METHOD(AddComposition_ValidData_True)
		{
			auto author = Author::createAuthor("FirstName1", "LastName1", "Patronymic1");
			std::vector<std::shared_ptr<Author>> authors = { author };
			auto composition = Composition::createComposition("ComposiitionName1", "Genre1", 1971, authors);

			auto result = author.get()->AddComposition(composition);

			Assert::IsTrue(result);
		}
	};
}