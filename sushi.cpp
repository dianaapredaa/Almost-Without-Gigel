// Copyright Preda Diana 324CA 2022-2023

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void compute_rating(vector<vector<int>> &g, int n, int m, vector<int> &rating) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			rating[i] += g[j][i];
		}
	}
}

void dinero_rating(vector<vector<int>> &g, int n, int m, vector<int> &rating,
				   vector<int> &dinero, vector<int> &p) {
	// calculate maximum rating
	for (int i = 0; i < m; i++) {
		dinero[i] = p[i];
		dinero[i + m] = p[i];
		for (int j = 0; j < n; j++) {
			rating[i] += g[j][i];
			rating[i + m] += g[j][i];
		}
	}
}

int task1(int n, int m, int x, vector<int>& p, vector<vector<int>>& g) {
	// create a DP table
    vector<vector<int>> dp(m + 1, vector<int>(x * n + 1, 0));

	// rating vector
    vector<int> rating(m, 0);

    // compute rating
	compute_rating(g, n, m, rating);

    // initialize the base case
    for (int cap = 0; cap <= x * n; cap++) {
		int *ptr = &dp[0][cap];
		std::fill(ptr, ptr + 1, 0);
    }

    // fill the DP table with the optimal solutions
    for (int i = 1; i <= m; i++) {
        for (int cap = 0; cap <= x * n; cap++) {
            // if we don't use exhibit i, we can use the same solution as before
            dp[i][cap] = dp[i - 1][cap];

			int sol_aux;

            // if we use exhibit i and we have enough money,
			// we can use the solution
            if (cap >= p[i - 1]) {
                sol_aux = dp[i - 1][cap - p[i - 1]] + rating[i - 1];

				int sol = max(dp[i][cap], sol_aux);
                dp[i][cap] = sol;
            }
        }
    }

    // return the biggest rating that can be earned with the given constraints
    return dp[m][x * n];;
}

int task2(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	// create a DP table
    vector<vector<int>> dp(2 * m + 1, vector<int>(x * n + 1, 0));

	// rating and money vectors
    vector<int> rating(2 * m, 0);
	vector<int> dinero(2 * m, 0);

	// // compute rating and money
	dinero_rating(g, n, m, rating, dinero, p);

    // initialize the base case
    for (int cap = 0; cap <= x * n; cap++) {
		int *ptr = &dp[0][cap];
		std::fill(ptr, ptr + 1, 0);
    }

    // fill the DP table with the optimal solutions
    for (int i = 1; i <= 2 * m; i++) {
        for (int cap = 0; cap <= x * n; cap++) {
            // if we don't use exhibit i, we can use the same solution as before
            dp[i][cap] = dp[i - 1][cap];

			int sol_aux;

            // if we use exhibit i and we have enough money,
			// we can use the solution
            if (cap >= dinero[i - 1]) {
                sol_aux = dp[i - 1][cap - dinero[i - 1]] + rating[i - 1];

				int sol = max(dp[i][cap], sol_aux);
                dp[i][cap] = sol;
            }
        }
    }

    // return the biggest rating that can be earned with the given constraints
    return dp[2 * m][x * n];
}

int task3(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	// create a DP table
	vector<vector<vector<int>>> dp(2 * m + 1, vector<vector<int>>
									(x * n + 1, vector<int>(n + 1)));

	// rating and money vectors
	vector<int> rating(2 * m, 0);
	vector<int> dinero(2 * m, 0);

	// // compute rating and money
	dinero_rating(g, n, m, rating, dinero, p);

    // initialize the base case
    for (int cap = 0; cap <= x * n; cap++) {
		for (int j = 0; j <= n; ++j) {
			int* ptr = &dp[0][cap][j];
			std::fill(ptr, ptr + 1, 0);
		}
    }

    // fill the DP table with the optimal solutions
    for (int i = 1; i <= 2 * m; i++) {
        for (int cap = 0; cap <= x * n; cap++) {
			for (int j = 1; j <= n; ++j) {
				// if we don't use exhibit i, we can use the same solution as before
				dp[i][cap][j] = dp[i - 1][cap][j];

				int sol_aux;

				// if we use exhibit i and we have enough money,
				// we can use the solution
				if (cap >= dinero[i - 1]) {
					sol_aux = dp[i - 1][cap - dinero[i - 1]][j - 1] + rating[i - 1];

					int sol = max(dp[i][cap][j], sol_aux);
					dp[i][cap][j] = sol;
				}
			}
        }
    }

    // return the biggest rating that can be earned with the given constraints
    return dp[2 * m][x * n][n];
}

int main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);

	int task;  // task number

	int n;  // number of friends
	int m;  // number of sushi types
	int x;  // how much each of you is willing to spend

	vector <int> prices;  // prices of each sushi type
	// the grades you and your friends gave to each sushi type
	vector <vector <int> > grades;

	cin >> task;
	cin >> n >> m >> x;

	prices.assign(m, 0);
	grades.assign(n, vector <int> (m, 0));

	// price of each sushi
	for(int i = 0; i < m; ++i) {
		cin >> prices[i];
	}

	// each friends rankings of sushi types
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> grades[i][j];
		}
	}

	int ans = -1;

	switch(task) {
		case 1:
			ans = task1(n, m, x, prices, grades);
			break;
		case 2:
			ans = task2(n, m, x, prices, grades);
			break;
		case 3:
			ans = task3(n, m, x, prices, grades);
			break;
		default:
			cout << "wrong task number" << endl;
	}

	cout << ans << endl;

	return 0;
}
