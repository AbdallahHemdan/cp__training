#include <bits/stdc++.h>
using namespace std;

int n;
int e[27][27];
string s[101];
bool visited[27];

int getID(char c)
{
	if(c == ' ') return 0;
	return c - 'a' + 1;
}

int MAIN()
{
	memset(e, 0, sizeof(e));
	for(int i = 1; i <= 26; i++)
		e[0][i] = true;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] += " ";
	}
	for(int i = 1; i < n; i++)
	{
		int pos = 0;
		while(s[i][pos] == s[i+1][pos]) pos ++;
		e[getID(s[i][pos])][getID(s[i+1][pos])] = true;
	}
	for(int k = 0; k <= 26; k++)
		for(int i = 0; i <= 26; i++)
			for(int j = 0; j <= 26; j++)
				e[i][j] |= e[i][k] & e[k][j];
	bool haveCycle = false;
	for(int i = 0; i <= 26; i++)
		haveCycle |= e[i][i];
	if(haveCycle)
		cout << "Impossible" << endl;
	else
	{
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i <= 26; i++)
		{
			int now = 0;
			for(int j = 0; j <= 26; j++)
			{
				bool valid = (!visited[j]);
				for(int k = 0; k <= 26; k++)
					if(visited[k] == false && e[k][j])
						valid = false;
				if(valid)
				{
					now = j;
					break;
				}
			}
			if(i > 0)
				cout << char('a' + now - 1);
			visited[now] = true;
		}
		cout << endl;
	}
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
