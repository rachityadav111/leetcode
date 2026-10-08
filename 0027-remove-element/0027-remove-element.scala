object Solution {
    def removeElement(nums: Array[Int], `val`: Int): Int = {

        var k = 0
        var i = 0

        while (i < nums.length) {

            if (nums(i) != `val`) {
                nums(k) = nums(i)
                k += 1
            }

            i += 1
        }

        k
    }
}