#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> Frequent(vector<int>& nums, int k) {

    // COUNT FREQUENT

    unordered_map<int, int> Map;
    for (int num : nums) {
        Map[num]++;
    }

    // MIN HEAP FOR K

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    
    for (auto i = Map.begin(); i != Map.end(); ++i) {
        minHeap.push({ i->second, i->first });

        // Maintain the size of the heap to k
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // MIN HEAP EXCTRACT

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    // REVERSE

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int ary;
    cout << "ENTER NUMBER OF ELEMENTS : ";
    cin >> ary;

    vector<int> num(ary);
   
    for (int i = 0; i < ary; ++i) {
        cin >> num[i];
    }

    int k;
    cout << "ENTER K VALUE : ";
    cin >> k;

    vector<int> ans = Frequent(num, k);

    cout << "TOP " << k << " FREQUENT NUM : ";
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}
