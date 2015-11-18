#include <iostream>
using namespace std;

struct interval{
	int buy, sell;
};

void stockbuysell(int *price, int n){
	if(n == 1)
		return;
	int cnt = 0;
	interval sol[n/2+1];
	int i = 0;
	while(i < n - 1){
		while(i < n - 1 && price[i+1] <= price[i])
			++i;

		sol[cnt].buy = i++;

		while(i < n && price[i] >= price[i-1])
			++i;

		sol[cnt].sell = i - 1;
		cnt++;
	}
	if(!cnt)
		cout<<"ERROR"<<endl;
	else{
		for (int i = 0; i < cnt; ++i){
			cout<<"Buy on day "<<sol[i].buy<<" and sell on day "<<sol[i].sell<<endl;
		}
	}
}

int main(){
	int n;
	cin>>n;
	int price[n];
	for (int i = 0; i < n; ++i)
		cin>>price[i];
	stockbuysell(price, n);
}