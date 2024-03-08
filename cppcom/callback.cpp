#include <iostream>
using namespace std;

typedef void (*PFUNC)(double v, int n, void *pObject);

class Dst
{
private:
    double m_dblValue;
    int m_nCount;

public:
    double DoSomething()
    {
        double dblResult = m_dblValue / m_nCount;
        return dblResult;
    }
    static void FuncCallBack(double v, int n, void *pObject)
    {
        Dst *pDst = (Dst *)pObject;

        pDst->m_dblValue = v;
        if (n < 1)
        {
            pDst->m_nCount = 1;
        }
        else
        {
            pDst->m_nCount = n;
        }
    }
};

class Src
{
public:
    void SendDataTo(Dst *pDst, PFUNC pFunc)
    {
        pFunc(2.0, 3, pDst);
    }
};

int main()
{
    Dst theDst;
    Src theSrc;
    theSrc.SendDataTo(&theDst, Dst::FuncCallBack);
    cout << theDst.DoSomething();
    return 0;
}