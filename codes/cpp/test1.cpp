#include<iostream>
#include<string>
using namespace std;

int main()
{
    string user_name;
    cout<<"Please input your username: ";
    cin>>user_name;
    cout<<"Hello, "
        <<user_name
        <<"\nGoodbye\n";
    return 0;
}

#include<vector>
/*
int main()
{
    const int seq_size=18;
    int elem_vals[seq_size]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
    vector<int>elem_seq(elem_vals,elem_vals+seq_size);
    char str[20]="abcd,efgh,ijkl,mnop";
    vector<char>elem_char(str,str+seq_size);
    cout<<("%s\n",str);
    for(int ix=0;ix<seq_size+10;++ix)
    cout<<elem_char[ix];
    return 0;
}*/



