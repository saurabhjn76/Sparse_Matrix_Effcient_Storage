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

vector<double> randomProbab(){
	vector<double> a;
	double sum=0;
	R(i,10){
		a.push_back(rand()%10);
		sum+=a[i];
	}
	R(i,10){
		a[i]/=sum;
	}
// double sum2=0;
// R(i,10){
// 	sum2+=a[i];
// }
// printf("%lf\n",sum2 );
// R(i,10){
// 	printf("%lf ",a[i] );
// }
// printf("\n");
return a;
}

double gendouble(){
	 return ((double) rand() / (RAND_MAX)) ;
}

vector<int> genrateSeq(vector<double> cdf[10]){
	vector<int> seq;
	int current_label=0;
R(i,100){
	double ab = gendouble();
	R(j,10){
		if(ab<=cdf[current_label][j]){
			current_label = j;
			seq.push_back(current_label);
			break;
		}
	}
}
return seq;
} 



int main()
{
 srand (time(NULL));
 int t=3;
R(t,3){
vector<double> v[10];
vector<double> cdf[10];
R(i,10){
	//	printf("%lf\n",gendouble());
	v[i] = randomProbab();
}

R(i,10){
	R(j,10){
		if(j==0){
			cdf[i].push_back(v[i][0]);
		} else
		cdf[i].push_back(v[i][j] + cdf[i][j-1]);
	}
	//printf("\n");
}
printf("-------------\n");
printf("PDF %d\n",t);
printf("-------------\n");
R(i,10){
	R(j,10){
		printf("%lf ", v[i][j]);
	}
	printf("\n");
}
printf("-------------\n");
printf("CDF %d\n",t);
printf("-------------\n");
R(i,10){
	R(j,10){
		printf("%lf ", cdf[i][j]);
	}
	printf("\n");
}

vector<int> seq[100];
int current_label=0;
R(k,100){
R(i,100){
	double ab = gendouble();
	R(j,10){
		if(ab<=cdf[current_label][j]){
			current_label = j;
			seq[k].push_back(current_label);
			break;
		}
	}
}
}
//printf("-------------\n");
// R(j,100){
// 	printf("action_%d.txt\n",(100*t)+j+1 );
// 	printf("[");
// R(i,seq[j].size()){
// 	if(i==seq[j].size()-1){
// 		printf("%d]\n",seq[j][i]);
// 	}
// 	else 
// 	printf("%d, ",seq[j][i]);
// }
// }
//printf("-------------\n");

}
 

	
	return 0;
}