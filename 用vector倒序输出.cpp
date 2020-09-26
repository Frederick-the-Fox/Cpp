#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    vector <int> v(10) ;
    vector <int> :: iterator vi;
    vector <int> :: reverse_iterator vir;
    cout<<"please input your factors"<<endl;
    for (vi = v.begin(); vi != v.end(); ++vi)
    {
        cin>>*vi;
    }
    for (vir = v.rbegin(); vir  !=  v.rend(); ++vir)
    {
        cout<<*vir<<endl;
    }
    return 0;
}
