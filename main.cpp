// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This file is lesson 0.12 "testing your compiler fo C++17 compatibility.
//

#include <iostream>

#include "lists.h"
#include "queues.h"


void list_demo() {
    std::cout << "Creating a singly linked list of integers..." << std::endl;

    lists::singly_linked_list<int> my_int_list;

    // use std::boolalpha to print "true" or "false" and not "1" or "0".
    std::cout << "Is List Empty: " << std::boolalpha << my_int_list.is_empty() << std::endl;
    // call print_list on an empty list
    my_int_list.print_list();
    std::cout << "Append some elements to the list" << std::endl;
    // insert an element in the list
    my_int_list.append(1);
    my_int_list.append(8);
    my_int_list.append(6);
    my_int_list.append(3);
    std::cout << "Is List Empty: " << std::boolalpha << my_int_list.is_empty() << std::endl;
    // print the list
    my_int_list.print_list();
    std::cout << "Insert some elements at the front of list" << std::endl;
    my_int_list.insert(9);
    my_int_list.insert(7);
    my_int_list.insert(4);
    // print the updated list
    my_int_list.print_list();
    std::cout << "Iterate using a range-based for loop" << std::endl;
    // now print the list using a for range loop
    for (const auto& item : my_int_list) {
        std::cout << item.data << std::endl;
    }
    std::cout << "------------------" << std::endl;

    std::cout << "Creating a doubly linked list of chars..." << std::endl;

    lists::doubly_linked_list<char> my_char_list;

    std::cout << "Is List Empty: " << std::boolalpha << my_char_list.is_empty() << std::endl;

    my_char_list.print_list();
    std::cout << "Append some elements to the list" << std::endl;

    my_char_list.append('W');
    my_char_list.append('o');
    my_char_list.append('r');
    my_char_list.append('l');
    my_char_list.append('d');

    std::cout << "Is List Empty: " << std::boolalpha << my_char_list.is_empty() << std::endl;
    my_char_list.print_list();

    std::cout << "Insert some elements at the front of list" << std::endl;
    my_char_list.insert(' ');
    my_char_list.insert('o');
    my_char_list.insert('l');
    my_char_list.insert('l');
    my_char_list.insert('e');
    my_char_list.insert('H');
    my_char_list.print_list();

    std::cout << "Iterate using a range-based for loop" << std::endl;
    for (const auto& item : my_char_list) {
        std::cout << item.data << std::endl;
    }

    std::cout << "Forward iteration using a standard for loop" << std::endl;
    for (auto it = my_char_list.begin(); it != my_char_list.end(); ++it) {
        std::cout << it->data << std::endl;
    }

    std::cout << "Backward iteration using a standard for loop" << std::endl;
    for (auto it = my_char_list.rbegin(); it != my_char_list.rend(); --it) {
        std::cout << it->data << std::endl;
    }

}


void standard_queue_demo() {
    queues::standard_queue<int> my_int_queue;
    std::cout << "Created a standard FIFO queue for integers." << std::endl;

    std::cout << "Is Queue Empty: " << std::boolalpha << my_int_queue.empty() << ". Size: " << my_int_queue.size() << std::endl;
    std::cout << std::endl;

    std::cout << "Push elements..." << std::endl;
    my_int_queue.push(1);
    my_int_queue.print();
    my_int_queue.push(2);
    my_int_queue.print();
    my_int_queue.push(3);
    my_int_queue.print();
    std::cout << std::endl;

    std::cout << "Is Queue Empty: " << std::boolalpha << my_int_queue.empty() << ". Size: " << my_int_queue.size() << std::endl;
    std::cout << std::endl;

    std::cout << "Pop elements..." << std::endl;
    my_int_queue.pop();
    my_int_queue.print();
    my_int_queue.pop();
    my_int_queue.print();
    my_int_queue.pop();
    my_int_queue.print();
    std::cout << std::endl;

    std::cout << "Push some more elements..." << std::endl;
    my_int_queue.push(4);
    my_int_queue.push(5);
    my_int_queue.push(6);
    my_int_queue.print();
    std::cout << std::endl;

    std::cout << "The front element in the queue is: " << my_int_queue.front() << std::endl;
    std::cout << "The back element in the queue is: " << my_int_queue.back() << std::endl;
    std::cout << std::endl;

    std::cout << "Push and pop elements..." << std::endl;
    my_int_queue.push(7);
    my_int_queue.pop();
    my_int_queue.push(8);
    my_int_queue.pop();
    my_int_queue.print();
    std::cout << std::endl;

    std::cout << "The front element in the queue is: " << my_int_queue.front() << std::endl;
    std::cout << "The back element in the queue is: " << my_int_queue.back() << std::endl;
    std::cout << std::endl;
}



int main()
{
    // lists
    //list_demo();

    // queues
    standard_queue_demo();


    return 0;
}

