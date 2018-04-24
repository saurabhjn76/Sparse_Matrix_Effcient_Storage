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
# define LENGTH 10000

typedef long long ll;


 vector<int> source[400];


double dotProduct(vector<int> v1, vector<int> v2)
    {
        // I'm not validating inputs here for simplicity.            
        double dotProduct = 0;
        for (int i=0; i < LENGTH; i++)
        {
            dotProduct += (v1[i] * v2[i]);
        }

        return dotProduct;
    }

  double magnitude(vector<int> v1){
  	return sqrt(dotProduct(v1,v1));
  }

  double cosineSimillarity(vector<int> v1, vector<int> v2){
  	double dotProductAB = dotProduct(v1,v2);
  	double magA = magnitude(v1);
  	double magB = magnitude(v2);
  	return (dotProductAB/(magA*magB));
  }

vector<int> randTenThousandBitString(){
	vector<int> v;
	R(i,LENGTH){
		if(rand()%2 == 1){
			v.push_back(1);  // four bits for maintaing constant length after addition 
		} else {
			v.push_back(-1);
		}
	}

	return v;
}


vector<int> addBitVectors(vector<int> s1, vector<int> s2){
	vector<int> c;
	R(i,LENGTH){
		c.push_back(s1[i] + s2[i]);
	}
	return c;
}
vector<int> leftShift(vector<int> s1){
	vector<int> c;
	c.push_back(0);
	FOR(i,1,LENGTH){
		c.push_back(s1[i-1]);

	}
	return c;
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
    		source[index].push_back(stoi(ss));
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

int getNearestProfileVector(vector<int> profileVector[10], vector<int> rowXored){
	double max_cosine_simmilarity =-2;
	int max_cosine_simmilarity_label = -1;
	double cosineSimillarities=0;
	for(int i=0;i<10;i++){
		cosineSimillarities =  cosineSimillarity(profileVector[i],rowXored);
		if(cosineSimillarities > max_cosine_simmilarity ){
			max_cosine_simmilarity = cosineSimillarities;
			max_cosine_simmilarity_label = i;
		}
	}
	return max_cosine_simmilarity_label;
}

int main()
{
	// vector<int> a,b,c,d;
	// a = randTenThousandBitString();
	// b = randTenThousandBitString();
	// c = addBitVectors(a,b);
	// d = leftShift(a);
	// R(i,LENGTH){
	// 	printf("%d %d %d %d\n",a[i],b[i],c[i],d[i] );
	// }
	 srand (time(NULL));
	 int k=150; // depends on the given text
	 map <vector<int>,int> mapping;
	 map <int,vector<int> > reverse_mapping;
	 int miss=0, hit =0;

	 // genrates the map of string and reverse string
	 for(int i = 0 ;i<k;i++){
	 	vector<int> v1 = randTenThousandBitString();
	 	mapping.insert(pair <vector<int>,int>(v1,i));
	 	reverse_mapping.insert(pair<int,vector<int> > (i,v1));
	 }
	 //////////////////////////////////
	// read the file
	readFile("k150.txt");
	////////////////////////////////////
	 vector<int>  singletriplet, rowXored, profileVector[10];
	//Training
	for(int profiles = 0; profiles< 10; profiles++) {
		for(int i=0;i<30;i++){
			for(int j=0;j<source[40*profiles+i].size()-2;j++) { /// for triplet 
				singletriplet = addBitVectors(addBitVectors(leftShift(leftShift(reverse_mapping.at(source[40*profiles+i][j]))),leftShift(reverse_mapping.at(source[40*profiles+i][j+1]))),reverse_mapping.at(source[40*profiles+i][j+2]));

				if(rowXored.size()==0){
					rowXored = singletriplet;
				} else {
					rowXored = addBitVectors(rowXored,singletriplet);
				}
			}
			if(profileVector[profiles].size()==0){
				profileVector[profiles] = rowXored;
			} else {
				profileVector[profiles] = addBitVectors(profileVector[profiles], rowXored);
			}
		}
	}
	 // R(i,1) {
	 // 	R(j,LENGTH){
	 // 		printf("%d ",profileVector[i][j] );
	 // 	}
	 // 	printf("\n");
	 // }
	 

	 //testing
	int label[100];	
	for(int profiles =0 ; profiles<10; profiles++){
		for(int i =30;i<40;i++){
			for(int j=0;j<source[40*profiles+i].size()-2;j++) { /// for triplet 
				singletriplet = addBitVectors(addBitVectors(leftShift(leftShift(reverse_mapping.at(source[40*profiles+i][j]))),leftShift(reverse_mapping.at(source[40*profiles+i][j+1]))),reverse_mapping.at(source[40*profiles+i][j+2]));

				if(rowXored.size()==0){
					rowXored = singletriplet;
				} else {
					rowXored = addBitVectors(rowXored,singletriplet);
				}
			}
			label[10*profiles+i-30] = getNearestProfileVector(profileVector,rowXored);
			if(label[10*profiles+i-30]!=profiles){
				miss++;
			} else {
				hit++;
			}
		}
	}

	R(i,100){
		printf("profiles %d,Label %d\n",i,label[i]);
	}

	printf("hit-%d\nmiss-%d\n",hit,miss );


	return 0;
}