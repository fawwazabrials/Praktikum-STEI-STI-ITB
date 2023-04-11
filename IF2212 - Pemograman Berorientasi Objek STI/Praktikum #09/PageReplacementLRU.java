import java.util.HashMap;
import java.util.Map;

public class PageReplacementLRU {
    private final Integer maxPages;
    // Pair<processID, page>
    private Map<Pair<Integer, Integer>, Node> pages;
    private Node head;
    private Node tail;

    private class Node {
        Pair<Integer, Integer> pageID;
        Integer physicalAddr;
        Node prev;
        Node next;

        public Node(Pair<Integer, Integer> pageID, int physicalAddr) {
            this.pageID = pageID;
            this.physicalAddr = physicalAddr;
            prev = null;
            next = null;
        }
    }

    private void addNode(Node node) {
        // Please provide your solution in the space below
        // Tambahkan node di depan head
        if (head == null) {
            head= node; tail= node;
        }

        head.prev = node;
        node.next = head;
        head = node;
    }

    private void removeNode(Node node) {
        // Please provide your solution in the space below
        if (pages.size() == 1) {
            head = null;
            tail = null;
        }

        else {
            if (node == head) {
                head = node.next;
                node.next.prev = null;
            } else if (node == tail) {
                tail = node.prev;
                node.prev.next = null;
            } else {
                node.prev.next = node.next;
                node.next.prev = node.prev;
            }
        }

    }

    private void moveToHead(Node node) {
        // Please provide your solution in the space below
        removeNode(node);
        addNode(node);
    }

    public PageReplacementLRU(Integer maxPages) {
        this.maxPages = maxPages;
        tail = null;
        head = null;

        pages = new HashMap<Pair<Integer, Integer>, Node>();
        
    }

    public int accessPage(Pair<Integer, Integer> pageID) {
        // Please provide your solution in the space below
        // print "page fault!" ketika pageID tidak ditemukan dalam LRU
        // lalu kembalikan -1

        if (pages.containsKey(pageID)) {
            moveToHead(pages.get(pageID));
            return pages.get(pageID).physicalAddr;
        } else {
            System.out.println("page fault!");
            return -1;
        }
    }

    public void addPage(Pair<Integer, Integer> pageID, int physicalAddr) {
        // Please provide your solution in the space below
        Node n = new Node(pageID, physicalAddr);
        if (pages.size() == maxPages) {
            pages.remove(tail.pageID);
            removeNode(tail);
        }
        pages.put(pageID, n);
        addNode(n);
        //System.out.println(pages);
    }
}
