#include<iostream>
using namespace std;

int minCoins(int coinList[], int n, int value) {
   int coins[value+1];       //store minimum coins for value i

   if(value == 0)
      return 0;              //for value 0, it needs 0 coin

   coins[0] = 0;

   for (int i=1; i<=value; i++)
      coins[i] = INT_MAX;            //initially all values are infinity except 0 value

   for (int i=1; i<=value; i++) {      //for all values 1 to value, find minimum values
      for (int j=0; j<n; j++)
         if (coinList[j] <= i) {
            int tempCoins = coins[i-coinList[j]];
         if (tempCoins != INT_MAX && tempCoins + 1 < coins[i])
            coins[i] = tempCoins + 1;
      }
   }
   return coins[value];       //number of coins for value
}

int main() {
   int coins[] = {1, 2, 5, 10};
   int n = 4, value;
   cout << "Enter Value: "; cin >> value;
   cout << "Minimum "<<minCoins(coins, n, value)<<" coins required.";
   return 0;
}