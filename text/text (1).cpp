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
    fstream file;                       /*�ŧifile�O�@��fstream�A���i�Q�����Ψӿ�X�P��J*/ 
    string fileName;                    /*�ŧi�@��string fileName�A�Ψ�cin file��name*/
	string artical;
//	string split; 
 //   char * artical;						/*�ŧi�@��char artical�A�Q�ΨӼȦs�峹�A�æb�o�h�����I�Ÿ��P����ũM�ťի��J��word*/ 
    vector<string> word;				/*�ŧi�@��vector<string> word�A�Q�Ψө�artical�h�����b��word*/ 
    
    getline(cin,fileName);				/*��J�ɦW*/ 
     
    file.open(fileName);                /*���}���(�ɦW�A�Ҧ�:�i�Χ@��X)*/ 
    
    if(!file.is_open())			        /*�p�G�ɮץ����}*/
	{
		cout<<"Not found";
	}
    else if (file.is_open()){
    getline (file,artical);     /*��Jfile�ɮפ����C���split*/ 

    file.close();                       /*����file*/ 
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
	    cout << word[i] << endl;           /*�L�Xword�������e*/ 
    }
    return 0;
}
