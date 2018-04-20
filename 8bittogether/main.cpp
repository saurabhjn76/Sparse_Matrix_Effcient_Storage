#include "bits/stdc++.h"
#include <stdlib.h> 
#include <time.h>
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
# define LENGTH 1250      // 10000/8 =    1250
# define MASKMSB 127
# define MASKLSB 254

typedef long long ll;





// length -  1250

string paddZeroes(string s){
	if(s.length()==1){
		return ("00" + s);
	} else if(s.length() == 2){
		return ("0" + s);
	} else
		return s;
}



// Function which genrates the random string of 8 bit and converts it to corresponding 3byte string
string genrandomEightBit(){
	return paddZeroes(to_string(rand()%256));
}


// Function to genrate the random string of 10000 bit -> 1250 bytes
string genrateTenThousandBitString(){
	string s;
	for(int i=0;i<LENGTH;i++){
		s.append(genrandomEightBit());
	}
	return s;
}


int eightBitToInteger(string s, int index){
	return = stoi(s.substr(3*index,3));
}


// Function to XOR 8 bits at a time
string xorEightBit(string bitString1 ,string bitString2){
	return paddZeroes(to_string(stoi(bitString1) ^ stoi(bitString2)));
}



// Function return the XOR of 10000 long strings taken 8 bit at a times
string xorTenThousandBitString(string longBitString1, string longBitString2){
	string result;
	for(int i =0; i < LENGTH; i++){
		result.append(xorEightBit(longBitString1.substr(3*i,3), longBitString2.substr(3*i,3)));
	}
	return result;
}




bool checkSetBit(string s, int index){
	return false;
}

string rightShift(string s){
	string result;
	// For the first Eight bits

	int firstByte = eightBitToInteger(0);
	result.append(paddZeroes(to_string((firstByte & MASKMSB)>>1)));

	for(int i=1;i<LENGTH;i++){
		int current = eightBitToInteger(i);
		int predecessor = eightBitToInteger(i-1);
		int resultInt = ((current & MASKLSB) >> 1) + (predecessor & 1) ? 0 : 128 ;
		// check if it it of length 3
		result.append(paddZeroes(to_string(resultInt)));
	}
	return result;
}

string leftShift(string s){
	string result;
	for(int i=0;i<LENGTH-1;i++){
		int current = eightBitToInteger(i);
		int successor = eightBitToInteger(i+1);
		int resultInt = ((current & MASKMSB) << 1) + (successor > MASKMSB) ? 0 : 1 ;
		//check if it it of length 3
		result.append(paddZeroes(to_string(resultInt)));
	}
	// for the last 8 bits
	int lastByte = eightBitToInteger(LENGTH-1);
	result.append(paddZeroes(to_string((lastByte & MASKMSB) << 1)));
	return result;
}

string distance(string s1, string s2){
	
}

int main()
{
	 srand (time(NULL));
	 int k
	 map <string,int> mapping;
	 map <int,string> reverse_mapping;

	 // genrates the map of string and reverse string
	 for(int i = 0 ;i<k;i++){
	 	string s1 = genrateTenThousandBitString();
	 	mapping.insert(pair <string,int>(s1,i+1));
	 	reverse_mapping(pair<int,string> (i+1,s1));
	 }

	// R(i,10){
	// 	cout << genrandomEightBit() ;
	// 	printf("\n");
	// }
	 // string str ="123456789123456789";
	 // R(i,6)
	 // cout << str.substr(3*i,3)  << "\n";

	return 0;
}