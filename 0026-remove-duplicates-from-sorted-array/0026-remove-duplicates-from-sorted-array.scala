object Solution {
    def removeDuplicates(nums: Array[Int]): Int = {

        var k = 1
        var i = 1

        while (i < nums.length) {

            if (nums(i) != nums(i - 1)) {
                nums(k) = nums(i)
                k += 1
            }

            i += 1
        }

        k
    }
}