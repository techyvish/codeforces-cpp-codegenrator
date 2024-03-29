//
//  main.cpp
//  Codeforces
//
//  Created by Vishal Patel on 9/09/2014.
//  Copyright (c) 2014 Vishal Patel. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <unistd.h>
#include <climits>
#include <list>
#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

// CUT begin
ifstream data("/Users/Shared/Algorithms/AlgorithmTutorials/input.txt");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(string sizes,long long __answer) {
    Squres *instance = new Squres();
    long long __result = instance->getRequiredTiles(sizes);
    delete instance;
    if (__answer == __result ) {
        cout << "PASSED!" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << endl;
        cout << "           Expected: " << to_string(__answer) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
    return true;
}
int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    // skip first four lines.
    next_line();
    next_line();
    next_line();
    next_line();
    while (true) {
        if (next_line().find("input") != 0)
            break;
        //start writing here
        string sizes;
        from_stream(sizes);
        next_line();
        long long __answer;
        from_stream(__answer);
        cases++;
        cout << "  Testcase #" << cases - 1 << " ... ";
        if( do_test(sizes,__answer)) {
            passed++;
        }
        //end writing here
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    cout << "Start testing" << endl << endl << endl;
    return run_test(mainProcess, cases, argv[0]);
}
