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
# define LENGTH 1250 // 10000/8 =  1250
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
	//cout << paddZeroes(to_string((firstByte & MASKMSB) << 1)) << "\n";
	//cout << (253 & 127) << "\n";
	
	for(int i=1;i<LENGTH;i++){
		int current = eightBitToInteger(s,i);
		int successor = eightBitToInteger(s,i-1);
		int resultInt = ((current & MASKMSB) << 1) + ((successor <= MASKMSB) ? 0 : 1) ;
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

int getNearestProfileVector(string profileVector[10], string rowXored){
	int minimum_hamming_distance =100000;
	int minimum_hamming_distance_label = -1;
	int hammingDistanc=0;
	for(int i=0;i<10;i++){
		hammingDistanc =  hammingDistance(profileVector[i],rowXored);
		if(hammingDistanc <minimum_hamming_distance ){
			minimum_hamming_distance = hammingDistanc;
			minimum_hamming_distance_label = i;
		}
	}
	return minimum_hamming_distance_label;
}

int main()
{
	 srand (time(NULL));
	 int k=50; // depends on the given text
	 map <string,int> mapping;
	 map <int,string> reverse_mapping;
	 int miss=0, hit =0;
	 // function testing
	//  string s1 ="104172108246001241174213145222136064160078067222044043049112091252185120084110233102203215119038240023117215049051053000095126198136025153130095208119180117238056000170088211151101078026167041105001200054174201013216021104097061012238071239109150097039056062232179101095175090015013142199042223126233069117203142237137084175196038220114083166096134152109055245039022159146177029197019143252125045153247099187078190180202217105027125110168008244159146187175189255114114206137085235010137037006145148037166007240187130082099201093117060170003117051153170136169040039085248097223212084011142176096071117201100247188055064149096087086126063211075136002248175148070069202143197221111059210151158190211128075119037078181128089161089152109037000107124120219051041179232210055219022254123120225165228032181130234123019160172144165045083200012000089177115053198158099212114101241230056054044209017018185096222122136094043242236230121014099229006145036245127200164193142232056154195049218045060132004069125052078002115233076016103159155100162069202076017027053090126009002114080233202237224122137043046251173109139104230214101042078117075123070163186011032088222067012096088076146158209015180041136130064118099004026125137224017037175075111149126028188043167169108146211146164065116189056122007226078076139017065032192121231150070054132194222198052132077071042253204040074066087224142236081192105192215011035133095017149119202145043130209025022160148100026154213024127210175017095067222094165105069024208227157152065072017054191117073035064181070055139074062141116123117039085144127005248156095121153088198254241109059252189210046195067051004149227109068102042052019155228027186003025227138082055241228151164120000148123251131097056099183186095012255213025044100214128220187096116088144125192112231191227025136027033236232200049183113133125225048204181076034062145071235036109094021224180032124021060065140165188155108174204200139062049227152022075188006164161041043023215166001194049253092057010184000021236034169075093098038226197241082128061134233045187061059094201032248007225090166063055082133252146234216087044252163194230123041117171178060203117061005077208116015133089208141055185209155040077129216176118151020208009135040186245084210204044075002241165150166052083074020073121171046232169202112224195033066236095204058106077198084018183169046003006146137020091202194003244050034205082105233145141112166132030212131143007014199202227038131027212151044031129104179066180034042025042085209150255043192086223070166001227060120059215036025157179109186233158239099126001195142231020002196097134093047078109049215182140146247021207204217175188209201199155223150067016213086245212161167173233191196089250004003233086216052253057124064146089037073176022193068060074069190196080026027242244040080049114123102076057014055012156054016178244234187010123100116042163179054092216015166120083208146232007118194233148245093193025058112060017238229201112173230059154075223019227204125245210135246211089038132095196156138094126118101157022151166193182024188146097045228177038240146010217100177161015181047111179176223198162239209145223005111198160023150211198141213233209040067250110153069123189230201239042105020015082231212002171084224239187033137187159070217147159085231106113089133245243136128066147019245092166212068250236184251244015016076141182083181006201020099093171008164203149120215205082239241031073012066204166061075090116139005203055229039216096114246194188139049043015133077180106117109048095221116147041081162236189117178180178073119001242038030197194223028127045191029153022159197116172098030115012133164115145241021244044013148148187160077182243159115113236045221134118159028070004014031187219156225133024241144217163227212094160132125061240142076156066";
	//  string s2 = "109007167250134079085125006056030120080241201201114232209012199201197054222167236213146250049047239182028055209225156090241125216101210121081229128015138142010172124184145222015193011208101119149218053150083097066186088072093234091190121113001065090199168191222012023109080007173130043163088044214057000101146176149221245249105187010177065118189218227092040092024246218085230231199107137163022042133117158238201069048043212204021119142073030115159230242221219241014163083077129107090016019155046219137092220163253028200138163058060162082187221249254106146062214021112229211127010007057229144238213093050202143199193114004216184201252078164156151060053137137208105128211223066130186217197074118218192099175246187254139122114022003241105111136001046078193162038146187101107176139245074123104011092192124026001099083042087220046081042018094134139214223077168199145086251078033221047127251204240058098168117223051007170130074106052087011075151046064013024053093206250067024121225229188198195170045203201252000151135147057096005178137107105085213158083059123076031043125008043179048050124238105170248136108229205125241037059127132111101235050246201016026028028209134236146179138169030075231039057152020092155185227012151201044193202254218041005104150161238013178062076138112062178039122158160089218157186101208074044113109008149153136134189101250199118242225022252220156041132050073008021120076212136076135138176225064211183113171146059202230202191102152033033118139255083156237018254197151176011013090092058228131041008102000025018121122097225036222229016001090145150213198040016125149008127132024015195097018070053157141090131089146195096010029167191246063234207248059249127232122052065102112057069075059097043100063252239230176127126195178058170212082006036095202166083183122016230011138133166254069115085255253097027198151039051058116085097090014020155106050255045200082106018212196140043204161189244022234241199080068223194169207187117115179210194235125240222188014054158167154177179043168111045050005086003035011162200057039249006016038160233174248156081042060145173206029247230150083213031035146018081121098080185053057088211235115250254020101139217096044138252220042076113133028182150220038152071100214153223246218066192238209211029035121153012139118150204098250067147061090212052205214107097169183039099243234190145245041150039106048208033197087225219134083210022040009240210228053215140059173016008031040048240147109148179040018064118061175035201091117064032191018170222103176008021226149087111149195174010043090114144228019005242074083151127022035209140230075149118226157051245211223235004067223189025053006148116124038197186023161197204116128021087153252173206062139078026252204062252208158134105014151050168142011109007148242127205077100234005142089171063225078029083124045246183030155215000138103200123124098095232107063152222010115238226248236229050217102074134152200176214221134000105200028175033156254033015205178112027032187242009237243011228109003012140122030098017081071009142033165210002249091060241060216149222088053045085112150225169125227174053147239048184076227206003143198066132171194156011070129142028097142120011211043220067243225166055224076077036007191119112048162228086044065191108048076047221138073029072153002022145223034212126032131022222214027145036002056205202178037052132057194174233038159026125135101030155234211057059209085070159037230126253112004003144253097162109016107037045063239168219015019056070178177162073150214000196056126187144114044229166034023155152074209008193208151022201076044039000016030196151150208120157242168253007082255116037139066217188022050080166149198088111012220102041218065153000046232003041231057060141080106030179176081221049131130086033178154140187025215114151103087028080169190063140247";
	
	//  cout << "Hamming Distance\n" << hammingDistance(s1,s2) ;
	// cout << "XOR String\n" << xorTenThousandBitString(s1,s2) ;
	//  cout << "leftShift\n" << leftShift(s1) ;
	// cout << "rightShift\n" << rightShift(s1) ;

	// genrates the map of string and reverse string
	 for(int i = 0 ;i<k;i++){
	 	string s1 = genrateTenThousandBitString();
	 	mapping.insert(pair <string,int>(s1,i));
	 	reverse_mapping.insert(pair<int,string> (i,s1));
	 }
	 //////////////////////////////////
	// read the file
	readFile("k50.txt");
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
	// R(i,10) 
	// cout << profileVector[i] <<"\n";


	// testing
	

	int label[100];	
	for(int profiles =0 ; profiles<10; profiles++){
		for(int i =30;i<40;i++){
			rowXored ="";
			for(int j=0;j<v[40*profiles+i].size()-2;j++) { /// for triplet 
				singletriplet = xorTenThousandBitString(xorTenThousandBitString(leftShift(leftShift(reverse_mapping.at(v[40*profiles+i][j]))),leftShift(reverse_mapping.at(v[40*profiles+i][j+1]))),reverse_mapping.at(v[40*profiles+i][j+2]));

				if(rowXored==""){
					rowXored = singletriplet;
				} else {
					rowXored = xorTenThousandBitString(rowXored,singletriplet);
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