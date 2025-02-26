#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "rishabh";
    s.replace(0, s.length(), "ahdskfa ");
    cout << s << endl;

    // to_string() O(log(n))
    // Convert to string
    string intStr = to_string(42);          // "42"
    string floatStr = to_string(3.141590);  // "3.141590"
    string doubleStr = to_string(2.718280); // "2.718280"

    // Display results
    cout << "Integer as string: " << intStr << endl;
    cout << "Float as string: " << floatStr << endl;
    cout << "Double as string: " << doubleStr << endl;

    return 0;
}