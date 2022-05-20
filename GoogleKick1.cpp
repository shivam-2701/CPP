#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int k = 1;
    while (k <= t)
    {
        double r, a, b;
        cin >> r >> a >> b;
        double ans = 0;
        long long prev = r;
        long long count = 0;
        while (prev > 0)
        {
            
            while (prev > 0)
            {

                ans += (prev * prev);
                if (count % 2 == 0)
                {

                    prev = prev * a;
                }
                else
                    prev = prev / b;

                if (prev <= 0)
                    break;

                count++;
            }
        }
        cout << fixed << setprecision(6);
        cout << "Case #" << k << ": " << ans * pi << "\n";
        k++;
    }
}