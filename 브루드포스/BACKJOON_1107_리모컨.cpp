#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	int input_channel, standard_channel;
	int butNum; //버튼 갯수
	int but[10] = { 1,1,1,1,1,1,1,1,1,1 }; 
	
	standard_channel = 100;

	cin >> input_channel;

	cin >> butNum;

	for (int i = 0; i < butNum; i++)
	{
		int trouble;
		cin >> trouble;
		but[trouble] = 0;
	}

	int move_butNum = abs(input_channel - standard_channel); //+,- 버튼 횟수
	int min_but = move_butNum;
	for (int i = 0; i < 1000000; i++)
	{
		string input_channel_temp = to_string(i);

		int num_but = 0; // 숫자 버튼 가능 여부
		for (int j = input_channel_temp.length()-1; j >= 0; j--)
		{
			if (but[input_channel_temp[j] - '0'])
				num_but++;
			else
				break;
		}

		if (num_but == input_channel_temp.length())
		{
			if (i == input_channel) // 현재가 입력 채널인 경우 +,-버튼이 최소인지, 숫자만 누르는게 최소인지 판단
				min_but = min(min_but, num_but);
			else // 현재가 입력채널이 아닐경우, +,-버튼이 최소인지 숫자버튼과 조합된 것이 최소인지 확인
				min_but = min(min_but, num_but + abs(input_channel - i));
		}
	}

	cout << min_but;
	return 0;
}