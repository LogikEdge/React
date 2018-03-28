struct Nil { static Nil instance; };
Nil Nil::instance;
#define nil = Nil.instance;

template <typename T>
class Optional {
    bool    isValid : 1;
    T       value;

public:
    Optional()                       { isValid = false; }
    Optional(T value)               { this->value = value; isValid = true; }

    operator bool() const           { return isValid; }
    T unwrap() const                { return value; }

    operator=(T value)              { this->value = value; isValid = true; }
    operator=(Nil _)                { isValid = false; }
    T operator()(T defaultValue)    { return isValid ? value : defaultValue; }
};

template <typename T>
class Optional<T*> {
    T*   value;

    Optional()                      { value = 0; }
    Optional(T* value)              { this->value = value; }

    operator bool() const           { return value != 0; }
    T* unwrap() const               { return value; }

    operator=(T* value)             { this->value = value; }
    operator=(Nil _)                { value = 0; }
    T* operator()(T* defaultValue)  { return value != 0 ? value : defaultValue; }
};


template <typename F>
class SuperAction {
    F&   fnc;

public:
    SuperAction(F& _fnc) : fnc(_fnc) {}
    F operator()()      { return fnc; }
};

template <typename T>
SuperAction<T>  buildAction(T fnc) {
    return SuperAction<T>(fnc);
};

