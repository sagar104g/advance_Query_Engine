#include <iostream>
#include <fstream>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
#include "query.h"

supermap::supermap(){
    file.open("/home/vipin/Project/file/index.txt");
    loadfromfile();
}
//this function is use to load data from file
void supermap::loadfromfile(){
    std::string line;
    for(; getline(file, line);) {
        std::string word="";
        int i=0;
        while(line[i]!=' ')
            word+=line[i++];
        i++;
        while(line[i]!='\0'){
            std::string nn="";
            while(line[i]!=' ')
                nn+=line[i++];
            i++;
            int occur=std::stoi(nn,0,10);
            nn="";
            while(line[i]!=' ')
                nn+=line[i++];
            insert(word,occur,nn);
            i++;
        }
    }
    file.close();
}
//this function used to input data in supermap from file
void supermap::insert(std::string word, int occurance, std::string url){
    mainmap[word[0]][word].insert(std::pair<int,std::string>(occurance,url));
}

std::unordered_map<char,std::unordered_map<std::string,std::set<std::pair<int,std::string> > > > supermap::getMap(){
	return this->mainmap;
}

//this function used to put weight of words in mainmap
std::vector<std::pair<int,std::string> > weight(std::unordered_map<char,std::unordered_map<std::string,std::set<std::pair<int,std::string> > > > u_map1,std::string str){
	std::unordered_map<char,std::unordered_map<std::string,std::set<std::pair<int,std::string> > > >::const_iterator i_u_map1;
	std::vector<std::pair<int,std::string> > main_vector;
	std::vector<std::pair<int,std::string> >::iterator i_main_vector;
	std::unordered_map<std::string,std::set<std::pair<int,std::string> > > u_map2;
	std::unordered_map<std::string,std::set<std::pair<int,std::string> > >::iterator i_u_map2;
	char *temp=strtok(&str[0]," ?,.|/+-");
	while(temp!=NULL){
  		int flag=0;
  		int count=0;
		i_u_map1=u_map1.find(temp[0]);  
		std::set<std::pair<int,std::string> >::iterator i_set1;
		std::set<std::pair<int,std::string> > set1;
    	set1=u_map1[temp[0]][temp];
    	for(i_set1=set1.begin(); i_set1!=set1.end(); i_set1++){
       		if(main_vector.size()!=0){
       			for(i_main_vector=main_vector.begin();i_main_vector!=main_vector.end();i_main_vector++){
         			if((*i_set1).second==(*i_main_vector).second){
          				flag=1;
          				(*i_main_vector).first++;
          				break;
         			}
       			}
       		}
      		if(flag==0){
        		main_vector.push_back(make_pair(1,(*i_set1).second) );
       		}
		}
    	temp=strtok(NULL," ,.|?/+-"); 
    	count++;
	}
	std::sort(main_vector.rbegin(), main_vector.rend());
	return main_vector;
}