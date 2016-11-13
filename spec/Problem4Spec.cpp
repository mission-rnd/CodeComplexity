#include "stdafx.h"
#include "../src/Problem4.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem4Spec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
#pragma endregion 

		void CompareArraysSpecP4(int *expectedArray, int *actualArray, int len){
			int i = 0;
			for (i = 0; i < len; i++){
				Assert::AreEqual(expectedArray[i], actualArray[i], L"Failed in Comparing Array Elements ", 1, 2);
			}
		}

		void CompareIntSpecP4(int expected, int actual){
			Assert::AreEqual(expected, actual, L"Failed for Comparing Ints  ", 1, 2);
		}
		[TestMethod,Timeout(1000)]
		void Sample1_Problem4()
		{
			int *actualArray = getSquareLeaderArray(NULL, -1,NULL);
			if (actualArray != NULL){
				Assert::Fail();
			}
		};

		[TestMethod, Timeout(1000)]
		void Sample2_Problem4()
		{
			int arr[10] = { 1, 5, 10, 89, 145, 204, 5555, 2342, 1234, 999 };
			int len = 10;
			int ansLen = 0;
			int expectedArray[100] = { 1,10,5555 };
			int expectedLen = 3;

			int *ans = getSquareLeaderArray(arr, len, &ansLen);
			
			CompareIntSpecP4(expectedLen, ansLen);
			CompareArraysSpecP4(expectedArray, ans, expectedLen);
		};

		[TestMethod, Timeout(1000)]
		void Sample3_Problem4()
		{
			int arr[10] = { 444,444,367,445,134,103,219,983,999,950 };
			int len = 10;
			int ansLen = 0;
			int expectedArray[100] = { 367,103,219 };
			int expectedLen = 3;

			int *ans = getSquareLeaderArray(arr, len, &ansLen);

			CompareIntSpecP4(expectedLen, ansLen);
			CompareArraysSpecP4(expectedArray, ans, expectedLen);
		};


	};
}
