#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);//fastens the input
	//always use '\n' instead of <<endl;
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;//it shows the time taken by the program to run
	
	return 0;
}