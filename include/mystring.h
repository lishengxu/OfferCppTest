/*
 * string.h
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#ifndef STRING_H_
#define STRING_H_

/**
 * 将字符串operation中包含的src字符串替换成desc字符串，如果src字符串为空，则不做替换
 */
char* replaceString(const char* const operation, const char* const src,
        const char* const desc, bool fromFirst = true);

#endif /* STRING_H_ */
