#include<iostream>
#include<cstdio>
using namespace std;
int main(){
int circle_radius = 11; // or whatever you want
	float console_ratio = 4.0/3.0;
    float a = console_ratio*circle_radius;
    float b = circle_radius;

    for (int y = -circle_radius; y <= circle_radius; y++){
        for (int x = -console_ratio*circle_radius; x <= console_ratio*circle_radius; x++)
        {
            float d = (x/a)*(x/a) + (y/b)*(y/b);
			cout<<x<<endl;
            if (d > 0.90 && d < 1.1)
            {
                cout << "*";
            }
            else
            {
                 cout << " ";
            }
        }
        cout << endl;
    }
}