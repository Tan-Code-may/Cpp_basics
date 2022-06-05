#include <bits/stdc++.h>
using namespace std;

int main()
{
    // INPUT AND OUTPUT
    // string s;
    // Both of them are correct methods to take input of a string
    // getline(cin, s);
    // cin>>s;
    // cout << s;

    // CONCATENATION (USING APPEND)
    // string s1 = "fam";
    // string s2 = "ily";
    // s1.append(s2);
    // cout << s1 << endl;

    // CONCATENATION (BETTER METHOD)
    // string s1 = "fam";
    // string s2 = "ily";
    // cout << s1 + s2 << endl;
    // s1 = s1 + s2;
    // cout << s1 << endl;
    // cout << s2 << endl;
    // cout << s1[2] << endl;

    // COMPARING STRINGS
    // string str1 = "abc";
    // string str2 = "xyz";
    // if (str1.compare(str2) == 0)
    //     cout << "Strings are equal" << endl;
    // else
    //     cout << "Not equal" << endl;

    // if (!str1.compare(str2)) // Whenever we equate something with zero(0), such a code can be used as zero means false.
    //     cout << "Strings are equal" << endl;
    // else
    //     cout << "Not equal" << endl;

    // Empty string
    // string s = "hello user";
    // cout << s << endl;

    // s.clear();
    // if ( s.empty()) //It will return 1 if string is empty and 0 if it isn't
    //     cout << "String is empty" << endl;

    // Erase function
    //     string s = "nincompoop"; // foolish person
    //     s.erase(3, 4);           // focus on the arguments of the function
    //     cout << s << endl;

    // find function
    // string s = "nincompoop";
    // cout << s.find("poop") << endl;

    // insert function
    // string s = "Hello user";
    // s.insert(3, "lol");
    // cout << s << endl;
    // s.erase(3, 3);
    // s.insert(5, "lol");
    // cout << s << endl;
    // s.erase(5, 3);
    // s.insert(6, "lol");
    // cout << s << endl;

    // SIZE OF A STRING
    // The size() function is consistent with other STL containers (like vector, map, etc.) and length() is consistent with most
    // peoples intuitive notion of character strings like a word, sentence or paragraph. We say a paragraph's length not its size,
    // so length() is to make things more readable.
    // string s = "Hello user";
    // cout << s.size()<< endl;
    // for (int i = 0; i < s.length(); i++)
    //     cout << s[i] << endl;

    // SUBSTRING
    // string s = "nincompoop";
    // string s1 = s.substr(6, 4);
    // cout << s1 << endl;

    // STRING TO INTEGER AND INTEGER TO STRING
    string s = "780";
    int n = stoi(s);
    cout << n + 2 << endl;
    cout << to_string(n) + "2" << endl;

    // Sorting a string using #include<algorithm> header file
    // string s1 = "acfnsubvubnuhdg";
    // sort(s1.begin(), s1.end());
    // cout << s1 << endl;
}
