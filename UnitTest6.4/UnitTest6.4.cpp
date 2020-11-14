#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.4/lab6_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:
		
		TEST_METHOD(TestMethod6_4)
		{
			int t;
			const int n = 5;
			int a[n] = { 1,2,3,4,5 };
			t = SUM(a, n);
			Assert::AreEqual(t, 15);
		}
	};
}
