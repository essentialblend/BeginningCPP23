/*Ex 17-4: Define a template for a linked list type that allows the list to be traversed in both directions, meaning backward from the end of the list as well as forward from the beginning. Naturally, you should use the iterator design pattern you learned about in Chapter 12 for this (see also exercises 12-7 and 12-8). 

To keep things simple, elements stored in the list cannot be modified while traversing the list. elements can be added using push_front() and push_back() to use member names analogous to those of standard library containers. also add clear(), empty(), and size() functions that do the same as those of standard containers (see Chapters 5 and 20). 

Apply the template to a program that stores individual words from some arbitrary prose or poetry as std::string objects in a linked list and then displays them five to a line, in sequence and in reverse order */

import std;

import doublylinkedlist;

int main()
{
    std::string text;                            // Stores input prose or poem
    std::println("Enter a poem or prose over one or more lines.\n"
        "Terminate the input with #:");
    getline(std::cin, text, '#');

    LinkedList<std::string> words;               // List to store words

    // Extract words and store in the list
    std::string_view separators{ " ,.\"?!;:\n" };// Separators between words
    std::size_t start{};                        // Start of a word
    std::size_t end{};                          // separator position after a word
    while (std::string::npos != (start = text.find_first_not_of(separators, start)))
    {
        end = text.find_first_of(separators, start + 1);
        words.pushBack(text.substr(start, end - start));
        start = end;
    }

    // List the words 5 to a line
    std::println("\nThe words are:\n");
    auto iterator{ words.iterateFromHead() };
    std::size_t count{};            // Word counter
    const std::size_t perline{ 5 };   // Worde per line
    while (iterator.hasValue())
    {
        std::print("{} ", iterator.value());
        if (!(++count % perline))
            std::println("");
        iterator.next();
    }
    std::println("");

    // List the words in reverse order 5 to a line
    std::println("\nIn reverse order, the words are:\n");
    iterator = words.iterateFromTail();
    count = 0;
    while (iterator.hasValue())
    {
        std::print("{} ", iterator.value());
        if (!(++count % perline))
            std::println("");
        iterator.previous();
    }
    std::println("");
    
    return 0;
}