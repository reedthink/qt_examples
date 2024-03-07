#include <iostream>
using namespace std;

class Dst
{
private:
    double m_dblValue;
    int m_nCount;

public:
    double value()
    {
        return m_dblValue;
    }
    int count()
    {
        return m_nCount;
    }
    void setValue(double v)
    {
        m_dblValue = v;
    }
    void setCount(int n)
    {
        if (n < 1)
        {
            m_nCount = 1;
        }
        else
        {
            m_nCount = n;
        }
    }
    double DoSomeThing()
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
        theDst.setValue(2.0);
        theDst.setCount(3);
    }
};

int main()
{
    Dst theDst;
    Src theSrc;
    theSrc.SendDataTo(theDst);
    cout << theDst.DoSomeThing();
    return 0;
}