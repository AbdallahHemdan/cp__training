#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int W, H;
	int w1, h1, w2, h2; 
	cin >> W >> H; 
	cin >> w1 >> h1 >> w2 >> h2;
	while (H) {
		W += H; 
		if (H == h1) {
			W -= w1; 
			W = max(W, 0);
		}
		if (H == h2) {
			W -= w2; 
			W = max(W, 0);
		}
		H--; 
	}
	cout << W << endl;
}