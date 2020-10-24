# Sorting notes
> List of notes I take while learning about all the different sorting algorithms

### Algorithm analysis
- Worst case: Max(T(n))
- Best case: Min(T(n))
- Average case: E(T(n))


🚩 **Note:**
Average case requires knowledge of statistical distribution of inputs (can be biased)
  - Approx. to worst case (when the best case is the exception)
  - Approx. to best case (when the worst case is the exception)
  
### Asymptotic analysis
- 𝚶−𝒏𝒐𝒕𝒂𝒕𝒊𝒐𝒏(Big O):
  - [x] Works on _Upper bound_ of function (worst case)
  - [x] May be asymptotically tight 2n² = O(n²)
  - [x] May not be asymptotically tight 2n = O(n²)
- Θ−𝒏𝒐𝒕𝒂𝒕𝒊𝒐𝒏(Theta):
  - [x] Works on tight bound (fix complexity)
  - [x] We user theta when complexity of the algorithm is almost fixed for all cases
- Ω − 𝒏𝒐𝒕𝒂𝒕𝒊𝒐𝒏 (Big-Omega):
  - [x] Works on _Lower bound_ of function (best case)
  - [x] May be asymptotically tight 2n² = Ω(n²)
  - [x] May not be asymptotically tight 2n³ = Ω(n²)
