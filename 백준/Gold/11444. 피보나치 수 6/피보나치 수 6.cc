#include <iostream>
#include <vector>
#define mod 1000000007

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix operator*(matrix& a, matrix& b) {
    matrix tmp(2, vector<ll>(2));
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < 2; j ++) {
            for(int k = 0; k < 2; k ++) {
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= mod;
        }
    }
    
    return tmp;
}

int main() {
    ll n;
    cin >> n;
    matrix res = {{1, 0}, {0, 1}};
    matrix a = {{1, 1}, {1, 0}};
    while(n > 0) {
        if(n % 2) {
            res = res * a;
        }
        a = a * a;
        n /= 2;
    }
    cout << res[1][0];
    return 0;
}