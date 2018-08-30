#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
ll cal(int n) {
    ll res = 1;
    for(int i = 0; i < n; i++) {
        res = res * 10;
    }
    return res;
}
ll num = 1000000007;
int main() {
    int n;
    cin >> n;
    ll arr[n + 1];
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            arr[i] = 10;
        } else if (i == 2) {
            arr[i] = 100;
        } else if (i >= 3) {
            for (int j = 2; j <= i - 1; j++) {
                arr[i] = (arr[j - 1] + arr[i - j]) % num;
            }
            arr[i] = (cal(i)  + arr[i - 2]) % num;
        }
    }
    cout << arr[n] << endl;
    return 0;
}
