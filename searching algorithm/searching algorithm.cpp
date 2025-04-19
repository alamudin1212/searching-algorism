
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

// Exponential Search
int expSearch(vector<int>& arr, int x) {
    if (arr[0] == x) return 0;
    int i = 1;
    while (i < arr.size() && arr[i] <= x) i *= 2;
    int low = i/2, high = min(i, (int)arr.size()-1);
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (arr[mid] == x) return mid;
        arr[mid] < x ? low = mid+1 : high = mid-1;
    }
    return -1;
}

// Jump Search
int jumpSearch(vector<int>& arr, int x) {
    int step = sqrt(arr.size()), prev = 0;
    while (arr[min(step, (int)arr.size())-1] < x) {
        prev = step;
        step += sqrt(arr.size());
        if (prev >= arr.size()) return -1;
    }
    while (arr[prev] < x) {
        if (++prev == min(step, (int)arr.size())) return -1;
    }
    return arr[prev] == x ? prev : -1;
}

// Hash Search
int hashSearch(unordered_map<int,int>& map, int x) {
    return map.count(x) ? map[x] : -1;
}

int main() {
    vector<int> arr = {10,20,30,40,50,60,70,80,90};
    unordered_map<int,int> hashMap = {{10,0},{20,1},{30,2}};
    
    cout << "Exponential: " << expSearch(arr, 60) << endl;
    cout << "Jump: " << jumpSearch(arr, 60) << endl;
    cout << "Hash: " << hashSearch(hashMap, 20) << endl;
    
    return 0;
}