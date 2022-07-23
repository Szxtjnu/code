#include<bits/stdc++.h>
using namespace std;
using namespace std;

const int N = 20010;

int dp[N], pre[N], q[N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        memcpy(pre, dp, sizeof(dp));
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = 0; j < v; ++j) {
            int head = 0, tail = -1;
            for (int k = j; k <= m; k += v) {

                //总共有s件物品i，所以窗口值也就是说s，如果说这个窗口值大于了s，那么就说明i物品不够了
                //怎么用窗口值来判断呢？道理是如果现有的容量k比该物品的所有重量加起来都大，那么就说明了已经超出了窗口值了
                //则队头需要向右移动一位了。
                if (head <= tail && k - s*v > q[head]) 
                    ++head;

                while (head <= tail && pre[q[tail]] - (q[tail] - j)/v * w <= pre[k] - (k - j)/v * w)
                    --tail;

                if (head <= tail)
                    dp[k] = max(dp[k], pre[q[head]] + (k - q[head])/v * w);

                q[++tail] = k;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}
