#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main()
{
    uniform_int_distribution<unsigned int> score(0,100);
    default_random_engine r;
    
    vector<int> v;
    for (int i = 0; i <= 50; i++)
    {
        v.push_back(score(r));
        int num = v.back();
        v.pop_back();
        if (num <= 70)
        {
            cout << "the score of student #" << i << " is : passed" << endl;
            
        }
        else {
            cout << "the score of student #" << i << " is : failed" << endl;
        }
    }
    
    return 0;
}
