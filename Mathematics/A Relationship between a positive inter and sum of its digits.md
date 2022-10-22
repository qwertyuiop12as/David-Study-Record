# A Relationship between a positive inter and sum of its digits.

Let S(N) denote the sum of the digits of N.

For any Integer N, N ≡ S(N) (mod 9).



For example, when N = 12345, and 12345 ≡ x (mod 9).

We can Re write 12345 into 
$$
1*10000 + 2*1000 + 3*100+4*10+5≡x(mod 9)
$$

$$
1*9999+2*999+3*99+4*9+1+2+3+4+5≡x(mod 9)
$$

We know that first 4 terms(1x9999+2x999+3x99+4x9) ≡ 0 (mod 9), so we can eliminate those terms.

Then 
$$
1+2+3+4+5≡x(mod 9)
$$

$$
1+2+3+4+5 = S(12345)
$$

$$
12345 ≡ S(12345)(mod9)
$$

 Let's to another example with alphabets
$$
N = abcd (1000a + 100b + 10c + d)\\
S(N) = a+b+c+d\\\\
N = 999a + 99b + 9c + d + a + b + c + d\\
abcd ≡ 999a + 99b + 9c + d + a + b + c (mod 9)\\\\
abcd ≡ a+b+c+d (mod 9)
$$




