/*
 * string.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
