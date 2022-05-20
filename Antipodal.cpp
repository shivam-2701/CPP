#include <bits/stdc++.h>
using namespace std;
#define pp pair<long long, long long>
#define ll long long
#define PI 3.14159265
double getSlope(pp &a, pp &b)
{
    double m1 = atan(1.0 * (a.second - b.second) / (a.first - b.first)) * 180 / PI;
    return m1;
}
double getSlopeInv(pp &a, pp &b)
{
    double m2 = atan(1.0 * (b.first - a.first) / (a.second - b.second)) * 180 / PI;
    return m2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        pp points[n];

        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            points[i] = make_pair(x, y);
        }
         ll count = 0;
        
        for (int i = 0; i < n; i++)
        {
            unordered_map<double, ll> m;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                double slope = getSlope(points[i], points[j]);
                double temp = getSlopeInv(points[i], points[j]);
                // double slope =i;
                m[slope]++;


                if (m.find(temp) != m.end())
                {
                    count+=m[temp];
                }
            }
            
        }
        
        
        

        
        cout << count << endl;
    }
}