#include<bits/stdc++.h>
using namespace std;

// Implementation using binary search approach
// TC: O()

double power(double a,int n)
{
	double ans=1.0;
	while(n--)
		ans*=a;
	return ans;
}

void getNthRoot(int n,int m)
{
	double low=1;
	double high=n;
	double eps= 1e-6;
	while(high-low>eps)
	{
		double mid=(high+low)/2.0;
		if(power(mid,m)>n)
			high=mid;
		else
			low=mid;
	}
	cout<<low<<" "<<high;
}

int main()
{
	int t=1;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		getNthRoot(n,m);
		cout<<"\n";
	}
	
	return 0;
}