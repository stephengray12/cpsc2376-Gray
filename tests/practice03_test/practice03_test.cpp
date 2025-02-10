#include "pch.h"
#include "CppUnitTest.h"
#include "../../practice/practice03/main.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace practice03test
{
	TEST_CLASS(practice03test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(15, MathUtils::sumRange(1, 5));
		}
	};
}
