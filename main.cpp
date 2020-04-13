#include <iostream>
#include <vector>

using std::vector;
using std::string;

struct Node {
    Node(): pred(nullptr), terminal(false), max_priority(0), current_priority(0), max_Node(nullptr) {
        next.assign(26, nullptr);
    };
    vector<Node*> next;
    Node* pred;
    bool terminal;
    long max_priority;
    long current_priority;
    Node* max_Node;

};

class Bor {
public:
    Node root;
    Bor() {
        root = Node();
    };
    ~Bor() {
        // не успел чуть-чуть
    }
    void Add_word(string& word) {
        Node* current_node = &root;
        for (int i = 0; i < word.length(); ++i) {
            char current_symbol = word[i];
            int8_t index = (int)current_symbol - 97;
            //printf("%d\n", index);
            if (current_node->next[index] == nullptr) {
                (current_node->next[index]) = new Node();
                current_node->next[index]->pred = current_node;
                if (i == word.length() - 1) {
                    current_node->next[index]->terminal = true;
                    current_node->next[index]->max_priority = 1;
                    current_node->next[index]->current_priority = 1;
                    Make_relax(current_node->next[index]);
                }

            } else {

                current_node = current_node->next[index];
                if (i == word.length() - 1) {
                    current_node->next[index]->max_priority += 1;
                    current_node->next[index]->current_priority += 1;
                    Make_relax(current_node->next[index]);
                }
            }
        }
    };

    // change max_priority
    void Make_relax(Node* node_to_relax) {
        long max_priort = node_to_relax->current_priority;
        Node *current_node = node_to_relax->pred;
        Node *node_max = node_to_relax;
        while (current_node != nullptr && current_node->max_priority < max_priort) {
            current_node->max_priority = max_priort;
            current_node->max_Node = node_max;
            node_max = current_node;
            current_node = current_node->pred;
        }
    };

    string predict(string& prefix) {
        Node* current_node = &root;
        for (int i = 0; i < prefix.length(); ++i) {
            char current_symbol = prefix[i];
            int8_t index = (int)current_symbol - 97;
            if (current_node->next[index] == nullptr) {
                return "ERROR";
            }
            current_node = current_node->next[index];
        }
        string predict_string = prefix;
        while (current_node->terminal && current_node->max_priority > current_node->current_priority) {
            // не успел но тут чуть-чуть осталось
            break;
        }
        return predict_string;
    };
};

int main() {
    Bor words;
    string word = "aasd";
    words.Add_word(word);
}