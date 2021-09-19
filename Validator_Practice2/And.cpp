#include "And.h"
#include <stdarg.h>

And::~And()
{
    m_validators.clear();
    printf("Delete And\n");
}

