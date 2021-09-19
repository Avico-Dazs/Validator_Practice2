#include "GreaterThan.h"
#include <string>

bool GreaterThan::Eval(const char* sz, ValidationResult& result)
{
    const int num = atoi(sz);
    if (num <= m_num)
    {
        result.SetMessage("less than");
        return false;
    }
    return true;
}
