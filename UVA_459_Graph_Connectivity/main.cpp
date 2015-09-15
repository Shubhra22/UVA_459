//
//  main.cpp
//  UVA_459_Graph_Connectivity
//
//  Created by Shuvro Sarker on 9/12/15.
//  Copyright (c) 2015 Shuvro Sarker. All rights reserved.
//

#include <iostream>
#include <vector>
#define Max 1000000

using namespace std;

int par[26];
int c;
vector<char> vec;
void makeSet(int x)
{
    par[x] = x;
}

int Find(int r)
{
    
    if(par[r]==r) return r;
    par[r] = Find(par[r]);
    return par[r];
}

void  Union(int x,int y)
{
    int u = Find(x);
    int v = Find(y);
    if (u!=v)
    {
        par[u] = v;
        c--;
    }
    
}
int main(int argc, const char * argv[])
{
    int t_case;
    bool scnd = false;
    int tmp;
    char max_Char,c1,c2;
    string str;
    cin >> t_case;
    while (t_case--)
    {
        if(scnd)
        {
            cout<<endl;
        }
        scnd = true;
        cin >> max_Char;
        tmp = max_Char - 'A';
        c = tmp +1;
        for (int i = 0; i < c ; i++)
        {
            makeSet(i);
        }
        cin.ignore();
        while (true)
        {
            getline(cin,str);
            if(str == "") break;
            c1 = str[0];
            c2 = str[1];
            Union(c1-'A', c2-'A');
        }
        cout << c << endl;
        
    }
 
    
    return 0;
}
