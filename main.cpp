#include <iostream>


unsigned char gmul(unsigned char a, unsigned char b) {
    unsigned char p = 0;
    unsigned char counter;
    for(counter = 0; counter < 8; counter++) {
        unsigned char hi_bit_set;
        if((b & 1) == 1)
            p ^= a;
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if(hi_bit_set == 0x80)
            a ^= 0x1b;
        b >>= 1;
    }
    return p;
}

void inv_mix_column(unsigned char *r ) {
    unsigned char a[4];
    unsigned char c;
    for(c=0;c<4;c++) {
        a[c] = r[c];
    }
    r[0] = gmul(a[0],2) ^ gmul(a[3],1) ^ gmul(a[2],1) ^ gmul(a[1],3);
    r[1] = gmul(a[1],2) ^ gmul(a[0],1) ^ gmul(a[3],1) ^ gmul(a[2],3);
    r[2] = gmul(a[2],2) ^ gmul(a[1],1) ^ gmul(a[0],1) ^ gmul(a[3],3);
    r[3] = gmul(a[3],2) ^ gmul(a[2],1) ^ gmul(a[1],1) ^ gmul(a[0],3);
}

int main() {
    unsigned char r[4] = {183, 229, 65, 207};
    inv_mix_column(r);
    std::cout << std::hex << (int) r[0] << std::endl;
    std::cout << std::hex << (int) r[1] << std::endl;
    std::cout << std::hex << (int) r[2] << std::endl;
    std::cout << std::hex << (int) r[3] << std::endl;

    return 0;
}
