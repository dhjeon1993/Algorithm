#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
using namespace std;

const static int MAX_STUDENT_NUMBER = 10;

int C;
int N, M;

// 친구 쌍을 저장할 배열 선언
bool FRIENDS[MAX_STUDENT_NUMBER][MAX_STUDENT_NUMBER];

// 짝지어진 쌍들의 정보
bool MATCHED[MAX_STUDENT_NUMBER];


// 친구를 짝지어 준다.
// 입력받은 학생과 친구인 학생을 모두 한번씩 짝지어 본다.
int match(int remain) {
	// 모두 짝을 지어준 경우
	if (remain == 0) {
		return 1;
	}

	// 선택한 학생과 친구인 학생을 짝을 지어준다.

	int matching = -1, next = -1;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (MATCHED[i] == false) {
			if (matching < 0) {
				matching = i;
				MATCHED[matching] = true;
			}
			else {
				if (FRIENDS[matching][i] == true) {
					next = i;
					MATCHED[next] = true;
					sum += match(remain - 2);
					MATCHED[next] = false;
				}
			}
		}
	}
	MATCHED[matching] = false;

	// 선택한 학생과 친구인 학생이 없다면 짝을 만들 수 없다.
	if (next == -1) {
		return 0;
	}
	else {
		return sum;
	}
}

int solution() {
	// 학생의 수와 친구 쌍의 수 입력
	cin >> N >> M;

	// 짝지어진 쌍들의 정보 초기화
	for (int i = 0; i < MAX_STUDENT_NUMBER; i++) {
		for (int j = 0; j < MAX_STUDENT_NUMBER; j++) {
			FRIENDS[i][j] = false;
		}
	}
	for (int i = 0; i < MAX_STUDENT_NUMBER; i++) {
			MATCHED[i] = false;
	}

	// 친구 쌍 입력
	for (int i = 0; i < M; i++) {
		int student1, student2;
		cin >> student1 >> student2;
		FRIENDS[student1][student2] = true;
		FRIENDS[student2][student1] = true;
	}

	return match(N);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 테스트 케이스 입력
	cin >> C;

	for (int i = 0; i < C; i++) {
		cout << solution() << "\n";
	}


	return 0;
}