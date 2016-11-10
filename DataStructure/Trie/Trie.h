#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
   char ch;
   bool isLeaf;
   map<char, TrieNode *> adj;

   TrieNode() {
      ch = '*';
      isLeaf = false;
   }

   TrieNode(char c) {
      ch = c;
      isLeaf = false;
   }
} *root;

void insertKey(TrieNode *root, string key) {
   TrieNode *curNode = root;
   for (int level = 0; level < key.length(); level++) {
      char ch = key[level];
      if (curNode->adj.find(ch) == curNode->adj.end()) {
         TrieNode *newNode = new TrieNode(ch);
         curNode->adj.insert(make_pair(ch, newNode));
      }
      curNode = curNode->adj[ch];
   }
   curNode->isLeaf = true;
}

bool search(TrieNode *root, string key) {
   TrieNode *curNode = root;
   for (int lev = 0; lev < key.size(); lev++) {
      char ch = key[lev];
      if (curNode->adj.find(ch) == curNode->adj.end()) {
         return false;
      }
      curNode = curNode->adj[ch];
   }
   return (curNode != nullptr && curNode->isLeaf);
}

bool isFreeNode(TrieNode *n) {
   return (n->adj.size() == 0);
}

bool deleteKey_util(TrieNode *curNode, string key, int level) {
   // Base Case
   if (level == key.length()) {
      if (curNode->isLeaf) {
         // Unmark as Leaf Node
         curNode->isLeaf = false;

         // If Empty, Node to be deleted
         if (curNode->adj.size() == 0) {
            return true;
         }
         return false;
      }
   } else { // Recursive Case

      char ch = key[level];

      if (deleteKey_util(curNode->adj[ch], key, level + 1)) {
         // Last Node Marked, delete it

         auto it = curNode->adj.find(ch);
         delete (it->second);
         //root->adj.erase(ch);

         curNode->adj.erase(it);
         return (!curNode->isLeaf && curNode->adj.size() == 0);
      }

   }
   return false;
}

void deleteKey(TrieNode *curNode, string key) {
   if (key.length() > 0) {
      deleteKey_util(curNode, key, 0);
   }
}