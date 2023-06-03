There are two parts that need to be considered in this question.

## Range of variable

In the environment setting we can only store integers within 32-bit signed integer range [-2^31, 2^31-1]. If the quotient is greater than 2^31-1, return 2^31-1, else if the quotient is strictly less than -2^31 return -2^31.
I interpret this to be a requirement of not using `long` but only int in the code.

-> Also note that abs(MIN_INT) will be undefined behavior.

[A detailed explanation on how signed and unsigned intergers are calculated](https://www.cnblogs.com/lazycoding/archive/2011/03/21/unsigned-signed.html)

## Timeout

Since `* % /` are not allowed, the first thought is to use `-` to iteratively approximate the quotient, however it will be too slow.

[Here is a solution if reluctant to use bit operation](https://leetcode.cn/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/)

