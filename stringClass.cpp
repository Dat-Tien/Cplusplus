#include<iostream>
#include<string.h>
#include<stdio.h>

class String {
public:
    String() : mRes(nullptr), mLen(0) {}

    String(const char* data) {
        mLen = strlen(data);
        mRes = new char[mLen +1];
        strcpy(mRes, data);
    }

    String(const String& oStr) {
        if (oStr.mRes != nullptr) {
            mLen = oStr.mLen;
            mRes = new char[mLen + 1];
            strcpy(mRes, oStr.mRes);
        } else {
            printf("String to copy is null, do not perform copy contructor\n");
        }
    }

    String& operator=(const String& cStr) {
        if(cStr.mRes != nullptr && this != &cStr) {
            delete[] mRes;
            this->mLen = cStr.mLen;
            this->mRes = new char[mLen];
            strcpy(this->mRes, cStr.mRes);
        }
        printf("mRes %s with mLen %d\n", mRes, mLen);
        return *this;
    }

    // String& operator=(const String&& mStr) {

    // }


private:
    char* mRes;
    uint32_t mLen;
};


int main() {

    String str1; //default ctor
    String str2("Hello this is str2"); // para ctor
    // printf("%s %d", str2.mRes, str2.mLen);
    String str3 = str2; //copy ctor
    String str4 = str1; //copy ctor
    str3 = str2; // copy assignment operator
    // std::cout<<str2; //overloading <<
    // std::cin >> str1; // overloading >>

}