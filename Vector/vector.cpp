#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    // inserting elements in the vector
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(10);

    // inserting a value with out push back function
    v[4] = 11;
    v[5] = 12;

    v.push_back(200);
    v.push_back(300);

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    cout << v[6] << endl;
    cout << v[7] << endl;

    cout << "the size of the vector is " << v.size() << endl;
    cout << "the capacity of the vector is " << v.capacity() << endl;
}