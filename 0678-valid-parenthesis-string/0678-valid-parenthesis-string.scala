object Solution {

    def checkValidString(s: String): Boolean = {

        var low = 0
        var high = 0
        var i = 0
        var valid = true

        while (i < s.length && valid) {

            val ch = s(i)

            if (ch == '(') {
                low += 1
                high += 1
            }
            else if (ch == ')') {
                low -= 1
                high -= 1
            }
            else { // '*'
                low -= 1
                high += 1
            }

            if (high < 0) {
                valid = false
            }

            if (low < 0) {
                low = 0
            }

            i += 1
        }

        valid && low == 0
    }
}