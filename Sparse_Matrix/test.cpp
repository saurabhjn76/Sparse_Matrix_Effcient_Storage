#include "bits/stdc++.h"
using namespace std;

# define s(n)                        scanf("%d",&n)
# define sc(n)                       scanf("%c",&n)
# define sl(n)                       scanf("%lld",&n)
# define sf(n)                       scanf("%lf",&n)
# define ss(n)                       scanf("%s",n)

#define R(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

# define INF                         (int)1e9
# define EPS                         1e-9
# define MOD 1000000007


typedef long long ll;

string gen_random(string s, const int len) {
    static const char alphanum[] =
        "0123456789";

    for (int i = 0; i < len; ++i) {
       s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s += '\0';
    return s;
}


/////////////////////////////
// Right shift
/////////////////////////////
// Multiplies str1 and str2, and prints result.
string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";
 
    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);
 
    // Below two indexes are used to find positions
    // in result. 
    int i_n1 = 0; 
    int i_n2 = 0; 
 
    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0; 
         
        // Go from right to left in num2             
        for (int j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position. 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
       return "0";
 
    // generate the result string
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}

/////////////////////////////
// left shift
/////////////////////////////
string longDivision(string number, int divisor)
{
    // As result can be very large store it in string
    string ans;
   
    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
       temp = temp * 10 + (number[++idx] - '0');
     
    // Repeatedly divide divisor with temp. After 
    // every division, update temp to include one 
    // more digit.
    while (number.size() > idx)
    {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';
         
        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
     
    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";
     
    // else return ans
    return ans;
}

int main()
{
  vector<string> v;
  string s ;
  s= gen_random(s,3010);
  //cout << s << s.length()<<'\n';

  R(i,10000){
  	string s;
 	v.push_back(gen_random(s,3010));
  }
  R(i,10000){
  	cout << v[i] << "\n";
  }
 // cout << sizeof(v) << "\n";
  return 0;
}