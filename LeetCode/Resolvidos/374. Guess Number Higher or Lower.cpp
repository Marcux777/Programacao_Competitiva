class Solution
{
public:
    int guessNumber(int n)
    {
        int lo = 1, hi = n;
        int mid;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (guess(mid) == 1)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        if (guess(lo) == 0)
        {
            return lo;
        }
        else
        {
            return hi;
        }
    }
};
