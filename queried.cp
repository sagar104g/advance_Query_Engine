#include <iostream>
#include <fstream>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
#include "query.h"

using namespace std;

int main(){
	supermap mainmap;
	char a[1001];
	std::cout<<"Insert query\n";
	std::cin.getline(a,1000);
	std::vector<std::pair<int,std::string>> result=weight(mainmap.getMap(),a);
	for(int i=0;i<result.size();i++){
		std::cout<<result[i].first<<" "<<result[i].second<<std::endl;
	}
	return 0;
}


