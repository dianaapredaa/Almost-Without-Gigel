// Copyright Preda Diana 324CA 2022-2023

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

bool load_ferry(int n, int k, vector<long long> weights, long long mid) {
    int i = 0;
    bool possible = true;

    // distribute the cars across the ferries
    for (int j = 0; i < n && j < k; j++) {
        // current ferry's load
        long long load = 0;

        // add as many cars as possible to the ferries
        while (i < n && load + weights[i] <= mid) {
            load += weights[i];
            i++;
        }

        // check if the ferry is overloaded
        load == 0 ? possible = false : possible = true;
    }

    // check if we managed to distribute all cars across the ferries
    i != n ? possible = false : possible = true;

    return possible;
}

long long binary_search(long long sum, int n, int k,
                         vector<long long> weights) {
    long long left = 1, right = sum, mid;

    // binary search
    while (left < right) {
        bool possible = true;

        // current ferry's load
        mid = (right - left) / 2 + left;

        // check if we managed to distribute all cars across the ferries
        possible = load_ferry(n, k, weights, mid);

        // check if we managed to distribute all cars across the ferries
        possible ? right = mid : left = mid + 1;
    }

    return right;
}

int main() {
    ifstream fin("feribot.in");
    ofstream fout("feribot.out");

    int n, k;
    // numberight of cars
    fin >> n;
    // numberight of ferry boats
    fin >> k;

    vector<long long> weights(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        // car's weight
        fin >> weights[i];
        // sum of all cars' weights
        sum += weights[i];
    }

    long long result = binary_search(sum, n, k, weights);

    // print the result
    fout << result << endl;

    fin.close();
    fout.close();

    return 0;
}
