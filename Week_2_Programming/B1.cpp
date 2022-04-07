#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if(a == 0) {
        if(b == 0)
            if( c != 0) cout << "Phuong trinh vo nghiem";
            else cout << "Phuong trinh co vo so nghiem";
        else
            cout << "Phuong trinh co nghiem duy nhat: " << (double)(-b) / c;
        return 0;
    }
    double delta = b * b - (4 * a) * c;
    if(delta < 0) cout << "Phuong trinh vo nghiem";
    else if(delta == 0) cout << "Phuong trinh co 2 nghiem kep: " << -b / (2 * a);
    else {
        cout << "Phuong trinh co 2 nghiem phan biet: " << endl;
        cout << "x1 = " << (double)(-b + sqrt(delta)) / (2 * a) << endl;
        cout << "x2 = " << (double)(-b - sqrt(delta)) / (2 * a) << endl;
    }
}
