#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "..\Student\Person.h"

namespace PersonTest
{		
	TEST_CLASS(PersonTest)
	{
	public:
		
        ///
        /// Check whether the interface returns empty
        /// strings for name and phone on empty objects
        ///
        TEST_METHOD(Person_EmptyObject)
        {
            Person empty;

            Assert::AreEqual(empty.GetName(), "");
            Assert::AreEqual(empty.GetPhone(), "");
        }


        ///
        /// Check whether the copy constructor and assignment
        /// operator work correctly
        ///
		TEST_METHOD(Person_Copying)
		{
            Person original("John Smith", "1234567");

            Person copied(original);
            Assert::AreEqual(original.GetName(), copied.GetName());
            Assert::AreEqual(original.GetPhone(), copied.GetPhone());

            copied = original;
            Assert::AreEqual(original.GetName(), copied.GetName());
            Assert::AreEqual(original.GetPhone(), copied.GetPhone());
		}


		///
		/// Check whether the comparison operator works correctly
		///
		TEST_METHOD(Person_Compare)
		{
			Person original("John Smith", "1234567");
			Person copy(original);
			
			Assert::IsTrue(original == copy);
			Assert::IsTrue(copy == original); // should be commutative

			Person empty1, empty2;

			Assert::IsTrue(empty1 == empty2);

			Assert::IsFalse(empty1 == original);
			Assert::IsFalse(original == empty1);
		}

	};
}