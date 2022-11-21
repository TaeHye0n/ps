#include <iostream>
#include <queue>

using namespace std;

struct robot {
    int dur;
    bool isRobot;
};

int N, K;
deque<robot> dq;


void solve() {
    cin >> N >> K;
    
    for (int i = 0; i < 2 * N; i++) {
        int temp;
        cin >> temp;
        dq.push_back({temp,false});
      
    }

    int cnt = 0;
    int zeroSum = 0;

    while (zeroSum < K) {
        zeroSum = 0;
        cnt++;
        dq.push_front(dq.back());
        dq.pop_back();

        if (dq[N - 1].isRobot == true) dq[N - 1].isRobot = false;

        for (int i = N - 2; i >= 0; i--) {
            if (dq[i].isRobot && dq[i + 1].dur >= 1 && !dq[i + 1].isRobot) {
                dq[i + 1].dur -= 1;
                dq[i].isRobot = false;
                if (i == N - 2) continue;
                dq[i + 1].isRobot = true;
            }
        }

        if (dq[0].dur > 0 && !dq[0].isRobot) {
            dq[0].isRobot = true;
            dq[0].dur -= 1;
        }
       
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i].dur == 0) zeroSum += 1;
        }
    }

    cout << cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}