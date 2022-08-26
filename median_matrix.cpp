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
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pb push_back
#define inf INT_MAX
#define vbe v.begin(), v.end()
#define mii map<int,int>
#define pii pair<int,int>
#define edl "\n"
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
#define google(i) cout<<"Case #"<<i<<": "
#define precise(x,y) cout << fixed << setprecision(y) << x 
#define print(a) for(auto &x : a){cout<<x<<" ";} cout<<"\n"
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
bool perfectSqr(int n) {if(floor(sqrt(n))==ceil(sqrt(n))) return true; else return false;}
// v.assign(n,x); -> used to assign x value to initial n elements of a vector v.

// Inbuilt C++ STL upper_bound(vbe,val) - v.begin() function can also be used.
int upperBound(vector<int> &v,int val){
	int low=0;
	int high=v.size()-1;
	while(low<=high){
		int mid=(high+low)/2;
		if(v[mid]<=val)
			low=mid+1;
		else
			high=mid-1;
	}
	return low;
}

int getSmallerThanMid(vvi &v,int mid){
	int ans=0;
	int n=v.size();
	fi(i,0,n){
		ans+=upperBound(v[i],mid);
	}
	return ans;
}

//TC: O(32*n*log(m))
int getMedian(vvi &v){
	int low=0;
	int high=inf;
	int size=v.size()*v[0].size();
	while(low<=high){
		int mid=(low+high)/2;
		int ct=getSmallerThanMid(v,mid);
		if(ct<=size/2)
			low=mid+1;
		else
			high=mid-1;
	}
	return low;
}

int main()
{
	speed
	int n,m;
	cin>>n>>m;
	vvi v(n,vi (m));
	fi(i,0,n)
		fi(j,0,m)
			cin>>v[i][j];
	cout<<getMedian(v)<<edl;

	return 0;
}
