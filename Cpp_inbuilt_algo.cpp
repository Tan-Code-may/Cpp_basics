#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];

	// All these functions are working in the same way as they
	// used to when we implement them normally, i.e., most of
	// them have O(n) as TC, except that 'count' and 'find'
	// function will have log(n) as TC only in case of maps and
	// sets.

	int min = *min_element(v.begin(), v.end());
	cout<<min<<"\n";
	
	int max = *max_element(v.begin(), v.end());
	cout<<max<<"\n";
	
	// Both max and min functions returns a pointer, hence we
	// need to dereference them in order to print them.

	auto it = find(v.begin(), v.end(), 9);
	if(it != v.end())
		cout<<*it<<"\n";
	else
		cout<<"Element not found\n";
	// This function returns an iterator in case of vectors
	// and a pointer in case of arrays of the element that
	// need to be found.

	reverse(v.begin(), v.end());
	for(auto val:v)
		cout<<val<<" ";
	cout<<"\n";

	string s="aauhiaerngaej";
	reverse(s.begin() + 1, s.end());
	cout<<s<<"\n";

	// reverse() function is quite useful as it can reverse
	// an array, a vector or a string in a single line of code.

	//Lambda Functions-  short way to define any function.
	auto add = [](int x, int y){return x+y;};
	cout<< add(12,23) <<"\n";
	// Lambda functions can simple be assigned to a variable
	// by using 'auto' and can be called as normal functions.

	vector<int> a = {1,3,-2,-5,42};

	// All these 3 functions returns a bool value.
	cout<< all_of(a.begin(), a.end(),[](int x){return x>0;})<<"\n";
	// returns 1 if all the elements of the vector satisfies
	// the given function.

	cout<< any_of(a.begin(), a.end(),[](int x){return x>0;})<<"\n";
	// returns 1 if any one of the element of the vector
	// satisfies the given function.

	cout<< none_of(a.begin(), a.end(),[](int x){return x>0;})<<"\n";
	// returns 1 if none of the elements of the vector satisfies
	// the given function.

	// These functions also work for arrays, we only need to
	// change 'a.begin()' with 'a' and 'a.end()' with 'a+n'.
	
	return 0;
} 
