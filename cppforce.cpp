/*
*Educational purpose only             
*I'm not responsible for your actions 
*
*-----------------------------------------------
* The hash functions were created by someone else
* 
*/

#include <iostream>
#include "hashes/md5.h"
#include "hashes/sha1.h"
#include "hashes/sha256.h"
#include "hashes/sha384.h"
#include "hashes/sha512.h"

using namespace std;

const char letters[] = 
{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 
    'h', 'i', 'j', 'k', 'l', 'm', 'n', 
    'o', 'p', 'q', 'r', 's', 't', 'u', 
    'v', 'w', 'x', 'y', 'z', 'A', 'B', 
    'C', 'D', 'E', 'F', 'G', 'H', 'I', 
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 
    'X', 'Y', 'Z', '/', '.', ';', '"', 
    ']', '[', '+', '1', '2', '3', '4', 
    '5', '6', '7', '8', '9', '0', ':', 
    '|', ',', '=', '-', '_', '!', '@', 
    '#', '$', '%', '^', '&', '*', '(', 
    ')' ,'~', '`', 92, 39
};

void bruteforce(unsigned int lengths, string combos, string hashed)
{
    if(combos.length() == lengths)
    {
        cout << "Trying: " << combos << endl;
        if(md5(combos) == hashed)
        {
            cout << "Cracked: " << combos << std::endl;
            exit(0);
        }else if(sha1(combos) == hashed)
        {
            cout << "Cracked: " << combos << std::endl;
            exit(0);
        }else if(sha256(combos) == hashed)
        {
            cout << "Cracked: " << combos << std::endl;
            exit(0);
        }else if(sha384(combos) == hashed)
        {
            cout << "Cracked: " << combos << std::endl;
            exit(0);
        }else if(sha512(combos) == hashed)
        {
            cout << "Cracked: " << combos << std::endl;
            exit(0);
        }
        return;
    }else{
        for (unsigned int x=0; x < sizeof(letters); x++)
        {
            string oldcombo = combos + letters[x];
            bruteforce(lengths, oldcombo, hashed);
        }
    }
}

void cracker()
{
    string hashed;
    cout << "Hash: ";
    cin >>hashed;
    
    while(1)
    {    
        static unsigned int x = 1;
        bruteforce(x, "", hashed);
        x++;
    }
}

int main(int argc, char *argv[])
{
    cracker();
    return 0;
}
