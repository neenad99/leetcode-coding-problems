
class ListNode{
    int key;
    int data;
    ListNode prev;
    ListNode next;

    public ListNode(int key,int data){
        this.key = key;
        this.data = data;
        this.prev = null;
        this.next = null;
    }

}

class LRUCache {
    ListNode head = new ListNode(-1,-1);
    ListNode tail = new ListNode(-1,-1);
    HashMap<Integer,ListNode> hash = new HashMap<>();
    int maxSize = 0;
    int currSize = 0;
    public LRUCache(int capacity) {
        maxSize = capacity;
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        ListNode hashKey = hash.get(key);

        if(hashKey == null)return -1;
        
        deleteNode(hashKey);
        addToHead(hashKey);

        return hashKey.data;
    }
    
    public void put(int key, int value) {
        ListNode hashKey = hash.get(key);
        if(hashKey != null){
            hashKey.data = value;
            deleteNode(hashKey);
            addToHead(hashKey);
        }
        else{
            ListNode newNode = new ListNode(key,value);
            hash.put(key,newNode);
            if(currSize == maxSize){
                //System.out.println(hash.get(tail.) + " " + tail.prev.data);
                hash.remove(tail.prev.key);
                deleteNode(tail.prev);
                addToHead(newNode);
            }
            else{
                addToHead(newNode);
                currSize++;
            }
        }
    }

    void addToHead(ListNode newNode){
       head.next.prev = newNode;
       newNode.next = head.next;
       newNode.prev = head;
       head.next = newNode;

    }

    void deleteNode(ListNode currNode){
        currNode.prev.next = currNode.next;
        currNode.next.prev = currNode.prev;
    }

}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */