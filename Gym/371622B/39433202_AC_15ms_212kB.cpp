#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
int main()
{
	int n, k, m;
	cin >> n >> m >> k;
	vector<int>v(m + 1);
	vector<string>vs;
	for (int i = 0; i < m + 1; i++)
	{
		cin >> v[i];
		bitset<20>bs(v[i]);
		vs.emplace_back(bs.to_string());
    }
    int friends=0;
	for(int i=0;i<m;i++)
    {
            int c=0;
            for(int ii=0;ii<=20;ii++)
            {
                if(vs[i][ii]!=vs[m][ii])
                    c++;
            }
            if(c<=k)
                friends++;

    }
    cout<<friends;

}
