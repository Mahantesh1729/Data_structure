#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;

    cin >> m >> n;
    
    vector <vector <int>> arr(m, vector <int>(n));


    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int k;

    cin >> k;
    
    priority_queue<int> pq;

    for(int i = 0; i < m; i++)
    {

        for(int j = 0 ; j < n; j++)
        {
            if(pq.size() < k) 
            {
                pq.push(arr[i][j]);
            }
            else 
            {
                if(pq.top()>arr[i][j])
                {
                    pq.pop();
                    pq.push(arr[i][j]);
                }
            }
        }   
    } 
    vector <int> ans;

    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    reverse(ans.begin(), ans.end());


    for(int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}