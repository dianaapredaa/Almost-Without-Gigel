// Copyright Preda Diana 324CA 2022-2023

#include <cstdint>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int64_t SolveTask1(vector<int>& a, vector<int>& b, int n) {
    // sort the lines
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    // calculate the maximum score
    long long score = 0;
    for (int i = 0; i < n; i++) {
        score += max(a[i], b[i]);
    }

    return score;
}

int64_t SolveTask2(vector<int>& a, vector<int>& b, int moves, int n) {
    // Swap elements from a and b, before sorting, without consuming moves
    for (int i = 0; i < n; i++) {
        if (a[i] == max(a[i], b[i])) {
            swap(a[i], b[i]);
        }
    }

    int64_t sum = 0;

    // Sort arrays
    std::sort(b.begin(), b.end());
    std::sort(a.begin(), a.end(), std::greater<int>());

    int i = 0;

    // Swap elements from a and b, after sorting, consuming moves
    while (i < n) {
        // if we have moves left, swap elements
        if (moves && a[i] == max(a[i], b[i])) {
            sum += max(a[i], b[i]);
            moves--;
        } else {
            // else, just add the element from b
            sum += b[i];
        }

        i++;
    }

    // return the sum
    return sum;
}

vector<int> ReadVector(istream& is, int size) {
    vector<int> vec(size);
    for (auto& num : vec) {
        is >> num;
    }
    return vec;
}

int main() {
    ifstream fin("nostory.in");
    ofstream fout("nostory.out");

    int task;
    fin >> task;

    int n, moves;
    if (task == 1) {
        fin >> n;
    } else {
        fin >> n >> moves;
    }

    auto a = ReadVector(fin, n);
    auto b = ReadVector(fin, n);

    auto res = task == 1 ? SolveTask1(a, b, n) : SolveTask2(a, b, moves, n);
    fout << res << "\n";

    return 0;
}
