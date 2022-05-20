#include<bits/stdc++.h>
#define ll   long long int
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int>v(n + 2, 1);

        for (int i = 1; i <= n; i++)
        {
            cin >>v[i];
        }

        int i = 1, count = 1;

        while (i <= n)
        {
            if (count)
            {
            v[i] =v[i + 1] * 2;
                i += 2;
            }
            else
            {
            v[i] =v[i - 1] * 2;
                i++;
            }

            count = 1 - count;
        }

        for (int i = 1; i <= n; i++)
        {
            cout <<v[i] << " ";
        }

        cout<<endl;
    }
}