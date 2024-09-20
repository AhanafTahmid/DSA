//https://takeuforward.org/data-structure/implement-trie-1/                            
#include <iostream>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        int n = prefix.size();
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};


int main() {
    Trie trie;
    cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");
    
    cout << "Search if Strawberry exists in trie: " <<
    (trie.search("strawberry") ? "True" : "False")<< endl;
    
    cout << "Search if Strike exists in trie: " <<
   ( trie.search("strike") ? "True" : "False" )<< endl;
    
    cout << "If words is Trie start with Stri: " <<
    (trie.startsWith("stri") ? "True" : "False" )<< endl;

    return 0;
}
                            
                        
-----------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------
//Count prefix and how many word
#include <bits/stdc++.h> 

struct Node {
    Node* links[26];
    bool flag = false;
    int endswith = 0, prefixCount = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }


    void incrementWordCount() {
        endswith++;
    }

    void incrementPrefixCount() {
        prefixCount++;
    }

    void decrementWordCount() {
        endswith--;
    }

    void decrementPrefixCount() {
        prefixCount--;
    }

    int getWordCount() {
        return endswith;
    }

    int getPrefixCount() {
        return prefixCount;
    }
};


class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incrementPrefixCount();
        }
        node->setEnd();
        node->incrementWordCount();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        
        return node->getWordCount();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }

        return node->getPrefixCount();
    }

    void erase(string &word){
        Node* node = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->decrementPrefixCount();
            }
            else return;
        }
        node->decrementWordCount(); 
    }
};
