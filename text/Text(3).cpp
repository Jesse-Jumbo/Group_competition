#if 0

#include <iostream>											      /*cin, cout*/
#include <string>												  /*string, getline, begin(), end(), compare*/
#include <sstream>												  /*istringstream, sstream >>*/
#include <vector>												  /*vector, push_back, begin(), end()*/
#include <algorithm>											  /*remove_if, sort*/
#include <fstream>											   	  /*fstream*/
#include <map>                                                    /*map*/
#include <set>                                                    /*set, insert*/
#include <cctype>                                                 /*ispunct*/
#include <utility>                                                /*pair, first, second, make_pair*/

using namespace std;                                              /*�ٲ�std*/

bool not_alphanumeric(char s) {						              /*�Ыؤ@�Ө禡�ΨӧP�_�O�_���r���M�Ʀr�A�����^�ǭȬOboolean*/
	if(ispunct(s)){							      		          /*�p�G�O���I�Ÿ�*/
		return true;						      		          /*��^true�A�]�N�O�b�U���Q�ޥΡA�N�Q�ڭ̧R���Ҧ����I�Ÿ�*/
	}
	return false;							   		              /*�_�h��^false�A�]�N�O�b�U���ڭ̤��@��*/
}

bool compare(pair<string,int>a,pair<string,int> b){               /*�Ыؤ@�Ө禡�ΨӤ�����pair�Apair a�Mpair b��<first, second>�A�����^�ǭȬOboolean*/
	return a.second > b.second; //�]�w�ƧǥѤj��p                /*��^a��Type 2�j��b��Type 2�A�N�b�̫᪺final���Q�ڭ̤��final��second(Type 2)�q�j��p�A��sort�̧ǱƧ�*/
}

//jobs speech short.txt
//jobs speech in stanford.txt
int main(){
	fstream file;							                      /*�ŧi�@��fstream�A�Q�ΨӶ}���ɮרÿ�J��article*/
	string fileName;						                      /*�ŧi�@��string�Q�Ψӿ�JfileName�d��file*/
	string temp;						                          /*�ŧi�@��string�A�Q�Ψӷ�while�j�骺�����ܼ�*/
	string article;							                      /*�ŧi�@��string�Q�ΨӦs��file�����e�A�÷|�Q�ƻs��sstream��*/
	vector<string> word;				                          /*�ŧi�@��word�Ӧs����Ϋ�¦r���M�Ʀr��string vector*/
    string words;							                          /*�ŧi�@��words�Ψӱ���sstream���ΪŮ檺�r���J�A�æP��push_back��word string vector��*/
	set<string> word_in_artical; 	   		   //��l��set�A�Ψ��x�s�h�����ƪ�string
	map<string,int> number_of_appearances; //�ϥ�map�p�ơA�[�ַj�M�t�� /*map<key, value>�Akey������const���i���ơA�|�۰ʱƧ�*/
	vector<pair<string,int>> final; 		   //�ΨӱƧǨC��string���X�{���ơA��X�̫ᵲ�G/*�ŧi�@��vector final�A�����ݩʬO�@��pair�A�ҥH�䵲�G�|��X�@��Type 1, Type 2�A�b�o�Q�w�q��<string,int>*/
 
	getline(cin, fileName);					       /*Ū��cin�i������r��fileName*/
	file.open(fileName);					         /*open�@���ɮצW�٬�fileName��file*/
		
	if(!file.is_open())						         /*�p�Gfile.is_open������*/
	   cout<<"file open failed"<<endl;	   /*��X""�ô���*/
	   
	else									                 /*�_�h*/
		while(getline(file, temp))		       /*���file�����ɮ׾���檺Ū����temp*/
			article += temp;                   /*article�N=+�C����temp*/
    
    istringstream sstream(article);			 /*�ŧi�@��istringstream�A�Ψ�Ū��article�����e�A�æb�����X���P���ǥѪŮ氵���Φr��*/
    
    while(sstream >> words){			       /*��ڧ�sstream��J��words(�o�O�֩w�y)*/
 		/*words�|�R��(erase)(�_�I�}�l:(��words�}�Y�쵲����쪺not_alphanumeric�R��),�@����:words���̫�)*/
		words.erase(remove_if(words.begin(), words.end(), not_alphanumeric), words.end());   	
		word.push_back(words);				       /*��words����r��J�iword���̫�*/
	  }

	for(int i=0;i<word.size();i++)word_in_artical.insert(word[i]);   /*�Ыؤ@�Ӱj��(����:i�q�}�l�A�P�_i<word��size�A�U�@��������i+1)�Nword[i]���J��word_in_artical��*/
	//�Nword������Ʀs��word_in_artical���Aset�e�������ڵ���J���ƥX�{����r

	for(string str:word_in_artical)number_of_appearances[str] = 0;   /*�Ыؤ@�Ӵ`���hrun�ŧi��string str�Astr�Oword_in_artical�̪������A�ñNnumber_of_appearances���C��str(key)���ҹ�����value��l�ƹs*/
	//�N���إߦn��set��ƥΨӫإ�map, �ΥH�p�ơF�]�w��lvalue��0
 
	for(string str:word)number_of_appearances[str]+=1;               /*�Ыؤ@�Ӵ`���hrun str�Astr�Oword�̪������A�p�Gnumber_of_appearances��str�A���N�N����key([str])�ҹ�����value+1*//*�i�H�ǥѳX��key�h�ק復��value(key�O����Q�ק諸)*/
	//�M�X��l�r��}�C(�ȳz�L���I�Ÿ��ΪŮ�B�z��)�C�C�M�X��ӳ�r�A�N�b�H�ӳ�r��key��value+1
 
	for(pair<string,int> tmp:number_of_appearances)                  /*�Ыؤ@�Ӵ`���hrun tmp�Apair tmp��<string,int>first, second�Onumber_of_appearances����<string,int>key,value*/
		final.push_back(make_pair(tmp.first,tmp.second));              /*��tmp��Type 1(first), Type 2(second)�����@�ӷs��plair�A�ȩ̀ǿ�J�ifinal���̫�*/
	//�]map�D�ǦC(�u��)�e���A�ҥH���ઽ����sort�禡�C�ݱN���ഫ��t�@�ǦC�ʮe�����x�s�C 
	
	sort(final.begin(),final.end(),compare); //�ϥ�sort�[�W�ۭq�ƧǳW�h�i��Ƨ� /*�Ƨ�(first,last,�̾�)*/
	for(pair<string,int> tmp:final)cout<<tmp.first<<" "<<tmp.second<<endl; //��X���G /*�Ыؤ@�Ӵ`���hrun tmp�Atmp�Ofinl�̪�����*//*cout�Xtmp<Type 1, Type 2>�ᴫ��*/
		
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
		number_of_appearances.push_back(make_pair(word_in_artical[i],0));  /*��word_in_artical[i��first, 0��second, make a pair, �ÿ�J�inumber_of_appearances��*/
	
	//�̧��ˬd�p�Ʈe���̪��C�Ӧr��C�Y�b��e�����j�M��A�N�q��e�����N�Ӧr��R���A�æb�p�Ʈe���U+1 
    for(int i=0;i<number_of_appearances.size();i++){
    	for(int j=0;j<word.size();j++){
    		if(number_of_appearances[i].first==word[j]){                   /*�p�Gnumber_of_appearances[i]��first����word[j]*/
    			number_of_appearances[i].second++;                           /*number_of_appearances[i]��second +1*/
 //   			word.erase(word.begin()+j);                                  /*�R��(erase)word����begin(��0��) + j �����@��*/
			}                                                                /*erase()�����Ѽƻݬ� iterator positon*/
    	}
	}

	//�Ƨǭp�Ƶ��G�ÿ�X 
	sort(number_of_appearances.begin(),number_of_appearances.end(),compare);
	for(pair<string,int> thePair:number_of_appearances)                  /*�Ыؤ@�Ӵ`���hrun thePair�AthePair�Onumber_of_appearances��������*/
		cout<<thePair.first<<" "<<thePair.second<<endl;                    /*cout thePair��first(Type 1:string)�Msecond(Type 2:int)*/

}
#endif

#if 0

#include <iostream>

using namespace std;

int main(){

string text_1[5] = {"1","2"};

string text_2[5] = {"1","1","1","2","1"};

int i = 0;
int count = 0;

for(int i = 0 ; i < 5; i++ ){
    	for(int j=0 ; j<5 ; j++ ){
    		if(text_1[i]==text_2[j]){
    			count++;
//    			word.erase(word.begin()+j);
    		}
    	}
	}
	cout<<count<<endl;
	return 0;
}
#endif
