#include <bits/stdc++.h>
#define endl "\n"
#define ll int

using namespace std;

int main() {
  ll l = 0, b = 0, f = 0;

  cout << "Enter the Length, Breadth and Floors of the building" << endl;
  cin >> l >> b >> f;

  cout << "--------------------------------------------------------------------"
          "--------------------------------"
       << endl;
  cout << "The Length is: " << l << " , The Breadth is : " << b
       << " and The Floors are : " << f << endl;

  ll area = l * b;

  double price = (area * 1800 * (f - 1)) + (area * 1500);

  cout << "--------------------------------------------------------------------"
          "--------------------------------"
       << endl;
  cout << "The total cost of Construction is : " << price << endl;

  double plotPrice = (area * 0.111 * 35000);

  cout << "--------------------------------------------------------------------"
          "--------------------------------"
       << endl;
  cout << "The price of the Plot is : " << plotPrice << endl;

  double TotalPrice = (price + plotPrice);

  double profitPrice = (TotalPrice) / 5;

  cout << "--------------------------------------------------------------------"
          "--------------------------------"
       << endl;
  cout << "profit price of plot is " << profitPrice << endl;

  TotalPrice += profitPrice;

  cout << "--------------------------------------------------------------------"
          "--------------------------------"
       << endl;
  cout << "The Total selling Price of the Building is : " << TotalPrice << endl;

  return 0;
}