#include <bits/stdc++.h>
using namespace std;


// everything is constant inside a set, hence this function is const and the arguments are constant references
struct Comparator {
    bool operator()(const int &a, const int &b) const {
        return a < b;
    }
};

int main(int argc, char const *argv[]) {
    // declare a vector
    vector<int> vec({10,20,30,40,50});
    set<int, Comparator> s(vec.begin(), vec.end());
    
    // a custom function can be used to define the order of the elements 
    // set<int, greater<int>> s(vec.begin(), vec.end());

    // s = 10,20,30,40,50
    
    s.erase(50);
    s.insert(0);
    
    // s = 0,10,20,30,40
    
    // set<int>::iterator it;
    // set<int>::reverse_iterator rit;
    for(auto it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << " "; // 40,30,20,10,0
    }
    
    // printing from a particular element as a set is ordered
    for (auto it = s.find(20); it != s.end(); ++it) {
        cout << *it << " "; // 20,30,40
    }
    
    // lower bound = any number which is not before the given number in the set
    // upper bound = any number which is after the given number in the set
    cout << *(s.lower_bound(10)) << " " << *(s.lower_bound(-5)) << " " << *(s.upper_bound(5)) << endl;
    
}