#pragma once
#include "IValidator.h"
#include "GreaterThan.h"
#include <vector>

class And :
    public IValidator
{
public:
    // IValidator ‚ð‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
    virtual bool Eval(const char* sz, ValidationResult& result) override
    {
        for (auto& v : m_validators)
        {
            if(!v->Eval(sz, result)) return false;
        }
        return true;
    }
// Constructor/Destructor
public:
    template <class... Args>
    And(Args... args)
    {
        constexpr size_t size = sizeof...(Args);

        for (auto e : { args... })
        {
            auto p = new decltype(e)(e);
            auto u = std::unique_ptr<IValidator>(p);
            m_validators.push_back(std::move(u));
        }
    }

 /*   And(std::vector<IValidator*> validators)
    {
        for (auto& v : validators)
        {
            auto u = std::unique_ptr<IValidator>(v);
            m_validators.push_back(std::move(u));
        }
    }*/

    ~And();
// Attributes
private:
    std::vector<std::unique_ptr<IValidator>> m_validators;
};

