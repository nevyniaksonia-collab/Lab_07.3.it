#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.3.it/Lab_07.3.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest23
{
	TEST_CLASS(UnitTest23)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int r0[3] = { 0, 1, 2 };
			int r1[3] = { 3, 4, 5 };
			int r2[3] = { 6, 7, 8 };
			int* a[3] = { r0, r1, r2 };

			Assert::AreEqual(2, CountRowsWithoutZero(a, 3, 3));
		}
		TEST_METHOD(TestMethod2)
		{
			int r0[3] = { 5, 2, 3 };
			int r1[3] = { 4, 5, 1 };
			int r2[3] = { 6, 7, 5 };
			int* a[3] = { r0, r1, r2 };

			int maxRep;
			bool found = FindMaxRepeatedElement(a, 3, 3, maxRep);

			Assert::IsTrue(found);
			Assert::AreEqual(5, maxRep);
		}
		TEST_METHOD(TestMethod3)
		{
			int r0[3] = { 1, 2, 3 };
			int r1[3] = { 4, 5, 6 };
			int r2[3] = { 7, 8, 9 };
			int* a[3] = { r0, r1, r2 };

			int maxRep;
			bool found = FindMaxRepeatedElement(a, 3, 3, maxRep);

			Assert::IsFalse(found);
		}
	};
}
