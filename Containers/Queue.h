#ifndef _LogikEdge_React_Queue_h
#define _LogikEdge_React_Queue_h

namespace LogikEdge { namespace React {
	template <typename T, unsigned SIZE>
	class Queue {
	public:
		typedef Queue<T,SIZE>		Type;
		typedef CArray<T,SIZE>		Container;

		// ========================================================================
		/// Creates a new queue.
		Queue() { myReadIdx= myWriteIdx= 0; }

		// ========================================================================
		/// Returns the number of element(s) in the queue.
		///
		/// @return Number of element in the queue.
		///
		unsigned getCount() const {
			int count= myWriteIdx - myReadIdx;
			if(count >= 0) return count;
			return count+SIZE;
		}

		// ========================================================================
		/// Determines if the queue is empty.
		///
		/// @return _true_ if the queue is empty; _false_ otherwise.
		///
		bool isEmpty() const { return myReadIdx == myWriteIdx; }

		// ========================================================================
		/// Determines if the queue is full.
		///
		/// @return _true_ if the queue is full; _false_ otherwise.
		///
		bool isFull() const { return getCount() == SIZE-1; }

		// ========================================================================
		/// Returns the element at the top of the queue.
		///
		/// @param theElement A reference to the element to fill.
		/// @return _true_ if an element is available; _false_ otherwise.
		///
		bool top(T& theElement) const {
			if(isEmpty()) return false;
			theElement= myContainer[myReadIdx];
			return true;
		}

	private:
		unsigned	myReadIdx;
		unsigned	myWriteIdx;
		Container	myContainer;
	};

}}

#endif
