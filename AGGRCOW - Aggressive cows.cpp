#include <iostream>
#include <algorithm>
using namespace std;


bool canPlaceCows(int stalls[], int n, int c, int distance) {
    int count = 1; 
    int lastPosition = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPosition >= distance) {
            count++; 
            lastPosition = stalls[i];
            if (count == c) {
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(int stalls[], int n, int c) {
    sort(stalls, stalls + n);

    int low = 1; 
    int high = stalls[n - 1] - stalls[0]; 
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlaceCows(stalls, n, c, mid)) {
            result = mid; 
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        int stalls[n];
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        cout << aggressiveCows(stalls, n, c) << endl;
    }
    return 0;
}
