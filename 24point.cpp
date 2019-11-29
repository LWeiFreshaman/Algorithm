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

double calc_base(double num1, double num2, int op)
{
    if (op == 0)
    {
        return num1 + num2;
    }
    else if (op == 1)
    {
        return num1 - num2;
    }
    else if (op == 2)
    {
        return num1 * num2;
    }
    else if (op == 3)
    {
        return num1 / num2;
    }
    else if (op == 4)
    {
        return num2 - num1;
    }
    else if (op == 5)
    {
        return num2 / num1;
    }

    return 0;
}

double calc(vector<int> nums, int a, int b, int c)
{
    if (nums.size() != 4)
        return 0;

    stack<double> st;
    st.push(static_cast<double>(nums[0]));
    st.push(static_cast<double>(nums[1]));
    st.push(static_cast<double>(nums[2]));
    st.push(static_cast<double>(nums[3]));

    vector<int> vec = {a, b, c};

    int i = 0;

    while (st.size() > 1)
    {
        double tmp1 = st.top();
        st.pop();
        double tmp2 = st.top();
        st.pop();

        st.push(calc_base(tmp1, tmp2, vec[i]));

        ++i;
    }

    return st.top();
}

int calc2(vector<int> nums, int a, int b, int c)
{
    double num1 = static_cast<double>(calc_base(nums[0], nums[1], a));
    double num2 = static_cast<double>(calc_base(nums[2], nums[3], c));

    return fabs(calc_base(num1, num2, b) - 24) < 0.001;
}

bool judge(const vector<int>& nums)
{
    string ops = "+-*/89";

    for (int i = 0; i < ops.length(); ++i)
        for (int j = 0; j < ops.length(); ++j)
            for (int k = 0; k < ops.length(); ++k)
            {
                if (fabs(calc(nums, i, j, k) - 24) < 0.001)
                {
                    printf("%d%c%d%c%d%c%d=24\n", nums[3], ops[i], nums[2], ops[j], nums[1], ops[k], nums[0]);

                    return true;
                }

                if (calc2(nums, i, j, k))
                {
                    printf("%d%d%d%d%d%d%d=24\n", nums[0], i, nums[1], j, nums[2], k, nums[3]);
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
