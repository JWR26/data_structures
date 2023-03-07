#if !defined(QUEUES)
#define QUEUES

// To allow printing to the console
#include <iostream>

namespace queues {

	template<typename T>
	class standard_queue {
		struct element {
			T value;
			element* next;

			element() : value(NULL), next(nullptr) {}
			element(T v) : value(v), next(nullptr) {}
		};

	private:
		element* head;
		element* tail;
	
	public:
		standard_queue() : head(nullptr), tail(nullptr) {}

		bool empty() const { return head == nullptr; }

		int size() const {
			element* current = head;
			int size = 0;
			while (current != nullptr) {
				++size;
				current = current->next;
			}
			return size;
		}

		T& front() const {
			return head->value;
		}

		T& back() const {
			return tail->value;
		}

		void push(const T& val) {
			std::cout << "Pushing " << val << "..." << std::endl;
			element* temp = new element(val);
			// case where list is empty;
			if (head == nullptr) {
				head = temp;
				tail = temp;
				return;
			}
			tail->next = temp;
			tail = temp;
		}
		// pop
		void pop() {
			element* temp = head;
			std::cout << "Popping " << temp->value << "..." << std::endl;
			head = head->next;
			delete temp;
		}

		// print queue
		void print() const {
			if (head == nullptr) {
				std::cout << "The Standard Queue is empty." << std::endl;
				return;
			}

			std::cout << "The Standard Queue contains: ";
			element* temp = head;
			while (temp != nullptr) {
				std::cout << temp->value << " ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
	};

	//template<typename T>
	//class double_ended_queue {
	//	// size
	//	// resize
	//	// empty
	//	
	//	
	//	// interator

	//};

	//template<typename T>
	//class priority_queue {
	//	// empty
	//	// size
	//	// push
	//	// pop
	//	// top
	//};

}



#endif