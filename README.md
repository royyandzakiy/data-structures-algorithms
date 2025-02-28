# Data Structures and Algorithms in C++

a space for me to train and implement different data structures and algorithms

---

## C++ Cheatsheet

## Includes
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits> // For INT_MAX, INT_MIN
#include <numeric> // For accumulate

using namespace std;
```

## String
```cpp
string s = "Hellow";
s.length();
s.size();

char sChar = s[0];
string sub = s.substr(startIndex, length); // length is optional

// search
int pos = s.find("world"); // Returns string::npos if not found
if (pos != string::npos) {
    // Found
}

// reverse
reverse(s.begin(), s.end());

// conversion
int num = stoi(s);
string str = to_string(num);

// checking
char c = 'a';
if (isalpha(c)) { // Check if alphabet
}
if (isdigit(c)) { // Check if digit
}
if (islower(c)) { // Check if lowercase
}
if (isupper(c)) { // Check if uppercase
}
c = tolower(c);
c = toupper(c);
```

## Data Types
```cpp
// ======= vectors ======= 
vector<int> nums;
nums.push_back(1);
nums.pop_back();
int size = nums.size();
nums[0] = 5;
// Iterate
for (int num : nums) {
    // ...
}
//2D vector
vector<vector<int>> matrix;

// ======= hash maps ======= 
unordered_map<int, int> map;
map[1] = 10;
if (map.count(1)) { // Check if key exists
    int value = map[1];
}
for (auto const& [key, val] : map) {
    // ...
}

// ======= hash sets ======= 
unordered_set<int> set;
set.insert(5);
if (set.count(5)) {
    // ...
}
// ======= stack (LIFO) ======= 
stack<int> st;
st.push(1);
int top = st.top();
st.pop();
if (st.empty()) {
    // ...
}

// ======= queue (FIFO) ======= 
queue<int> q;
q.push(1);
int front = q.front();
q.pop();
if (q.empty()) {
    // ...
}

// ======= priority queue (Heaps) ======= 
// Max heap
priority_queue<int> maxHeap;
// Min heap
priority_queue<int, vector<int>, greater<int>> minHeap;
maxHeap.push(5);
int top = maxHeap.top();
maxHeap.pop();
```

## Math
```cpp
int maximum = max(a,b);
int minimum = min(a,b);
int power = pow(a,b);
int squareRoot = sqrt(a);
int sum = accumulate(nums.begin(), nums.end(), 0); //Sum of all elements.
```

## Algorithms
```cpp
// sorting
sort(nums.begin(), nums.end()); // Ascending
sort(nums.begin(), nums.end(), greater<int>()); // Descending

// binary search
int target = 5;
auto it = lower_bound(nums.begin(), nums.end(), target); // Returns iterator
if (it != nums.end() && *it == target) {
    // Found
}

// two pointers
int left = 0, right = nums.size() - 1;
while (left < right) {
    // ...
    if (condition) {
        left++;
    } else {
        right--;
    }
}

// sliding window
int left = 0, right = 0;
while (right < nums.size()) {
    // ...
    while (condition) {
        // ...
        left++;
    }
    right++;
}

// recursion/backtracking
void backtrack(vector<int>& path, vector<vector<int>>& result) {
    if (baseCase) {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < choices.size(); i++) {
        // ...
        path.push_back(choice);
        backtrack(path, result);
        path.pop_back(); // Undo choice
    }
}
```