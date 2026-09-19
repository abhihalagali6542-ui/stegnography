#include <stdio.h>
#include "encode.h"
#include "types.h"

int main(int argc,char *argv[])
{
    EncodeInfo encInfo;
    
   //check e or d from argv[1]
    if(check_operation_type(argv[1][1])==e_encode)
    {
        read_and_validate_encode_args(argv, &encInfo);
       // call do encodeing()==e_success
       //encoding done successfully
       return 0;
    }
   // else if(ret==e_decode)
    //{ 
    //}
    else
    {
        printf("Validation failed\n");
        return 0;
    }

    do_encoding(encInfo);

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
