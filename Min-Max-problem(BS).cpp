#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;
const int N=1e7;
vector<int> dp(N,-1);
int i;
int j;
 
// Macros
#define ll long long int
#define fi(i,a,b) for(i=a;i<b;i++)
#define fd(i,a,b) for(i=a;i>b;i--)
#define ff first
#define ss second
#define edl "\n"
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pb push_back
#define inf INT_MAX
#define vbe v.begin(), v.end()
#define mii map<int,int>
#define umii unordered_map<int,int>
#define pii pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
#define google(i) cout<<"Case #"<<i<<": "
#define precise(x,y) cout << fixed << setprecision(y) << x
#define print(a) for(auto &x : a){cout<<x<<" ";} cout<<"\n"
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
bool perfectSqr(int n) {if(floor(sqrt(n))==ceil(sqrt(n))) return true; else return false;}

// Problem Link: https://www.spoj.com/problems/AGGRCOW/
// Binary Search Min-Max problem.

int solve()
{
	int n,c;
	cin>>n>>c;
	vi v(n);
	fi(i,0,n)
		cin>>v[i];
	sort(vbe);
	
	//Search space
	int low=v[1]-v[0];
	int high=v[n-1]-v[0];

	//Binary Search implementation
	while(low<=high){
		int mid=(high+low)>>1;
		int ct=1,x=v[0];
		fi(i,0,n){
			if(v[i]-x>=mid){
				ct++;
				x=v[i];
			}
			if(ct==c)
				break;
		}
		if(ct<c)
			high=mid-1;
		else
			low=mid+1;
	}

	return high;
}

int main()
{
	speed
	int t=1;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		//google(i+1);
		cout<<solve()<<edl;
	}
	return 0;
}
