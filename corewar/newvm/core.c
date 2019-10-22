#include "core.h"

void movrr(uint8_t rega, uint8_t regb) 
{
    REG[rega] = REG[regb];
}

void movri(uint8_t rega, )
{

}




uint8_t     get_length(uint8_t opcode, uint8_t acb)
{
    static uint8_t instr_length[] = {
        1, 2 ,3 ,4 ,5, 6, 7, 8 // these number are placeholder 
    };
    static uint8_t arg_length[] = {
        0, 1, 2, 4 // these number are placeholder 
    };
    uint8_t ret;

    ret = 0;
    if (!acb)
        return instr_length[opcode];
    else
        while (acb)
        {
            ret += arg_length[acb & 0b11000000];
            acb <<= 2;
        }
    return ret;
}






