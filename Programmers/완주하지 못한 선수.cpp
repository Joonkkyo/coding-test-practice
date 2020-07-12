#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	int part_num = participant.size();
	int comp_num = completion.size();
	string answer;

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < comp_num; i++)
	{
		if (participant[i] != completion[i])
		{
			answer = participant[i];
			break;
		}
		else
			continue;
	}

	return participant[part_num - 1];
}

int main(void)
{
	vector<string> part = {"leo", "kiki", "eden"};
	vector<string> comp = {"eden", "kiki"};

	cout << solution(part, comp) << endl;
}