#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	int input_channel, standard_channel;
	int butNum; //��ư ����
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

	int move_butNum = abs(input_channel - standard_channel); //+,- ��ư Ƚ��
	int min_but = move_butNum;
	for (int i = 0; i < 1000000; i++)
	{
		string input_channel_temp = to_string(i);

		int num_but = 0; // ���� ��ư ���� ����
		for (int j = input_channel_temp.length()-1; j >= 0; j--)
		{
			if (but[input_channel_temp[j] - '0'])
				num_but++;
			else
				break;
		}

		if (num_but == input_channel_temp.length())
		{
			if (i == input_channel) // ���簡 �Է� ä���� ��� +,-��ư�� �ּ�����, ���ڸ� �����°� �ּ����� �Ǵ�
				min_but = min(min_but, num_but);
			else // ���簡 �Է�ä���� �ƴҰ��, +,-��ư�� �ּ����� ���ڹ�ư�� ���յ� ���� �ּ����� Ȯ��
				min_but = min(min_but, num_but + abs(input_channel - i));
		}
	}

	cout << min_but;
	return 0;
}