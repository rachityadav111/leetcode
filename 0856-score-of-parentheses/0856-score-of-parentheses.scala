object Solution {
    def scoreOfParentheses(s: String): Int = {

        var stack = List(0)

        for (ch <- s) {

            if (ch == '(') {
                stack = 0 :: stack
            } else {
                val current = stack.head
                stack = stack.tail

                val score =
                    if (current == 0) 1
                    else 2 * current

                stack = (stack.head + score) :: stack.tail
            }
        }

        stack.head
    }
}