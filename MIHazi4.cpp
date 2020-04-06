#include <iostream>    
#include <algorithm>    
#include <vector>       
#include <ctime>       
#include <cstdlib>     

using namespace std;

vector<int> queens;
int n = 100;

int is_attacked(int col) {
	int res = 0;
	int x = col;
	int y = queens[col];
	int i = 1;
	//mainDiagonal
	while (x - i >= 0 && y - i >= 0) {
		if (queens[x - i] == y - i) res++;
		i++;
	}
	i = 1;
	while (x + i <= n - 1 && y + i <= n - 1) {
		if (queens[x + i] == y + i) res++;
		i++;
	}
	//sideDiagonal
	i = 1;
	while (x - i >= 0 && y + i <= n - 1) {
		if (queens[x - i] == y + i) res++;
		i++;
	}
	i = 1;
	while (x + i <= n - 1 && y - i >= 0) {
		if (queens[x + i] == y - i) res++;
		i++;
	}

	return res;

}
bool swap(int i, int j, int oldi, int oldj) {
	int temp = queens[i];
	queens[i] = queens[j];
	queens[j] = temp;
	int resi = is_attacked(i);
	int resj = is_attacked(j);
	if (resi + resj > oldi + oldj) {
		temp = queens[i];
		queens[i] = queens[j];
		queens[j] = temp;
		return false;
	}

	return true;

}

int main() {
	srand(unsigned(time(0)));
	int i, j, resi, resj;
	for (int i = 0; i < n; ++i) queens.push_back(i);
	int collisions, nswaps = 0;


	random_shuffle(queens.begin(), queens.end());
	do {
		nswaps = 0;
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				resi = is_attacked(i);
				resj = is_attacked(j);
				if (resi || resj) {
					if (swap(i, j, resi, resj)) {
						nswaps++;
					}
				}
			}
		}

	} while (nswaps);

	for (int i = 0; i < n; ++i) {
		cout << queens[i] << " ";
	}


	return 0;
}