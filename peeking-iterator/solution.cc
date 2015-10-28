// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
    int peek_value;
    bool peek_flag;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
	if (peek_flag)
	    return peek_value;
	if (!Iterator::hasNext())
	    return -1;
	
	peek_flag = true;
	return peek_value = Iterator::next();
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    //using Iterator::next;
    int next() {
	if (!peek_flag)
	    return Iterator::next();
	
	peek_flag = false;
	return peek_value;
    }

    bool hasNext() const {
	if (peek_flag)
	    return true;
	
	return Iterator::hasNext();
    }
};
