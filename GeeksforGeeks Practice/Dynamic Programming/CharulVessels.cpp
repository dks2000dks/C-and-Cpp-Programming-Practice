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

int Compute(vector<int> &v, int Cap){
    int n = v.size();

    vec1d(dp,int,Cap+1,0);
    dp[0] = 1;

    fr(i,1,Cap){
        fr(j,0,n-1){
            if (i-v[j] >=0){
                dp[i] = dp[i] || dp[i-v[j]];
            }
        }
    }
    return dp[Cap];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,Cap;
        cin >> n >> Cap;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cout << Compute(v,Cap) << endl;
    }
}