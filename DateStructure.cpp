#include <iostream>

int main()
{
    class Complex
    {
        double re = 0;
        double lm = 0;
        Complex* point = NULL;

        bool InitComplex( Complex* z,double v1, double v2) 
        {
            re = v1;
            lm = v2;
            z = this;
        }
        bool GetReal( Complex* z,double* realPart) 
        {
            if (NULL ==z)
            {
                return false;
            }
            else
            {
                *realPart = z->re;
                return true;
            }
        }
        bool GetLmag(Complex* z, double* lmagPart)
       {
           if (NULL ==z)
           {
               return false;
           }
           else
           {
               *lmagPart = z->lm;
               return true;
           }
       }
        bool Add(Complex* z1, Complex* z2, Complex* sum)
        {
            if (NULL == z1 || NULL == z2)
            {
                return false;
            }
            else
            {
                sum->lm = z1->lm + z2->lm;
                sum->re = z1->re + z2->re;
                return true;
            }
        }
        bool Sub(Complex* z1, Complex* z2, Complex* residue)
        {
            if (NULL == z1 || NULL == z2)
            {
                return false;
            }
            else
            {
                residue->lm = z1->lm - z2->lm;
                residue->re = z1->re - z2->re;
                return true;
            }
        }
        bool Mul(Complex* z1, Complex* z2, Complex* product)
        {
            if (NULL == z1 || NULL == z2)
            {
                return false;
            }
            else
            {
                product->lm = z1->re * z2->lm + z1->lm * z2->re;
                product->re = z1->re * z2->re - z1->lm * z2->lm;
                return true;
            }
        }
        bool Div(Complex * z1, Complex * z2, Complex * quotient) 
        {
            if (NULL == z1 || NULL == z2)
            {
                return false;
            }
            else
            {
                quotient->re = (z1->re * z2->re + z1->lm * z2->lm) / (pow(z2->re, 2) + pow(z2->lm, 2));
                quotient->lm = (z1->lm * z2->re + z1->re * z2->lm)/ (pow(z2->re, 2) + pow(z2->lm, 2));
                return true;
            }
        }
    };
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
