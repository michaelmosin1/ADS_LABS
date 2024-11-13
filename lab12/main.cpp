#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct Element {
    int value;
    int block_id;

    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

bool readBlock(ifstream& file, vector<int>& block, size_t block_size) {
    block.clear();
    int value;
    while (block.size() < block_size && file >> value) {
        block.push_back(value);
    }
    return !block.empty();
}

void sortAndWriteBlock(const vector<int>& data, const string& filename) {
    vector<int> sorted_data = data;
    sort(sorted_data.begin(), sorted_data.end());
    ofstream file(filename, ios::binary);
    for (const auto& value : sorted_data) {
        file << value << endl;
    }
}

void mergeSortedBlocks(const vector<string>& block_files, const string& output_file) {
    priority_queue<Element, vector<Element>, greater<Element>> min_heap;
    vector<ifstream> files;
    for (const auto& block_file : block_files) {
        files.emplace_back(block_file);
    }
    for (int i = 0; i < files.size(); ++i) {
        int value;
        if (files[i] >> value) {
            min_heap.push({value, i});
        }
    }
    ofstream output(output_file);
    while (!min_heap.empty()) {
        Element current = min_heap.top();
        min_heap.pop();
        output << current.value << endl;
        int value;
        if (files[current.block_id] >> value) {
            min_heap.push({value, current.block_id});
        }
    }
}

void externalSort(const string& input_file, const string& output_file, size_t block_size) {
    ifstream input(input_file);
    if (!input.is_open()) {
        cerr << "Ошибка при чтении файла!" << endl;
        return;
    }
    vector<string> block_files;
    size_t block_id = 0;
    while (true) {
        vector<int> block;
        if (!readBlock(input, block, block_size)) {
            break;
        }
        string block_filename = "block_" + to_string(block_id++) + ".txt";
        sortAndWriteBlock(block, block_filename);
        block_files.push_back(block_filename);
    }
    mergeSortedBlocks(block_files, output_file);
    for (const auto& file : block_files) {
        remove(file.c_str());
    }
    cout << "Сортировка завершена. Отсортированный массив находится в файле " << output_file << endl;
}

int main() {
    string input_file = "input.txt";
    string output_file = "sorted_output.txt";
    size_t block_size = 1000; // Размер блока для сортировки в памяти

    externalSort(input_file, output_file, block_size);

    return 0;
}
