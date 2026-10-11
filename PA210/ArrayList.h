//
// Created by riosd on 9/15/2026.
//

#pragma once

#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
class ArrayList : public List<T> {
public:
    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }
    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) return true;
        }
        return false;
    }
    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }
    void addAnywhere(int position, T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
		// Check if position is within range; 
        if (position < 0 || position > size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
		//identical top addFront if position == 0
		if (position == 0) {
			addFront(value);
			return;
		}
		//adds to end of list if position == size_, avoiding the 0(n) shift.
        if (position == size_) {
			data_[size_] = value;
            return;
        }
        // adding to any other position, and shifting elements to the right, 
		for (int i = size_; i > position; --i) {
			data_[i] = data_[i - 1];
		}
		data_[position] = value;
		++size_;
    }
   
	void deleteAnywhere(int position) override {
		if (size_ == 0) {
			std::cout << "ArrayList is empty." << std::endl;
			return;
		}
		if (position < 0 || position >= size_) { // range is from 0 to size-1 becuase size points to an already empty or OOB index.
			std::cout << "Invalid position." << std::endl;
			return;
		}

		delete data_[position];

        if (position == size_ - 1) { // avoid shifting if deleting the last element.
            --size_;
            return;
        }
		for (int i = position; i < size_ - 1; ++i) { // shift elements to the left to fill the gap
			data_[i] = data_[i + 1];
		}
		--size_;
	}

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }
private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};