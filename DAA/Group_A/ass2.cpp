
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};


struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (root == NULL)
        return;

        if (root->left == NULL && root->right == NULL) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffmanEncoding(char chars[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

        for (int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

        printCodes(pq.top(), "");
}

int main() {
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char chars[n];
    int freq[n];

    cout << "Enter characters and their frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> chars[i] >> freq[i];
    }

    cout << "\nHuffman Codes:\n";
    huffmanEncoding(chars, freq, n);

    return 0;
}




/*Sample Input:

Enter number of characters: 5
Enter characters and their frequencies:
a 5
b 9
c 12
d 13
e 16

Sample output:
Huffman Codes:
c : 00
d : 01
a : 100
b : 101
e : 11*/


