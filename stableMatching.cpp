/* 
Nama    : Delanika Olympiani T. C.
NPM     : 140810180026
Tujuan  : Program  untuk Stable Matching Problem, menyocokan dari preferences
*/

#include<iostream>
	using namespace std;
	 
	typedef int prefer[5];
	 
	struct people{
	     string name;
	     int engaged;
	     int preferences[5];
	};
	 
	people info(string name, prefer prefers);
	void stableMatching(people (&man)[5], people (&woman)[5]);
	 
	int main(){
	     people man[5], woman[5];
	     prefer prefers;
	 
		prefers[0] = 1; prefers[1] = 0; prefers[2] = 3; prefers[3] = 4; prefers[4] = 2;
		man[0] = info("Victor",prefers);
		prefers[0] = 3; prefers[1] = 1; prefers[2] = 0; prefers[3] = 2; prefers[4] = 4;
		man[1] = info("Wyatt",prefers);
		prefers[0] = 1; prefers[1] = 4; prefers[2] = 2; prefers[3] = 3; prefers[4] = 0;
		man[2] = info("Xavier",prefers);
		prefers[0] = 0; prefers[1] = 3; prefers[2] = 2; prefers[3] = 1; prefers[4] = 4;
		man[3] = info("Yancey",prefers);
		prefers[0] = 1; prefers[1] = 3; prefers[2] = 0; prefers[3] = 4; prefers[4] = 2;
		man[4] = info("Zeus",prefers);
	 
		prefers[0] = 4; prefers[1] = 0; prefers[2] = 1; prefers[3] = 3; prefers[4] = 2;
		woman[0] = info("Amy",prefers);
		prefers[0] = 2; prefers[1] = 1; prefers[2] = 3; prefers[3] = 0; prefers[4] = 4;
		woman[1] = info("Bertha",prefers);
		prefers[0] = 1; prefers[1] = 2; prefers[2] = 3; prefers[3] = 4; prefers[4] = 0;
		woman[2] = info("Clare",prefers);
		prefers[0] = 0; prefers[1] = 4; prefers[2] = 3; prefers[3] = 2; prefers[4] = 1;
		woman[3] = info("Diane",prefers);
		prefers[0] = 3; prefers[1] = 1; prefers[2] = 4; prefers[3] = 2; prefers[4] = 0;
		woman[4] = info("Erika",prefers);
	 
	     stableMatching(man, woman);
	 
	     cout<<"\nRESULT"<<endl;
	     for(int i = 0; i < 5; i++){
	          cout<< man[i].name<< " ♥ " <<woman[man[i].engaged].name<<endl;
	     }
	}
	 
	people info(string name, prefer prefers){
	     people ppl;
	     ppl.name = name;
	     ppl.engaged = -1;
	     for(int i = 0; i < 5;i++){
	          ppl.preferences[i] = prefers[i];
	     }
	     return ppl;
	}
	 
	void stableMatching(people (&man)[5], people (&woman)[5]){
	     bool free = true;
	     int i=0, j=0, m,m1;
	     while(free){
	          if(woman[man[i].preferences[j]].engaged == -1){
	               man[i].engaged = man[i].preferences[j];
	               woman[man[i].preferences[j]].engaged = i;
	          }else{
				int k = 0;
				m = -1; m1 = -1;
				while(m == -1 || m1 == -1){
					if(i == woman[man[i].preferences[j]].preferences[k]){
						m1 = k;
					}
					if(woman[man[i].preferences[j]].engaged == woman[man[i].preferences[j]].preferences[k]){
						m = k;
					}
					k++;
				}
				if(m1<m){
					man[woman[man[i].preferences[j]].engaged].engaged = -1;
					man[i].engaged = man[i].preferences[j];
					woman[man[i].preferences[j]].engaged = i;
				}else{
					j++;
					continue;
				}
			}
			free = false;
			j=0;
			for(int x = 0; x < 5; x++){
				if(man[x].engaged == -1){
					i = x;
					free = true;
					break;
				}
			}
	     }
	}


