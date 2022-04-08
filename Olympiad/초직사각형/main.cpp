#include <stdio.h>
#include <vector>
#include <algorithm>
long long int len[4];
using namespace std;

vector<int> cards[4];
vector<int> cards_sum[4];
int idx[4];

bool cmp(const int a, const int b) {
    return a > b;
}

bool cmp2(const pair<int, int> a, const pair<int, int> b) {
    return a.second * len[b.first] > b.second * len[a.first];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int N, k;
    scanf("%d %d", &N, &k);
    scanf("%lld %lld %lld %lld\n", &len[0], &len[1], &len[2], &len[3]);
    long long int cur_volume = len[0] * len[1] * len[2] * len[3];

    char ch;
    int val;
    for (int i = 0; i < N; i++) {
        scanf("%c %d\n", &ch, &val);
        cards[ch-'A'].push_back(val);
    }

    for (int i = 0; i < 4; i++)
        sort(cards[i].begin(), cards[i].end(), cmp);

    for (int i = 0; i < 4; i++) {
        cards_sum[i].push_back(len[i]);
        for (int j = 0; j < cards[i].size(); j++)
            cards_sum[i].push_back(cards_sum[i][j] + cards[i][j]);
    }
    while(k > 0) {
        long long int max_volume = 0;
        int add_chr = -1, add_var = -1;
        vector<pair<int, int> > vect;
        for (int i = 0; i < 4; i++) {
            if (idx[i] >= cards_sum[i].size()-1)
                continue;
            if (cur_volume / cards_sum[i][idx[i]] * cards_sum[i][idx[i]+1] > max_volume) {
                add_chr = i;
                add_var = cards[i][idx[i]];
                max_volume = cur_volume / cards_sum[i][idx[i]] * cards_sum[i][idx[i]+1];
            }
            //vect.push_back(make_pair(i, cards[idx[i]]));
        }

        //sort(vect.begin(), vect.end(), cmp2);

        //len[vect[0].first] += vect[0].second;
        printf("%c %d\n", 'A' + add_chr, add_var);
        cur_volume = cur_volume / cards_sum[add_chr][idx[add_chr]] * cards_sum[add_chr][idx[add_chr]+1];
        idx[add_chr]++;
        k--;
    }
}
