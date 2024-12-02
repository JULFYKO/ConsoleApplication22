#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> v1;
    vector<int> v2(10, 0);
    vector<int> v3;
    vector<int> v4;
    vector<int> v5;

    int n;
    cout << "Enter the number of elements for v1: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        v1.push_back(val);
    }

    cout << "Enter the size of v3: ";
    cin >> n;
    v3.resize(n);
    srand(static_cast<unsigned>(time(nullptr)));
    for (int& elem : v3) {
        elem = rand() % 100;
    }

    v4 = v1;
    if (v3.size() > 2) {
        v5.assign(v3.begin() + 1, v3.end() - 1);
    }

    cout << "v3 elements: ";
    for (const int& elem : v3) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "v1 elements in reverse order: ";
    for (auto it = v1.rbegin(); it != v1.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; ++i) {
        v2[i] = i + 1;
    }

    std::random_shuffle(v2.begin(), v2.end());
    if (v2.size() > 1) {
        v2.erase(v2.begin() + 1);
    }
    if (!v2.empty()) {
        v2.pop_back();
    }

    cout << "v2 elements after shuffle and erase: ";
    for (const int& elem : v2) {
        cout << elem << " ";
    }
    cout << endl;

    vector<int> doubledV4;
    for (const int& elem : v4) {
        doubledV4.push_back(elem);
        doubledV4.push_back(elem);
    }
    v4 = doubledV4;

    v5.clear();
    for (const int& elem : v4) {
        if (elem % 2 == 0) {
            v5.push_back(elem / 2);
        }
    }

    cout << "v5 after processing: ";
    for (const int& elem : v5) {
        cout << elem << " ";
    }
    cout << endl;

    int target;
    cout << "Enter a value to find in v5: ";
    cin >> target;

    cout << "Positions of " << target << " in v5: ";
    int count = 0;
    for (auto it = v5.begin(); it != v5.end(); ++it) {
        if (*it == target) {
            cout << (it - v5.begin()) << " ";
            ++count;
        }
    }
    cout << endl;

    cout << "Count of " << target << " in v5: " << count << endl;

    std::swap(v4, v5);

    cout << "v4 after swap: ";
    for (const int& elem : v4) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "v5 after swap: ";
    for (const int& elem : v5) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
