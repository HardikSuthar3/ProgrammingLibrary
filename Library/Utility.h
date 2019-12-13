#include <bits/stdc++.h>

using namespace std;

int prime(long n)
{
   if (n < 2)
      return 0;
   bool *prm = new bool[n + 1];
   fill(prm, prm + n + 1, false);
   int count = 0;
   for (int num = 2; num <= n; num++)
   {
      bool flag = false;
      for (int i = 2; i <= sqrt(num); i++)
      {
         if (prm[i] == true)
         {
            if (num % i == 0)
            {
               prm[num] = false;
               flag = true;
               break;
            }
         }
      }

      if (flag == false)
      {
         count++;
         prm[num] = true;
      }
   }
   return count;
}

long long C(int n, int r)
{
   if (r > (n - r))
   {
      r = n - r;
   }

   long long ans = 1;
   for (int i = 1; i < r; i++)
   {
      ans *= (n - r + i);
      ans /= i;
   }
   return ans;
}

vector<string> split(const string &s, char delim)
{
   vector<string> elems;
   stringstream ss(s);
   string item;
   while (getline(ss, item, delim))
      elems.push_back(item);
   return elems;
}

int Kadane_Algo(int *a, int *start, int *finish, int n)
{
   *finish = -1;
   int curMax = a[0];
   int maxSoFar = a[0];
   for (int i = 1; i < n; ++i)
   {
      if (curMax + a[i] > a[i])
      {
         curMax = curMax + a[i];
      }
      else
      {
         curMax = a[i];
      }
   }
}

#define MOD 1000000007

inline void add(int &a, int b)
{
   a += b;
   if (a >= MOD)
   {
      a -= MOD;
   }
}

inline int mul(int a, int b)
{
   return (long long)(a * b) % MOD;
}

inline int power(int a, int b)
{
   int res = 1;
   while (b > 0)
   {
      if (b & 1)
      {
         res = mul(res, a);
      }
      b = b >> 1;
      a = mul(a, a);
   }
   return res;
}

inline int inv(int x)
{
   return power(x, MOD - 2);
}