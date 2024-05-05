// Copyright 2024 Adam-Al-Rahman

#include <iostream>
#include <queue>
#include <unordered_map>

// Define a tree node structure for Huffman encoding
struct Node {
  char data;
  unsigned freq;
  Node* left;
  Node* right;

  Node(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue in Huffman encoding
struct compare {
  bool operator()(Node* l, Node* r) { return (l->freq > r->freq); }
};

// Function to print Huffman codes from the tree
void printCodes(Node* root, std::string code, std::unordered_map<char, std::string>& huffmanCodes) {
  if (!root) return;

  if (root->data != '$') {
    huffmanCodes[root->data] = code;
  }

  printCodes(root->left, code + "0", huffmanCodes);
  printCodes(root->right, code + "1", huffmanCodes);
}

// Function to build the Huffman tree and generate codes
void buildHuffmanTree(std::string text) {
  std::unordered_map<char, unsigned> freq;
  for (char ch : text) {
    freq[ch]++;
  }

  std::priority_queue<Node*, std::vector<Node*>, compare> pq;
  for (auto pair : freq) {
    pq.push(new Node(pair.first, pair.second));
  }

  while (pq.size() != 1) {
    Node* left = pq.top();
    pq.pop();

    Node* right = pq.top();
    pq.pop();

    Node* newNode = new Node('$', left->freq + right->freq);
    newNode->left = left;
    newNode->right = right;

    pq.push(newNode);
  }

  Node* root = pq.top();

  std::unordered_map<char, std::string> huffmanCodes;
  printCodes(root, "", huffmanCodes);

  std::cout << "Huffman Codes are:\n";
  for (auto pair : huffmanCodes) {
    std::cout << pair.first << " : " << pair.second << "\n";
  }
}

int main() {
  std::string text = "AABCB";
  buildHuffmanTree(text);
  return 0;
}
