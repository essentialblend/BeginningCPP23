/*Ex 18-2: Another class that desperately needs to be upgraded with moving capabilities is the LinkedList<> template you defined for exercise 17-5. It could even do with more brushing up than just the two special move members. Can you tell what else would be needed for a modern LinkedList<> type? Write a quick program that demonstrates the newly added moving capabilities.*/
import std;

import dll;

int main()
{
    DLL<std::string> list;

    // Test adding elements
    list.pushBack("World");
    list.pushFront("Hello");

    // Test size
    std::cout << "Size after adding two elements: " << list.getSize() << std::endl;

    // Test iteration from head to tail
    std::cout << "Iterating from head to tail: ";
    for (auto it = list.iterHead(); it.hasValue(); it.next()) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;

    // Test iteration from tail to head
    std::cout << "Iterating from tail to head: ";
    for (auto it = list.iterTail(); it.hasValue(); it.previous()) {
        std::cout << it.value() << " ";
    }
    std::cout << std::endl;

    // Test removal
    list.popFront();
    std::cout << "Size after popping front: " << list.getSize() << std::endl;
    list.popBack();
    std::cout << "Size after popping back: " << list.getSize() << std::endl;

    // Test clear
    list.pushBack("Clear");
    list.pushBack("Test");
    list.clearList();
    std::cout << "Size after clear: " << list.getSize() << std::endl;

    // Test swap
    DLL<std::string> list2;
    list2.pushBack("Swap");
    list2.pushBack("Test");
    list2.pushBack("Third");
    std::cout << "Before swap, list2 size: " << list2.getSize() << ", list size: " << list.getSize() << std::endl;
    list.swap(list2);
    std::cout << "After swap, list2 size: " << list2.getSize() << ", list size: " << list.getSize() << std::endl;

    list = std::move(list2);
    std::println("Elements in list 1: {}", list.getSize());
    std::println("Elements in list 2: {}", list2.getSize());

    return 0;
}