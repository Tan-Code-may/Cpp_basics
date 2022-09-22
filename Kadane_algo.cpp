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
bool perfectSqr(int n) {if(floor(sqrt(n))==ceil(sqrt(n))) return true; else return false;

// TO FIND THE SUBARRAY WITH MAXIMUM SUM.


// Brute force
// TC: O(N^3)
int brute_solve(vi &v)
{	
	int n=v.size(),ans=0;
	fi(i,0,n){
		fi(j,i,n){
			int temp_sum=0,k;
			fi(k,i,j+1){
				temp_sum+=v[k];
			}
			ans=max(ans,temp_sum);
		}
	}
	return ans;
}


// Better Approach
// TC: O(N^2)
int better_solve(vi &v)
{	
	int n=v.size(),ans=0;
	fi(i,0,n){
		int temp_sum=0;
		fi(j,i,n){
			temp_sum+=v[j];
			ans=max(ans,temp_sum);
		}
	}
	return ans;
}


// Best Approach (Kadane's Algorithm)
// TC: O(N)
int kadane_solve(vi &v)
{	
	int n=v.size();
	int sum=0,max_sum=INT_MIN;
	fi(i,0,n){
		sum+=v[i];
		if(max_sum<sum)
			max_sum=sum;
		if(sum<0)
			sum=0;
	}
	return max_sum;
}
                        

int main()
{
	speed
	int t=1;
	//cin>>t;
	for(int j=0;j<t;j++)
	{
		int n;
		cin>>n;
		vi v(n);
		fi(i,0,n){
			cin>>v[i];
		}
		//cout<<brute_solve(v)<<edl;
                //cout<<better_solve(v)<<edl;
                 cout<<kadane_solve(v)<<edl;
	}
	return 0;
}
