#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int cnt=0;//记录所有摆放方法的数量
const int n = 8;

int available(vector<int> v,int k)//if position k is available for chess
{
    int pos = v.size(); 
    for (int i = 0; i < v.size(); i++)
        if (v[i] == k || (v[i] + i) == (k + pos) || (i - v[i]) == (pos - k))
            return 0;
 
    return 1;
}
void myshow(vector<int> v)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (v[i] == j)
                cout << 'o';
            else
                cout << 'x';
        }
        cout << endl;
    }
    cout << endl;
}
int play(vector<int> &data)
{
    int sum=0;

    for(int i=0;i<8;i++)
    {
        if(available(data,i)&&data.size()<7)
        {
            data.push_back(i);
            sum+= play(data);
            data.pop_back();
        }
        if(available(data,i)&&data.size()==7)
        {
            sum++;
            data.push_back(i);
            myshow(data);
            data.pop_back();
        }
    }
    return sum;
}
int main()
{
    vector<int> queen;
    cout<<play(queen)<<endl;
    return 0;
}

