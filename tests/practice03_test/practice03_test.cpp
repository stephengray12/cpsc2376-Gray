#include "pch.h"
#include "CppUnitTest.h"
#include "../practice03/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace practice03test
{
	TEST_CLASS(practice03test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(10, MathUtils::sumRange(1, 5));
		}
	};
}
