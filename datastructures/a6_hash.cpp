//Chaining hash table
#include <iostream>
#include <list>
#include <string>
#include <utility>
using namespace std;

class chainingHashTable
{
    int size;
    list<pair<string, int>> *table;
    public:
    chainingHashTable(int s)
    {
        size = s;
        table = new list<pair<string, int>>[size];
    }

    ~chainingHashTable(){
        delete [] table;
    }
    void insert(string key, int value)
    {
        int index = hashFunction(key);
        table[index].push_back(make_pair(key, value));
    }
    int hashFunction(string key)
    {
        int index = 0;
        for (int i = 0; i < key.length(); i++)
        {
            index += key[i];
        }
        return index % size;
    }
    int search(string key)
    {
        int index = hashFunction(key);
        for (auto x : table[index])
        {
            if (x.first == key)
            {
                return x.second;
            }
        }
        return -1;
    }
};   

int main()
{
    chainingHashTable h(7); 
    h.insert("mango", 100);
    h.insert("apple", 200);
    h.insert("banana", 300);
    h.insert("orange", 400);
    h.insert("pineapple", 500);
    h.insert("grape", 600); 

    cout << h.search("apple") << endl;
    cout << h.search("mango") << endl;
    cout << h.search("banana") << endl;
    cout << h.search("grape") << endl;
    cout << h.search("orange") << endl;
    cout << h.search("pineapple") << endl;
    cout << h.search("kiwi") << endl;
    return 0;
}