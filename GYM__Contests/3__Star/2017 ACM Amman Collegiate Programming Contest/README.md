# 2017 ACM Amman Collegiate Programming Contest
> List of some notes about the problems of this contest

## Notes

1. In `I` -> we have to use dp to find the pattern
2. In `D` -> think that `If we have a path of length a, how many ways to make b change in direction`

```
         root
        /    \
      A        B
    /   \    /   \
   C    D   E     F
```
> If we in node C and want to reach to the root node and a = 2 -> so we have `a - 1` time we have the choice to change direction for b change so we have nCr(a-1, b) * 2 (if we start to left | if we start to right)

note: You need to user nCr % p | (Using Fermat Little Theorem) to find nCr % MOD

3. In `J` -> try to split at each position from 1 to length - 1 and check if it's a valid solution
4. In `G` -> Super subarray is a subarray in which its sum is divisible be each element in the subarray

note: to check if a number is divisible by multiple of numbers -> check if it's divisible by lcm of them or not
