#if !defined(LINKED_LIST_H)
#define LINKED_LIST_H

#include <iostream>

namespace lists {

	template<typename T>
	class singly_linked_list {

		struct  node
		{
			T data;
			node* next;

			node() : data(NULL), next(nullptr) {}
			node(T value) : data(value), next(nullptr) {}
		};

	private:
		node* head;

	public:
		singly_linked_list(): head(nullptr) {}
		
		void append(T value) {
			node* temp = new node(value);
			// case where the list is empty, set the head to the new node.
			if (head == nullptr) {
				head = temp;
				return;
			}
			node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = temp;
		}

		void insert(T value) {
			node* temp = new node(value);
			// case where list is empty
			if (head == nullptr) {
				head = temp;
				return;
			}
			temp->next = head;
			head = temp;
		}

		bool is_empty() const { return head == nullptr;  }

		void print_list() const {
			// special output for an empty list
			if (head == nullptr) {
				std::cout << "The list is empty." << std::endl;
				return;
			}
			std::cout << "The list contains: ";
			node* temp = head;
			while (temp != nullptr) {
				std::cout << temp->data << " ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}

		// custom iterator
		struct iter
		{
			node* m_ptr;
			// iterator constructor
			iter(node* ptr): m_ptr(ptr) {}
			node& operator*() const { return *m_ptr; }
			node* operator->() const { return m_ptr; }

			iter& operator++() {
				m_ptr = m_ptr->next;
				return *this;
			}

			bool operator==(const iter& other) { return m_ptr == other.m_ptr; }
			bool operator!=(const iter& other) { return m_ptr != other.m_ptr; }
		};

		iter begin() { return iter(head);}
		iter end() { return nullptr; }
	};

	template<typename T>
	class doubly_linked_list {

		struct node {
			T data;
			node* next;
			node* previous;

			node(): data(NULL), next(nullptr), previous(nullptr) {}
			node(T value): data(value), next(nullptr), previous(nullptr) {}
		};

	private:
		node* head;
		node* tail;

	public:
		doubly_linked_list(): head(nullptr), tail(nullptr) {}

		void append(T value) {
			node* temp = new node(value);
			// case where list is empty;
			if (head == nullptr && tail == nullptr) {
				head = temp;
				tail = temp;
				return;
			}
			// make the tail point to the new node, the new nodes previous is the tail and finally set the new node to be the tail
			tail->next = temp;
			temp->previous = tail;
			tail = temp;
		}

		void insert(T value) {
			node* temp = new node(value);
			// case where list is empty;
			if (head == nullptr && tail == nullptr) {
				head = temp;
				tail = temp;
				return;
			}
			// make the head's previous the new node, the head is the new nodes next, and finally the new node is the head
			temp->next = head;
			head->previous = temp;
			head = temp;
		}

		bool is_empty() const { return head == nullptr; }

		void print_list() const{
			// special output for an empty list
			if (head == nullptr) {
				std::cout << "The list is empty." << std::endl;
				return;
			}
			std::cout << "The list contains: ";
			node* temp = head;
			while (temp != nullptr) {
				std::cout << temp->data << " ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}

		struct iter {
			node* m_ptr;
			iter(node* ptr): m_ptr(ptr){}
			node& operator*() const { return *m_ptr; }
			node* operator->() const { return m_ptr; }

			iter& operator++() {
				m_ptr = m_ptr->next;
				return *this;
			}

			iter& operator--() {
				m_ptr = m_ptr->previous;
				return *this;
			}

			bool operator==(const iter& other) { return m_ptr == other.m_ptr; }
			bool operator!=(const iter& other) { return m_ptr != other.m_ptr; }
		};

		iter begin() { return iter(head); }
		iter end() { return nullptr; }
		iter rbegin() { return iter(tail); }
		iter rend() { return nullptr; }
	};
}


#endif
