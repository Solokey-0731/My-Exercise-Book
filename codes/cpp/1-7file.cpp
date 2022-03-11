#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;
// Open a file to output
int main()
{
    string usr_name;
    char num_tries, num_right;
    ofstream outfile("seq_data.txt",ios_base::app);
    if(!outfile)
    cerr<<"Oops!Unable to save session data!\n";
    else
    {
        outfile<<usr_name<<"123456"
               <<num_tries<<'0'
               <<num_right<<endl;
    }
    return 0;
}