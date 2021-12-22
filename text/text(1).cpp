#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
	int main(){
//jobs speech short.txt		
    fstream file;                       /*宣告file是一個fstream，它可被直接用來輸出與輸入*/ 
    string fileName;                    /*宣告一個string fileName，用來cin file的name*/
	string artical;
//	string split; 
 //   char * artical;						/*宣告一個char artical，被用來暫存文章，並在這去除標點符號與換行符和空白後輸入到word*/ 
    vector<string> word;				/*宣告一個vector<string> word，被用來放artical去除乾淨的word*/ 
    
    getline(cin,fileName);				/*輸入檔名*/ 
     
    file.open(fileName);                /*打開文件(檔名，模式:可用作輸出)*/ 
    
    if(!file.is_open())			        /*如果檔案打不開*/
	{
		cout<<"Not found";
	}
    else if (file.is_open()){
    getline (file,artical);     /*輸入file檔案中的每行到split*/ 

    file.close();                       /*關閉file*/ 
    }

/*    artical = strtok (split.c_str()," ,.'");
      while (artical != NULL)
      {
        cout <<artical ;
        artical = strtok (NULL, " ,.'");
      }
*/  
/*	stringstream input(artical);
	
    while(input >> artical)
	{
        word.push_back(artical);
    }
 */   
    char temp ;
    string temp2 = "";
    for(int i=0;i<artical.size();i++)
	{	
    	for(int t = 0 ; t < artical.size(); t++)
		{
			temp = artical[t];
			if (ispunct(temp))
			{	
				temp2 +=temp;
				temp2 = "";
				
			}
      		
	    }
    }
   
  	for(int i=0;i<word.size();i++)
	{	
	    cout << word[i] << endl;           /*印出word中的內容*/ 
    }
    return 0;
}
