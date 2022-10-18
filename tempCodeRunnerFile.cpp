#include <iostream>
using namespace std;

float pi = 3.14;
float area, radius;

int main(){
    cout << "input the raduis of a circle: ";
    cin >> radius;

    area = pi * radius * radius;

    cout << "the area is " << area;

}