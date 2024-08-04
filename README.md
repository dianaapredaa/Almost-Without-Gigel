*Copyright Preda Diana 324CA 2022-2023*

# Algorithm Design Assignment

**Student:** *Preda Diana*

**Group:** *324CA*

## <span style="color:purple"> **Foribot** </span>

We perform a binary search for the minimum load capacity of the ferry boats and checks if it is possible to distribute all cars across the ferries with that load capacity. If it is possible, we try to minimize the load capacity further. If it is not possible, we try to increase the load capacity.

The code uses two functions: *load_ferry*, which returns a boolean indicating whether it is possible to distribute all the cars across the ferries with that load capacity; and *binary_search*, which performs a binary search for the minimum load capacity of the ferry boats.

Exemple:

n = 10 </br>
k = 5 </br>
weights = {3, 4, 2, 1, 6, 7, 1, 2, 2, 3} </br>
sum = 31 </br>

|left  |right |mid  |possible| 
|:----:|:----:|:---:|:------:|
|1     |31    |16   | true   |
|1     |16    |8    | true   |
|1     |8     |4    |true    |
|5     |8     |6    |true    |
|7     |8     |7    |true    |
|8     |8     |8    |true    |

out: 8

## <span style="color:purple"> **Nostory** </span>

*task 1*

We use a greedy approach to solve the problem. We start by sorting both lists: one in ascending order and one in descending order. Then we iterate through both lists to find the maximum value and add it to the total score.

Exemple:

task = 1
n = 3
a = {1, 5, 10}
b = {6, 3, 9}

|i  |a   |b  |
|:-:|:--:|:-:|
|0  |10  |3  | 
|1  |5   |6  |
|2  |1   |9  |

score = max(a[0], b[0]) + max(a[1], b[1]) + max(a[2], b[2])
      = max(10, 3) + max(5, 6) + max(1, 9)
      = 10 + 6 + 9
      = 25

out: 25

*task 2*

We use a greedy approach to solve the problem. We first swap the elements between a and b if necessary, to ensure that the maximum value in each position is in b. We then sort both arrays, a in descending order and b in ascending order.

Then we iterate over the two arrays, comparing the values at each position. If the maximum value is in a, and there are still moves left, we swap the values between a and b, and add the maximum value to the total sum. Otherwise, we just add the value from b to the sum. We continue until we have iterated over all positions.

Exemple:

task = 2
moves = 2
n = 5
a = {3, 6, 10, 9, 5}
b = {1, 8, 4, 7, 2}

|i	|a[i]	|b[i]	|max(a[i], b[i])	|swapped? |
|:-:|:-----:|:-----:|:-----------------:|:-------:|
|0	|3	    |1	    |3	                |Yes      |
|1	|6	    |8	    |8	                |No       |
|2	|10	    |4	    |10	                |Yes      |
|3	|9	    |7	    |9	                |Yes      |
|4	|5	    |2	    |5	                |Yes      |

|i	|moves	|a[i]	|b[i]	|max(a[i], b[i])	| sum |
|:-:|:-----:|:-----:|:-----:|:-----------------:|:---:|
|0	|2	    |3	    |1	    |3	                |3    |
|1	|1	    |6	    |2	    |6	                |9    |
|2	|1	    |10	    |4	    |10	                |19   |
|3	|0	    |9	    |7	    |9	                |28   |
|4	|0	    |5	    |2	    |5	                |40   |

out: 40


## <span style="color:purple"> **Sushi** </span>

We use dynamic programming to solve the problem by creating a DP table and using the optimal solutions of subproblems to solve the main problem. We calculate the maximum rating that can be obtained by ordering sushi menus within the budget constraint. 

To tackle the problem at hand, I leveraged the implementation of the Backpack algorithm from Laboratory 3 [1]. Specifically, I adapted it to solve the assignment by applying a dynamic programming approach as it is explained below.

*task 1*

This task is solved using dynamic programming. We first create a DP table of size (m + 1) x (x * n + 1), where dp[i][j] represents the maximum rating that can be earned by using exhibits 1 to i, with a maximum total cost of j, and with the condition that each sushi plate can only be ordered once. We then calculate the maximum rating for each exhibit by summing the ratings for each person. Next, we initialize the base case by setting dp[0][j] = 0 for all j. We then fill in the rest of the DP table by iterating through each exhibit and each possible cost, and checking if using the exhibit results in a higher rating than not using it. The final answer is stored in dp[m][x * n].

*task 2*

For this task, we used the same method as before with a minor alteration. Specifically, we increased the quantity of sushi plates that could be requested by a factor of two.

*task 3*

For this task, we used the same method as before with another alteration. Specifically, we constrained the number of sushi plates that could be ordered by introducing a third dimension in our dp table.

## <span style="color:purple"> **Semnale** </span>

This task is also solved using dynamic programming, in order to calculate the number of possible signals for each type.

*type 1*

For type 1 signals, we create a three-dimensional DP table with dimensions (x+y+1) x (y+1) x 1, where x is the number of 0s and y is the number of 1s in the signal. The DP table is initialized with base cases and then filled in using the following recurrence relation:

*dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % mod* </br>
*dp[i][j][1] = dp[i-1][j-1][0] % mod* </br>

The final answer is given by the sum of dp[x+y][y][0] and dp[x+y][y][1] modulo mod.

*type 2*

For type 2 signals, we create a three-dimensional DP table with dimensions (x+y+1) x (y+1) x 2. The DP table is initialized with base cases and then filled in using the following recurrence relation:

*dp[i][j][0] = ((((dp[i - 1][j][0] % mod) + (dp[i - 1][j][1] % mod)) % mod) + (dp[i - 1][j][2] % mod)) % mod* </br>
*dp[i][j][1] = dp[i-1][j-1][0] % mod* </br>
*dp[i][j][2] = dp[i-1][j-1][1] % mod* </br>

The final answer is given by the sum of dp[x+y][y][0], dp[x+y][y][1], and dp[x+y][y][2] modulo mod.


## <span style="color:purple"> **Weak spots** </span>

We assume that the input values are within the allowed range of integers. The function may not return the correct result if the input values are not within the allowed range. </br>
We assume that the input values are positive integers. </br>
We assume that the input vectors have the correct size and format. If the input vectors are not in the correct size or format, the function may not return the correct result. </br>
The time complexity for my implementatin for Semnale, exceed the time-out set for this problem. </br>

## <span style="color:purple"> **Observation** </span>
It would have been challenging to provide a step-by-step example for Sushi and Semnale due to the complexity of the algorithms involved.

## <span style="color:purple"> **Sources** </span>

#### *[1] https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-03 - Sushi*
