#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool solve(string a, string b)
{
    bool is_able = true;
    int pointer = 0;
    int nearest_pos; //Vi tri gan nhat ma phan viet hoa trong xau a trung voi xau b
    for (int i = 0; i < a.length(); i++)
    {
        //Truong hop phan tu dang duoc xet o xau a la viet hoa
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            if (a[i] == b[pointer])
            {
                nearest_pos = pointer;
                pointer++;
            }
            else
            {
                //Neu phan tu viet hoa o xau a ko trung voi xau b thi tien hanh kiem
                //tra lai xau b xem co phan tu nao phu hop khong. Xet tu vi tri
                //Pointer hien tai den nearest post, neu ko ton tai phan tu nao phu
                //hop thi ket thuc vong lap va tra ve false.
                bool found = false;
                for (int j = pointer; j >= nearest_pos; j--)
                {
                    if (b[j] == a[i])
                    {
                        found = true;
                    }
                }
                if (!found)
                {
                    is_able = false;
                    break;
                }
            }
            //Truong hop phan tu dang duoc xet o xau a la viet thuong
        }
        else
        {
            if (toupper(a[i]) == b[pointer])
            {
                pointer++;
            }
        }
    }
    if (pointer != b.length())
    {
        is_able = false;
    }
    return is_able;
}

int main()
{
    int n;

    string a, b;
    a = "aAbcD";
    b = "ABCD";
    if (solve(a, b))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
