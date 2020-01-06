#pragma once
#include <iostream>
#include <string>
#include <malloc.h>
#include <vector>
#include <list>

using namespace std;

class NumwWord {
private:
	string comm[21] = { "", "��", "��", "õ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "���ϻ�", "�ƽ���", "����Ÿ", "�Ұ�����", "�������" };
public:
	string numtowords(unsigned long long num) {
		string ret;
		string barrel;
		//list<char> barrel;		
		int cnt = 0;
		int ccnt = 1;
		int scnt = 3;
		while (num > 0) {
			//if (num % 10 == 0) continue;
			switch (num % 10) {
			case 1:
				barrel.append("��");
				break;
			case 2:
				barrel.append("��");
				break;
			case 3:
				barrel.append("��");
				break;
			case 4:
				barrel.append("��");
				break;
			case 5:
				barrel.append("��");
				break;
			case 6:
				barrel.append("��");
				break;
			case 7:
				barrel.append("ĥ");
				break;
			case 8:
				barrel.append("��");
				break;
			case 9:
				barrel.append("��");
				break;
			default:
				barrel.append("��");
			}			
			num /= 10;
		}		
		const char * barrelc = barrel.c_str();
		MessageBox(0, (LPCSTR)barrelc, "dd", MB_OK);
		scnt += ((int)barrel.length() - 1) / 8;
		cnt = ((int)barrel.length() / 2 - 1) % 4;
		for (int i = barrel.length() - 2; i >= 0; i-=2) {
			if ((cnt == 0 && barrel.substr(i, 2) != "��") || barrel.substr(i, 2) != "��") {
				ret += barrel.substr(i, 2);				
			}	
			if (barrel.substr(i, 2) != "��") {
				ret += comm[cnt];
			}			
			cnt--;
			if (cnt < 0) {
				cnt = 3;
				if (scnt > 3) {
					ret += comm[scnt--];
				}
			}
		}
		MessageBox(0, (LPCSTR)ret.c_str(), "dd", MB_OK);
		return ret;
	}

	string wordtonum(string nc) {

	}

};