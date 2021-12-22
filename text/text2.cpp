#if 0
#include <iostream>							/*cin,cout*/
#include <string>							/*string,getline,begin,end*//*有問題，不引用依然可正常運作*/
#include <sstream>							/*istringstream*/
#include <vector>							/*vector,push_back*/
#include <iterator>							/*還沒用到*/
#include <algorithm>						/*remove_if*/
#include <fstream>							/*fstream*/
#include <set>								/*set*/
#include <utility> 							/*pair*/
#include <cstdlib>
#include <map>

using namespace std;		
bool not_alphanumeric(char s) {				/*創建一個函式用來判斷是否為字母和數字*/
	if(isalnum(s)){							/*如果是字母和數字*/
		return false;						/*返回false，也就是在下面我們不作用*/
	}
	return true;							/*否則如果不是字母和數字，為true，在下面被引用，將被我們刪除*/
}

//jobs speech short.txt
//jobs speech in stanford.txt
int main(){
	fstream file;							/*宣告一個fstream，被用來開啟檔案並輸入到artical*/
	string fileName;						/*宣告一個string被用來輸入fileName查找file*/
	string artical;							/*宣告一個string被用來存放file的內容，並會被複製到sstream中*/
	vector<string> word;					/*宣告一個word來存放分割後純字母和數字的string vector*/
    string words;							/*宣告一個words用來接受sstream的無空格輸入，並同時push_back到word string vector中*/
    set <string> word_in_artical;			/*宣告一個set用來存放無重複字母，並在之後做重複出現次數的降冪排序(pair)*/
	int i;									/*宣告一個int i被用來做iterator(迭代)*/

	getline(cin, fileName);					/*讀取cin的整行文字到fileName*/
	file.open(fileName);					/*open一個檔案名稱為fileName的file*/
		
	if(!file.is_open())						/*如果file.is_open不成立*/
	{
	   cout<<"file open failed"<<endl;		/*輸出""並換行*/
	}
	else									/*否則*/
	{
		getline(file, artical);				/*把file內的檔案整行整行的讀取到artical*/
	
    }

    istringstream sstream(artical);			/*宣告一個istringstream，複製artical的內容，並在之後被用來做輸出*/

    
    while(sstream >> words){				/*當我把sstream輸入到words(這是肯定句)*/
 											/*words會刪除(erase)(起點:(把words開頭到結尾找到的not_alphanumeric移動到words的最後),一直刪到:words的最後)*/
		words.erase(remove_if(words.begin(), words.end(), not_alphanumeric), words.end());   	
		word.push_back(words);				/*把words的單字輸入到word的最後*/
//		word_in_artical.insert(words);		/*把woeds的單字插入到word_in_artical*/
	}
	
	
	for(i = 0;i<word.size();i++){ 			/*創建一個循環去跑i從0開始，到小於word的size，下一次的執行i+1*/
	cout<<word[i]<<endl;} 					/*印出word的第i項*/
		
//  	for (const auto &s : word_in_artical) {	/*創建一個循環去跑s，s是word_in_artical裡的項目*/
//        cout << s << endl;					/*印出s*/
//    }


//	map<string, int> word_count;// empty
// 
////	string word[]="abcdefg";
//	for (int j = 0; j <word_in_artical.size(); j++)
//	{
//		++word_count[word[j]];                      // 用下???
//	}
//	map<string, int>::iterator iter;             // iter ?pair ?型(value_type)
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

//map<string,int> word_count;//因?在map容器本?存?就是按序排的
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
	筆記:
	用pair做一個鍵值對
	用sort和greater做一個降冪排序
	
	要做的事:
	把每個字重複的次數抓出來
	把set的內容丟到pair t1
	把重複的次數丟到pair t2
	make pair一個降冪排序的pair
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
	cout << "Input the essay (0??止符)" << endl;
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
#include <string>							/*string,getline,begin,end*//*有問題，不引用依然可正常運作*/
#include <sstream>							/*istringstream*/
#include <vector>							/*vector,push_back*/
#include <iterator>							/*還沒用到*/
#include <algorithm>						/*remove_if*/
#include <fstream>							/*fstream*/
#include <set>								/*set*/
#include <utility> 							/*pair*/
#include <cstdlib>
#include <map>

using namespace std;		
bool not_alphanumeric(char s) {				/*創建一個函式用來判斷是否為字母和數字*/
	if(ispunct(s)){							/*如果是字母和數字*/
		return true;						/*返回false，也就是在下面我們不作用*/
	}
	return false;							/*否則如果不是字母和數字，為true，在下面被引用，將被我們刪除*/
}

//jobs speech short.txt
//jobs speech in stanford.txt
int main(){
	fstream file;							/*宣告一個fstream，被用來開啟檔案並輸入到artical*/
	string fileName;						/*宣告一個string被用來輸入fileName查找file*/
	string artical;							/*宣告一個string被用來存放file的內容，並會被複製到sstream中*/
	vector<string> word;					/*宣告一個word來存放分割後純字母和數字的string vector*/
    string words;							/*宣告一個words用來接受sstream的無空格輸入，並同時push_back到word string vector中*/
 string temp;
	int i;									/*宣告一個int i被用來做iterator(迭代)*/

	getline(cin, fileName);					/*讀取cin的整行文字到fileName*/
	file.open(fileName);					/*open一個檔案名稱為fileName的file*/
		
	if(!file.is_open())						/*如果file.is_open不成立*/
	{
	   cout<<"file open failed"<<endl;		/*輸出""並換行*/
	}
	else									/*否則*/
	{
		while(getline(file,temp))artical+=temp;
    	file.close();				/*把file內的檔案整行整行的讀取到artical*/
	
    }

    stringstream sstream(artical);			/*宣告一個istringstream，複製artical的內容，並在之後被用來做輸出*/

    
    while(sstream >> words){				/*當我把sstream輸入到words(這是肯定句)*/
 											/*words會刪除(erase)(起點:(把words開頭到結尾找到的not_alphanumeric移動到words的最後),一直刪到:words的最後)*/
		words.erase(remove_if(words.begin(), words.end(), not_alphanumeric), words.end());   	
		word.push_back(words);				/*把words的單字輸入到word的最後*/

	}
	
	artical>>sstream;
//	for(i = 0;i<word.size();i++){ 			/*創建一個循環去跑i從0開始，到小於word的size，下一次的執行i+1*/
//	cout<<word[i]<<endl;} 					/*印出word的第i項*/
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
#include <string>							  /*string,getline,begin,end*//*有問題，不引用依然可正常運作*/
#include <sstream>							/*istringstream, sstream>>*/
#include <vector>							  /*vector,push_back*/
#include <iterator>							/*還沒用到*/
#include <algorithm>						/*remove_if*/
#include <fstream>							/*fstream*/
#include <set>								  /*set*/
#include <utility> 							/*pair*/
#include <cstdlib>
#include <map>

using namespace std;		
bool not_alphanumeric(char s) {				/*創建一個函式用來判斷是否為字母和數字*/
	if(isalnum(s)){							        /*如果是字母和數字*/
		return false;						          /*返回false，也就是在下面我們不作用*/
	}
	return true;							          /*否則如果不是字母和數字，為true，在下面被引用，將被我們刪除*/
}

//jobs speech short.txt
//jobs speech in stanford.txt
int main(){
	fstream file;							  /*宣告一個fstream，被用來開啟檔案並輸入到artical*/
	string fileName;						/*宣告一個string被用來輸入fileName查找file*/
	string artical;							/*宣告一個string被用來存放file的內容，並會被複製到sstream中*/
	vector<string> word;				/*宣告一個word來存放分割後純字母和數字的string vector*/
    string words;							/*宣告一個words用來接受sstream的無空格輸入，並同時push_back到word string vector中*/
 
	int i;									    /*宣告一個int i被用來做iterator(迭代)*/

	getline(cin, fileName);			/*讀取cin的整行文字到fileName*/
	file.open(fileName);				/*open一個檔案名稱為fileName的file*/
		
	if(!file.is_open())					/*如果file.is_open不成立*/
	{
	   cout<<"file open failed"<<endl;		/*輸出""並換行*/
	}
	else{									                /*否則*/
		
		while(getline(file, artical)){};				      /*把file內的檔案整行整行的讀取到artical*/
	}
    

    istringstream sstream(artical);			/*宣告一個istringstream，複製artical的內容，並在之後被用來做輸出*/

    
    while(sstream >> words){				    /*當我把sstream輸入到words(這是肯定句)*/
 		/*words會刪除(erase)(起點:(把words開頭到結尾找到的not_alphanumeric移動到words的最後),一直刪到:words的最後)*/
		words.erase(remove_if(words.begin(), words.end(), not_alphanumeric), words.end());   	
		word.push_back(words);				      /*把words的單字輸入到word的最後*/

	}
	
	
	for(i = 0;i<word.size();i++){ 			  /*創建一個循環去跑i從0開始，到小於word的size，下一次的執行i+1*/
	cout<<word[i]<<endl;} 					      /*印出word的第i項*/
		
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
		number_of_appearances.push_back(make_pair(word_in_artical[i],0));  /*用word_in_artical[i]當key, 0當value, make a pair, 並輸入進number_of_appearances中*/
	
	//依序檢查計數容器裡的每個字串。若在原容器中搜尋到，就從原容器中將該字串刪除，並在計數容器下+1 
    for(int i=0;i<number_of_appearances.size();i++){
    	for(int j=0;j<word.size();j++){
    		if(number_of_appearances[i].first==word[j]){                   /*如果number_of_appearances[i]的key等於word[j]*/
    			number_of_appearances[i].second++;                           /*number+of_appearances[i]的value +1*/
    			word.erase(word[*j]);                                  /*刪除(erase)word中的begin+j的那一項*/
			}
    	}
	}

	//排序計數結果並輸出 
	sort(number_of_appearances.begin(),number_of_appearances.end(),compare);
	for(pair<string,int> thePair:number_of_appearances)                  /*創建一個循環去run thePair，thePair是number_of_appearances中的項目*/
		cout<<thePair.first<<" "<<thePair.second<<endl;                    /*cout thePair的key(first:string)和value(second:int)*/

}
#endif

1 2 3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8

