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

using namespace std;                                              /*省略std*/

bool not_alphanumeric(char s) {						              /*創建一個函式用來判斷是否為字母和數字，它的回傳值是boolean*/
	if(ispunct(s)){							      		          /*如果是標點符號*/
		return true;						      		          /*返回true，也就是在下面被引用，將被我們刪除所有標點符號*/
	}
	return false;							   		              /*否則返回false，也就是在下面我們不作用*/
}

bool compare(pair<string,int>a,pair<string,int> b){               /*創建一個函式用來比較兩個pair，pair a和pair b的<first, second>，它的回傳值是boolean*/
	return a.second > b.second; //設定排序由大到小                /*返回a的Type 2大於b的Type 2，將在最後的final中被我們比較final的second(Type 2)從大到小，用sort依序排序*/
}

//jobs speech short.txt
//jobs speech in stanford.txt
int main(){
	fstream file;							                      /*宣告一個fstream，被用來開啟檔案並輸入到article*/
	string fileName;						                      /*宣告一個string被用來輸入fileName查找file*/
	string temp;						                          /*宣告一個string，被用來當while迴圈的中介變數*/
	string article;							                      /*宣告一個string被用來存放file的內容，並會被複製到sstream中*/
	vector<string> word;				                          /*宣告一個word來存放分割後純字母和數字的string vector*/
    string words;							                          /*宣告一個words用來接受sstream分割空格的字串輸入，並同時push_back到word string vector中*/
	set<string> word_in_artical; 	   		   //初始化set，用來儲存去除重複的string
	map<string,int> number_of_appearances; //使用map計數，加快搜尋速度 /*map<key, value>，key必須為const不可重複，會自動排序*/
	vector<pair<string,int>> final; 		   //用來排序每個string的出現次數，輸出最後結果/*宣告一個vector final，它的屬性是一個pair，所以其結果會輸出一個Type 1, Type 2，在這被定義為<string,int>*/
 
	getline(cin, fileName);					       /*讀取cin進的整行文字到fileName*/
	file.open(fileName);					         /*open一個檔案名稱為fileName的file*/
		
	if(!file.is_open())						         /*如果file.is_open不成立*/
	   cout<<"file open failed"<<endl;	   /*輸出""並換行*/
	   
	else									                 /*否則*/
		while(getline(file, temp))		       /*當把file內的檔案整行整行的讀取到temp*/
			article += temp;                   /*article就=+每次的temp*/
    
    istringstream sstream(article);			 /*宣告一個istringstream，用來讀取article的內容，並在之後輸出的同時藉由空格做分割字串*/
    
    while(sstream >> words){			       /*當我把sstream輸入到words(這是肯定句)*/
 		/*words會刪除(erase)(起點開始:(把words開頭到結尾找到的not_alphanumeric刪除),一直到:words的最後)*/
		words.erase(remove_if(words.begin(), words.end(), not_alphanumeric), words.end());   	
		word.push_back(words);				       /*把words的單字輸入進word的最後*/
	  }

	for(int i=0;i<word.size();i++)word_in_artical.insert(word[i]);   /*創建一個迴圈(條件:i從開始，判斷i<word的size，下一次的執行i+1)將word[i]插入到word_in_artical中*/
	//將word中的資料存到word_in_artical中，set容器本身拒絕輸入重複出現的單字

	for(string str:word_in_artical)number_of_appearances[str] = 0;   /*創建一個循環去run宣告的string str，str是word_in_artical裡的元素，並將number_of_appearances中每個str(key)項所對應的value初始化零*/
	//將剛剛建立好的set資料用來建立map, 用以計數；設定初始value為0
 
	for(string str:word)number_of_appearances[str]+=1;               /*創建一個循環去run str，str是word裡的元素，如果number_of_appearances有str，那就將它的key([str])所對應的value+1*//*可以藉由訪問key去修改它的value(key是不能被修改的)*/
	//尋訪原始字串陣列(僅透過標點符號及空格處理的)。每尋訪到該單字，就在以該單字為key的value+1
 
	for(pair<string,int> tmp:number_of_appearances)                  /*創建一個循環去run tmp，pair tmp的<string,int>first, second是number_of_appearances中的<string,int>key,value*/
		final.push_back(make_pair(tmp.first,tmp.second));              /*把tmp的Type 1(first), Type 2(second)做成一個新的plair，並依序輸入進final的最後*/
	//因map非序列(線性)容器，所以不能直接用sort函式。需將其轉換到另一序列性容器中儲存。 
	
	sort(final.begin(),final.end(),compare); //使用sort加上自訂排序規則進行排序 /*排序(first,last,依據)*/
	for(pair<string,int> tmp:final)cout<<tmp.first<<" "<<tmp.second<<endl; //輸出結果 /*創建一個循環去run tmp，tmp是finl裡的元素*//*cout出tmp<Type 1, Type 2>後換行*/
		
	return 0;
}

#endif

#if 1

#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,int>a,pair<string,int> b){
	return a.second > b.second; //設定排序由大到小 
}

int main(){
	//jobs speech short.txt		
    fstream file; //讀檔變數 
    string fileName,article,temp;
    vector<string> word;
	vector<string> word_in_artical; //用來儲存去除重複的string
	vector<pair<string,int>> number_of_appearances;
	
    getline(cin,fileName); //讀入檔名 
    
    //開檔案 
    file.open(fileName);
    if(!file.is_open())cout<<"Could not open the file";
    else{
    	while(getline(file,temp))article+=temp;
    	file.close();
    }
    temp = "";                                                         /*初始化temp為空字串*/
    
    //將讀入檔案中的標點符號與空格去除，只留下英文和數字 
    for(int i=0;i<article.size();i++){	
		if (isalpha(article[i])||isdigit(article[i]))temp += article[i];   /*如果article[i]是字母(alpha)或(||)數字(digit)，把article[i]+進temp*/
		if(article[i]==' '||i == article.size()-1){                        /*如果article[i]是space或i等於article的size-1*/
			if(temp!="")word.push_back(temp);                                /*如果temp不等於space，把temp輸入word的最後*/
			temp = "";                                                       /*將temp淨空*/
		}
    }
    
    //檢查重複並刪除 
	word_in_artical.assign(word.begin(),word.end());                     /*將word中的每項分配給word_in_artical*/
	sort(word_in_artical.begin(),word_in_artical.end()); //使用unique函式可刪除"連續重複"元素，先使用sort，將相同的元素排序在一起 
    vector<string>::iterator it = unique(word_in_artical.begin(),word_in_artical.end());
    word_in_artical.resize(distance(word_in_artical.begin(),it)); //unique並不像erase一樣會自動清除vector空間，所以必須resize，刪除null元素 

	//為了計算字串重複出現次數，開一個以pair組成的vector，方便計數 
	for(int i=0;i<word_in_artical.size();i++)
		number_of_appearances.push_back(make_pair(word_in_artical[i],0));  /*用word_in_artical[i當first, 0當second, make a pair, 並輸入進number_of_appearances中*/
	
	//依序檢查計數容器裡的每個字串。若在原容器中搜尋到，就從原容器中將該字串刪除，並在計數容器下+1 
    for(int i=0;i<number_of_appearances.size();i++){
    	for(int j=0;j<word.size();j++){
    		if(number_of_appearances[i].first==word[j]){                   /*如果number_of_appearances[i]的first等於word[j]*/
    			number_of_appearances[i].second++;                           /*number_of_appearances[i]的second +1*/
 //   			word.erase(word.begin()+j);                                  /*刪除(erase)word中的begin(第0項) + j 的那一項*/
			}                                                                /*erase()中的參數需為 iterator positon*/
    	}
	}

	//排序計數結果並輸出 
	sort(number_of_appearances.begin(),number_of_appearances.end(),compare);
	for(pair<string,int> thePair:number_of_appearances)                  /*創建一個循環去run thePair，thePair是number_of_appearances中的項目*/
		cout<<thePair.first<<" "<<thePair.second<<endl;                    /*cout thePair的first(Type 1:string)和second(Type 2:int)*/

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
