#pragma once
#include <memory>
#include "IValidator.h"
class GreaterThan :
    public IValidator
{
public:
    // IValidator ����Čp������܂���
    virtual bool Eval(const char* sz, ValidationResult& result) override;

    GreaterThan(int n) : m_num(n)
    {
        printf("Create GreaderThan\n");
    };


    ~GreaterThan()
    {
        printf("Delete GreaterThan\n");
    };

// Attributes
private:
    int m_num;
};

