#ifndef _LogikEdge_React_PriorityQueue_h
#define _LogikEdge_React_PriorityQueue_h

//#include "Target/IReact.h"
#include "../std/utility.h"
#include <algorithm>

//=======================================================================================
/// The priorityQueue sorts its elements such as  its first element is always the greatest
/// of the elements it contains, according to some strict weak ordering criterion.
///
/// @param T 	The type of the stored elements --
/// @param Container The type of the underlying container to use to store the elements.
/// @param Compare A Compare type providing a strict weak ordering. It has
///                boolean operator ()(const T&,const T&)
namespace LogikEdge {
	namespace React {
		/// -- PriorityQueue real generic class --
		template <typename T, typename Container, typename Compare>
		class PriorityQueue {

		public:
			typedef void									Base;
			typedef PriorityQueue<T, Container, Compare>	Type;
			typedef T										ValueType;
			typedef typename Container::iterator			Iterator;


			//=======================================================================================
			/// Returns a pointer to the first item in the PriorityQueue
			Iterator begin() { return myContainer.begin(); }
			/// Returns a pointer the last item + 1 in the PriorityQueue
			Iterator end() { return myContainer.end(); }
			/// Returns true if PriorityQueue is empty
			bool empty() { return myContainer.empty(); }
			/// returns the current size of the PriorityQueue
			unsigned size() { return myCount; }

			PriorityQueue() { myCount = 0; }

			/// Sorts the Queue according to the Compare function
			void sort() {
				Compare comp;
				unsigned count = myCount;
				// -- Nothing to sort if Queue doesn't have more than 2 elements
				if (count <= 1) { return; }
				unsigned indexOfSmallestElement = 0;
				// -- find smallest element --
				for (unsigned i = 1; i < count; ++i) {
					//SAMAH : I fixed the reentrancy issue with the count, is that all??
					// MICHEL: you must have searched for this one ... but it does not provide the
					// protection you hoped for (sorry).  Imagine the following senario:
					// 1) in a lower priority thread a sort is started and the best element has been seen
					//    but we are still in the loop (here); then
					// 2) a higher priority thread gets control and also does a 'sort'.  This higher priority
					//    thread will find the same 'best element' and swaps the top with the best element.
					// 3) ... now the interrupted lower priority thread continues its loop still believeing that
					//    the 'indexOfSmallestElement' is the best element (but it is something unknown now).
					//    Eventually, the loop finished and the low priority thread now updates the 'top'
					//    with some element that is worst then the top.
					//startCriticalSection();
					if (comp(myContainer[indexOfSmallestElement], myContainer[i])) {
						indexOfSmallestElement = i;
					}
					//endCriticalSection();
				}


				// -- After finding the highest priority, need to place it on top of the PriorityQueue
				if (indexOfSmallestElement != 0) {
					T temp;
					temp = myContainer[0];
					myContainer[0] = myContainer[indexOfSmallestElement];
					myContainer[indexOfSmallestElement] = temp;
				}
			}

			/// insert element to the PriorityQueue
			/// @param value the element to be added to the PriorityQueue
			void push(T& valueToPush) {
				//-- Compare “top” with the new element and swap if needed, container will always have the “highest priority” element on top.
				if (myCount == 0) {
					myContainer.insert(myContainer.begin(), valueToPush);
				}
				if (myCount >= 1) {
					Compare comp;
					if (comp(myContainer[0], valueToPush)) {
						myContainer.insert(myContainer.begin(), valueToPush);
					}
					else {
						myContainer.insert(myContainer.end(), valueToPush);
					}

				}
				++myCount;

			}



			/// Returns the top element in the PriorityQueue
			T& top() {
				if (!empty()) {
					return myContainer[0];
				}
				// -- TODO : what do I do if its empty?
				// MICHEL: You should throw an error (to be defined)
				//else return;
			}


			/// Removes the element at the top of the PriorityQueue
			void pop() {
				if (myCount > 1) {
					myContainer[0] = myContainer[myCount - 1];
					// MICHEL: What is needed here is a default initializer type.  It will look like:
					// SAMAH:	can I use the default constructor of T ??
					myContainer.erase(end() - 1);
					//myContainer[myCount - 1] = T();
					--myCount;
					sort();
				}
			}



		private:
			unsigned 								myCount;			// --  Number of elements in the queue. --
			Container								myContainer;		// -- The underlying container. --
																		/// Defines the oprator [] that allows accessing the element in the container
			T& operator[](unsigned index) { return myContainer[index >= myCount ? myCount - 1 : index]; }
		};
		/// -- PriorityQueue specialization class for a void pointer --
		template <typename Container, typename Compare> class PriorityQueue<void*, Container, Compare> {
		public:
			typedef void										Base;
			typedef PriorityQueue<void*, Container, Compare>	Type;
			typedef typename Container::iterator				Iterator;
			//=======================================================================================
			/// Returns a pointer to the first item in the PriorityQueue
			Iterator begin() { return myContainer.begin(); }
			/// Returns a pointer the last item + 1 in the PriorityQueue
			Iterator end() { return myContainer.end(); }
			/// Returns true if PriorityQueue is empty
			bool empty() { return myContainer.empty(); }
			/// returns the current size of the PriorityQueue
			unsigned size() { return myCount; }

			PriorityQueue() { myCount = 0; }

			/// Sorts the Queue according to the Compare function
			void sort() {
				Compare comp;
				unsigned count = myCount;
				// -- Nothing to sort if Queue doesn't have more than 2 elements
				if (count <= 1) { return; }
				unsigned indexOfSmallestElement = 0;
				// -- find smallest element --
				for (unsigned i = 1; i < count; ++i) {
					//startCriticalSection();
					if (comp(myContainer[indexOfSmallestElement], myContainer[i])) {
						indexOfSmallestElement = i;
					}
					//endCriticalSection();
				}

				// -- After finding the highest priority, need to place it on top of the PriorityQueue
				if (indexOfSmallestElement != 0) {
					std::swap(myContainer[0], myContainer[indexOfSmallestElement]);
				}
			}

			/// insert element to the PriorityQueue
			/// @param value the element to be added to the PriorityQueue
			void push(void* valueToPush) {
				//-- Compare “top” with the new element and swap if needed, container will always have the “highest priority” element on top.
				if (myCount == 0) {
					myContainer.insert(myContainer.begin(), valueToPush);
				}
				if (myCount >= 1) {
					Compare comp;
					if (comp(myContainer[0], valueToPush)) {
						myContainer.insert(myContainer.begin(), valueToPush);
					}
					else {
						myContainer.insert(myContainer.end(), valueToPush);
					}

				}
				++myCount;
			}



			/// Returns the top element in the PriorityQueue
			void* top() {
				if (!empty()) {
					return (void*)myContainer[0];
				}
			}

			void pop() {
				if (myCount > 1) {
					myContainer[0] = myContainer[myCount - 1];
					// MICHEL: What is needed here is a default initializer type.  It will look like:
					// SAMAH:	can I use the default constructor of T ??
					myContainer.erase(end() - 1);
					//myContainer[myCount - 1] = T();
					--myCount;
					sort();
				}
			}

			unsigned 								myCount;			// --  Number of elements in the queue. --
			Container								myContainer;		// -- The underlying container. -- 																		/// Defines the oprator [] that allows accessing the element in the container
		void* operator[](unsigned index) {return myContainer[index >= myCount ? myCount - 1 : index]; }

		};
		/// -- PriorityQueue specialization class for all types of pointers --
		template <typename T, typename Container, typename Compare> class PriorityQueue<T*, Container, Compare> : public PriorityQueue<void*, Container, Compare> {
		public:
			typedef PriorityQueue<void*, Container, Compare>					Base;
			typedef PriorityQueue<T*, Container, Compare>		Type;
			typedef T										ValueType;


			PriorityQueue() {}
			/// insert element to the PriorityQueue
			/// @param value the element to be added to the PriorityQueue
			void push(T* valueToPush) {
				Base::push((void*)valueToPush);
			}



			/// Returns the top element in the PriorityQueue
			T* top() {
				return (T*)Base::top();
			}
		};


	}
}


#endif
