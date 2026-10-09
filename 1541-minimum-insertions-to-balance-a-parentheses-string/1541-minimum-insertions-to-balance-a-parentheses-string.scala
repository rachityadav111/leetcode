
object Solution {
    def minInsertions(s: String): Int = {

        var open = 0
        var insertions = 0
        var i = 0

        while (i < s.length) {

            if (s(i) == '(') {
                open += 1
            } else {

                // Check whether the next character is also ')'
                if (i + 1 < s.length && s(i + 1) == ')') {
                    i += 1
                } else {
                    // Insert one ')' to complete the pair
                    insertions += 1
                }

                if (open > 0) {
                    open -= 1
                } else {
                    // Insert '(' because no opening bracket exists
                    insertions += 1
                }
            }

            i += 1
        }

        // Each remaining '(' requires two ')'
        insertions += open * 2

        insertions
    }
}
