#include<bits/stdc++.h>
#include <windows.h>
using namespace std;
class Node {
public:
    string key;       // Custom Class containing the key of the data stored and the value
    int value;

    Node() {           //default constructor creates a new Node with key as empty String                
        key = "";       // default value of a node is 0    
        value = 0;
    }
    Node(string key, int value) {
        this->key = key;             // parameterized constructor
        this->value = value;
    }

};
class LRUCache {
private:
    const size_t maxSize;                                 // custom size of the cache
    list <Node> l;                                       // list to hold nodes in the Cache at any given time (Size of the list always lesser or equal to MaxSize) 
    unordered_map<string, list <Node> ::iterator>um;     // a hashmap for faster (O(1) on average) lookup of a key 

public:

    LRUCache() :maxSize(0) {                             // default constructor creates LRUCache of 0 size
    }

    LRUCache(size_t s) :maxSize(s) {                    // parametrized constructor Creates LRUCache of size s
    }

    void insertKeyValue(string key, int val) {        //Inserts a Key Value pair to the LRUCache  If Cache is full, least Recently UsedKey will be be deleted and new key will be inserted

        if (um.count(key) != 0) {                       //If a key is already present, its value will be updated

            list <Node>::iterator it = um[key];
            it->value = val;
        }
        else {                                            //Key is Not present in The cache

            if (l.size() == maxSize) {                      //Cache is Full 

                um.erase(l.back().key);                  //deleted entry of LRU pair     
                l.pop_back();                            //delete the LRU key value pair from Cache
            }

            Node n(key, val);
            l.push_front(n);                         //Key value added to Cache as MRU pair
            list <Node>::iterator it = l.begin();
            um[key] = it;                              // Address of new pair being added to Cache hashmaps


        }

    }

    int* getKeyValue(string key) {

        if (um.count(key) != 0) {                    //key exists in the cache

            list<Node>::iterator it = um[key];     //pointer to node in the list
            int val = it->value;
            l.push_front(*it);                   //insert node by value to front of the list
            //same as making the kv pair MRU key value pair
            l.erase(it);                         //remove the node from the original position
            um[key] = l.begin();
            return &l.begin()->value;            //return value of the key
        }

        return nullptr;

    }

    string mostRecent() {
        if (l.size() == 0) return "ERR";
        return l.begin()->key;
    }
};
int main() {


    cout << "\n\n-----------------------WELCOME TO YOUR OWN LRU Cache-------------------------" << endl << endl << endl;
    cout << "Please set size of LRU cache (1-10^5)" << endl << endl;

    int s;
    cout << "Enter the size of LRU cache : ";
    cin >> s;
    while (cin.fail()){
        std::cout << "Error \nEnter again : " << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> s;
    }
    cout << endl;
    
    while (s < 1 || s>100000 ) {
        cout << "Invalid -- please choose a size between 1 and 10^5" << endl;
        cout << "Enter the size of LRU cache : ";
        cin >> s;
        cout << endl;
    }

    class LRUCache c(s);
    int opt, val;
    int* v;
    string str;

    do {
        
        Sleep(1000);
        cout << "Please select an option from the choices--" << endl << endl;

        cout << "1. Create new Alphanumeric Key and Integer Value pair (Enter 1)" << endl;
        cout << "2. Find an item in the Cache by key value (Enter 2)" << endl;
        cout << "3. Find the Most Recently Used item in the Cache (Enter 3)" << endl;
        cout << "4. Exit (Enter 0)" << endl;
        cout << "Choose option : ";
        cin >> opt;



        switch (opt) {
        case 0: {
            break;
        }
        case 1: {
            cout << "Please enter alphanumeric Key" << endl;
            cin.ignore();
            getline(cin, str);
            cout << "Enter Integer value" << endl;
            cin >> val;
            c.insertKeyValue(str, val);
            cout << "\nItem inserted Successfully";
            break;
        }
        case 2: {
            cout << "Please enter a key to be Searched" << endl;
            cin.ignore();
            getline(cin, str);
            v = c.getKeyValue(str);
            if (v == NULL) cout << "\nOops no such key exists in the cache - think again";
            else
                cout << "\nItem value is "<<*v;

            break;

        }
        case 3: {
            if (c.mostRecent() == "ERR")
                cout << "\nOops Insert an item- Cache is empty ";
            else
                cout << c.mostRecent();
            break;
        }
        default: {
            cout << "\nNo such Option choose an opt between 0-3";
        }
        }



        cout << endl << endl;

    } while (opt != 0);
    cout << "Thanks \nCredits- Shivam (shivamkichitthi@gmail.com) 😎😎";
    return 0;
}