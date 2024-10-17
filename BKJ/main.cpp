#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 각 시간과 시간과 관련된 로직을 가지는 Time 클래스 정의
class Time {
public:
        int h, m, s;

        // 초로 변환된 시간을 가지고도 Time을 만들 수 있도록 생성자 정의
        Time(int seconds) {
                this->h = seconds / 3600;
                this->m = (seconds % 3600) / 60;
                this->s = (seconds % 3600) % 60;
        }

        // 모든 시간을 초로 변환
        int toSeconds() {
                return h * 3600 + m * 60 + s;
        }

        // 각도를 계산해서 List 형태로 반환
        vector<double> getDegree() {
                double hDegree = (h % 12) * 30.0 + m * 0.5 + s * (1 / 120.0);
                double mDegree = m * 6.0 + s * (0.1);
                double sDegree = s * 6.0;

                return vector<double>{hDegree, mDegree, sDegree};
        }
};

// 시침가 초침의 겹침을 판단
bool hourMatch(vector<double> cnt, vector<double> next) {
        if (cnt[0] > cnt[2] && next[0] <= next[2]) {
                return true;
        }

        // 초침이 354도에서 0도로 넘어갈 때 예외 케이스
        if (cnt[2] == 354 && cnt[0] > 354) {
                return true;
        }
        return false;
}

// 분침과 초침의 겹침을 판단
bool minuteMatch(vector<double> cnt, vector<double> next) {
        if (cnt[1] > cnt[2] && next[1] <= next[2]) {
                return true;
        }

        // 초침이 354도에서 0도로 넘어갈 때 예외 케이스
        if (cnt[2] == 354 && cnt[1] > 354) {
                return true;
        }
        return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        int answer = 0;

        // 시작 시간과, 종료 시간을 초 단위로 변경
        int start = Time(h1 * 3600 + m1 * 60 + s1).toSeconds();
        int end = Time(h2 * 3600 + m2 * 60 + s2).toSeconds();

        // 시작 시간부터 1초씩 올려가며 계산(마지막 초는 포함되면 안됨)
        // 마지막 초 + 1까지 판단해버림
        for (int i = start; i < end; i++) {
                vector<double> cnt = Time(i).getDegree();
                vector<double> next = Time(i + 1).getDegree();

                bool hMatch = hourMatch(cnt, next);
                bool mMatch = minuteMatch(cnt, next);

                // 초침이 분침과 시침과 겹침이 발생했을 때,
                if (hMatch && mMatch) {
                        // 시침과 분침의 각도가 같다면 +1만 해줘야함
                        if (next[0] == next[1]) answer++;
                        // 아니라면 +2
                        else answer += 2;
                }
                // 둘 중 하나라도 겹치면 +1
                else if (hMatch || mMatch) answer++;
        }

        // 위 로직은 시작시간에 대한 검사를 안해줬음
        // 그래서 0시 또는 12시에 시작한다면, 한번 겹치고 시작하는 것이기 때문에 +1
        if (start == 0 || start == 43200) answer++;
        return answer;
}