#if 0
#include <iostream>							/*cin,cout*/
#include <string>							/*string,getline,begin,end*//*�����D�A���ޥΨ̵M�i���`�B�@*/
#include <sstream>							/*istringstream*/
#include <vector>							/*vector,push_back*/
#include <iterator>							/*�٨S�Ψ�*/
#include <algorithm>						/*remove_if*/
#include <fstream>							/*fstream*/
#include <set>								/*set*/
#include <utility> 							/*pair*/
#include <cstdlib>
#include <map>

using namespace std;		
bool not_alphanumeric(char s) {				/*�Ыؤ@�Ө禡�ΨӧP�_�O�_���r���M�Ʀr*/
	if(isalnum(s)){							/*�p�G�O�r���M�Ʀr*/
		return false;						/*��^false�A�]�N�O�b�U���ڭ̤��@��*/
	}
	return true;							/*�_�h�p�G���O�r���M�Ʀr�A��true�A�b�U���Q�ޥΡA�N�Q�ڭ̧R��*/
}

//jobs speech short.txt
//jobs speech in stanford.txt
int main(){
	fstream file;							/*�ŧi�@��fstream�A�Q�ΨӶ}���ɮרÿ�J��artical*/
	string fileName;						/*�ŧi�@��string�Q�Ψӿ�JfileName�d��file*/
	string artical;							/*�ŧi�@��string�Q�ΨӦs��file�����e�A�÷|�Q�ƻs��sstream��*/
	vector<string> word;					/*�ŧi�@��word�Ӧs����Ϋ�¦r���M�Ʀr��string vector*/
    string words;							/*�ŧi�@��words�Ψӱ���sstream���L�Ů��J�A�æP��push_back��word string vector��*/
    set <string> word_in_artical;			/*�ŧi�@��set�ΨӦs��L���Ʀr���A�æb���ᰵ���ƥX�{���ƪ������Ƨ�(pair)*/
	int i;									/*�ŧi�@��int i�Q�ΨӰ�iterator(���N)*/

	getline(cin, fileName);					/*Ū��cin������r��fileName*/
	file.open(fileName);					/*open�@���ɮצW�٬�fileName��file*/
		
	if(!file.is_open())						/*�p�Gfile.is_open������*/
	{
	   cout<<"file open failed"<<endl;		/*��X""�ô���*/
	}
	else									/*�_�h*/
	{
		getline(file, artical);				/*��file�����ɮ׾���檺Ū����artical*/
	
    }

    istringstream sstream(artical);			/*�ŧi�@��istringstream�A�ƻsartical�����e�A�æb����Q�ΨӰ���X*/

    
    while(sstream >> words){				/*��ڧ�sstream��J��words(�o�O�֩w�y)*/
 											/*words�|�R��(erase)(�_�I:(��words�}�Y�쵲����쪺not_alphanumeric���ʨ�words���̫�),�@���R��:words���̫�)*/
		words.erase(remove_if(words.begin(), words.end(), not_alphanumeric), words.end());   	
		word.push_back(words);				/*��words����r��J��word���̫�*/
//		word_in_artical.insert(words);		/*��woeds����r���J��word_in_artical*/
	}
	
	
	for(i = 0;i<word.size();i++){ 			/*�Ыؤ@�Ӵ`���h�]i�q0�}�l�A��p��word��size�A�U�@��������i+1*/
	cout<<word[i]<<endl;} 					/*�L�Xword����i��*/
		
//  	for (const auto &s : word_in_artical) {	/*�Ыؤ@�Ӵ`���h�]s�As�Oword_in_artical�̪�����*/
//        cout << s << endl;					/*�L�Xs*/
//    }


//	map<string, int> word_count;// empty
// 
////	string word[]="abcdefg";
//	for (int j = 0; j <word_in_artical.size(); j++)
//	{
//		++word_count[word[j]];                      // �ΤU???
//	}
//	map<string, int>::iterator iter;             // iter ?pair ?��(value_type)
// 
//	for (iter = word_count.begin(); iter != word_count.end(); iter++)
//	{
//		cout << "[" << iter->first << "] = " << iter->second << endl;//iter->first:key,iter->second:value
//	}
//	
//	vector<map<string, int>::iterator> v;
//      map<string, int>::iterator CountIt = word_count.begin();
//      while (CountIt != word_count.end())
//      {
//           v.push_back(CountIt);
//           ++CountIt;
//      }
//      struct Compare
//      {
//           bool operator()(map<string, int>::iterator l, map<string, int>::iterator r)
//           {
//                return l->second > r->second;
//           }
//      };
//      sort(v.begin(),v.end(),Compare());
//		map<string, int>::iterator it = word_count.begin();
//      system("pause");

//map<string,int> word_count;//�]?�bmap�e����?�s?�N�O���Ǳƪ�
// string wordi;
// while(sstream>>wordi&&wordi!="0") word_count[wordi]++;
// 
// for(auto &c:word_count)
//  cout<<c.first<<" "<<c.second<<endl;
//  return 0;


	return 0;
}
	
//    return 0;
//}
#endif
/*  int i;
    for(i = 0;i < sizeof(artical);i++){
    	cout<<artical[i]<<endl;
    	if(!isalnum(artical[i])){
    		artical.erase(i, 1);
    		i--;
		}
	}
    artical.erase(std::remove_if(artical.begin(), artical.end(), not_alpha), artical.end());
    cout<<artical<<endl;
	*/
	
	
	/*
	���O:
	��pair���@����ȹ�
	��sort�Mgreater���@�ӭ����Ƨ�
	
	�n������:
	��C�Ӧr���ƪ����Ƨ�X��
	��set�����e���pair t1
	�⭫�ƪ����ƥ��pair t2
	make pair�@�ӭ����ƧǪ�pair
	*/

#if 0
#include <iostream>
#include <map>
#include<string>
using namespace std;

int main()
{
	map<string,int> m;
	string word[500];
	int i, j;
	cout << "Input the essay (0??���)" << endl;
	for (i = 0;; i++)
	{
		cin >> word[i];
		if (word[i] == "0")
			break;
	}
	for (j = 0; j < i; j++)
	{
		map<string, int>::iterator iter = m.find(word[j]);
		if (iter != m.end())
		{
			iter->second++;
		}
		else
		{
			m.insert(pair<string, int>(word[j], 1));
		}
	}
	map<string, int>::iterator iter = m.begin();
	for (iter; iter != m.end(); iter++)
	{
		cout << iter->first << "  " << iter->second << endl;
	}
	return 0;
}

#endif 

#if 0 
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(void)
{
    int i;
    int a[] = { 1, 2, 3, 4, 5, 5, 5 };
    map<vector, int> m;
    for (i = 0; i < m.size(); i++)
    {
        if (m.end() != m.find(a[i])) m[a[i]]++;
        else m.insert(pair<int, int>(a[i], 1));
    }
    for (auto it : m)
    {
        cout << it.first << ends << it.second << endl;
    }
    return 0;
}

#endif

#if 0 
#include <iostream>							/*cin,cout*/
#include <string>							/*string,getline,begin,end*//*�����D�A���ޥΨ̵M�i���`�B�@*/
#include <sstream>							/*istringstream*/
#include <vector>							/*vector,push_back*/
#include <iterator>							/*�٨S�Ψ�*/
#include <algorithm>						/*remove_if*/
#include <fstream>							/*fstream*/
#include <set>								/*set*/
#include <utility> 							/*pair*/
#include <cstdlib>
#include <map>

using namespace std;		
bool not_alphanumeric(char s) {				/*�Ыؤ@�Ө禡�ΨӧP�_�O�_���r���M�Ʀr*/
	if(ispunct(s)){							/*�p�G�O�r���M�Ʀr*/
		return true;						/*��^false�A�]�N�O�b�U���ڭ̤��@��*/
	}
	return false;							/*�_�h�p�G���O�r���M�Ʀr�A��true�A�b�U���Q�ޥΡA�N�Q�ڭ̧R��*/
}

//jobs speech short.txt
//jobs speech in stanford.txt
int main(){
	fstream file;							/*�ŧi�@��fstream�A�Q�ΨӶ}���ɮרÿ�J��artical*/
	string fileName;						/*�ŧi�@��string�Q�Ψӿ�JfileName�d��file*/
	string artical;							/*�ŧi�@��string�Q�ΨӦs��file�����e�A�÷|�Q�ƻs��sstream��*/
	vector<string> word;					/*�ŧi�@��word�Ӧs����Ϋ�¦r���M�Ʀr��string vector*/
    string words;							/*�ŧi�@��words�Ψӱ���sstream���L�Ů��J�A�æP��push_back��word string vector��*/
 string temp;
	int i;									/*�ŧi�@��int i�Q�ΨӰ�iterator(���N)*/

	getline(cin, fileName);					/*Ū��cin������r��fileName*/
	file.open(fileName);					/*open�@���ɮצW�٬�fileName��file*/
		
	if(!file.is_open())						/*�p�Gfile.is_open������*/
	{
	   cout<<"file open failed"<<endl;		/*��X""�ô���*/
	}
	else									/*�_�h*/
	{
		while(getline(file,temp))artical+=temp;
    	file.close();				/*��file�����ɮ׾���檺Ū����artical*/
	
    }

    stringstream sstream(artical);			/*�ŧi�@��istringstream�A�ƻsartical�����e�A�æb����Q�ΨӰ���X*/

    
    while(sstream >> words){				/*��ڧ�sstream��J��words(�o�O�֩w�y)*/
 											/*words�|�R��(erase)(�_�I:(��words�}�Y�쵲����쪺not_alphanumeric���ʨ�words���̫�),�@���R��:words���̫�)*/
		words.erase(remove_if(words.begin(), words.end(), not_alphanumeric), words.end());   	
		word.push_back(words);				/*��words����r��J��word���̫�*/

	}
	
	artical>>sstream;
//	for(i = 0;i<word.size();i++){ 			/*�Ыؤ@�Ӵ`���h�]i�q0�}�l�A��p��word��size�A�U�@��������i+1*/
//	cout<<word[i]<<endl;} 					/*�L�Xword����i��*/
	string input;	
		map<string, int> word_count;
while(sstream >> input) {
++word_count[input];
}
for(map<string, int>::iterator i=word_count.begin(); i!=word_count.end(); ++i) {
cout << i->first << " : " << i->second << endl;
}

return 0;
}
#endif
#if 0
#include <iostream>							/*cin,cout*/
#include <string>							  /*string,getline,begin,end*//*�����D�A���ޥΨ̵M�i���`�B�@*/
#include <sstream>							/*istringstream, sstream>>*/
#include <vector>							  /*vector,push_back*/
#include <iterator>							/*�٨S�Ψ�*/
#include <algorithm>						/*remove_if*/
#include <fstream>							/*fstream*/
#include <set>								  /*set*/
#include <utility> 							/*pair*/
#include <cstdlib>
#include <map>

using namespace std;		
bool not_alphanumeric(char s) {				/*�Ыؤ@�Ө禡�ΨӧP�_�O�_���r���M�Ʀr*/
	if(isalnum(s)){							        /*�p�G�O�r���M�Ʀr*/
		return false;						          /*��^false�A�]�N�O�b�U���ڭ̤��@��*/
	}
	return true;							          /*�_�h�p�G���O�r���M�Ʀr�A��true�A�b�U���Q�ޥΡA�N�Q�ڭ̧R��*/
}

//jobs speech short.txt
//jobs speech in stanford.txt
int main(){
	fstream file;							  /*�ŧi�@��fstream�A�Q�ΨӶ}���ɮרÿ�J��artical*/
	string fileName;						/*�ŧi�@��string�Q�Ψӿ�JfileName�d��file*/
	string artical;							/*�ŧi�@��string�Q�ΨӦs��file�����e�A�÷|�Q�ƻs��sstream��*/
	vector<string> word;				/*�ŧi�@��word�Ӧs����Ϋ�¦r���M�Ʀr��string vector*/
    string words;							/*�ŧi�@��words�Ψӱ���sstream���L�Ů��J�A�æP��push_back��word string vector��*/
 
	int i;									    /*�ŧi�@��int i�Q�ΨӰ�iterator(���N)*/

	getline(cin, fileName);			/*Ū��cin������r��fileName*/
	file.open(fileName);				/*open�@���ɮצW�٬�fileName��file*/
		
	if(!file.is_open())					/*�p�Gfile.is_open������*/
	{
	   cout<<"file open failed"<<endl;		/*��X""�ô���*/
	}
	else{									                /*�_�h*/
		
		while(getline(file, artical)){};				      /*��file�����ɮ׾���檺Ū����artical*/
	}
    

    istringstream sstream(artical);			/*�ŧi�@��istringstream�A�ƻsartical�����e�A�æb����Q�ΨӰ���X*/

    
    while(sstream >> words){				    /*��ڧ�sstream��J��words(�o�O�֩w�y)*/
 		/*words�|�R��(erase)(�_�I:(��words�}�Y�쵲����쪺not_alphanumeric���ʨ�words���̫�),�@���R��:words���̫�)*/
		words.erase(remove_if(words.begin(), words.end(), not_alphanumeric), words.end());   	
		word.push_back(words);				      /*��words����r��J��word���̫�*/

	}
	
	
	for(i = 0;i<word.size();i++){ 			  /*�Ыؤ@�Ӵ`���h�]i�q0�}�l�A��p��word��size�A�U�@��������i+1*/
	cout<<word[i]<<endl;} 					      /*�L�Xword����i��*/
		
return 0;
}
#endif

#if 1
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,int>a,pair<string,int> b){
	return a.second > b.second; //�]�w�ƧǥѤj��p 
}

int main(){
	//jobs speech short.txt		
    fstream file; //Ū���ܼ� 
    string fileName,article,temp;
    vector<string> word;
	vector<string> word_in_artical; //�Ψ��x�s�h�����ƪ�string
	vector<pair<string,int>> number_of_appearances;
	
    getline(cin,fileName); //Ū�J�ɦW 
    
    //�}�ɮ� 
    file.open(fileName);
    if(!file.is_open())cout<<"Could not open the file";
    else{
    	while(getline(file,temp))article+=temp;
    	file.close();
    }
    temp = "";                                                         /*��l��temp���Ŧr��*/
    
    //�NŪ�J�ɮפ������I�Ÿ��P�Ů�h���A�u�d�U�^��M�Ʀr 
    for(int i=0;i<article.size();i++){	
		if (isalpha(article[i])||isdigit(article[i]))temp += article[i];   /*�p�Garticle[i]�O�r��(alpha)��(||)�Ʀr(digit)�A��article[i]+�itemp*/
		if(article[i]==' '||i == article.size()-1){                        /*�p�Garticle[i]�Ospace��i����article��size-1*/
			if(temp!="")word.push_back(temp);                                /*�p�Gtemp������space�A��temp��Jword���̫�*/
			temp = "";                                                       /*�Ntemp�b��*/
		}
    }
    
    //�ˬd���ƨçR�� 
	word_in_artical.assign(word.begin(),word.end());                     /*�Nword�����C�����t��word_in_artical*/
	sort(word_in_artical.begin(),word_in_artical.end()); //�ϥ�unique�禡�i�R��"�s�򭫽�"�����A���ϥ�sort�A�N�ۦP�������ƧǦb�@�_ 
    vector<string>::iterator it = unique(word_in_artical.begin(),word_in_artical.end());
    word_in_artical.resize(distance(word_in_artical.begin(),it)); //unique�ä���erase�@�˷|�۰ʲM��vector�Ŷ��A�ҥH����resize�A�R��null���� 

	//���F�p��r�꭫�ƥX�{���ơA�}�@�ӥHpair�զ���vector�A��K�p�� 
	for(int i=0;i<word_in_artical.size();i++)
		number_of_appearances.push_back(make_pair(word_in_artical[i],0));  /*��word_in_artical[i]��key, 0��value, make a pair, �ÿ�J�inumber_of_appearances��*/
	
	//�̧��ˬd�p�Ʈe���̪��C�Ӧr��C�Y�b��e�����j�M��A�N�q��e�����N�Ӧr��R���A�æb�p�Ʈe���U+1 
    for(int i=0;i<number_of_appearances.size();i++){
    	for(int j=0;j<word.size();j++){
    		if(number_of_appearances[i].first==word[j]){                   /*�p�Gnumber_of_appearances[i]��key����word[j]*/
    			number_of_appearances[i].second++;                           /*number+of_appearances[i]��value +1*/
    			word.erase(word[*j]);                                  /*�R��(erase)word����begin+j�����@��*/
			}
    	}
	}

	//�Ƨǭp�Ƶ��G�ÿ�X 
	sort(number_of_appearances.begin(),number_of_appearances.end(),compare);
	for(pair<string,int> thePair:number_of_appearances)                  /*�Ыؤ@�Ӵ`���hrun thePair�AthePair�Onumber_of_appearances��������*/
		cout<<thePair.first<<" "<<thePair.second<<endl;                    /*cout thePair��key(first:string)�Mvalue(second:int)*/

}
#endif

1 2 3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8

