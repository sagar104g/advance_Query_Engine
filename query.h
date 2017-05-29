

#ifndef _QUERY_H_
#define _QUERY_H_		

//this calss is supermap it contaions all relivent data which are indexed from crawled files
class supermap{
    private:
        std::unordered_map<char,std::unordered_map<std::string,std::set<std::pair<int,std::string> > > > mainmap;
        std::ifstream file;
    public:
        supermap();
        void loadfromfile();                         //this function is use to load data from file
        void insert(std::string,int,std::string);    //this function is use to search data from indexed file
        void output();                               //this function output the result
        std::unordered_map<char,std::unordered_map<std::string,std::set<std::pair<int,std::string> > > > getMap();
};

std::vector<std::pair<int,std::string> > weight(std::unordered_map<char,std::unordered_map<std::string,std::set<std::pair<int,std::string>>>>,std::string);

#endif