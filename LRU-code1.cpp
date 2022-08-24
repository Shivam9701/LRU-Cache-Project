#include<bits/stdc++.h>
using namespace std;
class Node{                
    public:
    string key;       // Custom Class containing the key of the data stored and the value
    int value;

    Node(){           //default constructor creates a new Node with key as empty String                
        key="";       // default value of a node is 0    
        value=0;
    }
    Node(string key, int value){
        this->key=key;             // parameterized constructor
        this->value=value;
    }

};
class LRUCache{
     private:
     const size_t maxSize;                                 // custom size of the cache
     list <Node> l;                                       // list to hold nodes in the Cache at any given time (Size of the list always lesser or equal to MaxSize) 
     unordered_map<string,list <Node> ::iterator>um;     // a hashmap for faster (O(1) on average) lookup of a key 
    
     public:

     LRUCache():maxSize(0){                             // default constructor creates LRUCache of 0 size
     }

     LRUCache(size_t s):maxSize(s){                    // parametrized constructor Creates LRUCache of size s
     }
 
     void insertKeyValue (string key, int val){        //Inserts a Key Value pair to the LRUCache  If Cache is full, least Recently UsedKey will be be deleted and new key will be inserted
        
         if (um.count(key) != 0) {                       //If a key is already present, its value will be updated

            list <Node>::iterator it=um[key];
            it->value=val;
        }                                               
        else{                                            //Key is Not present in The cache

            if (l.size()==maxSize){                      //Cache is Full 

              um.erase(l.back().key);                  //deleted entry of LRU pair     
              l.pop_back();                            //delete the LRU key value pair from Cache
            }

            Node n(key,val);
            l.push_front(n);                         //Key value added to Cache as MRU pair
            list <Node>::iterator it=l.begin();
            um[key]=it;                              // Address of new pair being added to Cache hashmaps

       
        }

     }
     
     int getKeyValue(string key){

     }
     
     string mostRecent(){

     }
};
int main(){

return 0;
}