object Solution {
    def removeOuterParentheses(s: String): String = {

        val result = new StringBuilder
        var depth = 0

        for (ch <- s) {

            if (ch == '(') {
                if (depth > 0) {
                    result.append(ch)
                }
                depth += 1
            }

            else {
                depth -= 1

                if (depth > 0) {
                    result.append(ch)
                }
            }
        }

        result.toString()
    }
}