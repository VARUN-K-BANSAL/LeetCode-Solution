// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
    public Iterator<Integer> itr;
    public boolean checked;
    public int val;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    itr = iterator;
        val = 0;
        checked = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        if(this.checked) return this.val;
        this.checked = true;
        this.val = this.itr.next();
        return this.val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
        if(this.checked) {
            this.checked = !this.checked;
            return this.val;
        }
        return this.itr.next();
	}
	
	@Override
	public boolean hasNext() {
        return this.checked || this.itr.hasNext();
	}
}