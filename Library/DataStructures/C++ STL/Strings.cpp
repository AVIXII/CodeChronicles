#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // Strings in cpp are mutable

    // Declaration and Initialisation in strings
    string a;
    a = "hello";
    string b = "hello world";
    string c("hello world");
    string d(5, 'a');

    // Input of Strings
    string inp;
    cin >> inp;        // inp will not include spaces
    getline(cin, inp); // inp will include any spaces in the string present in that line.
    cin.get();         // Used to get a white space from the console

    // Checking the length of strings.
    int sizeOfString = b.length();
    cout << "sizeOfString of: '" << b << "' is " << sizeOfString << endl;

    // Access character of a string
    char c = b[0];

    // Concatinate Strings
    string s1 = "abc";
    string s2 = "def";
    s1 = s1 + s2;

    // Clearing a string
    s1.clear();  // or s1 = ""

    // Comparing two strings - All the operators are internally overloaded to perform the functionality of comparison.
    s1.compare(s2);
    s1 <= s2;

    // Checking if the string is empty or not
    bool ans = s1.empty();

    // Substring of a string
    string a1 = "rishabh shital ramdhave";
    a1.substr(5, 6); // bh shi
    a1.substr(5);    // bh shital ramdhave

    // Find - .find()
    int pos = b.find("world"); // Can find a string or a character. If the string is not found, it returns value equal to "string::npos"
    cout << "pos" << pos << endl;

    // Inserting elements in a string
    string tst2 = "rishabh ramdhave";
    tst2.insert(8, "shital "); // rishabh shital ramdhave

    // Erasing elements from a string
    string tst1 = "rishabh shital ramdhave";
    tst1.erase(8, 7); // rishabh ramdhave

    // Replacing elements in a string
    string tst3 = "rishabh ramdhave";
    tst3.replace(0, 7, "samruddhi"); // samruddhi ramdhave

    // Push and pop from the string
    tst3.push_back('a'); // samruddhi ramdhavea
    tst3.pop_back();     // samruddhi ramdhave

    // Transform the string to uppercase
    string str = "hello world";
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "Uppercase: " << str << std::endl; // Output: HELLO WORLD
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "Lowercase: " << str << std::endl; // Output: hello world

    // Replace the occurences of a character with another character
    string s = "apples and bananas"; // Replace all 'a' with 'o'
    replace(s.begin(), s.end(), 'a', 'o');
    cout << s << endl; // Output: opples ond bononos

    /**
     * Common functions/methods for iterators in C++. Works on string, vector
     * .front()
     * .back()
     * sort()
     * reverse()
     * random_shuffle()
     * transform()
     *      for unary and binary operations
     *
     * accumulate()
     *      for sum, or other simple operations like multiply, divide, etc.
     * count()
     * find()
     * replace()
     *
     * NOTE: For strings, the find, count and replace functions will work for characters only not for finding or replacing substrings.
     * Hence, this may also be applicable in other places where we have to work with strings. Better to use inbuilt functions of
     * string class.
     *
     * min_element() -> Returns an iterator to the min_element of the container.
     * max_element() -> Returns an iterator to the max_element of the container.
     *
     * partial_sum() -> Returns a prefix sum of the range of integers.
     *
     */

    return 0;
}