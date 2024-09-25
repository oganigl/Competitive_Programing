#include <iostream>
#include <string>
#include <cstdint>
#include <unordered_map>
#include <sstream>
#include <cctype>

class node {
public:
    std::string word;
    node* next;
    node* prev;

    node(node* prev, const std::string& word) : word(word), next(nullptr), prev(prev) {
        if (prev != nullptr) {
            prev->next = this;
        }
    }

    node(node* prev, const std::string& word, node* next) : word(word), next(next), prev(prev) {
        if (prev != nullptr) {
            prev->next = this;
        }
        if (next != nullptr) {
            next->prev = this;
        }
    }
};

class list_linked {
public:
    node* first;
    std::unordered_map<std::string, node*> node_map;

    list_linked() {
        first = new node(nullptr, "1");
        node* aux = first;
        node_map[first->word] = first;
        for (size_t i = 2; i <= 1000000; i++) {
            std::string num_str = std::to_string(i);
            aux = new node(aux, num_str);
            node_map[num_str] = aux;
        }
    }

    void delete_node(const std::string& word) {
        node* current = node_map[word];
        if (current == nullptr) return;
        std::string curr_word = current->word;
        while (current != nullptr) {
            node* next = current->next;
            node* prev = current->prev;
            node_map.erase(curr_word);
            if (current == first) {
                first = next;
            }
            if (prev != nullptr) {
                prev->next = next;
            }
            if (next != nullptr) {
                next->prev = prev;
            }
            delete current;
            current = next;
            curr_word=current->word;
            if (std::isdigit(curr_word[0])) {
                break;
            }
        }

    }

    void add_node(const std::string& word_to_find, const std::string& new_node_name) {
        node* prev = node_map[word_to_find];
        node* new_node = new node(prev, new_node_name, prev->next);
        node_map[new_node_name] = new_node;
    }

    void print() {
        std::ostringstream output;
        node* aux = first;

        while (aux != nullptr) {
            output << aux->word << '\n';
            aux = aux->next;
        }

        std::cout << output.str();
    }
};

int main() {
    uint32_t queries;
    char oper;
    int number;
    std::string line;
    std::cin >> queries;
    list_linked list;
    while (queries--) {
        std::cin >> oper;
        if (oper == '+') {
            std::cin >> number;
            std::getline(std::cin >> std::ws, line);
            list.add_node(std::to_string(number), line);
        } else {
            std::cin >> number;
            list.delete_node(std::to_string(number));
        }
    }
    list.print();
    return 0;
}
