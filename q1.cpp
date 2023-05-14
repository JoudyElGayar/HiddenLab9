#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
private:
    vector<list<int> > table;
    int size;

public:
    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hash(key);
        table[index].push_back(key);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "]: ";
            for (int element : table[i]) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<int> array;
    array.push_back(1);
    array.push_back(4);
    array.push_back(7);
    array.push_back(1);
    array.push_back(5);
    array.push_back(2);
    array.push_back(4);
    array.push_back(1);
    array.push_back(3);
    array.push_back(5);

    int size = array.size();

    HashTable hashTable(size);

    for (int element : array) {
        hashTable.insert(element);
    }

    hashTable.display();

    return 0;
}
