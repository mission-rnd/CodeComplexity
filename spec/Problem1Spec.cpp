#include "stdafx.h"
#include "../src/Problem1.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem1Spec
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

		struct charNode * createNode_Spec(char l) {
			struct charNode *newNode = (struct charNode *)malloc(sizeof(struct charNode));
			newNode->letter = l;
			newNode->next = NULL;
			return newNode;
		}

		struct charNode * createSLLFromString(char *str){
			int len = 0;
			int i = 0;
			while (str[i] != '\0'){
				len++;
				i++;
			}
			struct charNode *head=NULL;
			struct charNode *temp = NULL;
			i = 0;
			while (i < len){
				struct charNode *tempNode = createNode_Spec(str[i]);
				if (head){
					temp->next = tempNode;
					temp = tempNode;
				}
				else{
					head = tempNode;
					temp = tempNode;
				}
				i++;
			}
			temp->next = NULL;
			return head;
		}
		[TestMethod]
		void Sample1_Problem1()
		{
			int actualAns = isDivisibleSLL(NULL,1);
			Assert::AreEqual(-1, actualAns, L"Failed for Invalid case P1", 1, 2);

		};

		[TestMethod]
		void Sample2_Problem1()
		{

			char str[100] = "+1234";
			int key = 5;
			int expectedAns = 1;
			struct charNode *head = createSLLFromString(str);
			int actualAns = isDivisibleSLL(head, key);
			Assert::AreEqual(expectedAns, actualAns, L"Failed  P1", 1, 2);
		};

		[TestMethod , Timeout(1000)]
		void Sample3_Problem1()
		{

			char str[100] = "-1234";
			int key = 6;
			int expectedAns = 0;
			struct charNode *head = createSLLFromString(str);
			int actualAns = isDivisibleSLL(head, key);
			Assert::AreEqual(expectedAns, actualAns, L"Failed  P1", 1, 2);
		};

	};
}
