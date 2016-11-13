#include "stdafx.h"
#include "../src/Problem3.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem3Spec
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

		void CompareArraysSpec(int *expectedArray, int *actualArray, int len){
			int i = 0;
			for (i = 0; i < len; i++){
				Assert::AreEqual(expectedArray[i], actualArray[i], L"Failed  ", 1, 2);
			}
		}
		[TestMethod ,Timeout(1000)]
		void Sample1_Problem3()
		{
			
			int *actualArray = getLeaderIndex(NULL,-1);
			if (actualArray != NULL){
				Assert::Fail();
			}
		};

		[TestMethod, Timeout(1000)]
		void Sample2_Problem3()
		{
			int arr[100] = { 4, 3, 8, 6, 5, 1, 7, 2 };
			int len = 8;
			int expectedArray[2] = { 6, 3 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample3_Problem3()
		{
			int arr[100] = { 1, 2, 7, 20, 3, 5, 4, 9, 8 };
			int len = 9;
			int expectedArray[2] = { 3, 3 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};

		
	};
}
