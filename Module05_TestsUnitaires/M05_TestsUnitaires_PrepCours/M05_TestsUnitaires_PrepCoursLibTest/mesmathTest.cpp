#include <CppUnitTest.h>

#include "../M05_TestsUnitaires_PrepCoursLib/mesmath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace M05TestsUnitairesPrepCoursLibTest
{
	TEST_CLASS(mesmathTest)
	{
	public:
		
		TEST_METHOD(calculerMinimum_UnElement_LElelement)
		{
			// Arranger
			constexpr int nombreElements = 1;
			int valeurs[nombreElements] = { 1 };
			int valeurAttendue = 1;

			// Agir
			int valeurCalculee = calculerMinimum(valeurs, nombreElements);

			// Auditer
			Assert::AreEqual(valeurAttendue, valeurCalculee);
		}

		TEST_METHOD(calculerMinimum_Null_Exception)
		{
			// Arranger
			int* valeurs = nullptr;
			int nombreElements = INT_MAX;

			// Agir & Auditer
			Assert::ExpectException<std::invalid_argument>([&]() { calculerMinimum(valeurs, nombreElements); });
		}
	};
}
