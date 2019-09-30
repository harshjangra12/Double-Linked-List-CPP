#include <iostream>
using namespace std;

struct Element {
	Element* next{};
	Element* previous{};
	void insertAfter(Element* next_element) {
		next_element->next = next;
		next = next_element;
	}
	void insertBefore(Element* previous_element) {
		previous_element->previous = previous;
		previous = previous_element;
	}

	char prefix[2];
	int operator_number;
};

int main() {
	Element trooper1, trooper2, trooper3;
	trooper1.prefix[0] = 'K';
	trooper1.prefix[1] = 'O';
	trooper1.operator_number = 7;
	trooper1.insertAfter(&trooper2);
	trooper2.prefix[0] = 'I';
	trooper2.prefix[1] = 'O';
	trooper2.operator_number = 8;
	trooper2.insertAfter(&trooper3);
	trooper3.prefix[0] = 'M';
	trooper3.prefix[1] = 'O';
	trooper3.operator_number = 9;
	trooper3.insertBefore(&trooper2);
	trooper2.insertBefore(&trooper1);

	for (Element* cursor = &trooper1; cursor; cursor = cursor->next) {
		cout << "Stromtrooper " << cursor->prefix[0] << cursor->prefix[1] << "-" << cursor->operator_number << endl;
	}

	for (Element* cursor = &trooper3; cursor; cursor = cursor->previous) {
		cout << "Stromtrooper " << cursor->prefix[0] << cursor->prefix[1] << "-" << cursor->operator_number << endl;
	}
}