//Trie

- Trie: string related problems, bit related problems
- Putting every single character, bits in the trie tree

---------------------------------------------------------------------------------------------------------
Striver Trie Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp
Resource: https://takeuforward.org/blogs/trie
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##################-------Lec 1: Theory--------#########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------L1. Implement TRIE | INSERT | SEARCH | STARTSWITH--------########
//Tutorial: https://takeuforward.org/data-structure/implement-trie-1/
//Problem: https://leetcode.com/problems/implement-trie-prefix-tree/description/
https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1

------------------------Theory----------------------------------
//

trie has 2 member function, array and bool
Go to reference trie When a new alphabet appears
and create another reference trie from there, sekhane true kore dewa flag, which means the word exits

starswith
if you are not standing at a null there was a startwith definitely
if the trie pointing to a reference trie, that means there exists a trie

Node -> Need reference links, and a flag variable

------------
Approach:
1. 

------------
Time Complexity: O(N) for all operations[depends on the size of the word]
Space Complexity: O()

#include <iostream>
using namespace std;

// Node structure for Trie
struct Node {
    // Array to store links to child nodes,
    // each index represents a letter
    Node* links[26];
    // Flag indicating if the node
    // marks the end of a word
    bool flag = false;

    // Check if the node contains
    // a specific key (letter)
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // Insert a new node with a specific
    // key (letter) into the Trie
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Get the node with a specific
    // key (letter) from the Trie
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Set the current node
    // as the end of a word
    void setEnd() {
        flag = true;
    }

    // Check if the current node
    // marks the end of a word
    bool isEnd() {
        return flag;
    }
};

// Trie class
class Trie {
private:
    Node* root;

public:
    // Constructor to initialize the
    // Trie with an empty root node
    Trie() {
        root = new Node();
    }

    // Inserts a word into the Trie
    // Time Complexity O(len), where len
    // is the length of the word
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // Create a new node for
                // the letter if not present
                node->put(word[i], new Node());
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }

    // Returns if the word
    // is in the trie
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // If a letter is not found,
                // the word is not in the Trie
                return false;
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Check if the last node
        // marks the end of a word
        return node->isEnd();
    }

    // Returns if there is any word in the
    // trie that starts with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                // If a letter is not found, there is
                // no word with the given prefix
                return false;
            }
            // Move to the next node
            node = node->get(prefix[i]);
        }
        // The prefix is found in the Trie
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

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//###################-------Lec 2: Problems--------######################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------L2. Implement Trie - 2 (Prefix Tree) | INSERT | countWordsEqualTo() | countWordsStartingWith()--------########
//Tutorial: https://takeuforward.org/data-structure/implement-trie-ii/
//Problem: https://www.naukri.com/code360/problems/implement-trie_1387095

------------
Approach:
1. Add 2 more variable in the trie datastructure
a. endwith 
b. count prefix 

------------
Time Complexity: O(N) [for every operation]
Space Complexity: O()

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
            node->incrementPrefixCount(); // confused
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

//#######################################################################
//#######-------L3. Longest Word With All Prefixes | Complete String--------########
//Tutorial: https://takeuforward.org/trie/longest-string-with-all-prefixes
//Problem: https://www.naukri.com/code360/problems/complete-string_2687860

Task: Find Longest Word from all prefixes of the word 

//BruteForce Approach [Using Map]
------------
Approach:
1. Put all element in a map 
2.1 Keep searching with the word, if the prefix of the current is avaiable in the whole map 
2.2 If so update answer
------------
Time Complexity: O(N) + O( N * word_length)
Space Complexity: O(N * [word_size in memory]) [for putting all the word]

#include <bits/stdc++.h> 

string completeString(int n, vector<string> &arr){
    unordered_map<string, int>mp;
    for(string s: arr){
        mp[s] = 1;
    }

    string ans = "";

    for(string s: arr){
        int sz = s.size();
        string tmp = "";
        bool ok = 1;
        for(int i=0;i<sz;i++){
            tmp+=s[i];
            if(mp[tmp]!=1){
                ok = 0;
                break;
            }
        }
        if(ok){
            if(ans.size()<tmp.size() || (ans.size()==tmp.size() && ans>tmp) )
            ans = tmp;
        }
    }
    if(ans.empty()) return "None";
    return ans;
}

//Optimal Approach [Using Trie]
------------
Approach:
1. Insert all the word in the string 
2.1 check for all prefix
2.2 if all prefix exists update the answer string with the longest string

------------
Time Complexity: O(2N) where N is the total number of characters of all unique words hence the time complexity.
Space Complexity: O(N) 

#include <bits/stdc++.h> 

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

    bool checkIfAllPrefixExists(string word) {
        Node* node = root; 
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                if(!node->isEnd()) return false;
            }
            else return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &arr){
    Trie t;
    for(string s: arr){
        t.insert(s);
    }

    string ans = "";
    for(string s: arr){
        bool ok = t.checkIfAllPrefixExists(s);
        if(ok){
            if(ans.size()<s.size() || (ans.size()==s.size() && ans>s) )
            ans = s;
        }
    }

    if(ans.empty()) return "None";
    return ans;
}

//#######################################################################
//#######-------L4. Number of Distinct Substrings in a String--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/
//Problem: https://www.naukri.com/code360/problems/count-distinct-substrings_985292

------------
Approach:
1. Put all the substring in the string set 
2. return the size of the set

------------
Time Complexity: O(N * N * log(N*N)) //approx 
Space Complexity: O(N*N) //approx 

brute
#include<bits/stdc++.h>
int countDistinctSubstrings(string &s)
{   
    int n = s.size();
    set<string>st;
    for(int i=0;i<n;i++){
        string tmp = "";
        for(int j=i;j<n;j++){
            tmp+=s[j];
            st.insert(tmp);
        }
    }
    return st.size()+1;
}

//Optimal Approach[Better in space complexity]
------------
Approach:
Watch video for better understanding
1.1 From root, i to n add in tree 
1.2 From root, i+1 to n add in tree 
2. If element is not present then cnt++, and increase the tree 

------------
Time Complexity: O(N*N)
Space Complexity : O(N*N)

#include<bits/stdc++.h>

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

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

int countDistinctSubstrings(string &word)
{   
    int n = word.size();
    Node* root = new Node();
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        Node* node = root;
        for(int j=i;j<n;j++){
            if (!node->containsKey(word[j])) {
                node->put(word[j], new Node());
                cnt++;
            }
            node = node->get(word[j]);
        }   
    }
    return cnt;
}


//#######################################################################
//#######-------L5. Bit PreRequisites for TRIE Problems--------########
//Tutorial: https://takeuforward.org/trie/bit-prerequisites-for-trie-problems
//Problem: https://www.geeksforgeeks.org/problems/bits-basic-operations/1


------------
Approach:
1. xor on bits: nums ^ nums2
2. check if set or not: nums & (1<<i)
3. set ith bit: nums | (1<<i)
------------
Time Complexity: O(1)
Space Complexity: O(1)

class Solution {
  public:
    int XOR(int n, int m) {
        return n^m;
    }
    int check(int a, int b) {
        a--;
        if( (b & (1<<a)) ) return 1;
        return 0;
    }
    int setBit(int c, int d) {
        return d | (1 << c);
    }
};

//#######################################################################
//#######-------L6. Maximum XOR of Two Numbers in an Array--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-xor-of-two-numbers-in-an-array/
//Problem: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

Task: Maximum xor between 2 number in an array 

------------
Approach:
1. insert the bits in the tries(0 or 1) and Build a trie tree from array
2. For each bit in trie try to maximize the answer by putting the opposite bit[see video for dryrun]

------------
Time Complexity: O(32*N + 32*M) where N is the length of the input array.
Space Complexity: O(32N) where N is the length of the input array.

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
            //go to opposite bit, to maximise answer
            if (node->containsKey(opposite_bit)) {
                mx |= (1<<i);
                node = node->get(opposite_bit);
            }
            //go to not opposite, ar kono way na thakle
            //crossed out hoye jabe same bit bole 
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

//#######################################################################
//#######-------L7. Maximum XOR With an Element From Array | Queries--------########
//Tutorial: https://takeuforward.org/trie/maximum-xor-queries-trie/
//Problem: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/
https://www.geeksforgeeks.org/problems/maximum-xor-with-an-element-from-array/0

------------
Approach:
1. 
Offline queries
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################-------Finished--------#########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
-------------------------------------------------------------------------
-------------------------------------------------------------------------