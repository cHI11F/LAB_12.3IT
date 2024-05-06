#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.3/LAB_12.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestDeleteNode)
		{
			// Arrange
			int values[] = { 1, 2, 3, 4, 5 };
			int size = sizeof(values) / sizeof(values[0]);
			Node* head = createList(values, size);

			// Act
			head = deleteNode(head, 3); // Видалення вузла зі значенням 3

			// Assert
			Assert::AreEqual(head->next->data, 2); // Перевірка, чи наступний вузол після першого вузла має значення 4

			// Cleanup
			deleteList(head);
		}

		TEST_METHOD(TestDeleteFirstNode)
		{
			// Arrange
			int values[] = { 1, 2, 3, 4, 5 };
			int size = sizeof(values) / sizeof(values[0]);
			Node* head = createList(values, size);

			// Act
			head = deleteNode(head, 1); // Видалення першого вузла зі значенням 1

			// Assert
			Assert::AreEqual(head->data, 2); // Перевірка, чи новий початковий вузол має значення 2

			// Cleanup
			deleteList(head);
		}

		TEST_METHOD(TestDeleteLastNode)
		{
			// Arrange
			int values[] = { 1, 2, 3, 4, 5 };
			int size = sizeof(values) / sizeof(values[0]);
			Node* head = createList(values, size);

			// Act
			head = deleteNode(head, 5); // Видалення останнього вузла зі значенням 5

			// Assert
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			Assert::IsNull(current->next); // Перевірка, чи останній вузол тепер пустий

			// Cleanup
			deleteList(head);
		}

		TEST_METHOD(TestDeleteNonExistingNode)
		{
			// Arrange
			int values[] = { 1, 2, 3, 4, 5 };
			int size = sizeof(values) / sizeof(values[0]);
			Node* head = createList(values, size);

			// Act
			head = deleteNode(head, 6); // Видалення вузла зі значенням 6, якого немає у списку

			// Assert
			Assert::IsNotNull(head); // Перевірка, чи головний вузол не є пустим

			// Cleanup
			deleteList(head);
		}
	};
}
