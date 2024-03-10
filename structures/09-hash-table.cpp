#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable {
    
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups];

    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const{
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups;
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& bucket = table[hashValue];
    auto itr = begin(bucket);
    bool keyExists = false;
    for (; itr != end(bucket); itr++) {
        if (itr->first == key) {
            keyExists = true;
            itr->second = value;
            cout << "[WARNING] Key exists. Value replaced." << "\n";
            break;
        }
    }
    if (!keyExists) {
        cout << "[INFO] Pair added successfully." << "\n";
        bucket.emplace_back(key, value);
    }
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& bucket = table[hashValue];
    auto itr = begin(bucket);
    bool keyExists = false;
    for (; itr != end(bucket); itr++) {
        if (itr->first == key) {
            keyExists = true;
            itr = bucket.erase(itr);
            cout << "[INFO] Pair removed." << "\n";
            break;
        }
    }
    if (!keyExists) {
        cout << "[WARNING] Key not found. Pair not removed." << "\n";
    }
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto itr = table[i].begin();
        for (; itr != table[i].end(); itr++) {
            cout << "[INFO] Key: " << itr->first << " Value: " << itr->second << "\n";
        }
    }
}

string HashTable::searchTable(int key) {
    int hashValue = hashFunction(key);
    auto& bucket = table[hashValue];
    auto itr = begin(bucket);
    bool keyExists = false;
    for (; itr != end(bucket); itr++) {
        if (itr->first == key) {
            keyExists = true;
            return "Value: " + itr->second;
        }
    }
    if (!keyExists) {
        cout << "[WARNING] Key not found. Pair not removed." << "\n";
    }
    return "[WARNING] Invalid Key.";
}

int main() {
    HashTable H1;

    if (H1.isEmpty()) {
        cout << "Hash Table is currently empty." << "\n";
    }
    cout << "\n";

    H1.insertItem(117, "John");
    H1.insertItem(118, "Jane");
    H1.insertItem(127, "Smith");
    H1.insertItem(124, "Shane");
    H1.insertItem(122, "Sandy");
    H1.insertItem(108, "Sally");
    H1.insertItem(324, "Tim");
    H1.insertItem(125, "Tina");
    H1.insertItem(125, "Tom");
    cout << "\n";

    H1.printTable();
    cout << "\n";

    cout << H1.searchTable(122) << "\n";
    cout << "\n";

    H1.removeItem(122);
    H1.removeItem(200);
    cout << "\n";

    cout << H1.searchTable(122) << "\n";
    cout << "\n";

    if (!H1.isEmpty()) {
        cout << "Hash Table implemented successfully." << "\n";
    }

    return 0;
}