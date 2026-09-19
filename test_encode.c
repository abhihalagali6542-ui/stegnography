#include <stdio.h>
#include "encode.h"
#include "types.h"

int main(int argc,char *argv[])
{
    EncodeInfo encInfo;
   
    char *ret=check_operation_type(argv[1][1]);
    if(strcmp(ret,"e_encide"))
    {
        read_and_validate_encode_args(argv, &encInfo);
    }

    return 0;
}
OperationType check_operation_type(char opt)
{
    if(opt=='e')
    {
        return e_encide;
    }
    else if(opt=='d')
    {
        return e_decode;
    }
    else
    {
        return e_unsupported;
    }
}
