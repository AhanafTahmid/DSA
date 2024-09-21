//https://takeuforward.org/data-structure/implement-trie-1/    
//Implement Trie  
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



-----------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------
//Maximum XOR of Two Numbers in an Array
struct Node {
    Node* links[2];
    bool flag = false;

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};
class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(int nums){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (nums>>i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
        node->setEnd();
    }

    int getMax(int nums){
        Node* node = root;
        int mx = 0;
        for(int i=31;i>=0;i--){
            int bit = (nums>>i) & 1;
            int opposite_bit = 1 - bit;
            if (node->containsKey(opposite_bit)) {
                mx |= (1<<i);
                node = node->get(opposite_bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return mx;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& arr) {
        Trie t;
        for(int x: arr) t.insert(x);

        int mx = 0;
        for(int x: arr){
            mx = max(mx , t.getMax(x));
        }
        return mx;
    }
};