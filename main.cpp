//
//  main.cpp
//  lastRec
//
//  Created by Ty Wenrick on 4/29/22.
//
#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

// 9
void displayListIter(const list<int>& inputList){
    for (list<int>::const_iterator p = inputList.begin(); p != inputList.end(); ++p) {
        cout << *p << ' ';
    }
    cout << endl;
}

// 10
void displayListRanged(const list<int>& inputList) {
    for (int el : inputList) {
        cout << el << ' ';
    }
    cout << endl;
}

// 11
void displayEveryOther(const list<int>& inputList) {
    for (auto p = inputList.begin(); p != inputList.end(); ++++p) {
        cout << *p << ' ';
    }
    cout << endl;
}

// 12
list<int>::const_iterator findInList(const list<int>& inputList, int target) {
//    list<int>::const_iterator where = find(inputList.begin(), inputList.end(), target);
    for (list<int>::const_iterator p = inputList.begin(); p != inputList.end(); ++p) {
        if (*p == target) {
            return p;
        }
    }
    return inputList.end();
}

// 13
auto findInListAuto(const list<int>& inputList, int target) {
    //auto where = find(inputList.begin(), inputList.end(), target);
    for (auto p = inputList.begin(); p != inputList.end(); ++p) {
        if (*p == target) {
            return p;
        }
    }
    return inputList.end();
}

// 14
list<int>::const_iterator myFind(list<int>::const_iterator start, list<int>::const_iterator end, int target) {
    for (list<int>::const_iterator p = start; p != end; ++p) {
        if (*p == target) {
            return p;
        }
    }
    return end;
}

// 19
list<int>::iterator ourFind(list<int>::iterator start, list<int>::iterator end, int target) {
    cout << "looking in list ourFind" << endl;
    for (list<int>::iterator p = start; p != end; ++p) {
        if (*p == target) {
            return p;
        }
    }
    return end;
}

// 20
template <typename T, typename U>
T ourFind(T start, T end, U target) {
    cout << "looking in template" << endl;
    for (T p = start; p != end; ++p) {
        if (*p == target) {
            return p;
        }
    }
    return end;
}

// 16
bool isEven(int n) { return n % 2 == 0; }


class isEvenFunctor {
public:
    bool operator() (int n) const { return n % 2 == 0; }
};

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    
    vector<int> vec1 {5, 1, 3, 2, 4, 0};
    for (int el : vec1) {
        cout << el << ' ';
    }
    cout << endl;
    
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> list1(vec1.begin(), vec1.end());
    for (int el : list1) {
        cout << el << ' ';
    }
    cout << endl;
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(vec1.begin(), vec1.end());
    for (size_t i = 0; i < vec1.size(); ++i) {
        cout << vec1[i] << ' ';
    }
    cout << endl;
    
    cout << "\n=======\n";

    // 4. print every other element of the vector. ASSUMING the length is odd.
    cout << "Task 4:\n";
    for (size_t i=0; i < vec1.size(); i+=2) {
        cout << vec1[i] << ' ';
    }
    cout << endl;
    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    for (size_t i=0; i < list1.size(); i+=2) {
        // no sqaure bracket op for list
        //cout << list1[i] << ' ';
    }
    cout << endl;
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator p = vec1.begin(); p != vec1.end(); p+=2) {
        cout << *p << ' ';
    }
    cout << endl;
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator p = list1.begin(); p != list1.end(); ++++p) {
        cout << *p << ' ';
        // work around: increment again
    }
    cout << endl;
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    cout << "unsorted linked list: ";
    for (list<int>::iterator p = list1.begin(); p != list1.end(); ++p) {
        cout << *p << ' ';
    }
    cout << endl;
    
    list1.sort();
    
    cout << "sorted linked list: ";
    for (list<int>::iterator p = list1.begin(); p != list1.end(); ++p) {
        cout << *p << ' ';
    }
    cout << endl;
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    displayListIter(list1);
    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    displayListRanged(list1);
    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    displayEveryOther(list1);
    cout << "=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    list<int>::const_iterator val = findInList(list1, 5);
    if (val != list1.end()) {
        cout << "find val: "<< *val;
        cout << endl;
    } else {
        cout << "List does not contain target" << endl;
    }
    
    // test not in list
    list<int>::const_iterator val2 = findInList(list1, 7);
    if (val2 != list1.end()) {
        cout << "find val: "<< *val2;
        cout << endl;
    } else {
        cout << "List does not contain target" << endl;
    }
    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    auto val3 = findInListAuto(list1, 5);
    if (val3 != list1.end()) {
        cout << "find val using auto: "<< *val3;
        cout << endl;
    } else {
        cout << "List does not contain target" << endl;
    }
    
    auto val4 = findInListAuto(list1, 10);
    if (val4 != list1.end()) {
        cout << "find val using auto: "<< *val4;
        cout << endl;
    } else {
        cout << "List does not contain target" << endl;
    }
    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    auto val5 = myFind(list1.begin(), list1.end(), 2);
    if (val5 != list1.end()) cout << "Found: "  << *val5;
    else cout << "could not find value\n";
    cout << endl;
    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    auto val6 = find_if(list1.begin(), list1.end(), isEven);
    if (val6 != list1.end()) cout << "Found: " << *val6;
    else cout << "could not find an even value\n";
    cout << endl;
    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
    isEvenFunctor testEven;
    auto where2 = find_if(list1.begin(), list1.end(), testEven);
    if (where2 != list1.end()) cout << "Found: " << *where2;
    else cout << "could not find an even value\n";
    cout << endl;
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    auto where3 = find_if(list1.begin(), list1.end(), [](int n) { return n % 2 == 0; });
    if (where3 != list1.end()) cout << "Found: " << *where3;
    else cout << "could not find an even value\n";
    cout << endl;
    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* arr = new int[list1.size()];
    copy(list1.begin(), list1.end(), arr);
    auto where4 = find_if(arr, arr+list1.size(), [](int n) { return n % 2 == 0; });
    if (where4 != arr+list1.size()) cout << "Found: " << *where4;
    else cout << "could not find an even value\n";
    delete [] arr;
    cout << endl;
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    list<int>::const_iterator where5 = ourFind(list1.begin(), list1.end(), 3);
    if (where5 != list1.end()) cout << "Found: " << *where5;
    else cout << "could not find an target value in list\n";
    cout << endl;
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    vector<int>::const_iterator where6 = ourFind(vec1.begin(), vec1.end(), 5);
    if (where6 != vec1.end()) cout << "Found: " << *where6;
    else cout << "could not find an target value in vector\n";
    cout << endl;
    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    ifstream stream;
    stream.open("pooh_nopunc.txt");
    if (!stream) {
        cout << "Failed to open file\n";
        exit(1);
    }
    vector<string> tokens;
    string word;
    while(stream >> word) {
        vector<string>::iterator newWord = find(tokens.begin(), tokens.end(), word);
        if (newWord == tokens.end()) {
            tokens.push_back(word);
        }
    }
    stream.close();
    cout << "Tokens Size: " << tokens.size() << endl;
    cout << "Token Contents: " << endl;
    for (const string& el : tokens) {
        cout << el << ' ';
    }
    cout << endl;
    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    ifstream ifs;
    ifs.open("pooh_nopunc.txt");
    if (!ifs) {
        cout << "Failed to open file\n";
        exit(1);
    }
    set<string> tokens2;
    string token;
    while(ifs >> token) {
        tokens2.insert(token);
        
    }
    ifs.close();
    cout << "Tokens Size: " << tokens2.size() << endl;
    cout << "Token Contents: " << endl;
    for (const string& el : tokens2) {
        cout << el << ' ';
    }
    cout << endl;
    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    ifstream ifs2;
    ifs2.open("pooh_nopunc.txt");
    if (!ifs2) {
        cout << "Failed to open file\n";
        exit(1);
    }
    map<string,vector<int>> wordMap;
    string token3;
    int position = 0;
    while(ifs2 >> token3) {
        wordMap[token3].push_back(position);
        ++position;
    }
    ifs2.close();
    
    cout << wordMap.size() << endl;
    
    for (const auto& token: wordMap) {
        cout << token.first << ": ";
        for (auto i: token.second) {
            cout << i << ' ';
        }
        cout << endl;
    }

    
    cout << "=======\n";
    
}
