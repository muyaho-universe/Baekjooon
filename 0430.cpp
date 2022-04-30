#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long input_sum;
    long long calculated_sum = 0;
    long long count = 0;

    cin >> input_sum;

    for (long long i = 1; i < input_sum; i++)
    {
        if (input_sum - calculated_sum - i == 0)
        {
            count ++;
            break;
        }
        if (input_sum - calculated_sum - i < i)
        {
            continue;
        }
        else 
        {
            calculated_sum += i;
            count++;
        }

    }
    cout << count << endl;
    return 0;
}