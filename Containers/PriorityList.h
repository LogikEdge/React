#ifndef _LogikEdge_React_PriorityList_h
#define _LogikEdge_React_PriorityList_h

#include "List.h"

namespace LogikEdge { namespace React {

    struct _PriorityList {
        ListElement*    head;
        bool            isDirty;

        _PriorityList() { head= 0; isDirty= false; }

        /// Declares the priority list dirty.It will need to be resorted. --
        void setDirty() { isDirty= true; }

        void addElement(ListElement& element) {
            // -- Don't accept to add element that is already linked. --
            if(element.next != 0) return;
            // -- Add element at the head and request sorting. --
            isDirty= true;
            element.next= head;
            head= &element;
        }

        ListElement* peakAtTop(int (*cmp)(const ListElement&, const ListElement&)) {
            sort(cmp);
            return head;
        }

        ListElement* getFromTop(int (*cmp)(const ListElement&, const ListElement&)) {
            sort(cmp);
            ListElement* top= head;
            if(top != 0) {
            	head= top->next;
            	top->next= 0;
            	isDirty= true;
            }
            return top;
        }

        void sort(int (*cmp)(const ListElement&, const ListElement&)) {
            // -- Nothing to do if the list is already sorted. --
            if(isDirty == false) return;

            // -- Nothing to sort if we have one or less element. --
            if(head == 0 || head->next == 0) { isDirty= false; return; }

            // -- Find best element. --
            ListElement* best= head;
            ListElement* previousToBest= 0;
        	ListElement* prev= head;
        	for(ListElement* cursor= head->next; cursor != 0; prev= cursor, cursor= cursor->next) {
            	if(cmp(*best, *cursor) < 0) {
                	best= cursor;
                	previousToBest= prev;
            	}
        	}

            // -- Reposition the best element at the head. --
            if(previousToBest != 0) {
                previousToBest->next= best->next;
                best->next= head;
                head= best;
            }
            // -- The list is now sorted. --
            isDirty= false;
        }
    };

    template <typename T, typename ComparatorObject>
    struct PriorityList : public _PriorityList {
        struct Comparator {
            static int stub(const ListElement& e1, const ListElement& e2) {
                return ComparatorObject::compare((const T&)e1, (const T&)e2);
            };
        };

        T* peakAtTop() {
            return (T*)_PriorityList::peakAtTop(Comparator::stub);
        }

        T* getFromTop() {
            return (T*)_PriorityList::getFromTop(Comparator::stub);
        }
    };

}}

#endif
