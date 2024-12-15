#include "CppUnitTest.h"
#include "..\Solver\Author.h"
#include "..\Solver\Composition.h"
#include "..\Solver\Product.h"
#include "..\Solver\Store.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace MusicStore;

namespace Tests
{
	TEST_CLASS(CompositionTests)
	{
	public:

		TEST_METHOD(Composition_ValidData_Success)
		{
			auto author = Author::createAuthor("FirstName1", "LastName1", "Patronymic1");
			std::vector<std::shared_ptr<Author>> authors = { author };
			const std::string compositionName = "ComposiitionName";
			const std::string genre = "Genre";
			const int releaseYear = 1971;
			auto composition = Composition::createComposition(compositionName, genre, releaseYear, authors);
			Assert::IsTrue(composition != nullptr);
			Assert::IsTrue(composition->getTitle() == compositionName);
			Assert::IsTrue(composition->getGenre() == genre);
			Assert::IsTrue(composition->getReleaseYear() == releaseYear);
			Assert::IsTrue(composition->getAuthors() == authors);
		}

	};
}