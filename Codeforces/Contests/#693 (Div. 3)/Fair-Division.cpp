#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <string>
#include <math.h>
#include <float.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

bool Subset(vector<int> v, int sum){
    int n = v.size();
    vec2d(dp,bool,n+1,sum+1,false);

    fr(i,0,n){
        dp[i][0] = true;
    }

    fr(i,1,sum){
        dp[0][i] = false;
    }

    fr(i,1,n){
        fr(j,1,sum){
            if (j < v[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
        }
    }
    return dp[n][sum];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        int sum = accumulate(v.begin(),v.end(),0);
        if (sum%2 != 0){
            cout << "NO" << endl;
        }
        else{
            sum = sum/2;
            if (Subset(v,sum)){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}