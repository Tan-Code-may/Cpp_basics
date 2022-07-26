#include <bits/stdc++.h>
using namespace std;

int main()
{
    // In maps, unique key-value pairs are stored.
    // They are always stored in sorted form with respect to key.(For ex. Strings are stored in lexicographical order if they are passed as key)
	// Maps are not necessarily alloted continous memory locations.
	// Internally implementation of maps takes place using 'Red-black trees', and that is why the TC of all the operations of maps is O(log(n)).

    map<int,string> m;
    m[3]="abd";
    m[1]="sfd";

    // This operation is also considered as insertion and it inserts empty string for string and 0 for int.
    m[5];
    
    // Both insertion and accessing a pair from a map takes O(log n) TC, n = m.size().
    m.insert({7,"njsid"});

    //Printing key-value pairs of map using 'auto' keyword.
    for(auto &pr: m)
    	cout<< pr.first<<" "<<pr.second<<"\n";
 
    // Prints the size of a map.
    cout<<m.size()<<"\n";

    // m.find() returns an iterator to the key-value pair whose key is passed as an argument.
    // If no pair is present corresponding to the key passed, then the function returns m.end().
    // TC- O(log n)
    auto it= m.find(3); 

    if(it==m.end())
    	cout<<"No value\n";
    else
    	cout<<it->first<<" "<<it->second<<"\n";

    // Two possible arguments for m.erase() -> 1. Key, 2. Iterator.
    // TC- O(log n)
    if(it != m.end())
    	m.erase(it);
    
    //Uses to remove all the elements from a map or any other STL container like vector, set, pair etc.
    m.clear();
    
    // TC of operation also depends on the keys.
    // TC -> s.size() * log(n).
    // As in order to insert this in the map comparision between each of the characters of the string will also take place, so that this key-value pair
    // is inserted in sorted manner. Now, this will also consume some time, depending upon the length of the key string.
    map<string,string> ms;
    ms["gnofejas"] = "bgdafjks";

    return 0;
}
