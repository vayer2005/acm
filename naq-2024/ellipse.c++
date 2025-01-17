#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    double x1; double y1; double x2; double y2; double a;

    cin >> x1 >> y1 >> x2 >> y2 >> a;

    double c = sqrt(pow(abs(x2-x1), 2) + pow(abs(y2-y1), 2));
    double b = sqrt(pow((a/2), 2) - pow(c/2, 2));

    double rot = atan2((y2-y1), (x2-x1));

    a = a/2;
    double dx = atan2((-1* b * sin(rot)), (a * cos(rot)));

    double x = a * cos(dx) * cos(rot) - b * sin(dx) * sin(rot);


    double dy = atan2((b * cos(rot)), (a * sin(rot)));

    double y = a * cos(dy) * sin(rot) + b * sin(dy) * cos(rot);

    double cx = (x1 + x2)/2;
    double cy = (y1 + y2)/2;

    cout << cx - abs(x) << " "<< cy - abs(y) << " " << cx + abs(x) << " " << cy + abs(y);


}