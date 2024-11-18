// This is a program to check wether a given string is pallinderome or not
int rev(int x)
{
    int revs = 0;
    while (x != 0)
    {
        revs = (revs * 10) + (x % 10);
        x = x / 10;
    }
    return revs;
}
bool isPalindrome(int x)
{
    int t = x;
    if (rev(t) == x)
    {
        return true;
    }
    else
    {
        return false;
    }
}