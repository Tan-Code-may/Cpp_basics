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

// // 1. Printing all the subsequences of an array using recursion.
// // TC- O(2^N)

// vi ans;
// void solve(int ind,int n, vi &v)
// {	
// 	//Base Condition
// 	if(ind>=n) {
// 		print(ans);
// 		return;
// 	}
	
// 	//Recursively calling the function
// 	ans.pb(v[ind]);
// 	solve(ind+1,n,v);
// 	ans.pop_back();
// 	solve(ind+1,n,v);
// }

// int main()
// {
// 	speed
// 	int t=1;
// 	//cin>>t;
// 	for(int j=0;j<t;j++)
// 	{
// 		//google(i+1);
// 		int n;
// 		cin>>n;
// 		vi v(n);
// 		fi(i,0,n){
// 			cin>>v[i];
// 		}
// 		solve(0,n,v);
// 	}
// 	return 0;
// }

// 2. Printing only the subsequences which have the given sum. (All of them)
// TC: O(2^N)

// vi ans;
// int sum=0;
// void solve(int ind,int n, vi &v,int sum_req)
// {	
// 	//Base Condition
// 	if(ind>=n){
// 		if(sum==sum_req){
// 			print(ans);
// 		}
// 		return;
// 	}
	
// 	//Recursively calling the function
// 	ans.pb(v[ind]);
// 	sum+=v[ind];
// 	solve(ind+1,n,v,sum_req);

// 	sum-=v[ind];
// 	ans.pop_back();
// 	solve(ind+1,n,v,sum_req);
// }

// int main()
// {
// 	speed
// 	int t=1;
// 	//cin>>t;
// 	for(int j=0;j<t;j++)
// 	{
// 		//google(i+1);
// 		int n,sum_req;
// 		cin>>n>>sum_req;
// 		vi v(n);
// 		fi(i,0,n){
// 			cin>>v[i];
// 		}
// 		solve(0,n,v,sum_req);
// 	}
// 	return 0;
// }

// 2. Printing only the subsequence which has the given sum. (Only the first one) -> IMPORTANT -> How the recursion is breaked 
// on the first encounter of the required subS. (Avoid using the flag concept in this as it will increase the TC)
// TC: O(2^N) (Worst Case)
vi ans;
int sum=0;
bool solve(int ind,int n, vi &v,int sum_req)
{	
	//Base Condition
	if(ind>=n){
		if(sum==sum_req){
			print(ans);
			return true;
		}
		return false;
	}
	
	//Recursively calling the function
	ans.pb(v[ind]);
	sum+=v[ind];
	if(solve(ind+1,n,v,sum_req)==true) return true;

	sum-=v[ind];
	ans.pop_back();
	if(solve(ind+1,n,v,sum_req)==true) return true;
	return false;
}

int main()
{
	speed
	int t=1;
	//cin>>t;
	for(int j=0;j<t;j++)
	{
		//google(i+1);
		int n,sum_req;
		cin>>n>>sum_req;
		vi v(n);
		fi(i,0,n){
			cin>>v[i];
		}
		solve(0,n,v,sum_req);
	}
	return 0;
}
