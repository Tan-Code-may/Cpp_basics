#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;
const int N=1e7;
vector<int> dp(N,-1);
int i;
int j;

// Macros
#define vi vector<int>
#define vp vector<pair<int,int>>
#define ll long long int
#define fi(i,a,b) for(i=a;i<b;i++)
#define fd(i,a,b) for(i=a;i>b;i--)
#define precise(x,y) cout << fixed << setprecision(y) << x 
#define pb push_back
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define vbe v.begin(), v.end()

int main()
{
	int n;
	cin>>n;
	vi v(n+1);
	vi nge(n+1,-1);
	stack<int> s;
	fi(i,1,n+1)
	{
		cin>>v[i];
		if(s.empty())
			s.push(i);
		else
		{
			while(s.empty()==0 && v[s.top()]<v[i])
			{
				nge[s.top()]= v[i];
				s.pop();
			}
			s.push(i);
		}
	}
	fi(i,1,n+1)
		cout<<v[i]<<" "<<nge[i]<<"\n";
	
	return 0;
}
