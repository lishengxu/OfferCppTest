/*
 * string.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#include <stdio.h>
#include <exception>
#include <stdexcept>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string>

char* copy(const char* const src) {
    if (src == NULL) {
        return NULL;
    }
    char* result = (char*) calloc(strlen(src) + 1, sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    strcpy(result, src);
    return result;
}

static char* replaceStringFromFirst(const char* const operation,
        const char* const src, const char* const desc) {
    int operationLen = strlen(operation), srcLen = strlen(src), descLen =
            strlen(desc);
    int countOfContain = 0, index = 0;
    while (index <= operationLen - srcLen) {
        if (strncmp(operation + index, src, srcLen)) {
            ++index;
        } else {
            ++countOfContain;
            index += srcLen;
        }
    }

    char* newString = (char*) calloc(
            operationLen + 1 + countOfContain * (descLen - srcLen),
            sizeof(char));
    if (newString == NULL) {
        return NULL;
    }
    index = 0;
    while (index <= operationLen - srcLen) {
        if (strncmp(operation + index, src, srcLen)) {
            strncat(newString, operation + index, 1);
            index++;
        } else {
            strcat(newString, desc);
            index += srcLen;
        }
    }

    strcat(newString, operation + index);

    return newString;

}

static char* replaceStringFromLast(const char* const operation,
        const char* const src, const char* const desc) {
    int operationLen = strlen(operation), srcLen = strlen(src), descLen =
            strlen(desc);
    int countOfContain = 0, index = 0;
    while (index <= operationLen - srcLen) {
        if (strncmp(operation + index, src, srcLen)) {
            ++index;
        } else {
            ++countOfContain;
            index += srcLen;
        }
    }

    char* newString = (char*) calloc(
            operationLen + 1 + countOfContain * (descLen - srcLen),
            sizeof(char));

    if (newString == NULL) {
        return NULL;
    }
    index = operationLen - 1;
    int newStringIndex = operationLen + countOfContain * (descLen - srcLen) - 1;
    if (newStringIndex >= 0) {
        while (index >= 0) {
            if (strncmp(operation + index, src, srcLen)) {
                newString[newStringIndex--] = operation[index--];
            } else {
                newStringIndex -= descLen - srcLen;
                for (int descIndex = 0; descIndex < descLen; ++descIndex) {
                    newString[newStringIndex + descIndex] = desc[descIndex];
                }
                for (int srcIndex = 0; srcIndex < srcLen; ++srcIndex) {
                    if (index >= 0) {
                        newString[--newStringIndex] = operation[--index];
                    }
                }
            }
        }
    }

    return newString;
}

char* replaceString(const char* const operation, const char* const src,
        const char* const desc, bool fromFirst) {
    if (operation == NULL || src == NULL || desc == NULL) {
        return NULL;
    }

    if (strlen(operation) == 0 || strlen(src) == 0) {
        return copy(operation);
    }
    return fromFirst ?
            replaceStringFromFirst(operation, src, desc) :
            replaceStringFromLast(operation, src, desc);
}

static void permutationRecursive(char* pStr, char* pBegin,
        std::vector<std::string>* pOut = NULL) {
    if (*pBegin == '\0') {
        printf("%s\n", pStr);
        if (pOut != NULL) {
            pOut->push_back(pStr);
        }
    } else {
        for (char* pIndex = pBegin; *pIndex != '\0'; ++pIndex) {
            char temp = *pBegin;
            *pBegin = *pIndex;
            *pIndex = temp;
            permutationRecursive(pStr, pBegin + 1, pOut);
            temp = *pBegin;
            *pBegin = *pIndex;
            *pIndex = temp;
        }
    }
}

void permutation(char* pStr, std::vector<std::string>* pOut/*= NULL*/) {
    if (pStr == NULL) {
        return;
    }
    permutationRecursive(pStr, pStr, pOut);
}

static void combinationRecursive(char* pStr, int number,
        std::vector<char>* result, std::vector<std::string>* pOut = NULL) {
    if (number == 0) {
        std::string str;
        for (std::vector<char>::iterator iter = result->begin();
                iter != result->end(); ++iter) {
            str += *iter;
        }
        if (!str.empty()) {
            printf("%s\n", str.c_str());
            if (pOut != NULL) {
                pOut->push_back(str);
            }
        }
        return;
    }
    if (*pStr == '\0') {
        return;
    }
    result->push_back(*pStr);
    combinationRecursive(pStr + 1, number - 1, result, pOut);
    result->pop_back();
    combinationRecursive(pStr + 1, number, result, pOut);
}

void combination(char* pStr, std::vector<std::string>* pOut = NULL) {
    if (pStr == NULL) {
        return;
    }
    std::vector<char> result;
    for (int i = 1, length = strlen(pStr); i <= length; ++i)
        combinationRecursive(pStr, i, &result, pOut);
}

char firstNotRespondingChar(const char* pStr) {
    if (pStr == NULL) {
        throw std::invalid_argument("invalid input");
    }
    int stringHash[256] = { 0 };
    for (unsigned int i = 0, length = strlen(pStr); i < length; ++i) {
        ++stringHash[(int) pStr[i]];
    }
    char result = '\0';
    for (unsigned int i = 0, length = strlen(pStr); i < length; ++i) {
        if (stringHash[(int) pStr[i]] == 1) {
            result = pStr[i];
            break;
        }
    }
    return result;
}

static void reverse(char* pBegin, char* pEnd) {
    if (pBegin == NULL || pEnd == NULL) {
        return;
    }
    while (pBegin < pEnd) {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        ++pBegin, --pEnd;
    }
}

void reverseSentence(char* sentence, const int length) {
    if (sentence == NULL || length < 1) {
        return;
    }

    char* pBegin = sentence;
    char* pEnd = sentence + length - 1;
    reverse(pBegin, pEnd);

    pBegin = pEnd = sentence;
    while (*pBegin != '\0') {
        if (*pBegin == ' ') {
            ++pBegin, ++pEnd;
        } else if (*pEnd == ' ' || *pEnd == '\0') {
            reverse(pBegin, pEnd - 1);
            pBegin = pEnd;
        } else {
            ++pEnd;
        }
    }
}

void leftRotateString(char* pStr, const int n) {
    if (pStr == NULL) {
        return;
    }
    int length = strlen(pStr);
    if (length < n || n < 0) {
        return;
    }
    char* begin = pStr;
    char* end = pStr + length - 1;
    char* pNIndex = begin + n - 1;
    reverse(begin, pNIndex);
    if (pNIndex < end) {
        reverse(pNIndex + 1, end);
    }
    reverse(begin, end);
}
