# 1. Does machine processing power affect execution time? (2 pts)
### Yes, machine processing power definitely affects execution time. A faster processor can perform calculations quicker, meaning that the time taken to eliminate destinations will be shorter on a more powerful machine. However, for small values of N, the difference may not be noticeable since the operations are simple and complete very quickly.

# 2. Which performs better: std::list or std::vector? Under what conditions? (5 pts)
### From my tests, std::vector performs better when N is small because accessing elements is faster in a contiguous memory block. However, as N grows, std::list starts to perform better because inserting and deleting elements in the middle is more efficient. Since the Josephus problem requires frequent removals, std::list generally performs better for larger N because deletion in a vector requires shifting all elements.

# 3. How does N impact runtime compared to M? (3 pts)
### The runtime increases as N gets larger because there are more destinations to process. The value of M also affects runtime but in a different way — smaller values of M result in faster eliminations since we don’t skip too many elements before removing one. If M is close to N, the iteration takes longer, which slows down the process.