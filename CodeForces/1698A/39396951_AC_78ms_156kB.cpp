#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
int main()
{
	int t;
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;
		vector<int>v(n);
		int x=0;
		
		for (int i = 0; i < n; i++)
			cin >> v[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					continue;
				x ^= v[j];
			}
			if (v[i] == x)
				break;
			else
				x = 0;
 
		}
		cout << x << endl;
	}
 
}