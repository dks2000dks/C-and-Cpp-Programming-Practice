#include<iostream>
#include<cmath>
#include <cassert>
#include<algorithm>
#include <cstdlib>
#include<vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include<string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int BinarySearch(vector<int> v, int l, int r, int search){
	if (l>r)
		return -1;
	else{
		int m = (l+r)/2;
		if (v[m] == search)
			return m;
		else if (v[m] < search)
			return BinarySearch(v,m+1,r,search);
		else
			return BinarySearch(v,l,m-1,search);
	}
	return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        int s;
        cin >> s;
        cout << BinarySearch(v,0,n-1,s) << endl;
    }
}