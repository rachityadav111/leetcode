
object Solution {
    def swapPairs(head: ListNode): ListNode = {

        if (head == null || head.next == null) {
            return head
        }

        val second = head.next

        head.next = swapPairs(second.next)
        second.next = head

        second
    }
}