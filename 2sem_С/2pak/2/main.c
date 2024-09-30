#include "modular.h" 
#include <assert.h>

int main()
{
    MOD = 13;
    assert(pnorm(5645654) == 1);
    MOD = 999999937;
    assert(pnorm(45) == 45);
    assert(pnorm(-45) == 999999892);
    assert(padd(100, 50) == 150);
    assert(padd(999999936, 45) == 44);
    assert(psub(40, 100) == 999999877);
    assert(pmul(100000, 100000) == 630);
    assert(pmul(100001, 99999) == 629);
    assert(pmul(100002, 100001) == 300632);
    assert(pdiv(1000, 100000) == 269999983);
    assert(pdiv(1000, 8900) == 415730311);
    assert(pdiv(100, 213) == 896713559);
    assert(pdiv(2130000, 2220000) == 878378324);
    return 0;
}