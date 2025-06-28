#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP
#include <bits/stdc++.h>
// #define __debug_stream() cout

inline std::ofstream& __debug_stream() {
    static std::ofstream out("debug.txt");
    return out;
}

namespace __DEBUG_UTIL__
{
using namespace std;
/* Primitive Datatypes Print */
void print(const char *x) { __debug_stream() << x; }
void print(bool x) { __debug_stream() << (x ? "T" : "F"); }
void print(char x) { __debug_stream() << '\'' << x << '\''; }
void print(signed short int x) { __debug_stream() << x; }
void print(unsigned short int x) { __debug_stream() << x; }
void print(signed int x) { __debug_stream() << x; }
void print(unsigned int x) { __debug_stream() << x; }
void print(signed long int x) { __debug_stream() << x; }
void print(unsigned long int x) { __debug_stream() << x; }
void print(signed long long int x) { __debug_stream() << x; }
void print(unsigned long long int x) { __debug_stream() << x; }
void print(float x) { __debug_stream() << x; }
void print(double x) { __debug_stream() << x; }
void print(long double x) { __debug_stream() << x; }
void print(string x) { __debug_stream() << '\"' << x << '\"'; }
template <size_t N>
void print(bitset<N> x) { __debug_stream() << x; }
void print(vector<bool> v)
{   /* Overloaded this because stl optimizes vector<bool> by using
        _Bit_reference instead of bool to conserve space. */
    int f = 0;
    __debug_stream() << '{';
    for (auto && i : v)
        __debug_stream() << (f++ ? "," : "") << (i ? "T" : "F");
    __debug_stream() << "}";
}
/* Templates Declarations to support nested datatypes */
template <typename T>
void print(T &&x);
template <typename T>
void print(vector<vector<T>> mat);
template <typename T, size_t N, size_t M>
void print(T (&mat)[N][M]);
template <typename F, typename S>
void print(pair<F, S> x);
template <typename T, size_t N>
struct Tuple;
template <typename T>
struct Tuple<T, 1>;
template <typename... Args>
void print(tuple<Args...> t);
template <typename... T>
void print(priority_queue<T...> pq);
template <typename T>
void print(stack<T> st);
template <typename T>
void print(queue<T> q);
/* Template Datatypes Definitions */
template <typename T>
void print(T &&x)
{
    /*  This works for every container that supports range-based loop
        i.e. vector, set, map, oset, omap, dequeue */
    int f = 0;
    __debug_stream() << '{';
    for (auto && i : x)
        __debug_stream() << (f++ ? "," : ""), print(i);
    __debug_stream() << "}";
}
template <typename T>
void print(vector<vector<T>> mat)
{
    int f = 0;
    __debug_stream() << "\n~~~~~\n";
    for (auto && i : mat)
    {
        __debug_stream() << setw(2) << left << f++, print(i), __debug_stream() << "\n";
    }
    __debug_stream() << "~~~~~\n";
}
template <typename T, size_t N, size_t M>
void print(T (&mat)[N][M])
{
    int f = 0;
    __debug_stream() << "\n~~~~~\n";
    for (auto && i : mat)
    {
        __debug_stream() << setw(2) << left << f++, print(i), __debug_stream() << "\n";
    }
    __debug_stream() << "~~~~~\n";
}
template <typename F, typename S>
void print(pair<F, S> x)
{
    __debug_stream() << '(';
    print(x.first);
    __debug_stream() << ',';
    print(x.second);
    __debug_stream() << ')';
}
template <typename T, size_t N>
struct Tuple
{
    static void printTuple(T t)
    {
        Tuple < T, N - 1 >::printTuple(t);
        __debug_stream() << ",", print(get < N - 1 > (t));
    }
};
template <typename T>
struct Tuple<T, 1>
{
    static void printTuple(T t) { print(get<0>(t)); }
};
template <typename... Args>
void print(tuple<Args...> t)
{
    __debug_stream() << "(";
    Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
    __debug_stream() << ")";
}
template <typename... T>
void print(priority_queue<T...> pq)
{
    int f = 0;
    __debug_stream() << '{';
    while (!pq.empty())
        __debug_stream() << (f++ ? "," : ""), print(pq.top()), pq.pop();
    __debug_stream() << "}";
}
template <typename T>
void print(stack<T> st)
{
    int f = 0;
    __debug_stream() << '{';
    while (!st.empty())
        __debug_stream() << (f++ ? "," : ""), print(st.top()), st.pop();
    __debug_stream() << "}";
}
template <typename T>
void print(queue<T> q)
{
    int f = 0;
    __debug_stream() << '{';
    while (!q.empty())
        __debug_stream() << (f++ ? "," : ""), print(q.front()), q.pop();
    __debug_stream() << "}";
}
/* Printer functions */
void printer(const char *) {} /* Base Recursive */
template <typename T, typename... V>
void printer(const char *names, T &&head, V &&...tail)
{
    /* Using && to capture both lvalues and rvalues */
    int i = 0;
    for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
        if (names[i] == '(' or names[i] == '<' or names[i] == '{')
            bracket++;
        else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
            bracket--;
    __debug_stream().write(names, i) << " = ";
    print(head);
    if (sizeof...(tail))
        __debug_stream() << " ||", printer(names + i + 1, tail...);
    else
        __debug_stream() << "]\n";
}
/* PrinterArr */
void printerArr(const char *) {} /* Base Recursive */
template <typename T, typename... V>
void printerArr(const char *names, T arr[], size_t N, V... tail)
{
    size_t ind = 0;
    for (; names[ind] and names[ind] != ','; ind++)
        __debug_stream() << names[ind];
    for (ind++; names[ind] and names[ind] != ','; ind++)
        ;
    __debug_stream() << " = {";
    for (size_t i = 0; i < N; i++)
        __debug_stream() << (i ? "," : ""), print(arr[i]);
    __debug_stream() << "}";
    if (sizeof...(tail))
        __debug_stream() << " ||", printerArr(names + ind + 1, tail...);
    else
        __debug_stream() << "]\n";
}
}

#define debug(...) __debug_stream() << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) __debug_stream() << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#endif