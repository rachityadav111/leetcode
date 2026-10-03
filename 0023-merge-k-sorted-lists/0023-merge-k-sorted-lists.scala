object Solution {

    def mergeTwoLists(a: ListNode, b: ListNode): ListNode = {

        val dummy = new ListNode(0)
        var current = dummy

        var list1 = a
        var list2 = b

        while (list1 != null && list2 != null) {

            if (list1.x <= list2.x) {
                current.next = list1
                list1 = list1.next
            } else {
                current.next = list2
                list2 = list2.next
            }

            current = current.next
        }

        if (list1 != null) {
            current.next = list1
        } else {
            current.next = list2
        }

        dummy.next
    }


    def mergeKLists(lists: Array[ListNode]): ListNode = {

        if (lists == null || lists.length == 0) {
            return null
        }

        var interval = 1

        while (interval < lists.length) {

            var i = 0

            while (i + interval < lists.length) {

                lists(i) = mergeTwoLists(
                    lists(i),
                    lists(i + interval)
                )

                i += interval * 2
            }

            interval *= 2
        }

        lists(0)
    }
}