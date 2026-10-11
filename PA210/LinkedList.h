//
// Created by riosd on 9/17/2026.
//
 
// tail_ is back so addBack is O(1). size_ is new so size() is O(1).
# pragma once
#include "Node.h" #include "List.h"

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        if (tail_ == nullptr) {
            tail_ = fresh;          // first node is both head and tail
        }
        ++size_;
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        if (head_ == nullptr) {
            tail_ = nullptr;        // list is empty again
        }
        delete doomed->data;
        delete doomed;
        --size_;
    }

    bool isEmpty() const override {
        return head_ == nullptr;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override {
        Node<T>* fresh = new Node<T>(value);
		// if position is 0 or less, implementation is identical to addFront
		if (position <= 0) {
			fresh->next = head_;
			head_ = fresh;
			if (tail_ == nullptr) {
				tail_ = fresh;      // first node is both head and tail
			}
		}

		else {
			Node<T>* current = head_;
			for (int i = 0; i < position - 1 && current != nullptr; ++i) { // n-1 steps unless current is nullptr, O(n) is tightest bound still.
                /*i increments to two spaces before position since the operations sends current
                to the next node, this ends a step ahead of the logical index of i, 
                and we want to stop `current` in just before the position */
				current = current->next;
			}
			// this checks that we aren't adding past the end of the list.
			if (current == nullptr) {
				std::cout << "Invalid position." << std::endl;
                delete fresh->data;
				delete fresh;
				return;
			}
            //positions and inserts the new node.
			fresh->next = current->next; //current->next is the node that fresh will point to.
			current->next = fresh;
            //in case the new node is added to the back, we update tail_
			if (fresh->next == nullptr) {
				tail_ = fresh;      // new node is now the tail
			}
		}
		++size_;
    }
    void deleteAnywhere(int position) override {
        //position == 0 is identical to deleteFront, avoiding o(n) search
        if (position == 0) {
            deleteFront();
            return;
        }
        if (size_ == 0) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
		if (position < 0 || position >= size_) { //range excludes size_ since size is not a valid index; position is 0-indexed.
            std::cout << "Invalid position." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        for (int i = 0; i < position; ++i) {
            doomed = doomed->next;
        }//doomed is at position
		Node<T>* prev = head_;
		for (int i = 0; i < position - 1; ++i) {
			prev = prev->next;
		} 
		prev->next = doomed->next;
        /* prev points to node after doomed, skipping over it.
        including pointing to nullptr if doomed was tail_. */
		if (doomed == tail_) { 
            tail_ = prev; 
		}
		delete doomed->data;
		delete doomed;
		--size_;
	}
	void reverse() override {
		if (head_ == nullptr || head_->next == nullptr) {
			return; // empty or single node list, nothing to reverse
		}
		Node<T>* prev = nullptr;
		Node<T>* current = head_;
		Node<T>* next = nullptr;
		tail_ = head_; // new tail will be the old head
        /* the condition to end the loop is that current is nullptr. 
        in example, a linkedlist of 2 nodes would take three iterations to reverse successfully.
        (Originally, the loop ended at current == tail_, but that failed to relink the last node) */
		while (current != nullptr) {
            /* Starting at the head, we set the next pointer to what current points to, then
            current links backwards to prev, which is nullptr for the firt iteration.*/
			next = current->next; 
			current->next = prev; 
            /* Below, the logical index of the previous node and current are shifted to the right.
            current and node are pointing to the same memory location.*/
			prev = current;       // move prev forward
			current = next;       // move current forward
		}
		head_ = prev; // new head is the last non-null node
	}
	void concat(List<T>* other) override {
		LinkedList<T>* otherList = dynamic_cast<LinkedList<T>*>(other);
		if (otherList == nullptr) {
			std::cout << "List type does not match, cannot concatenate." << std::endl;
			return;
		}
		if (otherList->head_ == nullptr) {
			return; // other list is empty, nothing to do
		}
		// if this list is empty, just point head_ and tail_ to the other list's head_ and tail_
		if (isEmpty()) {
			head_ = otherList->head_;
			tail_ = otherList->tail_;
		} 
		else {
			tail_->next = otherList->head_; //tail_ lets us link without traversing the list, O(1) time.
			tail_ = otherList->tail_;
		}
		size_ += otherList->size_;
        //otherlist ends up empty
		otherList->head_ = nullptr;
		otherList->tail_ = nullptr;
		otherList->size_ = 0;
	}

	~LinkedList() override {
		while (head_ != nullptr) {
			Node<T>* doomed = head_;
			head_ = head_->next;
                delete doomed->data;
                delete doomed;
            }
        }
private:
    Node<T>* head_;
	Node <T>* tail_;
	int size_;
    };