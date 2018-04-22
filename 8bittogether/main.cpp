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
# define LENGTH 1250  // 10000/8 =    1250
# define MASKMSB 127
# define MASKLSB 254

typedef long long ll;

 vector<int> v[400];



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
	return  stoi(s.substr(3*index,3));
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

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}



bool checkSetBit(string s, int index){
	return false;
}

string rightShift(string s){
	string result;
	// For the first Eight bits

	

	for(int i=0;i<LENGTH-1;i++){
		int current = eightBitToInteger(s,i);
		int predecessor = eightBitToInteger(s,i+1);
		//printf("%d -- %d\n",((predecessor & 1)==1 ? 0 : 128));
		int resultInt = ((current & MASKLSB) >> 1) + ((predecessor & 1)==1 ? 128 : 0) ;
		// check if it it of length 3
		result.append(paddZeroes(to_string(resultInt)));
	}
	int lastByte = eightBitToInteger(s,LENGTH-1);
	result.append(paddZeroes(to_string((lastByte & MASKLSB)>>1)));
	return result;
}

string leftShift(string s){
	string result;
	int firstByte = eightBitToInteger(s,0);
	result.append(paddZeroes(to_string((firstByte & MASKMSB) << 1)));
	
	for(int i=1;i<LENGTH;i++){
		int current = eightBitToInteger(s,i);
		int successor = eightBitToInteger(s,i-1);
		int resultInt = ((current & MASKMSB) << 1) + ((successor < MASKMSB) ? 0 : 1) ;
		//check if it it of length 3
		result.append(paddZeroes(to_string(resultInt)));
	}

	return result;
}

 int oneByteHammingDistance(int byteOne, int byteTwo){
 	int result = byteOne^byteTwo;
 	return countSetBits(result);
 }

int hammingDistance(string s1, string s2){
	int distance = 0;
	for(int i=0;i< LENGTH ;i++){
		distance += oneByteHammingDistance(eightBitToInteger(s1,i),eightBitToInteger(s2,i)); 
	}
	return distance;
}

void readFile(string fileName){
	string line;
  ifstream myfile (fileName);
  int index =0;
  if (myfile.is_open())
  {
  	int count = 0;
  	
  	string ss ;
    while (getline (myfile,line))
    {
    count++;
    if(count%2==0){
    	//cout << line << '\n';
    	//cout << line.length() <<'\n';

    	for(int i=1;i<line.length();i++){
    		ss="";
    		while(line[i]!=',' && line[i]!=']'){
    			ss+= line[i];
    			i++;
    			//printf("sD\n");
    		}
    		i++;
    		//printf("%d\n",stoi(ss) );
    		v[index].push_back(stoi(ss));
    	}
    	index++;

    }
    else	
      continue;
    }

    myfile.close();
    
  }

  else { cout << "Unable to open file";   }

}

int main()
{
	 srand (time(NULL));
	 int k=10; // depends on the given text
	 map <string,int> mapping;
	 map <int,string> reverse_mapping;

	 //genrates the map of string and reverse string
	 for(int i = 0 ;i<k;i++){
	 	string s1 = genrateTenThousandBitString();
	 	mapping.insert(pair <string,int>(s1,i));
	 	reverse_mapping.insert(pair<int,string> (i,s1));
	 }
	 ////////////////////////////////////
	 // read the file
	readFile("k10.txt");
	////////////////////////////////////

	string singletriplet, rowXored="", profileVector[10];
	//Training
	for(int profiles = 0; profiles< 10; profiles++) {
		profileVector[profiles]="";
		for(int i=0;i<30;i++){
			rowXored="";
			for(int j=0;j<v[40*profiles+i].size()-2;j++) { /// for triplet 
				singletriplet = xorTenThousandBitString(xorTenThousandBitString(leftShift(leftShift(reverse_mapping.at(v[40*profiles+i][j]))),leftShift(reverse_mapping.at(v[40*profiles+i][j+1]))),reverse_mapping.at(v[40*profiles+i][j+2]));

				if(rowXored==""){
					rowXored = singletriplet;
				} else {
					rowXored = xorTenThousandBitString(rowXored,singletriplet);
				}
				}
			if(profileVector[profiles]==""){
				profileVector[profiles] = rowXored;
			} else {
				profileVector[profiles] = xorTenThousandBitString(profileVector[profiles], rowXored);
			}
		}
	}
	R(i,10) 
	cout << profileVector[i] <<"\n";

	







	return 0;
}