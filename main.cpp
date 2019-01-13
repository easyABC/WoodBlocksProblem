#include <iostream>
#include <algorithm>

using namespace std;
const int max_num = 30;
int n;
vector<int> pile[max_num];

void find_block(int a, int& p, int& h)
{
    for(p = 0; p < n; p++)
        for(h = 0; h < pile[p].size(); h++)
            if(pile[p][h] == a) return;
}

void clear_above(int p, int h)
{
    for(int n = h+1; n < pile[p].size(); n++)
    {
        int b = pile[p][n];
        pile[b].push_back(b);
    }
    pile[p].resize(h+1);
}

//将p堆h以上的木块全部移动到p2的末端
void pile_onto(int p, int h, int p2)
{
    for(int i = h; i < pile[p].size(); i++)
    {
        int b = pile[p][i];
        pile[p2].push_back(b);
    }
    pile[p].resize(h);
}

void print()
{
    for(int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for(int j = 0; j < pile[i].size(); j++)
        {
            cout << pile[i][j] <<" ";
        }
        cout << endl ;
    }
    cout << endl ;
}

int main()
{
    int a, b;
    cout << "input n:";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        pile[i].push_back(i);
    }
    string cmd1, cmd2;
    int pa, pb, ha, hb;

    cout << endl;
    cout << "input command:\n";
    while(cin >> cmd1 >> a >> cmd2 >> b)
    {
        find_block(a, pa, ha);
        find_block(b, pb, hb);

        if(pa == pb) continue;  //非法指令

        if(cmd1 == "move")  clear_above(pa, ha);

        if(cmd2 == "onto")  clear_above(pb, hb);

        pile_onto(pa, ha, pb);

        print();
    }
    print();
    return 0;
}

