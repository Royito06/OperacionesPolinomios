#include <iostream>
#include <limits>

using namespace std;

//Este usaria un archivo tpp
template <typename Tipo>
bool CapturaSegura(Tipo &n)
{
    if (cin.fail()||n<0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}
