#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<iterator>
using namespace std;
void Delete_Head_Tail_Char(string &string)
{
    string=string.substr(1,string.length());
    string.resize(string.length()-1);
}
int main()
{
    int num_Line,num_Ques;
    string line;
    cin>>num_Line >>num_Ques;
    cin.ignore();
    map <string,string>Result;
    string str_Now,pLine,properties;
    vector <string> part_Line;
    for(int i=0;i<num_Line;++i)
    {
        getline(cin,line);
        
        // Nếu đóng thẻ 
        if(line[1]=='/')
        {
            //line=line.substr(1,line.length());
            if(str_Now.find(".")!=string::npos)
                str_Now=str_Now.substr(0,str_Now.rfind("."));
        }
        else 
        {
            //Loại bỏ dấu '>' và '<'
            Delete_Head_Tail_Char(line);
            // Loại bỏ dấu '='
            while(line.find("=")!=string::npos)
                line[line.find("=")]=' ';
            istringstream iss(line);
            
            // Chuyển đổi sang chuỗi con 
            while(iss>>pLine)
            {
                if(pLine!="")
                part_Line.push_back(pLine);
                pLine.clear();
            }
            if(str_Now.length())
            str_Now+="."+part_Line[0];
            else str_Now+=part_Line[0];
            for(int i=0;i<part_Line.size()/2;++i)
                {
                    properties=str_Now+"~"+part_Line[i*2+1];
                    Delete_Head_Tail_Char(part_Line[i*2+2]);
                    Result.insert(pair<string,string>(properties,part_Line[i*2+2]));
                }
        }
        line.clear();
        part_Line.clear();
    }
    for(int i=0;i<num_Ques;++i)
        {
            getline(cin,line);
            if(Result.find(line)!=Result.end())
                cout<<Result.find(line)->second<<endl;
            else 
                cout<<"Not Found!"<<endl;
        }
    return 0;
}