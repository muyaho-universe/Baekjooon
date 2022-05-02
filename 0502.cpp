#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class node
{
    
public:
    int number;
    void set_data(int s);
    node *link;
};

void node::set_data(int s)
{
   
    number = s;
}

class my_queue
{
    node *front, *rear;
public:
    my_queue();
    void insert_q(node x);
    node delete_q();
    bool empty();

};

my_queue::my_queue()
{
    front = NULL;
    rear = NULL;
}

void my_queue::insert_q(node x)
{
    node *p;
    p = new node;
    (*p) = x;
    p->link = NULL;
    if(!empty())
        rear->link = p; // 이전 상태가 empty가 아니라면
    else
        front = p;       // 이전 상태가 empty였다면 front도 변경
    rear = p;  
}

node my_queue::delete_q()
{
    node temp;
    node *t;
    t = front;
    temp = *front;
    front = t->link;
    delete t;
    if(front==NULL)
        rear = NULL;
    return temp;
}

bool my_queue::empty()
{
    if ((rear == NULL) &&(front == NULL))
        return true;
    return false;
}

int main()
{
    my_queue que, que_num;
    node  tmp;
    int number;
    int sum, temp;

    while (true)
    {
        cin >> number;
        tmp.set_data(number);
        que.insert_q(tmp);
        if (number == -1) break;
    }

    while (true)
    {
        vector<int> solution;
        sum = 0;
        temp = que.delete_q().number;
        if(temp == -1) break;
        for (int i = 1; i <= sqrt(temp); i++)
        {
            if (temp % i == 0)
		    {
			    solution.push_back(i);
			    if (i != temp / i) solution.push_back(temp / i);
		    }
        }
        sort(solution.begin(), solution.end());
        
		for (int i = 0; i < solution.size()-1; i++)
        {
            sum += solution[i];
        }
        if(sum == temp)
        {
            cout << temp << " = ";
            for (int i = 0; i < solution.size()-1; i++)
            {
                if ( i != solution.size()-2) cout << solution[i] << " + ";
                else cout << solution[i] << endl;
            }
            
        }
        else
        {
            cout << temp << " is NOT perfect." << endl;
        } 
    }
    return 0;
}
