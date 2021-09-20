#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define mod 998244353
#define pb push_back  
#define endl "\n"
#define fi first
#define se second 
#define ll long long
#define inf 9000000000000000000
#define PI 3.14159265359
 

vector<int> add_biginteger(vector<int>x,vector<int>y)
{
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	
	int length = min(x.size(),y.size());
	
	int carry=0;
	vector<int>answer;
	for(int i = 0 ; i < length ; i++)
	{
		int value = x[i] + y[i] + carry;
		carry = value/10;
		answer.pb(value%10); 
	}
	if(x.size() > length)
	{
		for(int i = length ; i < x.size() ; i++)
		{
		    int value = x[i] + carry;
		    carry = value/10;
		    answer.pb(value%10); 
		}
	}
	else if(y.size() > length)
	{
		for(int i = length ; i < y.size() ; i++)
		{
		    int value = y[i] + carry;
		    carry = value/10;
		    answer.pb(value%10); 
		}
	}
	while(carry > 0)
	{
		answer.pb(carry%10);
		carry = carry/10;
	}
	reverse(answer.begin(),answer.end());
	return answer;
}

vector<int> subtraction(vector<int>x,vector<int>y)
{
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	
	int length = y.size();
	vector<int>ans;
	for(int i = 0 ; i < y.size() ; i++)
	{
		if(x[i] < y[i])
		{
			x[i+1]--;
			ans.pb(10 + x[i] - y[i]);
		}
		else
		{
			ans.pb(x[i] - y[i]);
		}
	}
	if(x.size() > length)
	{
		for(int i = length ; i < x.size() ; i++)
		{
			if(x[i] < 0)
			{
				x[i+1]--;
				ans.pb(10 + x[i]);
			}
			else
			{
				ans.pb(x[i]);
			}
		}
	}
	vector<int>result;
	int i=0;
	reverse(ans.begin(),ans.end());
	while(ans[i] == 0)
	{
		i++;
	}
	for( ; i < ans.size() ; i++)
	{
		result.pb(ans[i]);
	}
	return result;
}

vector<int> divisionby2(vector<int>x)
{
	vector<int>ans;
	int remainder = 0;
	for(int i = 0 ; i < x.size() ; i++)
	{
		if(remainder == 0)
		{
			if(x[i] < 2)
			{
				remainder = remainder + x[i];
				ans.pb(0);
			}
			else
			{
				remainder = x[i]%2;
				ans.pb(x[i]/2);
			}
		}
		else
		{
			remainder = 10*remainder + x[i];
			ans.pb(remainder/2);
			remainder = remainder%2;
		}
	}
	vector<int>result;
	int i=0;
	while(ans[i] == 0)
	{
		i++;
	}
	for(; i < ans.size() ; i++)
	{
		result.pb(ans[i]);
	}
	return result;
}

void multiply(vector<int>&ans,int number)
{
	int carry = 0;
	
	for(int i=0 ; i < ans.size() ; i++)
	{
		int product =  (ans[i]*1LL*number) + carry;
		carry = product/10;
		ans[i] = product%10;
	}
	while(carry > 0)
	{
		ans.pb(carry%10);
		carry = carry/10;
	}
}
vector<int> factorial(int n)
{
	vector<int>ans;
	
	ans.pb(1);
	
	for(int i = 2 ; i <= n ; i++)
	{
		multiply(ans,i);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int32_t main()
{
   IOS
  
   string a,b;
   cin>>a>>b;
   
   vector<int>v1,v2;
   
   for(int i = 0 ; i < a.size() ; i++)
   {
   	v1.pb(a[i]-'0');
   }
   for(int i=0 ; i < b.size() ; i++)
   {
   	v2.pb(b[i]-'0');
   }
   
   vector<int>sum = add_biginteger(v1,v2);
   
   for(int i = 0 ; i < sum.size() ; i++)
   {
   	cout<<sum[i];
   }
   cout<<endl;
   
   vector<int>subtract = subtraction(v1,v2);
   
   for(int i = 0 ; i < subtract.size() ; i++)
   {
   	cout<<subtract[i];
   }
   cout<<endl;
    
   vector<int>fact = factorial(16);
   
   for(int i = 0 ; i < fact.size() ; i++)
   {
   	cout<<fact[i];
   }
   cout<<endl;

   vector<int>divide = divisionby2(v1);
   
   for(int i = 0; i < divide.size() ; i++)
   {
   	cout<<divide[i];
   }
   cout<<endl;  
   
}
