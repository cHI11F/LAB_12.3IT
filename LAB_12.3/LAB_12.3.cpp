#include <iostream>
#include <Windows.h>
using namespace std;

// Структура, що представляє вузол двунаправленого списку
struct Node {
    int data;     // Дані вузла
    Node* prev;   // Вказівник на попередній вузол
    Node* next;   // Вказівник на наступний вузол
};

// Функція для створення двунаправленого списку на основі масиву значень
Node* createList(int values[], int size) {
    Node* head = nullptr;  // Початковий вузол
    Node* tail = nullptr;  // Кінцевий вузол

    // Прохід по масиву значень
    for (int i = 0; i < size; i++) {
        // Створення нового вузла
        Node* newNode = new Node();
        newNode->data = values[i];  // Присвоєння значення вузлу
        newNode->prev = nullptr;    // Початкове значення вказівника на попередній вузол
        newNode->next = nullptr;    // Початкове значення вказівника на наступний вузол

        // Перевірка, чи це перший вузол у списку
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;  // Додавання нового вузла після кінцевого вузла
            newNode->prev = tail;  // Встановлення посилання на попередній вузол для нового вузла
            tail = newNode;        // Встановлення нового вузла як кінцевого
        }
    }

    return head;  // Повернення посилання на початковий вузол
}

// Функція для вилучення вузла зі списку
Node* deleteNode(Node* head, int valueToDelete) {
    Node* current = head;

    // Прохід по усіх вузлах у списку
    while (current != nullptr) {
        if (current->data == valueToDelete) { // Якщо значення поточного вузла співпадає зі значенням для видалення
            Node* prevNode = current->prev;
            Node* nextNode = current->next;

            // Перевірка, чи поточний вузол не є початковим
            if (prevNode != nullptr)
                prevNode->next = nextNode;
            else
                head = nextNode;

            // Перевірка, чи поточний вузол не є кінцевим
            if (nextNode != nullptr)
                nextNode->prev = prevNode;

            delete current; // Звільнення пам'яті, що була виділена для поточного вузла
            break; // Вихід з циклу після видалення вузла
        }
        current = current->next; // Перехід до наступного вузла
    }

    return head;
}

// Функція для виведення значень усіх вузлів у списку
void printList(Node* head) {
    Node* current = head;  // Початковий вузол

    // Прохід по усіх вузлах у списку
    while (current != nullptr) {
        cout << current->data << " ";  // Виведення значення поточного вузла
        current = current->next;       // Перехід до наступного вузла
    }

    cout << endl;  // Виведення символу нового рядка в кінці списку
}

// Функція для видалення всього списку та звільнення пам'яті
void deleteList(Node* head) {
    Node* current = head;  // Початковий вузол

    // Прохід по усіх вузлах у списку
    while (current != nullptr) {
        Node* temp = current;      // Тимчасовий вказівник на поточний вузол
        current = current->next;   // Перехід до наступного вузла
        delete temp;               // Звільнення пам'яті, що була виділена для поточного вузла
    }
}

int main() {

    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // Масив значень для створення списку
    int size = sizeof(values) / sizeof(values[0]);  // Розмір масиву

    Node* head = createList(values, size);  // Створення двунаправленого списку

    cout << "Список елементів:" << endl;
    printList(head);  // Виведення елементів списку

    int valueToDelete;
    cout << "Введіть значення для видалення: ";
    cin >> valueToDelete;

    head = deleteNode(head, valueToDelete); // Видалення вузла зі списку

    cout << "Список після видалення:" << endl;
    printList(head);  // Виведення елементів списку після видалення

    deleteList(head);  // Видалення списку та звільнення пам'яті

    return 0;
}
