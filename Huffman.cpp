#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// Class to represent a Huffman Tree Node
class Node {
public:
    int freq;           // Frequency of the character
    char symbol;        // The character itself
    Node* left;         // Left child
    Node* right;        // Right child
    string huff;        // Huffman code for the character

    Node(int frequency, char character, Node* l = nullptr, Node* r = nullptr) {
        freq = frequency;
        symbol = character;
        left = l;
        right = r;
        huff = "";
    }
};

// Comparator function for the priority queue
struct compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq; // Min heap based on frequency
    }
};

// Function to print the Huffman codes and calculate encoded lengths
void printNodes(Node* node, string val, unordered_map<char, int>& encoded_lengths) {
    string new_val = val + node->huff;  // Update the current Huffman code

    if (node->left || node->right) {    // If there are children, keep traversing
        if (node->left)
            printNodes(node->left, new_val, encoded_lengths);
        if (node->right)
            printNodes(node->right, new_val, encoded_lengths);
    } else {
        // If it's a leaf node, print the symbol and its Huffman code
        cout << node->symbol << " -> " << new_val << endl;
        encoded_lengths[node->symbol] = new_val.length();  // Store the encoded length
    }
}

int main() {
    // Getting user input for characters and their frequencies
    int num_chars;
    cout << "Enter number of characters: ";
    cin >> num_chars;

    vector<char> chars(num_chars);
    vector<int> freqs(num_chars);

    for (int i = 0; i < num_chars; i++) {
        cout << "Enter character " << i + 1 << ": ";
        cin >> chars[i];
        cout << "Enter frequency of character " << chars[i] << ": ";
        cin >> freqs[i];
    }

    // Creating the priority queue (min heap) of nodes
    priority_queue<Node*, vector<Node*>, compare> nodes;
    for (int i = 0; i < num_chars; i++) {
        nodes.push(new Node(freqs[i], chars[i]));
    }

    // Building the Huffman Tree
    while (nodes.size() > 1) {
        Node* left = nodes.top();  // Node with the lowest frequency
        nodes.pop();
        Node* right = nodes.top();  // Node with the second lowest frequency
        nodes.pop();

        left->huff = "0";  // Assign 0 to the left child
        right->huff = "1"; // Assign 1 to the right child

        // Create a new internal node with the sum of the frequencies
        Node* new_node = new Node(left->freq + right->freq, '\0', left, right);
        nodes.push(new_node);
    }

    // Calculating total size before encoding
    int total_size_before = 0;
    for (int freq : freqs)
        total_size_before += freq * 8;

    // Printing the nodes and calculating encoded lengths
    unordered_map<char, int> encoded_lengths;
    cout << "Huffman Codes:" << endl;
    printNodes(nodes.top(), "", encoded_lengths);

    // Calculating total size after encoding
    int total_size_after = 0;
    for (int i = 0; i < num_chars; i++) {
        total_size_after += freqs[i] * encoded_lengths[chars[i]];
    }

    // Calculating encoded data representation (compressed size)
    int characters = num_chars * 8;
    int frequency = 0;
    for (int freq : freqs)
        frequency += freq;

    int encoded_data_representation = characters + frequency + total_size_after;

    // Output results
    cout << "\nTotal size before encoding: " << total_size_before << " bits" << endl;
    cout << "Total size after encoding: " << total_size_after << " bits" << endl;
    cout << "Encoded Data Representation: " << encoded_data_representation << " bits" << endl;

    return 0;
}
