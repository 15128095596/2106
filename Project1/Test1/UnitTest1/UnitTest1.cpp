#include "pch.h"
#include "CppUnitTest.h"
#include "../../first.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int max, num[] = { 0 };
			max = test(num, 0);
			Assert::AreEqual(max, 0);
		}
		TEST_METHOD(TestMethod2)
		{
			int max, num[5] = { 0,-2,-2,-3,-4 };
			max = test(num, 5);
			Assert::AreEqual(max, 0);
		}
		TEST_METHOD(TestMethod3)
		{
			int max, num[6] = { 0,4,2,6,5,1 };
			max = test(num, 6);
			Assert::AreEqual(max, 18);
		}
		TEST_METHOD(TestMethod4)
		{
			int max, num[6] = { 5,-2,3,4,-3,3 };
			max = test(num, 4);
			Assert::AreEqual(max, 10);
		}
		TEST_METHOD(TestMethod5)
		{
			int max, num[4] = { 3,-8,6,4 };
			max = test(num, 4);
			Assert::AreEqual(max, 10);
		}
	};
}
