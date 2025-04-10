#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main()
{
	string s1, s2 = "Game"; 		
	s1.size(), s2.size(); 			
	s1 = s2 + ' ' + "Over"; 		
	if (s1 == "Game Over")			
		cout << s1 << "가 맞습니다\n";
	cout << s1.find("Over") << endl;
									
	cout << s1.find("e", 4) << endl;
									
	cout << s1[0] << endl; 			
	cout << s1.substr(5, 4) << endl;
	printf("s1 = %s\n", s1.c_str());
	getline(cin, s1); 				
	cout << s1 << endl;
}