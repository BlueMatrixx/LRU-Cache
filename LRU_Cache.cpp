#include<bits/stdc++.h>
using namespace std;

// Node to store data of Linked list
class node{
    public:
    string key;
    int value;
    node(string key,int value){
        this->key=key;
        this->value=value;
    }
};

// LRU Cache Data structure
class LRU_Cache{
    void printCache(){
        for(auto x:l){
            cout<<x.key<<" -> "<<x.value<<endl;
        }
    }
    public:
    int maxSize;
    list<node> l;
    unordered_map<string,list<node>::iterator> m;

    LRU_Cache(int maxSize){
        this->maxSize= maxSize>1?maxSize:1;  
    }

    void insertKeyValue(string key,int value){
        //
        //if present in cache
        if(m.count(key)!=0){
           m[key]->value=value;
        }
        else{
         //not present
         //check if cache is full or not
         //if full
         if(l.size()==maxSize){
            node last=l.back();
            m.erase(last.key);
            l.pop_back();
         }
         // if not full
         node n(key,value);
         l.push_front(n);
         m[key]=l.begin();
        }
       
    }

    int* getValue(string key){
        //if key is present
        if(m.count(key)!=0){
            int ans=m[key]->value;
            l.push_front(*m[key]);
            l.erase(m[key]);
            m[key]=l.begin();
            return &(l.begin()->value);
        }
        else{
            // key not present
            // ideally should be return from searching in the disk
            return NULL;

        }
    }

    string mostRecentKey(){
        //
        return l.begin()->key;
    }

};

int main(){
	LRU_Cache lru(3);
	lru.insertKeyValue("mango",10);
	lru.insertKeyValue("apple",20);
	lru.insertKeyValue("guava",30);
    // lru.printCache();
	cout << lru.mostRecentKey() <<endl;

	lru.insertKeyValue("mango",40);
	cout << lru.mostRecentKey() <<endl;

	int *orders = lru.getValue("mango");
	if(orders!=NULL){
		cout<<"Order of Mango "<<*orders <<endl;
	}


	lru.insertKeyValue("banana",20);

	if(lru.getValue("apple")==NULL){
		cout<<"apple doesn't exist";
	}

	if(lru.getValue("guava")==NULL){
		cout<<"guava doesn't exist";
	}

	if(lru.getValue("banana")==NULL){
		cout<<"banana doesn't exist";
	}
	if(lru.getValue("mango")==NULL){
		cout<<"mango doesn't exist";
	}

	

	return 0;
}
