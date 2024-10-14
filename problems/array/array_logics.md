When dealing with subarrays, there are different types of problems you might want to solve. Each problem typically requires a specialized algorithm for optimal performance. Here are some of the best algorithms based on common subarray-related tasks:

### 1. **Kadane's Algorithm (Maximum Subarray Sum)**

**Problem**: Find the subarray with the maximum sum.

**Time Complexity**: O(n)

**Approach**: This is a dynamic programming-based approach that processes the array in one pass and keeps track of the maximum sum that ends at the current index.

**Algorithm**:

```cpp
int max_subarray_sum(const std::vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];

    for (std::size_t i = 1; i < arr.size(); ++i) {
        max_current = std::max(arr[i], max_current + arr[i]);
        max_global = std::max(max_global, max_current);
    }
    return max_global;
}
```

**Key Insight**: The algorithm efficiently computes the maximum sum by either extending the current subarray or starting a new one at each step.

### 2. **Sliding Window Technique**

**Problem**: Find all subarrays of a fixed size `k` or subarrays with specific properties (e.g., sum within a certain range).

**Time Complexity**: O(n)

**Approach**: Use two pointers to represent the window of interest. Adjust the window dynamically by moving the right pointer to expand the window and the left pointer to shrink it as necessary.

**Algorithm for Fixed Size `k`**:

```cpp
std::vector<int> sliding_window_sum(const std::vector<int>& arr, std::size_t k) {
    std::vector<int> results;
    int window_sum = 0;

    // Initial window
    for (std::size_t i = 0; i < k; ++i) {
        window_sum += arr[i];
    }
    results.push_back(window_sum);

    // Slide the window across the array
    for (std::size_t i = k; i < arr.size(); ++i) {
        window_sum += arr[i] - arr[i - k];  // Add the new element and remove the leftmost one
        results.push_back(window_sum);
    }

    return results;
}
```

**Key Insight**: The sliding window optimally maintains the sum (or any other metric) for subarrays of fixed size by reusing previous computations.

### 3. **Prefix Sum Array**

**Problem**: Efficiently find the sum of any subarray in O(1) time after preprocessing.

**Time Complexity**: O(n) for preprocessing, O(1) per query

**Approach**: Build a prefix sum array where each element at index `i` holds the sum of elements from the start of the array up to `i`. The sum of a subarray can be computed by subtracting two prefix sums.

**Algorithm**:

```cpp
std::vector<int> build_prefix_sum(const std::vector<int>& arr) {
    std::vector<int> prefix_sum(arr.size() + 1, 0);
    for (std::size_t i = 1; i <= arr.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
    }
    return prefix_sum;
}

int sum_of_subarray(const std::vector<int>& prefix_sum, std::size_t left, std::size_t right) {
    return prefix_sum[right + 1] - prefix_sum[left];
}
```

**Key Insight**: Precomputing the prefix sums allows constant-time subarray sum queries, making it very useful when multiple queries need to be processed.

### 4. **Two-Pointer Technique**

**Problem**: Find subarrays that meet certain criteria, such as having a sum less than or equal to a target.

**Time Complexity**: O(n)

**Approach**: Use two pointers (`start` and `end`) to represent a subarray. Adjust the window dynamically by moving the `end` pointer to expand the subarray and the `start` pointer to shrink it when the sum exceeds a target.

**Algorithm**:

```cpp
int count_subarrays_with_sum_less_than_or_equal(const std::vector<int>& arr, int target) {
    int count = 0;
    int sum = 0;
    std::size_t start = 0;

    for (std::size_t end = 0; end < arr.size(); ++end) {
        sum += arr[end];

        while (sum > target && start <= end) {
            sum -= arr[start++];
        }

        count += end - start + 1;  // All subarrays ending at `end`
    }

    return count;
}
```

**Key Insight**: This approach avoids recalculating the sum for every possible subarray by dynamically adjusting the window size.

### 5. **Divide and Conquer (For Maximum Subarray Problem)**

**Problem**: Find the subarray with the maximum sum using divide and conquer.

**Time Complexity**: O(n log n)

**Approach**: Recursively divide the array into two halves, find the maximum subarray sum in each half, and also check for the maximum subarray that crosses the midpoint.

**Algorithm**:

```cpp
int cross_sum(const std::vector<int>& arr, std::size_t left, std::size_t mid, std::size_t right) {
    int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;

    for (int i = mid; i >= static_cast<int>(left); --i) {
        sum += arr[i];
        left_sum = std::max(left_sum, sum);
    }

    sum = 0;
    for (std::size_t i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        right_sum = std::max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int max_subarray_divide_and_conquer(const std::vector<int>& arr, std::size_t left, std::size_t right) {
    if (left == right) return arr[left];

    std::size_t mid = left + (right - left) / 2;
    int left_sum = max_subarray_divide_and_conquer(arr, left, mid);
    int right_sum = max_subarray_divide_and_conquer(arr, mid + 1, right);
    int cross = cross_sum(arr, left, mid, right);

    return std::max({left_sum, right_sum, cross});
}
```

**Key Insight**: This approach is useful for learning and has a more structured divide-and-conquer methodology, but Kadane's algorithm is often more efficient for maximum subarray problems.

---

### Conclusion

Here’s a summary of the algorithms and their typical use cases:

- **Kadane's Algorithm**: For maximum subarray sum.
- **Sliding Window**: For subarrays of fixed size or specific constraints (like sum ≤ target).
- **Prefix Sum**: For efficient subarray sum queries.
- **Two-Pointer Technique**: For finding subarrays with constraints like sum ≤ target.
- **Divide and Conquer**: For recursive solutions to problems like maximum subarray sum.

Each of these algorithms has an optimal use case, depending on the type of subarray problem you're solving.
