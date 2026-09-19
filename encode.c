#include <stdio.h>
#include "encode.h"
#include "types.h"

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

    	return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

    	return e_failure;
    }

    // No failure return e_success
    return e_success;
}

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    //check ".bmp" exatention at last
    encInfo->src_image_fname=argv[2];  

    //if not ".bp extaction is not there" return e_failure

    encInfo->secret_fname=argv[3];

    //check out file is given or not
    if(argv[4]!=NULL)
    {
       encInfo->stego_image_fname=argv[4];
    }
    else
    {
        encInfo->stego_image_fname="output.bmp";
    }

    if(open_files(encInfo)==e_failure)
    {
        return e_failure;
    }
}

Status open_files(EncodeInfo *encInfo)
{
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname,"r");
    if(encInfo->fptr_src_image==NULL)
    {
        printf("Source file is not Opened\n")
        return e_failure;
    }

    encInfo->fptr_secret = fopen(secret_fname,"r");
    if(encInfo->fptr_secret==NULL)
    {
        printf("Secret file is not Opended\n")
        return e_failure;
    }

    encInfo->fptr_stego_image = fopen(stego_image_fname,"w");
    if(encInfo->fptr_stego_image==NULL)
    {
        printf("Secret file is not Opended\n")
        return e_failure;
    }

}

Status do_encoding(EncodeInfo *encInfo)
{
    //check capacity
    //check_capacity(encInfo) == e_failure
    // print error return failure

    // call copy bmp headrer
    copy_bmp_header(fptr_src_image, fptr_stego_image);//check == e_failure
     // print error return failure

     //call encode magic string
        encode_magic_string(MAGIC_STRING, encInfo);//==e_failure
        //return e_failure and print error

        //call function
        encode_secret_file_extn(const char *file_extn, encInfo);
}

Status check_capacity(EncodeInfo *encInfo)
{
    //get image capacity
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);
    
    //get file size
    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);

    // check ((14+size_secret_file)*8)>image_capacity
    // return e_failure
    // else return e_succes
}

uint get_file_size(FILE *fptr)
{
    //move the offset to last pos
    //return ftell()
}

Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    //move the file ptr to the SEEK_SET or rewind()
    //declare the buffe[54];
    //read 54 bytes from src file
    //write 54 byts to dest file

    //return e_success
}

Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    char image_buffer[8];
    //read 8byte from the source file to image_buffer

    encInfo->fptr_stego_image = encode_byte_to_lsb(magic_string[1], image_buffer);
    //write encoded buffer tor output_file

    //return e_success

}

Status encode_byte_to_lsb(char data, char *image_buffer)
{
    for(int i=7;i>=0;i++)
    {
        // get the ith bit set or not
        // if set,set the lSB of image_buffer[]
        //else clear the lSB of image_buffer[]
    }
}

Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo)
{
    /*
        char *dot = strchar(secreat_file_name,'.')
        strcpy(extn_scr_file,dot)


        declare a buffer[32]
        read 32 bytes from src_file into buffer
        call encode_SIZE_TO_LSB(strlen(extn_scr_file),buffer)
    */
}

Status encode_secret_file_size(int size, )
{

}