#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int student_num = n;
	int lost_num = lost.size();

	vector<bool> isHave(n + 1, true);

	for (int i = 0; i < lost_num; i++) { //잃어버린 학생은 false로 체크
		int idx = lost[i];
		isHave[idx] = false;
	}

	for (int i = 0; i < lost_num; i++) {  //잃어버린 학생 중 여분을 갖고 있는 학생이 있으면 true로 체크하고, reserve 벡터에서 제거
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				isHave[lost[i]] = true;
				reserve.erase(reserve.begin() + j);
			}
		}
	}

	for (int i = 0; i < reserve.size(); i++) {
		if (reserve[i] == student_num) {
			if (isHave[reserve[i] - 1] == false) {
				isHave[reserve[i] - 1] = true;
				break;
			}
			break;
		}
		if (reserve[i] == 1 && isHave[reserve[i] + 1] == false)
			isHave[reserve[i] + 1] = true;
		if (reserve[i] != 1) {
			if (isHave[reserve[i] + 1] == false && isHave[reserve[i] - 1] == true)
				isHave[reserve[i] + 1] = true;
			else if (isHave[reserve[i] + 1] == true && isHave[reserve[i] - 1] == false)
				isHave[reserve[i] - 1] = true;
			else if (isHave[reserve[i] + 1] == false && isHave[reserve[i] - 1] == false)
				isHave[reserve[i] - 1] = true;
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (isHave[i] == true)
			answer++;
	}
	return answer;
}