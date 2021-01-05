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

void Print_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int Compute(vector<int> &v, int n){
    vec1d(dp,int,n,0);

    br(i,n-1,0){
        if (v[i] + i > n-1)
            dp[i] = v[i];
        else{
            dp[i] = v[i] + dp[v[i] + i];
        }
    }
    return *max_element(dp.begin(),dp.end());
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cout << Compute(v,n) << endl;
    }
}