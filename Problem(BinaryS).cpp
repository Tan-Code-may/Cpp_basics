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

//Problem link: https://www.youtube.com/watch?v=gYmWHvRHu-s&list=PLgUwDviBIf0qYbL4TBaEWgb-ljVdhkM7R&index=8

ll solve()
{
	int n,k;
	cin>>n>>k;
	vi v(n);
	fi(i,0,n)
		cin>>v[i];
	ll sum=accumulate(vbe,0);
	cout<<sum<<edl;
	ll low=v[0];
	ll high=sum;
	while(low<=high){
		ll mid=(high+low)>>1;
		int part_sum=0,ct=1;
		fi(i,0,n){
			part_sum+=v[i];
			if(part_sum>mid){
				ct++;
				part_sum=v[i];
			}
			if(ct>k)
				break;
		}
		if(ct>k)
			low=mid+1;
		else
			high=mid-1;
	}
	return low;
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
