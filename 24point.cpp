#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> getNum(const string& s)
{
    vector<int> result;
    for (auto c : s)
    {
        if (c == 'A')
            result.emplace_back(1);
        else if (c >= '2' && c <= '9')
            result.emplace_back(c - '0');
        else if (c == 'T')
            result.emplace_back(10);
        else if (c == 'J')
            result.emplace_back(11);
        else if (c == 'Q')
            result.emplace_back(12);
        else if (c == 'K')
            result.emplace_back(13);
    }

    return result;
}

int calc(vector<int> nums, int a, int b, int c)
{
    if (nums.size() != 4)
        return 0;

    stack<int> st;
    st.push(nums[0]);
    st.push(nums[1]);
    st.push(nums[2]);
    st.push(nums[3]);

    vector<int> vec = {c, b, a};

    int i = 0;
    while (st.size() > 1)
    {
        int tmp1 = st.top();
        st.pop();
        int tmp2 = st.top();
        st.pop();

        if (vec[i] == 0)
        {
            st.push(tmp1 + tmp2);
        }
        else if (vec[i] == 1)
        {
            st.push(tmp1 - tmp2);
        }
        else if (vec[i] == 2)
        {
            st.push(tmp1 * tmp2);
        }
        else if (vec[i] == 3)
        {
            st.push(tmp1 / tmp2);
        }
    }

    return st.top();
}

bool judge(const vector<int>& nums)
{
    string ops = "+-*/";

    for (int i = 0; i < ops.length(); ++i)
        for (int j = 0; j < ops.length(); ++j)
            for (int k = 0; k < ops.length(); ++k)
            {
                if (calc(nums, i, j, k) == 24)
                {
                    printf("%d%c%d%c%d%c%d=24", nums[0], ops[i], nums[1], ops[j], nums[2], ops[k], nums[3]);

                    return true;
                }
            }

    return false;
}

int main()
{
    string str;

    while (getline(cin, str, '\n'))
    {
        auto nums = getNum(str);

        sort(nums.begin(), nums.end());

        do
        {
            bool result = judge(nums);
            if (result)
                break;
            else
                cout << "no result" << endl;
        }
        while (next_permutation(nums.begin(), nums.end()));
    }

    return 0;
}
