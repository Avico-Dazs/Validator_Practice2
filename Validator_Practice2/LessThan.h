#pragma once
#include "IValidator.h"

class LessThan :
	public IValidator
{
public:
    LessThan(int n) : m_num(n) {};

    // IValidator を介して継承されました
    virtual bool Eval(const char* sz, ValidationResult& result) override
    {
        const int num = atoi(sz);
        if (num >= m_num)
        {
            result.SetMessage("greater than");
            return false;
        }
        return true;
    }
private:
    int m_num;
};
