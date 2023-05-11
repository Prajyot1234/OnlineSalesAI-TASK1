#include<bits/stdc++.h>
using namespace std;

int main(){
	int type;
	//Enter 1 for entering dice probability
	//Enter 2 for entering coin probability
	cin>>type;
	int n;
	if(type==1){
		n=6;
	}
	else{
		n=2;
	}
	//Format of input
	//for dice 
	//6 times
	//key probability
	//Example:
		//1 10
		//2 30
		//3 15
		//4 15
		//5 30
		//6 0

	//for coin
	//HEAD=1	TAIL=2
	//2 times
	//key value
	//Example:
		//1 35
		//2 65
	vector<pair<int,int>> range;	
	int lastProb=0;
	for(int i=0;i<n;i++){
		int key,value;
		cin>>key>>value;
		if(value==0){
			range.push_back({-1,-1});
		}
		else{
			range.push_back({lastProb,lastProb+value-1});
			lastProb+=value;
		}
	}

	int result[n]={0};
	for(int i=0;i<1000;i++){
		int number=rand();
		if(number<-1)	number*=-1;
		number%=100;
	
		for(int j=0;j<n;j++){
			if(range[j].first<=number && number<=range[j].second){
				result[j]++;
				break;
			}
		}		
	}
	for(int i=0;i<n;i++){
		printf("%d %d\n",i+1,result[i]);
	}

	return 0;
}
