#include <iostream>
#include <cmath>
using namespace std;
typedef pair<double, double> dd;
int ax, ay, bx, by, cx, cy, dx, dy;

dd minho(double k)
{
    return {(double)ax + ((double)(bx - ax)) * k / (double)100, (double)ay + ((double)(by - ay)) * k / (double)100};
}
dd kangho(double k)
{
    return {(double)cx + ((double)(dx - cx)) * k / (double)100, (double)cy + ((double)(dy - cy)) * k / (double)100};
}
double dist(dd m, dd k)
{
    return (pow(m.first - k.first,2) + pow(m.second - k.second,2));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    //percentage로 따진다.
    double fp = 0, lp = 100, ans = 2e9;
    while (fp + 1e-10 <= lp)
    {
        double p = (fp * 2 + lp) / 3;
        double q = (fp + lp * 2) / 3;

        dd m1 = minho(p);
        dd m2 = minho(q);
        dd k1 = kangho(p);
        dd k2 = kangho(q);

        ans = min(ans, min(dist(m1, k1), dist(m2, k2)));

        if (dist(m1, k1) >= dist(m2, k2))
        {
            fp = p;
        }
        else
        {
            lp = q;
        }
    }
    cout.setf(ios::fixed);//고정소수점 표시
    cout.precision(10);//자리수 표시
    
    cout << sqrt(ans) << '\n';
    //cout<<typeid(fp*3).name();
}