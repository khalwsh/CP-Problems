#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

#define MX (1<<29)
using namespace std;
int toInt(string str)
{
    istringstream buf(str);
    int x;
    buf>>x;
    return x;
}
vector<int> Split(string st)
{
    vector<int> AllInts;
    string a;
    istringstream bff(st);
    while(bff>>a)
    {
        AllInts.push_back(toInt(a));
    }
    return AllInts;
}

int ManHutWays( vector<vector <int > > &grid,int n,int m)
{
    int i,j;
    grid[1][1]=1;
    for(i=1 ; i<=n;i++)
    {
        if(grid[i][1]==-1)
            break;
        grid[i][1]=1;
    }
    for(i=1 ; i<=m;i++)
    {
        if(grid[1][i]==-1)
            break;
        grid[1][i]=1;
    }
    for(i=2 ; i<=n;i++)
    {
        for(j=2;j<=m;j++)
        {
            if(grid[i][j]!=-1)
                grid[i][j]=(grid[i-1][j]==-1?0:grid[i-1][j])+(grid[i][j-1]==-1?0:grid[i][j-1]);
        }
    }
    return grid[n][m];
}

int main()
{
	//freopen("in.txt","r+",stdin);
	int tasty,W,E,i,j,k;
	vector <int> di;
   cin>>tasty;
        while(tasty--)
        {
            getchar();
            string inp;
            cin>>W>>E;
            getchar();
            vector<vector <int > > grid(W+1,vector<int>(E+1,0));
            for(i=0;i<W;i++)
            {
                getline(cin, inp);
                di=Split(inp);
                if(di.size()>1)
                {
                    for(j=1;j<di.size();j++)
                    {
                        grid[ di [0]  ]  [  di[j]  ] = -1;
                    }
                }
                //cout<<i<<" -< "<<endl;
            }

            cout<<ManHutWays(grid,W,E)<<endl;
            if(tasty!=0)
                cout<<endl;
            /*
             for(i=0;i<=W;i++)
            {
                for(j=0;j<=E;j++)
                {
                    cout<<grid[i][j]<<"  ";
                }
                cout<<endl;
            }
            */
        }
return 0;
}