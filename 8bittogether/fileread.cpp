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

int main()
{
  string line;
  ifstream myfile ("k50.txt");
  vector<int> v[400];
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

  else cout << "Unable to open file"; 

  R(i,index){
  	printf("\n%d-->", i+1);
  	R(j,v[i].size()){
  		printf("%d ",v[i][j] );
  	}
  }

	
	return 0;
}