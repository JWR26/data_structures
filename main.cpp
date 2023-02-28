// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This file is lesson 0.12 "testing your compiler fo C++17 compatibility.
//

#include <iostream>

#include "lists.h"

int main()
{
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


    return 0;
}

