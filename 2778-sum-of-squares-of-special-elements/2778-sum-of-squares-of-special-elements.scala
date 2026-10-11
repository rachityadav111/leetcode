
object Solution {
    def sumOfSquares(nums: Array[Int]): Int = {
        val n = nums.length
        var sum = 0
        var i = 1

        while (i <= n) {
            if (n % i == 0) {
                sum += nums(i - 1) * nums(i - 1)
            }
            i += 1
        }

        sum
    }
}
