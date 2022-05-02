#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int number[100000];
    vector<int> solution;
    int sum, a = 0, b = 0;

    while (true)
    {
        cin >> number[a];
        if (number[a] == -1) break;
        a++;
    }
    

    while (b != a)
    {
        sum = 0;
        
        for (int i = 1; i <= sqrt(number[b]); i++)
        {
            if (number[b] % i == 0)
		    {
			    solution.push_back(i);
			    if (i != number[b] / i) solution.push_back(number[b] / i);
		    }
        }
        sort(solution.begin(), solution.end());
        
		for (int i = 0; i < solution.size()-1; i++)
        {
            sum += solution[i];
        }
        if(sum == number[b])
        {
            cout << number[b] << " = ";
            for (int i = 0; i < solution.size()-1; i++)
            {
                if ( i != solution.size()-2) cout << solution[i] << " + ";
                else cout << solution[i] << endl;
            }
            
        }
        else
        {
            cout << number[b] << " is NOT perfect." << endl;
        } 
        b++;
    }
    return 0;
}