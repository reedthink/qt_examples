#include <iostream>

using namespace std;

class Dst
{
    public:
        double m_dblValue;
        int m_nCount;

        double DoSomething()
        {
            double dblResult = m_dblValue / m_nCount;
            return dblResult;
        }
};

class Src
{
    public:
        void SendDataTo(Dst &theDst)
        {
            theDst.m_dblValue = 2.0;
            theDst.m_nCount = 3;
        }
};

int main()
{
    Dst theDst;
    Src theSrc;
    theSrc.SendDataTo(theDst);
    cout<<theDst.DoSomething();
    return 0;
}