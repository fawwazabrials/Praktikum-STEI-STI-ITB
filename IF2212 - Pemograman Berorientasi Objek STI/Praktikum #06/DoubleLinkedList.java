/**
 * LinkedList.java
 * Class ini adalah class pengimplementasian linked list dengan metode double pointer
 * @author 18221067 Fawwaz Abrial Saffa
 */

public class DoubleLinkedList<T> {

    private Node<T> head;
    private Node<T> tail;
    private int size;

    /**
     * Konstruktor
     * buat Double linked list dengan size = 0 dan head = tail = null
     */
    public DoubleLinkedList() {
        size = 0;
        head = null;
        tail = null;
    }

    /**
     * Cari elemen yang terletak pada posisi position
     * @param position
     * @return elemen pada posisi position jika ada, null jika tidak ada
     */
    public Node<T> getNode(int position) {
        if (position >= size) return null;

        Node<T> p;
        p = head;
        while (position-- > 0) {
            p = p.getNext();
        } return p;
    }

    /**
     * Tambah elemen dengan nilai item dengan menambahkan
     * node sebagai elemen paling belakang
     * @param item
     */
    public void add(T item) {
        Node<T> p = new Node<T> (item);
        
        if (size == 0) {
            head = p;
        } else {
            tail.setNext(p);
            p.setPrev(tail);
        } 
        tail = p; size++;
    }

    /**
     * Cari nilai elemen pada posisi position
     * @param position
     * @return nilai elemen pada posisi position jika ada, null jika tidak ada
     */
    public T get(int position) {
        if (getNode(position) != null) return getNode(position).getValue();
        return null;
    }

    /**
     * Ubah nilai elemen pada posisi position menjadi nilai item jika ada
     * @param position
     * @param item
     */
    public void set(int position, T item) {
        if (getNode(position) != null) getNode(position).setValue(item);
    }
        

    /**
     * Hapus elemen pada posisi position jika ada
     * @param position
     */
    public void remove(int position) {
        if (getNode(position) != null) {
            if (getSize() == 1) clear();
            else {
                Node<T> next = getNode(position).getNext();
                Node<T> prev = getNode(position).getPrev();

                if (getNode(position) == head) { // node is head
                    head = getNode(position).getNext();
                    next.setPrev(prev);
                }

                else if (getNode(position) == tail) { // node is tail
                    tail = getNode(position).getPrev();
                    prev.setNext(next);

                }

                else {
                    next.setPrev(prev);
                    prev.setNext(next);
                }

                size--;

                
            }
        }
    }

    /**
     * Hapus semua elemen dari Double Linked List
     */
    public void clear() {
        head = null;
        tail = null;
        size = 0;
    }

    /**
     * Getter size
     * @return size
     */
    public int getSize() {
        return size;
    }

    /**
     * Menampilkan keseluruhan isi Double Linked List
     * Format yang dikeluarkan adalah sebagai berikut, misal isi list adalah [1,2,3,4]
     * Maka output yang dihasilkan adalah (dengan enter) :
     * 1 2 3 4
     */
    public void display() {
        StringBuilder sb = new StringBuilder("");
        int pos = -1;

        if (size > 0) {
            Node<T> cur = head;
            while (cur.getNext() != null && pos < size-1) {
                pos++;
                sb.append(cur.getValue().toString() + " ");
                cur = cur.getNext();
            } sb.append(cur.getValue().toString());
        }

        System.out.println(sb); 
    }

    /**
     * Find element position
     * jika terdapat lebih dari 1 elemen dengan nilai yang sama, maka ambil posisi
     * yang ditemukan pertama kali dari head
     * @return posisi dari sebuah item mulai dari head dengan zero indexing
     */
    public Integer find(T item) {
        int pos = 0;

        Node<T> cur = head;
        boolean found = false;
        while (cur.getNext() != null && !found) {
            if (item == cur.getValue()) found = true;
            else pos++;
            cur = cur.getNext();
        }

        if (found) return pos;
        else return -1;
    }
}
