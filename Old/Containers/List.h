#ifndef _LogikEdge_Seal_List_h
#define _LogikEdge_Seal_List_h

namespace LogikEdge { namespace Seal {

    struct ListElement {
      ListElement*  next;

      ListElement() { next= 0; }
    };

    class _List {
        ListElement*    first;
        ListElement*    last;

    public:
        _List() { first= last= 0; }

        bool isEmpty() const { return first == 0; }

        ListElement* peakAtTop() const {
            return isEmpty() ? 0 : first;

        }

        ListElement* peakAtBottom() const {
            return isEmpty() ? 0 : last;
        }

        ListElement* getFromTop() {
            if(isEmpty()) return 0;
            ListElement* top= first;
            first= top->next;
            top->next= 0;
            if(first == 0) last= 0;
            return top;
        }

        void addAtTop(ListElement& element) {
            // -- Don't accept to add element that is already linked. --
            if(element.next != 0) return;
            element.next= first;
            first= &element;
            if(last == 0) last= &element;
        }

        void addAtBottom(ListElement& element) {
            // -- Don't accept to add element that is already linked. --
            if(element.next != 0) return;
            element.next= 0;
            if(last == 0) { first= last= &element; return; }
            last->next= &element;
            last= &element;
        }
    };

    template <typename T>
    struct List : public _List {
        T* peakAtTop() const    { return (T*)_List::peakAtTop(); }
        T* peakAtBottom() const { return (T*)_List::peakAtBottom(); }
        T* getFromTop()         { return (T*)_List::getFromTop(); }
    };
}}

#endif
